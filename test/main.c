#include <stdio.h>
#include "puzzle_ws.h"

int main(){
	
	Table table = maketable(20, 20);
    fillrand_t(&table, "abcdefghijklmnopqrstuvwxyz"); // abcdefghijklmnopqrstuvwxyz aeiou
	
	printTable(table);
	printf("\n");
	vecstr arrstr = makevecstr();
	append_vecstr(&arrstr, "ou");
	append_vecstr(&arrstr, "xyz");
	append_vecstr(&arrstr, "zyx");
	append_vecstr(&arrstr, "au");
	append_vecstr(&arrstr, "ame");
	
	words_t searched = findwords_t(table, arrstr);
	
	for(int i=0; i<getword_len_t(searched); i++){
		  int *p = getword_pos_t(searched, i);
          printf("%s : %d %d\n", getword_t(searched, i), p[0], p[1]);
    }
	
	return 0;
}