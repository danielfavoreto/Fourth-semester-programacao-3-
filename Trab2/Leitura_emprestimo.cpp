#include "Leitura_emprestimo.h"


Leitura_emprestimo::Leitura_emprestimo (string argv,map<int,midia*> *midias,list<emprestimo*> *emprestimos)
{
	string linha;
	
	vector<string> dado;

	ifstream file (argv); // declara arquivo

	if (file.is_open()) // verifica se está aberto
	{
	
	try {
	
	getline (file,linha);// Tirar cabeçalho

		while ( getline (file,linha) )
		{
			dado = split(linha,';'); // guarda em dado a linha separada por ponto e virgula

			int midcod = stoi(dado[0]); // guarda o codigo da midia

			auto a = midias->find(midcod); // tenta achar achar midia pelo codigo na lista de midias
			
			if (a == midias->end()) // se nao encontrou lança exceção
				throw Exception_Inconsis("Mídia",dado[0]); 
			else
			{
			midia* m = midias->find(midcod)->second; // cria uma midia
			
			time_t inicio = parseDate(dado[2],DATE_FORMAT_PT_BR_SHORT); // tempo inicio

			time_t fim = parseDate(dado[3],DATE_FORMAT_PT_BR_SHORT); // tempo fim
			
			emprestimo* e = new emprestimo(m, dado[1], inicio, fim); // cria um emprestimo

			emprestimos->push_back(e); // adiciona na lista de emprestimos	  
			}
			
		}
	} // tratamento de exceções
	catch (invalid_argument) {
		throw Exception_Format ("Erro de formatação");
	}
	
	}
	else
		throw Exception_IO("Erro de I/O");
}
Leitura_emprestimo::~Leitura_emprestimo()
{
}
