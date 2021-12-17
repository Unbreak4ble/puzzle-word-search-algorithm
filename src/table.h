#include <stdlib.h>
#include <stdarg.h>
#include "modernstring.h"

typedef struct {
    string table;
    size_t totalsize;
	size_t v;
	size_t h;
} Table;

Table maketable(int v, int h){
	Table table;
	table.v = v;
	table.h = h;
	table.totalsize = 0;
    table.table = makestr("");
	return table;
}

void free_t(Table *t){
	free(t->table);
}

void clone_t(Table *dest, Table src){
	dest->v = src.v;
	dest->h = src.h;
    dest->totalsize = src.totalsize;
    
    dest->table = realloc(dest->table, src.totalsize);
    memcpy(dest->table, src.table, src.totalsize);
    
}

int get_tlen(Table table){
	return table.totalsize/sizeof(char);
}

void add_tval(Table *table, char c){
	 if(table->totalsize <= (table->v * table->h)*sizeof(char)){
	 appendchar(&table->table, c);
	table->totalsize += sizeof(char);
	}
}

void set_tval(Table *table, char c, int i, int j){
	table->table[i*(table->v >= table->h ? table->h : table->v) + j] = c;
}

char get_tval(Table table, int i, int j){
	return table.table[i*(table.v >= table.h ? table.h : table.v) + j];
}

int* toXY_t(Table t, int pos){
	int X=0, Y=pos;
	int *res = (int*)calloc(2, sizeof(int));
	res[0] = -1;
	res[1] = -1;
	for(int i=0; i<t.v; i++){
		X = Y-t.v*i;
		if(X >= 0 && X <= t.v)
		{
			res[0] = i+1;
			res[1] = X;
		    return res;
		}
	}
	
	return res;
}

void add_more_tval(Table *table, int count, ...){
	va_list chars;
	va_start(chars, count);
	
	for(int i=0; i<count; i++)
	add_tval(table, (char)va_arg(chars, int));
	
	va_end(chars); 
}

void printTable(Table table){
	printf("[\n");
	int *XY_t = toXY_t(table, table.totalsize/sizeof(char));
	for(int i=0; i<XY_t[1]; i++){
		for(int j=0; j<XY_t[0]; j++){
			printf("%c", get_tval(table, i, j));
			if(j != XY_t[0]-1)
			printf(" ");
		}
		printf("\n");
    }
    free(XY_t);
	printf("]\n");
}