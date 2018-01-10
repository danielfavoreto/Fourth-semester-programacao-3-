#include "Escreve_porpessoa.h"

// construtor do escritor do relatorio porpessoa
Escreve_porpessoa::Escreve_porpessoa (map<int,pessoa*> *pessoas)
{
	ofstream myfile2 ("2-porpessoa.csv");// escreve porpessoa
	
	if (myfile2.is_open()) // se conseguir abrir arquivo
	{
	
	int i;
	map<int,pessoa*>::iterator it; // iterador da map de pessoas
	vector< map_pessoas > v; // vetor de map_pessoas 
	vector< map_pessoas >::iterator itv; // iterador de map_pessoas
	map_pessoas sm; // uma map_pessoas para inserir uma pessoa na map de pessoas
	
	for (it = pessoas->begin(); it != pessoas->end(); ++it) // para cada pessoa na map de pessoas 
	{
		sm.key = (*it).first; sm.value = (*it).second; // captura a chave e valor da pessoa
		v.push_back(sm); // insere no vetor de map_pessoas a pessoa
	}
	
	sort(v.begin(),v.end(),sort_map_names); // ordena o vetor de map_pessoas usando sort_map_names
	
	myfile2 << "Pessoa;Produção\n";	// cabeçalho
	
	for (itv = v.begin(); itv != v.end(); ++itv) // para cada map_pessoas no vetor v
	{
		vector<string> producao = (*itv).value->getProducao(); // um vetor de produções para guardar o nome das midias em que cada pessoa participa
		
		if (producao.size() != 0) // se nao for vazio
	    	{
	    		string nome_pessoa = (*itv).value->getNome(); // captura o nome da pessoa 
	    		
			size_t found = nome_pessoa.find('\n'); // verifica se tem '\n' no nome da pessoa
		
			if (found != std::string::npos)	// se achou
		    		nome_pessoa.erase(nome_pessoa.begin()+(nome_pessoa.size()-1));	 // retira esse caractere '\n'
	    		
	     	 	myfile2 << nome_pessoa << ";";// escreve no arquivo o nome da pessoa seguido de ponto e virgula
	      
			sort (producao.begin(),producao.end(),sort_names); // ordena o vetor de produções usando o sort_names

	
	     	 for (i=0;i<producao.size();i++) // para cada midia em que a pessoa é participante
	     	 {
			if(i == (producao.size() - 1)) // verifica se não é a última mídia
			{
	 		   myfile2 << producao[i]; // escreve no arquivo o nome da mídia
			}
			else // não é a última mídia
			{
			  myfile2 << producao[i] << ", "; // escreve no arquivo o nome da mídia seguido de vírgula
			}
	     	 }
	     	 myfile2 << "\n"; 
	    }	
	}
	  myfile2.close();// fim porpessoa
	}
	else // tratamento de exceção
		throw Exception_IO("Erro de I/O");
}
Escreve_porpessoa::~Escreve_porpessoa()
{
}
