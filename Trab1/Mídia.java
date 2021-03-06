/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.Serializable;
import static java.lang.Integer.parseInt;
import java.util.HashMap;

/**
 *
 * @author Favoreto
 */
public class Mídia implements Serializable{
    private Integer código;
    private String nome;
    private Character tipo;
    private Integer diretor; // no caso de livros e séries ficará vazio
    private HashMap<Integer, Integer> autores = new HashMap<Integer,Integer>(); //autores e atores na mesma lista
    private Integer tamanho;
    private String gênero;
    private String série; // no caso de livros e filmes ficará vazio
    private Integer temporada;
    private boolean possui ; // vazio se o usuário nao tem
    private boolean consumiu ; // vazio se o usuário nao consumiu
    private boolean deseja ; // vazio se o usuário nao deseja
    private float preço;
    
        protected Mídia (Integer código, String nome, Character tipo, String diretor, String autores, Integer tamanho, String gênero,String série, Integer temporada, Character possui,Character consumiu, Character deseja, String preço){
            
            setCódigo(código);
            setNome(nome);
            setTipo(tipo);
            
            if (tipo == 'L' || tipo == 'S'){ //se é um livro ou serie nao tem diretor
                setDiretor(null);
            }
            else {
                if (diretor.equals("")){ //caso nao tenha diretor 
                    setDiretor(null);
                }
                else {
                    setDiretor(parseInt(diretor));
                }
            }
                
            setAutor(autores);
            setTamanho(tamanho);
            setGênero(gênero);
            
            if (tipo != null) { //verificando se o tipo existe
                    if (tipo != 'L' || tipo == 'S'){
                        setSérie(null);
                    }
                    else {
                        setSérie(série);
                    }    
                  }
            else
                 setSérie(null);
            
            setTemporada(temporada);
            setPossui(possui);
            setConsumiu(consumiu);
            setDeseja(deseja);
            setPreço(preço);
        }
        
        protected Integer getDiretor(){
            return diretor;
        }
        protected void setDiretor(Integer diretor){
            this.diretor = diretor;
        }
        protected int getCódigo(){
            return código;
        }
        protected void setCódigo(int código){
            this.código = código;
        }
        protected String getNome(){
            return nome;
        }
        protected void setNome(String nome){
            this.nome = nome;
        }
        protected Character getTipo(){
            return tipo;
        }
        protected void setTipo(Character tipo){
            this.tipo = tipo;
        }
        protected void setAutor(String autores){
            
            if (autores != null)
            {
                
                String[] linha;
                String divisor = ",";
                
                linha = autores.split(divisor); // dividindo a(u)tores por ,
                
                if (linha != null){
                    
                    int i;
                    
                    for (i = 1;i <= linha.length;i++){
                   
                        if (linha[linha.length-i].equals("")){
                            break;
                        }
                        else
                        {
                            this.autores.put(parseInt(linha[linha.length-i]),parseInt(linha[linha.length-i]));
                        }
                            }
                    }
            }
            else {
                this.autores = null;
            }
        }
        protected int getTamanho(){
            return tamanho;
        }
        protected void setTamanho(Integer tamanho){
            this.tamanho = tamanho;
        }
        protected String getGênero(){
            return gênero;
        }
        protected void setGênero(String gênero){
            this.gênero = gênero;
        }
        protected String getSérie(){
            return série;
        }
        protected void setSérie(String série){
            this.série = série;
        }
        protected int getTemporada(){
            return temporada;
        }
        protected void setTemporada(Integer temporada){
            this.temporada = temporada;
        }
        protected boolean getPossui(){
            return possui;
        }
        protected void setPossui(Character possui){
            this.possui = possui != null && possui != ' ';
        }
        protected boolean getConsumiu(){
            return consumiu;
        }
        protected void setConsumiu(Character consumiu){
            this.consumiu = consumiu != null && consumiu != ' ';
        }
        protected boolean getDeseja(){
            return deseja;
        }
        protected void setDeseja(Character deseja){
            this.deseja = deseja != null && deseja != ' ';
        }
        protected float getPreço(){
            return preço;
        }
        protected void setPreço(String preço){
            String divisor = ",";
            String[] linha = preço.split(divisor);
            
            if (linha.length > 1){
                
                float centavos = Float.parseFloat(linha[linha.length-1]); // pegando os "centavos"
                
                if (linha[linha.length-1].length() == 1){
                    centavos = Float.parseFloat(linha[linha.length-1])*10; // multiplica por 10 em caso de ser por exemplo: 59,9. O 9 é multiplicado por 10 para ser considerado 90 centavos ao invés de 9 centavos
                 
                }
                this.preço = Float.parseFloat(linha[linha.length-2]) + centavos/100; // guardando o preço da midia
               
            }
            else if (linha.length == 1)
                this.preço = Float.parseFloat(linha[linha.length-1]);
            else
                this.preço = 0;
        }
        protected HashMap<Integer,Integer> getAutores(){
            return autores;
        }
}
