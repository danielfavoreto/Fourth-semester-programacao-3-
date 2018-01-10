#include "Escreve_estatisticas.h"

// construtor do escritor do relatorio de estatisticas 

Escreve_estatisticas::Escreve_estatisticas (map<string,genero*> *generos,vector<serie*> series,int horasConsumidas,int horaConsumir)
{
	ofstream myfile ("1-estatisticas.txt");//escreve as estatisticas
	
	int i;
	
	if (myfile.is_open()) // se arquivo está aberto 
	{
	  myfile << "Horas consumidas: " << horasConsumidas << " minutos\n"; // escreve as horas consumidas
	  myfile << "Horas a consumir: " << horaConsumir << " minutos\n"; // escreve as horas a consumir
	  myfile << "\nMídias por gênero:\n"; // cabeçalho 

		map<string,genero*>::iterator it_g; // iterador da map de generos
		vector< map_generos > v_g; // vetor contendo map_generos 
		vector< map_generos >::iterator itv_g; // iterador de map_generos
		map_generos sm_g; // variavel para guarda um genero

		for (it_g = generos->begin(); it_g != generos->end(); ++it_g) // para cada genero na map de generos
		{
			sm_g.key = (*it_g).first; sm_g.value = (*it_g).second; // captura a chave e valor
			v_g.push_back(sm_g); // insere no vetor de map_generos o genero
		}

		sort(v_g.begin(),v_g.end(),sort_cont); // ordena esse vetor de map_generos usando sort_cont

		for (itv_g = v_g.begin(); itv_g != v_g.end(); ++itv_g) // para cada genero
		{
		string nome_genero = (*itv_g).value->getNome(); // captura o nome do genero
		
		size_t found = nome_genero.find('\n'); // verifica se achou um '\n' no nome do genero
		
		if (found != std::string::npos) // se achou
		    	nome_genero.erase(nome_genero.begin()+(nome_genero.size()-1));	// retira esse caractere '\n'
	    	
		myfile << "	" << nome_genero << ": " << (*itv_g).value->getCont() << '\n';			// escreve no arquivo o nome do genero seguido o numero de ocorrencias
		}
		
	  myfile << "\nTemporadas por série:\n"; // cabeçalho

	  for(i=0;i<series.size();i++)
	  {
	  	// para cada serie imprime o nome da serie, numero de temporadas consumidas e temporadas a consumir
	    	myfile << "	" << series[i]->getSerie() << ": " << series[i]->getTemporada_consumida() << " assistidas, " << series[i]->getTemporada_a_consumir() << " a assistir" << "\n";
	  }
	  myfile.close();
	} // tratamento de exceções
	else
		throw Exception_IO("Erro de I/O");
}
Escreve_estatisticas::~Escreve_estatisticas()
{
}
