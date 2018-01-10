#ifndef MAP_PESSOAS_H_
#define MAP_PESSOAS_H_
#include "pessoa.h"

// classe map_pessoas para facilitar a manipulação de map de pessoas com chave sendo inteiro e pessoa como valor

class map_pessoas
{
	public:
		int key;
		pessoa* value;
};
#endif
