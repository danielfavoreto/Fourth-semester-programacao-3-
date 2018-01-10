#include "Exception_Inconsis.h"

// construtor da exceção de inconsistência
Exception_Inconsis::Exception_Inconsis (string coluna,string valor)
{
	cout << "Dados inconsistentes" << "(" << coluna << ":" << valor << ")";
}
