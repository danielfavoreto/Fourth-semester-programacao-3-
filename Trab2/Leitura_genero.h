#ifndef LEITURA_GENERO_H_
#define LEITURA_GENERO_H_
#include "DateUtils.h"
#include <fstream>
#include <map>
#include <typeinfo>
#include "NumPunctPTBR.h"
#include "NumberUtils.h"
#include "map_pessoas.h"
#include <stdexcept>
#include "map_generos.h"
#include "Exception_Format.h"
#include "Exception_Inconsis.h"
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

using namespace br_ufes_inf_nemo_cpp_util;

class Leitura_genero
{
	public:
	~Leitura_genero();
	Leitura_genero (string argv,map<string,genero*> *generos);
};
#endif
