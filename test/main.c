#include <stdio.h>
#include "puzzle_ws.h"

int main(){
	
	Table table = maketable(20, 20); // cria uma tabela 20x20
	
     fillrand_t(&table, "abcdefghijklmnopqrstuvwxyz"); // preenche os campos com caracteres aleatorios da string
	
	printTable(table); // imprime a tabela
	printf("\n");
	vecstr arrstr = makevecstr(); // cria um array que sera usado como lista de palavras á ser buscada na tabela
	append_vecstr(&arrstr, "ou"); // adiciona a string "ou" para o array
	append_vecstr(&arrstr, "oui"); // adiciona a string "oui" para o array
	
	words_t searched = findwords_t(table, arrstr); // inicia a busca pelas palavras
	
	for(int i=0; i<getword_len_t(searched); i++) // obtem o tamanho da lista de palavras achadas
         {
		  int *p = getword_pos_t(searched, i); // obtem as posições iniciais XY e as posições finais XY
		  int *xy_b = toXY(searched, p[0]); // obtendo a posição inicial XY
		  int *xy_e = toXY(searched, p[1]); // obtendo a posição final XY
		  string str = getword_slide_t(searched, i); // pegando a palavra achada
          printf("word: %s | start: {%d, %d}; end: {%d, %d} | direct: %s\n", getword_t(searched, i), xy_b[0], xy_b[1], xy_e[0], xy_e[1], str);
          free(xy_b); //limpando a memoria
          free(xy_e); //limpando a memoria
    }
    
	free_words_t(&searched); // limpando a memória
	
	return 0;
}
