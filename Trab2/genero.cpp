/*
 * genero.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "genero.h"

using namespace std;

genero::genero(){}
// construtor de genero
genero::genero(string sigla, string nome)
{
  this->sigla = sigla;
  this->nome = nome;
  this->cont = 0;
}
genero::~genero()
{
}
// getters e setters
string genero::getSigla()
{
  return sigla;
}

string genero::getNome()
{
  return nome;
}

int genero::getCont()
{
  return cont;
}

void genero::setCont(int cont)
{
  this->cont = cont;
}
