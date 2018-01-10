#include "Escreve_wishlist.h"


// construtor de escreve wishlist
Escreve_wishlist::Escreve_wishlist (list<midia*> *wishlist)
{
	ofstream myfile4 ("4-wishlist.csv");//escreve wishlist

	if (myfile4.is_open()) // verifica se consegue abrir arquivo
	{

	  myfile4 << "Tipo;Mídia;Gênero;Preço\n"; // cabeçalho
	  
	  wishlist->sort(comparator_midia_tipo);  // ordena wishlist usando o camparator_midia_tipo
	  
	  string tipo; 
	  
	  for (list<midia*>::iterator w = wishlist->begin(); w != wishlist->end(); w++) // para cada midia na lista de midias
	  {
	  	tipo = (*w)->getTipo(); // guarda o tipo
	  	
	  	if (tipo == "L") // se for livro
	  	{
	  		tipo = "Livro";
	  	}
	  	if (tipo == "S") // se for serie
	  	{
	  		tipo = "Série";
	  	}
	  	if (tipo == "F") // se for filme
	  	{
	  		tipo = "Filme";
	  	}
	  	
	  	string nome_genero = (*w)->getGenero()->getNome(); // guarda o nome do genero
	  	
	  	size_t found = nome_genero.find('\n'); // procura no nome do genero o caractere '\n' 
	  	
	  	if (found != std::string::npos)	// se achar o caractere 
		    	nome_genero.erase(nome_genero.begin()+(nome_genero.size()-1));	// retira esse caractere do final da string
		    	
		myfile4 << tipo << ";" << (*w)->getNome() << ";" << nome_genero << ";R$ " << formatDoubleCurrency((*w)->getPreco(),LOCALE_PT_BR) << '\n'; // escreve no arquivo
	  }
	  myfile4.close();//fim wishlist
	 }
	 else
	 	throw Exception_IO("Erro de I/O");
}
Escreve_wishlist::~Escreve_wishlist()
{
}
