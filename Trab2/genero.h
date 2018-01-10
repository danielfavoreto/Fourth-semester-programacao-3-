/*
 * genero.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef GENERO_H_
#define GENERO_H_

using namespace std;

#include <string>

class genero {
private:
	string sigla;
	string nome;
	int cont;

public:
	genero();
	genero(string, string);
	string getSigla();
	string getNome();
	int getCont();
	void setCont(int);
	~genero();
};


#endif
