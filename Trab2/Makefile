all:
	g++ -std=c++0x main.cpp genero.cpp pessoa.cpp midia.cpp filme.cpp livro.cpp serie.cpp emprestimo.cpp DateUtils.cpp NumberUtils.cpp NumPunctPTBR.cpp sort.cpp Leitura_emprestimo.cpp Leitura_genero.cpp Leitura_pessoa.cpp Leitura_midia.cpp Escreve_emprestimos.cpp Escreve_porpessoa.cpp Escreve_wishlist.cpp Escreve_estatisticas.cpp Exception_IO.cpp Exception_Format.cpp Exception_Inconsis.cpp -o trab2
	
run:
	./trab2 -p pessoas.csv -m midias.csv -g generos.csv -e emprestimos.csv
clean:
	rm 1-estatisticas.txt 2-porpessoa.csv 3-emprestimos.csv 4-wishlist.csv pessoas.csv emprestimos.csv generos.csv midias.csv
