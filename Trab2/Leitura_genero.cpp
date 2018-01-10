#include "Leitura_genero.h"

// construtor de leitura de genero
Leitura_genero::Leitura_genero (string argv,map<string,genero*> *generos)
{
	string linha;
	
	vector<string> dado;

	ifstream file (argv); // abre arquivo
			
	if (file.is_open()) // se arquivo for aberto normalmente
	{

	getline (file,linha);// pula cabeçalho

		while ( getline (file,linha) )
		{
			try
			{
			dado = split(linha,';'); // guarda em dado a linha separada por ponto e virgula
			
			size_t found = dado[1].find(' '); // declara variavel para verifica se existe um espaço no dado lido
		
			if (found != std::string::npos)	// se existe
			{
				if (found == 0)	// na primeira posição
		    			dado[1].erase(dado[1].begin());	 // apaga esse espaço
		    	}
		    	
			genero* g = new genero(dado[0],dado[1]); // cria um genero com uma sigla e seu nome
			
			generos->insert(pair<string,genero*>(g->getSigla(),g)); // insere na map de generos, um genero com a sigla como chave
			} // tratamento de exceções
			catch (invalid_argument) {
				throw Exception_Format ("Erro de formatação");
			}
		}

	file.close();
	}
	else
		throw Exception_IO("Erro de I/O");
}
Leitura_genero::~Leitura_genero()
{
}
