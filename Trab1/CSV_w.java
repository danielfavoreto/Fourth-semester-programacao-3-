/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Favoreto
 */
public class CSV_w {
    FileWriter writer;
    public CSV_w(String file) throws IOException{

            writer = new FileWriter(file);
            writer.append("Tipo");
            writer.append(";");
            writer.append("Mídia");
            writer.append(";");
            writer.append("Gênero");
            writer.append(";");
            writer.append("Preço");
            writer.append("\n");

        
    }
    public void Escreve(Mídia m, HashMap<String ,Gênero> generos) throws IOException{
            
            if (m.getTipo() == 'F'){
                writer.append("Filme");
            }
            else if (m.getTipo() == 'L'){
                writer.append("Livro");
            }
            else if (m.getTipo() == 'S'){
                writer.append("Série");
            }
            
            writer.append(";");
            writer.append(m.getNome());
            writer.append(";");
            
            if (generos.containsKey(m.getGênero())){
                
                writer.append(generos.get(m.getGênero()).getNome());
            }
            writer.append(";");
            writer.append("R$ ");
          
            String linha = Float.toString(m.getPreço());
            String[] frase = linha.split("\\."); // vai até "."
            
            writer.append(frase[frase.length-2] + ",");
            writer.append(frase[frase.length-1]);
            
            writer.append("\n");

    }
    public void fecha () throws IOException{

            writer.flush();
            writer.close();

    }
}
