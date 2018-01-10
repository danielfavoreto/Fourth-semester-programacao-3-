/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.util.Scanner;
import java.io.File;
import java.io.IOException;

/**
 *
 * @author Favoreto
 */
public class Leitura_g extends Leitura{
    public Leitura_g (String arg) throws IOException{
    
    String linha = "";
    
    String csvDivisor = ";";
    
    String[] frase;
    
    	File arq = new File(arg);

    	Scanner in = new Scanner(arq);
    	
    	in.nextLine();	

        while (in.hasNextLine()) {
        
	    linha = in.nextLine();
            frase = linha.split(csvDivisor);
            
            Gênero g = new Gênero(frase[frase.length-2],frase[frase.length-1]);
            
            gêneros.put(g.getSigla(),g);
        }
    }
}
