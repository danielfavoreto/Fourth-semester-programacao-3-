/* emprestimo.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "emprestimo.h"

// construtor de emprestimo
emprestimo::emprestimo(midia* midiaEmprestada, string tomador, time_t inicio, time_t fim)
{
	this->midiaEmprestada = midiaEmprestada;
	this->tomador = tomador;
	this->inicio = inicio;
	this->fim = fim;
}
// getters e setters
midia* emprestimo::getMidia()
{
  return midiaEmprestada;
}

string emprestimo::getTomador()
{
  return tomador;
}

time_t emprestimo::getInicio()
{
  return inicio;
}

time_t emprestimo::getFim()
{
  return fim;
}
