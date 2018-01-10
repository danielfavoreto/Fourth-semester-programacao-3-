/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.FileWriter;
import java.io.IOException;
import java.text.Collator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;

/**
 *
 * @author Favoreto
 */
public class CSV_m {
    FileWriter writer;
    public CSV_m(String file) throws IOException{

            writer = new FileWriter(file);
            writer.append("Pessoa");
            writer.append(";");
            writer.append("Produção");
            writer.append("\n");
        
    }
    public void Escreve(String nome,ArrayList<String> mídias) throws IOException{

            writer.append(nome);
            if (mídias != null){
                Collator collator = Collator.getInstance(new Locale("pt","br"));
                collator.setStrength(Collator.PRIMARY);
                
               Collections.sort(mídias,collator);
            }
            writer.append(";");
            int i = 0,size = mídias.size();
            for (String m : mídias){
                writer.append(m);
                i++;
                if (size == i){
                    break;
                }
                writer.append(", ");
            }
            writer.append("\n");
    }
    public void fecha () throws IOException{

            writer.flush();
            writer.close();

    }
}
