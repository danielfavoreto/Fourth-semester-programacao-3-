/*
 * livro.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef LIVRO_H_
#define LIVRO_H_

using namespace std;

#include <string>
#include <list>
#include "pessoa.h"
#include "genero.h"
#include "midia.h"

// classe livro herda de midia
class livro : public midia{
public:
	livro(int, string, string, list<pessoa*>, int, genero*, bool, bool, bool, double);
	~livro();
};

#endif /* LIVRO_H_ */
