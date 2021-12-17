#include <stdio.h>
#include "puzzle_ws.h"

int main(){
	
	Table table = maketable(20, 20);
	
     fillrand_t(&table, "abcdefghijklmnopqrstuvwxyz"); // abcdefghijklmnopqrstuvwxyz aeiou
	
	printTable(table);
	printf("\n");
	vecstr arrstr = makevecstr();
	append_vecstr(&arrstr, "ou");
	append_vecstr(&arrstr, "oui");
	
	words_t searched = findwords_t(table, arrstr);
	
	for(int i=0; i<getword_len_t(searched); i++){
		  int *p = getword_pos_t(searched, i);
		  int *xy_b = toXY(searched, p[0]);
		  int *xy_e = toXY(searched, p[1]);
		  string str = getword_slide_t(searched, i);
          printf("word: %s | start: {%d, %d}; end: {%d, %d} | direct: %s\n", getword_t(searched, i), xy_b[0], xy_b[1], xy_e[0], xy_e[1], str);
          free(xy_b);
          free(xy_e);
    }
    
	free_words_t(&searched);
	
	return 0;
}