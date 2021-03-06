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
public class Gênero implements Serializable{
    private String sigla;
    private String nome;
    private int quantidade_gêneros = 0;
    
    public Gênero(String sigla, String nome){
        setSigla(sigla);
        setNome(nome);
    }
    protected String getNome(){
        return nome;
    }
    protected void setNome(String nome){
        this.nome = nome;
    }
    protected String getSigla(){
        return sigla;
    }
    protected void setSigla(String sigla){
        this.sigla = sigla;
    }
    protected int getQuantidade(){
        return quantidade_gêneros;
    }
    protected void incrementa(){
        quantidade_gêneros++;
    }
}
