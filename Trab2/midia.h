/*
 * midia.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef MIDIA_H_
#define MIDIA_H_

using namespace std;

#include <string>
#include <list>
#include "pessoa.h"
#include "genero.h"

class midia {
protected:
	int codigo;
	string nome;
	string tipo;
	int tamanho;
	genero* midiaGenero;
	bool possui;
	bool consumiu;
	bool deseja;
	double preco;
	list<pessoa*> atores;

public:
	midia(int, string, string, list<pessoa*>, int, genero*, bool, bool, bool, double);
	int getCodigo();
	string getNome();
	string getTipo();
	int getTamanho();
	genero* getGenero();
	bool getPossui();
	bool getConsumiu();
	bool getDeseja();
	double getPreco();
	~midia();

};

#endif /* MIDIA_H_ */
