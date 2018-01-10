/* filme.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "filme.h"
 // construtor de filme
filme::filme(int codigo, string nome, string tipo, pessoa* diretor, list<pessoa*> atores, int tamanho, genero* midiaGenero, bool possui, bool consumiu, bool deseja, double preco) : midia(codigo, nome, tipo, atores, tamanho, midiaGenero, possui, consumiu, deseja, preco)
{
	this->diretor = diretor;
}
filme::~filme()
{
}
