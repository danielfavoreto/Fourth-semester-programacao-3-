/*
 * main.cpp
 *
 *  Created on: 24 de nov de 2015
 *      Author: 2013101847,2013101445
 */
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <locale>
#include <map>
#include <vector>
#include <sstream>
#include <utility>
#include <cstdint>
#include <time.h>  
#include <algorithm>
#include "DateUtils.h"
#include "NumPunctPTBR.h"
#include "NumberUtils.h"
#include "Leitura_emprestimo.h"
#include "Leitura_midia.h"
#include "Leitura_pessoa.h"
#include "map_pessoas.h"
#include "map_generos.h"
#include "Exception_IO.h"
#include "Exception_Format.h"
#include "Exception_Inconsis.h"
#include "Leitura_genero.h"
#include "Escreve_emprestimos.h"
#include "Escreve_wishlist.h"
#include "Escreve_estatisticas.h"
#include "Escreve_porpessoa.h"
#include "genero.h"
#include "sort.h"
#include "pessoa.h"
#include "midia.h"
#include "livro.h"
#include "filme.h"
#include "serie.h"
#include "emprestimo.h"

using namespace std;

using namespace br_ufes_inf_nemo_cpp_util;

int main (int argc,char *argv[])
{
	map<string,genero*> generos; // guarda generos
	map<int,pessoa*> pessoas; // guarda pessoas
	map<int,midia*> midias; // guarda midias
	list<emprestimo*> emprestimos; // guarda emprestimos
	
	list<midia*> wishlist; // guarda wishlist
	
	Leitura_midia *leitura_midia; // objeto de leitura para ser usado na construção da wishlist
	
	int k = 0,cont = 1;
	string linha,leitura;
	vector<string> dado;
	vector<string> dado2;

	// Leitura começa aqui
	
	try {
	
	while (cont != argc) // enquanto nao se chega ao final dos parâmetros
	{

	 if (cont == 1) // utilizou-se a variável "cont" devido a construção de midias ter como pré requisito a map de pessoas para inserir pessoas como atores, diretores e etc
	 {
			for (k = 0; k < argc; k++)
			{

			  leitura = argv[k]; // lê o parâmetro sendo passado: -g,-p,-e,-m

			  	if (leitura.compare("-g") == 0)
			      		break;
			}

			k += 1; // busca-se o nome do arquivo.csv
			
			string nome_arquivo = argv[k];
			
			new Leitura_genero (nome_arquivo,&generos);
	 }

	 if (cont == 3)
	 {
			for (k = 0; k < argc; k++)
			{

			  leitura = argv[k];

			  if(leitura.compare("-p") == 0)
			   {
			      break;
			   }

			}

			k += 1;

			ifstream file (argv[k]);
			
			string nome_arquivo = argv[k];
			
			new Leitura_pessoa (nome_arquivo,&pessoas);
			
	 }

	 if (cont == 5)
	 {
		for (k = 0; k < argc; k++)
		{
		  leitura = argv[k];

		  	if (leitura.compare("-m") == 0)
		  	    break;
		}

		k += 1;
			
		string nome_arquivo = argv[k];

		Leitura_midia *leitura_midia = new Leitura_midia (nome_arquivo,&pessoas,&generos,&midias);
	}

	if (cont == 7)
	{
		for (k = 0; k < argc; k++)
		{
		  leitura = argv[k];

			  if (leitura.compare("-e") == 0)
			      break;
		}

		k += 1;   
				
		string nome_arquivo = argv[k];
			
		new Leitura_emprestimo (nome_arquivo,&midias,&emprestimos);

		}
		
		cont += 2;
	}// fim Leitura	

	wishlist = leitura_midia->gera_wishlist(midias);

	int i = 0;	
	int horasConsumidas = 0;
	int horaConsumir = 0;
	
	vector<serie*> series;

	series = organiza_series(midias);
	
	for (map<int,midia*>::iterator m = midias.begin(); m != midias.end(); ++m)
	{
		if((m->second->getConsumiu() == true) && !(m->second->getTipo().compare("L") == 0))
			horasConsumidas += m->second->getTamanho();
			
		if((m->second->getDeseja() == true) && !(m->second->getTipo().compare("L") == 0))
			horaConsumir += m->second->getTamanho();
	}

	new Escreve_porpessoa(&pessoas);

	new Escreve_emprestimos(&emprestimos);

	new Escreve_wishlist(&wishlist);

	new Escreve_estatisticas(&generos,series,horasConsumidas,horaConsumir);

	} 
	catch (Exception_IO) {
		cout << endl;
	}
	catch (Exception_Inconsis) {
		cout << endl;
	}
	catch (Exception_Format) {
		cout << endl;
	}

	return 0;
}
