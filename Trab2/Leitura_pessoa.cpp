#include "Leitura_pessoa.h"


// construtor de leitura de pessoa tendo o nome do arquivo a ser lido e uma map das pessoas
Leitura_pessoa::Leitura_pessoa (string argv,map<int,pessoa*> *pessoas)
{
	string linha;
	
	vector<string> dado;

	ifstream file (argv); // abre arquivo

	if (file.is_open()) // verifica se tem permissao e consegue abrir arquivo
	{
	
	getline (file,linha);// Tirar cabeçalho

	try {

		while ( getline (file,linha) ) // ler a linha até acabar
		{
		
		dado = split(linha,';'); // guarda em dado a linha separada por ponto e virgula
		
		int codigo = stoi(dado[0]); // guarda o codigo da pessoa
		
		pessoa* p = new pessoa(codigo,dado[1]); // cria pessoa p
		
		pessoas->insert(pair<int,pessoa*>(p->getCodigo(),p)); // insere na map de pessoas a pessoa p e codigo como chave

		}
	file.close();
	
	}
	// tratamento de exceções
	catch (invalid_argument) {
		throw Exception_Format ("Erro de formatação");
	}
	
	}
	else
		throw Exception_IO("Erro de I/O");
}
Leitura_pessoa::~Leitura_pessoa()
{
}
