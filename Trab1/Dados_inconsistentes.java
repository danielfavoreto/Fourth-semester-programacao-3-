/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

/**
 *
 * @author Favoreto
 */
public class Dados_inconsistentes extends Exception{

	
    
    public Dados_inconsistentes(){
    	super();
    }
    public Dados_inconsistentes(String mensagem, Throwable causa){
    	super(mensagem,causa);
    	System.err.println(mensagem);
    }
    public Dados_inconsistentes(String mensagem){
    	super(mensagem);
	System.err.println(mensagem);
    }
    public Dados_inconsistentes(Throwable causa){
    	super(causa);
    }

}
