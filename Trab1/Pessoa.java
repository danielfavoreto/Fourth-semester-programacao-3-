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
public class Pessoa implements Serializable{
    private int código;
    private String nome;
    
    public Pessoa(int código,String nome){
        
        setCódigo(código);
        setNome(nome);
    }
    public int getCódigo(){
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
}