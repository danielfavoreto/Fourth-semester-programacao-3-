#ifndef LEITURA_PESSOA_H_
#define LEITURA_PESSOA_H_
#include "DateUtils.h"
#include <fstream>
#include <map>
#include "NumPunctPTBR.h"
#include "NumberUtils.h"
#include <stdexcept>
#include <typeinfo>
#include "map_pessoas.h"
#include "map_generos.h"
#include "Exception_IO.h"
#include "Exception_Format.h"
#include "Exception_Inconsis.h"
#include "genero.h"
#include "sort.h"
#include "pessoa.h"
#include "midia.h"
#include "livro.h"
#include "filme.h"
#include "serie.h"
#include "emprestimo.h"
#include <sstream>

using namespace br_ufes_inf_nemo_cpp_util;

class Leitura_pessoa
{
	public:
	~Leitura_pessoa();
	Leitura_pessoa (string argv,map<int,pessoa*> *pessoas);
};
#endif
