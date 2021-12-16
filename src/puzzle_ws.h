#pragma once
#include <stdlib.h>
#include "table.h"
#include "arrstr.h"
#include <time.h>

typedef struct {
	vecstr words;
	integer begin_pos;
	integer end_pos;
} words_t;

int randint(int n) {
  return rand()%n;
}

void fillrand_t(Table *table, string str){
	srand(time(NULL));
	while(table->totalsize < table->v * table->h){
		int r = randint(strlen(str));
		
        add_tval(table, str[r]);
	}
}

int getword_len_t(words_t words){
	return get_lenvecstr(words.words);
}
string getword_t(words_t words, int pos){
	return get_vecstr(words.words, pos);
}

int* getword_pos_t(words_t words, int pos){
	int *arr = malloc(2*sizeof(int));
	arr[0] = getint(words.begin_pos, pos);
	arr[1] = getint(words.end_pos, pos);
	
	return arr;
}

int get_lowestlen(vecstr array){
	int len = get_lenvecstr(array);
	for(int i=0; i<len; i++){
		int current=0;
		
		for(int j=0; j<len; j++){
			if(get_lenstr(array, i) < get_lenstr(array, j))
			++current;
		}
		
		if(current >= len-1)
		return get_lenstr(array, i);
	}
	
	return get_lenstr(array, 0);
}

int get_highestlen(vecstr array){
	int len = get_lenvecstr(array);
	for(int i=0; i<len; i++){
		int current=0;
		
		for(int j=0; j<len; j++){
			if(get_lenstr(array, i) > get_lenstr(array, j))
			++current;
		}
		
		if(current >= len-1)
		return get_lenstr(array, i);
	}
	
	return get_lenstr(array, 0);
}

int toNeg(int x){
	return x - x*2;
}

words_t findwords_t(Table table, vecstr array){
	const char slide_s[4][2] = {"r", "l", "t", "b"};
    const char slide_m[4][2] = {"tr", "tl", "br", "bl"};
    const int slide_i[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};
    words_t find;
    find.words = makevecstr();
    find.begin_pos = makeint((int*){0}, 0);
    find.end_pos = makeint((int*){0}, 0);
    int words_len = get_lenvecstr(array),
        // current_word = 0, 
         current_slide = 0,
         //words_test = 0,
         highest_len = get_highestlen(array),
         lowest_len = get_lowestlen(array);
    
    for(int i = 0; i <  table.v; i++){
    	for(int j=0; j< table.h; j++){
    	     while(current_slide < 8){
    	      if(i+slide_i[current_slide][0] >= 0 && j+slide_i[current_slide][1] >= 0){
    	         const char* cs = current_slide < 4 ? slide_s[current_slide] : slide_m[current_slide-4];
                 string currentstr = makestr("");
                 
                 for(int cp_b = 0; cp_b < highest_len; cp_b++){
                 	const int slide_i_cp[8][2] = {{0, toNeg(cp_b)}, {0, cp_b}, {cp_b, 0}, { toNeg(cp_b), 0}, {cp_b, toNeg(cp_b)}, {cp_b, cp_b}, {toNeg(cp_b), toNeg(cp_b)}, {toNeg(cp_b), cp_b}};
                 	char c = get_tval(table, i+slide_i_cp[current_slide][0], j+slide_i_cp[current_slide][1]);
                 	appendchar(&currentstr, c);
                      if(cp_b >= lowest_len-1)
                      
                      if(cp_b >= lowest_len-1 && isEqual_vecstr(currentstr, array) == 1 && isEqual_vecstr(currentstr, find.words) == 0){
                      	append_vecstr(&find.words, currentstr);
                          appendint(&find.begin_pos, i*table.v+j);
                          appendint(&find.end_pos, (i+slide_i_cp[current_slide][0])*table.v+(j+slide_i_cp[current_slide][1]));
                      	}
                 }
                 
                 free(currentstr);
    	      }
                ++current_slide;
              }
              current_slide = 0;
        }
    }
    
    return find;
}