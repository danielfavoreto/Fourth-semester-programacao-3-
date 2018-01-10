/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Favoreto
 */
public class CSV_e {
    
    FileWriter writer;
    public CSV_e (String file) throws IOException{

            writer = new FileWriter(file);
            writer.append("Data");
            writer.append(";");
            writer.append("Tomador");
            writer.append(";");
            writer.append("Atrasado?");
            writer.append(";");
            writer.append("Dias de atraso");
            writer.append("\n");
    }
    
    public void fecha () throws IOException{

            writer.flush();
            writer.close();
    }
    
    protected void escreve_emprestimo_csv(String empréstimo,String tomador,boolean x, long dias)throws IOException{
        
            writer.append(empréstimo);
            writer.append(";");
            writer.append(tomador);
            writer.append(";");
            if (x == true){
                writer.append("Sim");
            }
            else 
                writer.append("Não");
            
            writer.append(";");
            writer.append(String.valueOf(dias));
            writer.append("\n");    
    }
}
