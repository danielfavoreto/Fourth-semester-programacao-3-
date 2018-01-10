/*
 * filme.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef FILME_H_
#define FILME_H_

using namespace std;

#include <string>
#include <list>
#include "pessoa.h"
#include "genero.h"
#include "midia.h"


class filme : public midia{
private:
	pessoa* diretor;

public:
	filme(int, string, string, pessoa*, list<pessoa*>, int, genero*, bool, bool, bool, double);
	~filme();
};

#endif /* FILME_H_ */
