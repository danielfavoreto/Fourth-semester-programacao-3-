/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package TrabalhoPROG3_2015_2;

import java.io.Serializable;

/**
 *
 * @author Favoreto
 */
public class Série implements Serializable{
    private String nome;
    private int temporadas_consumidas;
    private int temporadas_a_consumir;
    
    public Série(String nome){
        setNome(nome);
    }
    
    protected int getTemporadas_consumidas(){
        return temporadas_consumidas;
    }
    protected int getTemporadas_a_consumir(){
        return temporadas_a_consumir;
    }
    protected void incrementar_consumidas(){
        temporadas_consumidas++;
    }
    protected void incrementar_a_consumir(){
        temporadas_a_consumir++;
    }
    protected String getNome(){
        return nome;
    }
    protected void setNome(String nome){
        this.nome = nome;
    }
}
