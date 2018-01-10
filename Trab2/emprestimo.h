/*
 * emprestimo.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef EMPRESTIMO_H_
#define EMPRESTIMO_H_

using namespace std;

#include <string>
#include <list>
#include <time.h>  

#include "pessoa.h"
#include "genero.h"
#include "midia.h"


class emprestimo {
private:
	midia* midiaEmprestada;
	string tomador;
	time_t inicio;
	time_t fim;

public:
	emprestimo(midia*, string, time_t, time_t);
	midia* getMidia();
	string getTomador();
	time_t getInicio();
	time_t getFim();
};

#endif /* EMPRESTIMO_H_ */