
package TrabalhoPROG3_2015_2;

import java.io.Serializable;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.TimeUnit;

/**
 *
 * @author Favoreto
 */
public class Empréstimo implements Serializable{
    
    private int mídia;
    private String tomador;
    private String empréstimo;
    private String devolução;
    
    protected Empréstimo (int mídia, String tomador, String empréstimo, String devolução){
        setMídia(mídia);
        setTomador(tomador);
        setEmpréstimo(empréstimo);
        setDevolução(devolução);
    }
    protected int getMídia(){
        return mídia;
    }
    protected void setMídia(int mídia){
        this.mídia = mídia;
    }
    protected String getEmpréstimo(){
        return empréstimo;
    }
    protected void setEmpréstimo(String empréstimo){
        this.empréstimo = empréstimo;
    }
    protected String getDevolução(){
        return devolução;
    }
    protected void setDevolução(String devolução){
        this.devolução = devolução;
    }
    protected String getTomador(){
        return tomador;
    }
    protected void setTomador(String tomador){
        this.tomador = tomador;
    }
    
    protected long is_late(String devolução,String hoje ) throws ParseException{
        
 	    DateFormat dateformat = new SimpleDateFormat("dd/MM/yyyy");

            Date date_devolução = dateformat.parse(devolução);
            
            Date date_hoje = dateformat.parse(hoje);
            
            long diff = date_hoje.getTime() - date_devolução.getTime();
            
            return TimeUnit.DAYS.convert(diff,TimeUnit.MILLISECONDS);
    }

}
