#include "sort.h"

vector<string> split(string str, char delimiter)  // função para "splitar" uma string dado um delimitador, retorna um vetor de strings para a nova string separada pelo delimitador
{
  vector<string> linha;
  stringstream ss(str);
  string tok;

  while(getline(ss, tok, delimiter)) 
  {
    linha.push_back(tok);
  }
  return linha;
}
vector<serie*> organiza_series (map<int,midia*> midias) // função que recebe a map de midias e retorna um vetor de séries
{
	vector<serie*> series;
	vector<string> nomes_series;
	int i = 0;
	
	for (map<int,midia*>::iterator m = midias.begin(); m != midias.end(); ++m)
	{
		if((m->second->getTipo().compare("S") == 0)) // verifica se é série
		{
			serie* s = (serie*)m->second; // captura a série da mídia
			
			string nome = s->getSerie(); // captura nome
			
			if (find(nomes_series.begin(),nomes_series.end(),nome) == nomes_series.end()) // verifica se essa série está no vetor de nomes das séries (se já foi incluída)
			{
			    nomes_series.insert(nomes_series.begin()+i,nome); // insere o nome da série
			    series.insert(series.begin()+i,s); // insere a série no vetor de séries
			    i++; // próxima posição a inserir
		    	}
		    	else // caso em que é uma nova temporada da série
		    	{
			    	int j;
		    		for (j = 0 ; j < series.size(); j++) 
		    		{
		    			if (series[j]->getSerie() == nome) // acha a série correspondente
		    			{
		    				series[j]->setConsumiu(s->getTemporada_consumida()); // adiciona no campo consumiu as temporadas consumidas
		    				series[j]->setAconsumir(s->getTemporada_a_consumir()); // adiciona no campo a consumir as temporadas que deseja consumir
		    			}
		    		}
		    	}
		}
	}
	
	sort (series.begin(),series.end(),sort_names_serie); // ordena o vetor por nomes
	
	return series;
}
bool sort_map_names(const map_pessoas& a ,const map_pessoas& b) // ordena uma map de pessoas por nome, mas transforma as strings para minusculo para fazer essa ordenação
{
	
	string pessoa_a = a.value->getNome();
	string pessoa_b = b.value->getNome();
	
	int i = 0;
	char ca,cb;
	
	while (pessoa_a[i])
	{
		ca = pessoa_a[i];
		pessoa_a[i] = tolower(ca); // transforma para minusculo
		i++;
	}
	i = 0;
	while (pessoa_b[i])
	{
		cb = pessoa_b[i];
		pessoa_b[i] = tolower(cb); // transforma para minusculo
		i++;
	}
	
	return pessoa_a < pessoa_b;
}
bool sort_cont (const map_generos& a, const map_generos& b) // ordena uma map de generos por numero de ocorrencias, caso haja empate, ordena por nome
{
	if (a.value->getCont() == b.value->getCont())
	{
		return a.value->getNome() < b.value->getNome();
	}
	return a.value->getCont() > b.value->getCont();
}
bool sort_names (string a, string b) // ordena uma string por nome
{
	return (a < b);
}
bool sort_names_serie (serie* a, serie* b) // ordena séries por nome
{
	return a->getSerie() < b->getSerie();
}
bool comparator_midia_tipo(midia* a, midia* b) // ordena uma midia por tipo, caso haja empate, ordena por preço, se persistir o empate, ordena por nome
{
	if (a->getTipo() == b->getTipo())
	{
		if (a->getPreco() == b->getPreco())
		{	
			return (a->getNome() < b->getNome());
		}
		return (a->getPreco() > b->getPreco());
	}
	return a->getTipo() < b->getTipo(); 
}
