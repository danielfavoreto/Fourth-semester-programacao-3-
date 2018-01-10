/*
 * pessoa.h
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847
 */

#ifndef PESSOA_H_
#define PESSOA_H_

using namespace std;

#include <string>
#include <vector>

class pessoa {
private:
	int codigo;
	string nome;
	vector<string> producao;
public:
	pessoa();
	~pessoa();
	pessoa(int, string);
	int getCodigo();
	string getNome();
	void addProducao(string);
	vector<string> getProducao();
	void setProducao(vector<string>);
};

#endif /* PESSOA_H_ */
