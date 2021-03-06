/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author Favoreto
 */
public class CSV_estatistica {
        FileWriter writer;
        public CSV_estatistica(String file,int horas_consu, int horas_a_consu) throws IOException{

                writer = new FileWriter(file);
                writer.append("Horas consumidas: " + horas_consu + " minutos" + "\n");
                writer.append("Horas a consumir: " + horas_a_consu + " minutos");
                writer.append("\n\n");
                writer.append("Mídias por gênero:\n");            
        }
        public void Escreve(ArrayList<Gênero> gêneros,HashMap<String,Série> map_série) throws IOException{

                for (Gênero g: gêneros){
                    writer.append("\t" + g.getNome() + ": " + g.getQuantidade() + "\n");
            }
            writer.append("\n");
            
            writer.append("Temporadas por série:\n");
            for (Map.Entry<String, Série> entry : map_série.entrySet()) {
                writer.append("\t" + entry.getKey()+": " + entry.getValue().getTemporadas_consumidas() + " assistidas, " + entry.getValue().getTemporadas_a_consumir() + " a assistir\n" );
            }
            writer.flush();
            writer.close();
        }
}
