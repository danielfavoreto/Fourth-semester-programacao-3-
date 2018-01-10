#ifndef LEITURA_EMPRESTIMO_H_
#define LEITURA_EMPRESTIMO_H_
#include "DateUtils.h"
#include <fstream>
#include <map>
#include "NumPunctPTBR.h"
#include "NumberUtils.h"
#include "map_pessoas.h"
#include <stdexcept>
#include <typeinfo>
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

class Leitura_emprestimo
{
	public:
	~Leitura_emprestimo();
	Leitura_emprestimo (string argv,map<int,midia*> *midias,list<emprestimo*> *emprestimos);		
};
#endif
