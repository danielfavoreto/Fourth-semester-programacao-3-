#ifndef ESCREVE_PORPESSOA_H_
#define ESCREVE_PORPESSOA_H_
#include "DateUtils.h"
#include <fstream>
#include <map>
#include "NumPunctPTBR.h"
#include "NumberUtils.h"
#include "map_pessoas.h"
#include "map_generos.h"
#include "Exception_IO.h"
#include "genero.h"
#include "sort.h"
#include "pessoa.h"
#include "midia.h"
#include "livro.h"
#include "filme.h"
#include "serie.h"
#include "emprestimo.h"
#include <sstream>

using namespace std;
using namespace br_ufes_inf_nemo_cpp_util;

class Escreve_porpessoa
{
	public:
	Escreve_porpessoa (map<int,pessoa*> *pessoas);
	~Escreve_porpessoa();
};
#endif
