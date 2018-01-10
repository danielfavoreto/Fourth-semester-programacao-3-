
package TrabalhoPROG3_2015_2;

import java.io.File;
import java.util.Scanner;
import java.io.IOException;
import java.io.Serializable;
import static java.lang.Integer.parseInt;

/**
 *
 * @author Favoreto
 */
public class Leitura_e extends Leitura implements Serializable {
    public Leitura_e(String arg) throws IOException{
    
    String linha;
    
    String[] frase;
    
    String csvDivisor = ";";
    
	File arq = new File(arg); 
	
    	Scanner in = new Scanner(arq);
    	
    	in.nextLine();

    
        while (in.hasNextLine()) {
            
            linha = in.nextLine();
            frase = linha.split(csvDivisor);

            Empréstimo e = new Empréstimo(parseInt(frase[frase.length-4]),frase[frase.length-3],frase[frase.length-2],frase[frase.length-1]);
            
            empréstimos.add(e);
        }
    }
}
