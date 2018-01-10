/* serie.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "serie.h"

// construtor da série

serie::serie(int codigo, string nome, string tipo, list<pessoa*> atores, int tamanho, genero* midiaGenero, string nomeSerie, int temporada, bool possui, bool consumiu, bool deseja, double preco):midia(codigo, nome, tipo, atores, tamanho, midiaGenero, possui, consumiu, deseja, preco)
{
  this->nomeSerie = nomeSerie;
  this->temporada = temporada;
  
  temporadas_consumidas = 0;
  temporadas_a_consumir = 0;
  
  if (consumiu) // se pessoa consumiu
  {
  		setConsumiu(1);
  	
  	if (deseja)
  		setConsumiu(1);
  	else
	  	setAconsumir(0);
  }
  else if (deseja) // se deseja mas nao consumiu
  {
  	setConsumiu(0);
  	setAconsumir(1);
  }
  else // nao deseja nem consumiu
  {
  	setConsumiu(0);
  	setAconsumir(0);
  }
}
serie::~serie()
{
}
//getters e setters
void serie::setConsumiu(int x)
{
	temporadas_consumidas = temporadas_consumidas + x;
}
void serie::setAconsumir(int x)
{
	temporadas_a_consumir = temporadas_a_consumir + x;;
}
int serie::getTemporada_a_consumir ()
{
	return this->temporadas_a_consumir;
}
int serie::getTemporada_consumida ()
{
	return this->temporadas_consumidas;
}
string serie::getSerie()
{
  return nomeSerie;
}

int serie::getTemporada()
{
  return temporada;
}
