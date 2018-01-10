/* livro.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#include "livro.h"
// construtor de livro
livro::livro(int codigo, string nome, string tipo, list<pessoa*> atores, int tamanho, genero* midiaGenero, bool possui, bool consumiu, bool deseja, double preco):midia(codigo, nome, tipo, atores, tamanho, midiaGenero, possui, consumiu, deseja, preco)
{
}
livro::~livro()
{
}
