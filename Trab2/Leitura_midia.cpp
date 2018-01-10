#include "Leitura_midia.h"

// construtor de leitura de midias
Leitura_midia::Leitura_midia (string argv,map<int,pessoa*> *pessoas,map<string,genero*> *generos,map<int,midia*> *midias)
{
	string linha;
	
	vector<string> dado,dado2;

	ifstream file (argv); // arquivo 

	if (file.is_open()) // verifica se tem permissao e consegue abrir arquivo
	{
	
	getline (file,linha);// Tirar cabeçalho
	
	try {
	
		while ( getline (file,linha) ) // ler uma linha
		{

		dado = split(linha,';'); // guarda em dado a linha separada por ponto e virgula
		
		bool possui = false, consumiu = false, deseja = false;
		
		if ((dado[9].compare("x") != 0) && (dado[9].compare("") != 0) && (dado[9].compare(" ") != 0)) // verifica se nao tem nenhum dado invalido no campo possui
		{
			throw Exception_Inconsis ("Possui?",dado[9]); // lança exception com a coluna possui? e o dado invalido
		}
		else if ((dado[10].compare("x") != 0) && (dado[10].compare("") != 0) && (dado[10].compare(" ") != 0)) // verifica se nao tem nenhum dado invalido no campo consumiu
		{
			throw Exception_Inconsis ("Consumiu?",dado[10]); // lança exception com a coluna consumiu? e o dado invalido
		}
		else if ((dado[11].compare("x") != 0) && (dado[11].compare("") != 0) && (dado[11].compare(" ") != 0))// verifica se nao tem nenhum dado invalido no campo deseja
		{
			throw Exception_Inconsis ("Deseja?",dado[11]);// lança exception com a coluna deseja? e o dado invalido
		}
		else
		{
			if (dado[9].compare("x") == 0) // se tiver "x" marca como true
				possui = true;
				
			if (dado[10].compare("x") == 0)	// se tiver "x" marca como true
				consumiu = true;
				
			if (dado[11].compare("x") == 0) // se tiver "x" marca como true
				deseja = true;
		}

 		int codigo = stoi(dado[0]); // extrai o dado
		
 		double preco = parseDouble(dado[12],LOCALE_PT_BR); // ler o preço
			
		int tamanho = stoi(dado[5]); // ler o tamanho da midia

 		list<pessoa*> atores; // lista de atores 

 			if (dado[4].compare("") != 0)
 			{

			dado2 = split(dado[4],','); // separa atores por virgula

 				for(int k=0; k<dado2.size();k++)
	 			{
	
 				int atorcod = stoi(dado2[k]); // extrai o codigo do ator

				auto a = pessoas->find(atorcod); // tenta achar pessoa pelo codigo na lista de pessoas
				
				if (a == pessoas->end()) // se nao achou manda exception
					throw Exception_Inconsis("A(u)tores",dado2[k]);
				else
				{
					pessoa* p = pessoas->find(atorcod)->second; // captura a pessoa na lista de pessoas
	 				atores.push_back(p); // adiciona em atores a pessoa
					p->addProducao(dado[1]); // adiciona a produção em que a pessoa participa no vetor de produções da pessoa
 				}
 				
 				}
 			}


		auto ag = generos->find(dado[6]); // tenta achar genero pela sigla na lista de generos
		
		if (ag == generos->end()) // se nao achou manda exception
		{
			throw Exception_Inconsis("Gênero",dado[6]);
		}
		
		genero* g = generos->find(dado[6])->second; // captura o genero na lista de generos

		int cont = g->getCont(); // extrai o contador do numero de ocorrencias desse genero

		cont = cont + 1; // incrementa o contador

		g->setCont(cont); // seta o contador em genero

 			if(dado[2].compare("F") == 0) // se for um filme
			{
			
			 int direcod = stoi(dado[3]); // extrai o codigo de diretor
			
			 auto ad = pessoas->find(direcod); // tenta achar o diretor na lista de pessoas pelo codigo de diretor
			
			 if (ad == pessoas->end()) // se nao achou lança exceção
				throw Exception_Inconsis("Diretor",dado[3]);
			 else
			 {
			 	 pessoa* diretor = pessoas->find(direcod)->second; // busca diretor na lista de pessoas
			 	 
				 diretor->addProducao(dado[1]); // adiciona a midia na lista de produções do diretor
								  
				 filme* f = new filme(codigo, dado[1], dado[2], diretor, atores, tamanho, g, possui, consumiu, deseja, preco); // cria um filme
			
				 midias->insert(pair<int,midia*>(f->getCodigo(),f)); // insere na map de midias um filme com o codigo do filme como chave
			 }
			 

			}

			else if(dado[2].compare("L") == 0) // verifica se é um livro
			{
		
			livro* l = new livro(codigo, dado[1], dado[2], atores, tamanho, g, possui, consumiu, deseja, preco); // cria um livro chamando seu construtor
	
			midias->insert(pair<int,midia*>(l->getCodigo(),l)); // insere na map de midias o livro com o codigo do livro como chave
			
			}

			else if(dado[2].compare("S") == 0) // verifica se é uma série
			{

			int temporada = stoi(dado[8]); // extrai a temporada 

			serie* s = new serie(codigo, dado[1], dado[2], atores, tamanho, g, dado[7], temporada, possui, consumiu, deseja, preco); // cria uma série chamando pelo construtor

			midias->insert(pair<int,midia*>(s->getCodigo(),s)); // insere na map de mídias uma série com o seu código como chave
			}
			else // lança exception caso seja um caractere invalido na coluna de tipo
				throw Exception_Inconsis ("Tipo",dado[2]);
		}
		file.close();
	}	// tratamento de exceções
	catch (invalid_argument) {
		throw Exception_Format ("Erro de formatação");	
	}
	
	}
	else
		throw Exception_IO ("Erro de I/O");
}
list<midia*> Leitura_midia::gera_wishlist(map<int,midia*> midias) // função para gerar uma wishlist retornando uma wishlist
{
	list <midia*> wishlist; // wishlist 
	
	for (map<int,midia*>::iterator m = midias.begin(); m != midias.end(); ++m) // percorre a map de midias
	{
		if(m->second->getPossui() == false && m->second->getDeseja() == true) // verifica se não possui midia e deseja e insere na wishlist a midia
		{
		      wishlist.push_back(m->second);
		}
	}
	
	return wishlist;
}
Leitura_midia::~Leitura_midia()
{
}
