#include "Escreve_emprestimos.h"

// construtor do escritor de empréstimos
Escreve_emprestimos::Escreve_emprestimos (list<emprestimo*> *emprestimos)
{
	ofstream myfile3 ("3-emprestimos.csv"); //escreve emprestimos
	
	if (myfile3.is_open()) // tenta abrir arquivo
	{
		myfile3 << "Data;Tomador;Atrasado?;Dias de Atraso\n"; // cabeçalho

		emprestimos->sort( []( emprestimo* a, emprestimo* b ) // chama sort para ordenar a lista de empréstimos 
      		{
                   string inicio_a,inicio_b;
                   
                   inicio_a = formatDate((a)->getInicio(),"%Y/%m/%d"); // formata a data para fins de comparação
                   inicio_b = formatDate((b)->getInicio(),"%Y/%m/%d"); // formata a data para fins de comparação
        	           if (inicio_a == inicio_b) // se data de empréstimo são iguais
        	           {
        	           	return (a->getTomador() < b->getTomador()); // ordena pelo nome do tomador
        	           }
        	           return inicio_a > inicio_b ; // ordena pela data mais antiga
      		} ) ;

	for (list<emprestimo*>::iterator e = emprestimos->begin(); e != emprestimos->end(); e++) // para cada empréstimo
	{
		struct tm  calendar = {0, 0, 0, 6, 10, 115, 0, 0, 0};
		time_t hoje = mktime(&calendar); // dia de hoje
		double seconds = difftime(hoje,(*e)->getFim()); // segundos desde 1970
		int dia = seconds/(60*60*24); // conta o número de dias
		if(dia < 0 || dia == 0) // se a diferença de dias de atraso for igual a 0 ou negativa não está atrasado
		{
		  dia = 0;
		  myfile3 << formatDate((*e)->getInicio(),DATE_FORMAT_PT_BR_SHORT) << ";" << (*e)->getTomador()<< ";" << "Não" << ";" << dia << '\n';
		}
		else // está atrasado e imprime o numero de dias em atraso
		{
		  myfile3 << formatDate((*e)->getInicio(),DATE_FORMAT_PT_BR_SHORT) << ";" << (*e)->getTomador()<< ";" << "Sim" << ";" << dia << '\n';		  
		}

	}
	 myfile3.close();//fim emprestimos
	}
	else // tratamento de exceções
		throw Exception_IO("Erro de I/O");
}
Escreve_emprestimos::~Escreve_emprestimos()
{
}
