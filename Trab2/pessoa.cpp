/*
 * pessoa.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "pessoa.h"

using namespace std;
// construtor pessoa
pessoa::pessoa(int codigo, string nome)
{
  this->codigo = codigo;
  this->nome = nome;
}
pessoa::~pessoa()
{
	delete &producao;
}
// getters e setters
int pessoa::getCodigo()
{
  return codigo;
}

string pessoa::getNome()
{
  return nome;
}

vector<string> pessoa::getProducao()
{
  return producao;
}
// adiciona uma nova produção no vetor de produções
void pessoa::setProducao(vector<string> novaLista)
{
  producao = novaLista;
}
// função para adicionar uma midia no vetor de strings de produções
void pessoa::addProducao(string novaProducao)
{
  producao.push_back(novaProducao);
}
