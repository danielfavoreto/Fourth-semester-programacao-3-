/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.text.Collator;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

/**
 *
 * @author Favoreto
 */
public class Executa extends Leitura implements Serializable{
          public Executa (char tipo) throws IOException, ClassNotFoundException,ParseException, Dados_inconsistentes{
          
              verifica_inconsistencia (mídias,gêneros,empréstimos,códigos_pessoas,códigos_mídias); // função para verificar inconsistencia nos dados
          
              HashMap<String,Série> séries = organiza_mídia_por_gênero_e_série(gêneros,mídias); // organiza as séries para o arquivo de estatisticas.txt processar de forma eficiente, guardando as séries pelo nome antes do "-" correspondente à temporada
              
              if (tipo == 'w'){
                  writeOnly();
              }
              else if (tipo == 'r'){
                  readOnly(mídias,pessoas,empréstimos,gêneros,séries);
                 
              }
              else {
                  executa_emprestimos(empréstimos); // executa relatorio de emprestimos.csv
                  executa_midias(mídias,pessoas,gêneros); // executa a wishlist e porpessoa.csv
                  executa_estatistica(mídias,gêneros,séries); // executa relatorio de estatistica.txt
              }
                  
          }
          /*
          	Função para verificar as inconsistencias nos arquivos de entrada, achamos 4 tipos de inconsistencias: coluna gênero de mídia não corresponde ao arquivo de gêneros, coluna diretor de mídia não corresponde ao arquivo pessoas, coluna a(u)tores de mídia não corresponde ao arquivo pessoas, coluna mídia de empréstimo não corresponde ao arquivo mídias
          */
          
    private void verifica_inconsistencia (ArrayList<Mídia> mídias,HashMap<String, Gênero> gêneros, ArrayList<Empréstimo> empréstimos,HashMap<Integer,Integer> pessoas, HashMap<Integer,Integer> códigos_mídias) throws Dados_inconsistentes{
              for (Mídia mi: mídias){
                  if (!gêneros.containsKey(mi.getGênero())){ // inconsistencia de generos
                     throw new Dados_inconsistentes("Dados inconsistentes" + "("+"Gênero: "+mi.getGênero()+")");
                  	
                  }
                  if (mi.getDiretor() != null) {
                      if (!pessoas.containsKey(mi.getDiretor())){ // inconsistencia de diretor
                      throw new Dados_inconsistentes("Dados inconsistentes" + "(" + "Diretor: "+mi.getDiretor()+")");
                      
                    }
                  }
                  
                  for (Map.Entry<Integer,Integer> aut : mi.getAutores().entrySet()){
                      if (!pessoas.containsKey(aut.getKey())){ // inconsistencia de a(u)tores
                          throw new Dados_inconsistentes("Dados inconsistentes" + "("+"A(u)tores: "+aut.getKey()+")");
                          
                      }
                  }
              }
              for (Empréstimo e: empréstimos){
                  if (!códigos_mídias.containsKey (e.getMídia())){ // inconsistencia de midias
                      throw new Dados_inconsistentes("Dados inconsistentes" + "("+"Mídia: "+e.getMídia()+")");
                  }
              }
          }
          /*
          	Função para criar uma hash contendo séries, com a quantidade de temporadas que se deseja consumir e a consumir
          */
          
    private HashMap<String,Série> organiza_mídia_por_gênero_e_série (HashMap<String, Gênero> hash_gênero,ArrayList<Mídia> lista_mídias) throws IOException{
        
            HashMap<String,Série> séries = new HashMap<String,Série>();
            
            for (Mídia m: lista_mídias){
                
                hash_gênero.get(m.getGênero()).incrementa();
                
                if (m.getTipo() == 'S'){
                    String[] nome = m.getNome().split("-"); // retira o hífen que separa o nome da série e a temporada
                    
                    if (séries.containsKey(nome[nome.length-2])){
                            if (m.getConsumiu()){
                                séries.get(nome[nome.length-2]).incrementar_consumidas();
                        }
                            else if (m.getDeseja()){
                                séries.get(nome[nome.length-2]).incrementar_a_consumir();
                        }
                    }
                    else {
                        Série s = new Série(nome[nome.length-2]);
                    
                        if (m.getConsumiu()){
                            s.incrementar_consumidas(); //deseja consumir
                        }
                        else if (m.getDeseja()){
                            s.incrementar_a_consumir(); // foi consumido
                        }
                    
                        séries.put(s.getNome(),s);
                    }
                }
            }
            return séries;
    }
    /*
    	Função para executar o writeOnly lendo de inventario.dat e executando-o com readObject
    */
    
    private void writeOnly() throws IOException,ClassNotFoundException,ParseException{
    
    	    FileInputStream entrada = null;
    	    ObjectInputStream obj_entrada = null;    

            entrada = new FileInputStream("inventario.dat");
            obj_entrada = new ObjectInputStream(entrada);
                  
                  	// listas e hashes para guardar os dados
                     ArrayList<Mídia> lista_mídias = (ArrayList<Mídia>) obj_entrada.readObject();
                     ArrayList<Pessoa> lista_pessoas = (ArrayList<Pessoa>) obj_entrada.readObject();
                     ArrayList<Empréstimo> lista_empréstimos = (ArrayList<Empréstimo>) obj_entrada.readObject();
                     HashMap<String,Gênero> map_gêneros = (HashMap<String,Gênero>) obj_entrada.readObject();
                     HashMap<String,Série> map_série = (HashMap<String,Série>) obj_entrada.readObject();

                     obj_entrada.close();
                     entrada.close();
                     // segue fluxo de criação dos relatorios
                     
                     executa_emprestimos(lista_empréstimos);
                     executa_midias(lista_mídias,lista_pessoas,map_gêneros);
                     executa_estatistica(lista_mídias,map_gêneros,map_série);
                    
                    obj_entrada.close();
                    entrada.close();
                    
                    
    }
    /*
    	Função que fará apenas o readOnly criando o arquivo inventario e escrevendo-o com writeObject
    */
    private void readOnly(ArrayList<Mídia> lista_mídias,ArrayList<Pessoa> lista_pessoas,ArrayList<Empréstimo> lista_empréstimos, HashMap<String,Gênero> map_gêneros,HashMap<String,Série> map_série)throws IOException{
    
            FileOutputStream saida = null;
            ObjectOutputStream obj_saida = null;
            
            
            saida = new FileOutputStream("inventario.dat");
            obj_saida = new ObjectOutputStream(saida);
            
                    obj_saida.writeObject(lista_mídias);
                    obj_saida.writeObject(lista_pessoas);
                    obj_saida.writeObject(lista_empréstimos);
                    obj_saida.writeObject(map_gêneros);    
                    obj_saida.writeObject(map_série);
                    
            obj_saida.flush();
            obj_saida.close();
            saida.flush();
            saida.close();
            
    }
    /*
    	Função para criar o arquivo de empréstimos, ordenando emprestimos por nomes e datas 
    */
    private void executa_emprestimos(ArrayList<Empréstimo> lista_empréstimo) throws IOException,ParseException{
        
        sort_dates_names_empréstimo(lista_empréstimo); // ordena por nome e data
        
        CSV_e csv = new CSV_e("3-emprestimos.csv");
        
        long dif;
        
        for (Empréstimo e: lista_empréstimo){
            
            dif = e.is_late(e.getDevolução(),"06/11/2015"); // verifica a diferença de dias (em relação ao dia 06 de novembro)
            
            if (dif < 0){ //caso não está atrasado
                csv.escreve_emprestimo_csv(e.getEmpréstimo(), e.getTomador(), false, 0);
            }
            else
                csv.escreve_emprestimo_csv(e.getEmpréstimo(), e.getTomador(), true, dif) ;// caso esteja dentro do prazo
        }
        csv.fecha(); // close no arquivo
        
    }
    /*
    	Função para criar o arquivo porpessoas.csv e wishlist. OPtou-se por fazer os dois relatorios na mesma função para aproveitar o uso da lista de mídias
    
    */
    
    private void executa_midias(ArrayList<Mídia> mídia, ArrayList<Pessoa> pessoa, HashMap<String,Gênero> map_gêneros) throws IOException{ // mídias por pessoa e wishlist
            
            CSV_m csv_m = new CSV_m("2-porpessoas.csv");
           
            CSV_w csv_w = new CSV_w("4-wishlist.csv");
            
            sort_names_pessoa(pessoa); // ordena a lista de pessoas por ordem alfabética
            
            sort_price_names_mídia(mídia); // ordena as mídias por ordem decrescente de preço e ordem alfabética
            
            List<String> aux = new ArrayList<>(); // vetor para auxiliar a guardar o nome das mídias

            int i = 0;
            
            for (Pessoa p : pessoa){
                
                for(Mídia m: mídia){
                    
                    if (m.getTipo() == 'F'){ //filme
                        if (p.getCódigo() == m.getDiretor()){
                            aux.add(m.getNome());
                        }
                    }
                    if (m.getAutores() != null){
                        
                        for (Map.Entry<Integer, Integer> entry : m.getAutores().entrySet()) {
                            Integer value = entry.getValue();
                            
                            if (value == p.getCódigo()){
                                aux.add(m.getNome());
                            }
                        }
                    }
                        if (i == 0){
                            if (m.getDeseja() == true && m.getPossui() == false){
                                csv_w.Escreve(m,map_gêneros);
                            }
                        }
                }
                i++;
                if (!aux.isEmpty()){
                    csv_m.Escreve(p.getNome(), (ArrayList<String>) aux);
                    aux.clear();
                }
            }
            csv_m.fecha(); // fecha o relatorio porpessoa
            csv_w.fecha();// fecha o relatorio de wishlist
            
        }
     /*
     	Função para criar arquivo de estatisticas 
     */   
        
    private void executa_estatistica(ArrayList<Mídia> mídias, HashMap<String,Gênero> gêneros, HashMap<String, Série> séries) throws IOException{
	int horas_consu = 0,horas_a_consu = 0;
        
        for (Mídia m: mídias){
            if (m.getTipo() != 'L'){ // horas consumidas ou horas a consumir sao para séries e filmes, por isso livros estão fora da comparação
                if (m.getConsumiu() == true){
                    horas_consu += m.getTamanho();
                }
                if (m.getDeseja() == true){
                    horas_a_consu += m.getTamanho();
                }
            }
        }    
            ArrayList<Gênero> lista_ord_gêneros;
            lista_ord_gêneros = (ArrayList<Gênero>) sort_gêneros(gêneros); // lista com os gêneros ordenados
            CSV_estatistica csv = new CSV_estatistica("1-estatisticas.txt",horas_consu,horas_a_consu); // imprime o cabeçalho e as horas consumidas e a consumir
            csv.Escreve(lista_ord_gêneros, séries);  // escreve no arquivo estatisticas utilizando séries e a lista de gêneros ordenados
    }
    
    /*
    	Função para ordenar gêneros pela quantidade em que aparecem e depois pelo nome
    */
    private List<Gênero> sort_gêneros(HashMap<String, Gênero> hash_gêneros){
        
            List<Gênero> gênero_por_ocorrência = new ArrayList<Gênero>(hash_gêneros.values());
           
            Collections.sort(gênero_por_ocorrência, new Comparator<Gênero>() {

            public int compare(Gênero o1, Gênero o2) {
                int comparaQuantidade = o2.getQuantidade() - o1.getQuantidade();
                    if (comparaQuantidade == 0){
                        Collator collator = Collator.getInstance(new Locale("pt","br"));
                        collator.setStrength(Collator.PRIMARY);
                        
                        return collator.compare(o1.getNome(), o2.getNome());
                    }
                    return comparaQuantidade;
                }
            });
            return gênero_por_ocorrência;
    }
    /*
    	Função para ordenar empréstimos pelo nome e data
    */
    private void sort_dates_names_empréstimo (ArrayList<Empréstimo> lista_empréstimo) throws ParseException{
        
            Collections.sort(lista_empréstimo, new Comparator<Empréstimo>() {
            
            DateFormat dateformat = new SimpleDateFormat("dd/MM/yyyy"); // formatando o tipo de data 
            
            @Override
             public int compare(Empréstimo e1, Empréstimo e2){

		try {
		
		    Date d1 = dateformat.parse(e1.getEmpréstimo());
                    Date d2 = dateformat.parse(e2.getEmpréstimo());
                    
                    int result = d2.compareTo(d1);
                    
                    if (result == 0){
                        Collator collator = Collator.getInstance(new Locale("pt","br"));
                        collator.setStrength(Collator.PRIMARY);
                        
                        return collator.compare(e1.getTomador(), e2.getTomador());
                    }
                    else {
                        return result;
                    }		
		} catch (ParseException e){
		
			System.err.println("Erro de formatação");
			return 0;
		}
		
         }
            });
    }
    /*
    	Função para ordenar pessoas pelo nome
    */
    private void sort_names_pessoa (ArrayList<Pessoa> lista_pessoa){
        
            Collections.sort(lista_pessoa, new Comparator<Pessoa>() {

                @Override
                public int compare(Pessoa o1, Pessoa o2) {
                    Collator collator = Collator.getInstance(new Locale("pt","br"));
                    collator.setStrength(Collator.PRIMARY);
                    
                    return collator.compare(o1.getNome(), o2.getNome());
                    
                }
            } );
    }
    /*
    	Função para ordenar mídias pelo preço e pelo nome
    */
    private void sort_price_names_mídia (ArrayList<Mídia> lista_mídias){
        
        Collections.sort(lista_mídias, new Comparator<Mídia>() {

                @Override
                public int compare(Mídia o1, Mídia o2) {
                    
                    int tipo = o1.getTipo().compareTo(o2.getTipo());
                   
                    if (tipo == 0){
                        int preço = Float.compare(o2.getPreço(),o1.getPreço());
                        
                        if (preço == 0){
                            Collator collator = Collator.getInstance(new Locale("pt","br"));
                            collator.setStrength(Collator.PRIMARY);
                            
                            return collator.compare(o1.getNome(), o2.getNome());
                        }
                        else
                            return preço;
                    }
                    else
                        return tipo;
                }
            } );
    }
}
