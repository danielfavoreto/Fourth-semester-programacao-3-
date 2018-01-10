/*
 * midia.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "midia.h"

// construtor midias

midia::midia(int codigo, string nome, string tipo, list<pessoa*> atores, int tamanho, genero* midiaGenero, bool possui, bool consumiu, bool deseja, double preco)
{
	this->nome = nome;
	this->codigo = codigo;
	this->nome = nome;
	this->tipo = tipo;
	this->tamanho = tamanho;
	this->midiaGenero = midiaGenero;
	this->possui = possui;
	this->consumiu = consumiu;
	this->deseja = deseja;
	this->preco = preco;
	this->atores = atores;
}
midia::~midia ()
{
	delete midiaGenero;
	delete &atores;
}
// getters e setters
int midia::getCodigo()
{
  return codigo;
}

string midia::getNome()
{
  return nome;
}

string midia::getTipo()
{
  return tipo;
}

bool midia::getDeseja()
{
  return deseja;
}

bool midia::getPossui()
{
  return possui;
}

bool midia::getConsumiu()
{
  return consumiu;
}

int midia::getTamanho()
{
  return tamanho;
}

genero* midia::getGenero()
{
  return midiaGenero;
}

double midia::getPreco()
{
  return preco;
}



