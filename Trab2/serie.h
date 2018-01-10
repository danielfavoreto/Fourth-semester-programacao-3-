/*
 * serie.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef SERIE_H_
#define SERIE_H_

using namespace std;

#include <string>
#include <list>
#include "pessoa.h"
#include "genero.h"
#include "midia.h"


class serie : public midia{
private:
  string nomeSerie;
  int temporada;
  int temporadas_consumidas;
  int temporadas_a_consumir;
  
public:
	serie(int, string, string, list<pessoa*>, int, genero*, string, int, bool, bool, bool, double);
	string getSerie();
	int getTemporada();
	void setConsumiu(int);
	void setAconsumir(int);
	int getTemporada_consumida ();
	int getTemporada_a_consumir ();
	~serie();
};

#endif /* SERIE_H_ */
