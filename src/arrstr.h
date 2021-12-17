#pragma once
#include <string.h>
#include <stdlib.h>
#include "modernint.h"

typedef struct {
	string array;
	integer eachsize;
	size_t size;
	int len;
} vecstr;

vecstr makevecstr(){
    vecstr vs;
	vs.array = (string)malloc(0);
	vs.eachsize = makeint((int*){0}, 0);
	vs.size=0;
	vs.len=0;
	return vs;
}

void append_vecstr(vecstr* arr, string str){
	if(arr->array){
		int size = strlen(str);
		arr->size += size;
		arr->len += 1;
		appendint(&arr->eachsize, size);
		string array = (string)calloc(arr->size, sizeof(char));
        memcpy(array, arr->array, arr->size-size);
		strcat(array, str);
		arr->array = realloc(arr->array, arr->size);
		memcpy(arr->array, array, arr->size);
	} 
}

int get_lenstr(vecstr arr, int pos){
	if(pos >= 0 && pos <= arr.len-1)
	   return getint(arr.eachsize, pos);
    else
      return -1;
}

int get_lenvecstr(vecstr arr){
	   return arr.len;
}

int get_sizevecstr(vecstr arr){
	return arr.size;
}

string get_vecstr(vecstr arr, int pos){
	if(pos >= 0 && pos <= arr.len-1)
    {
    	int begin=0;
        string str = makestr("");
    	for(int i=0; i<pos; i++)
    	    begin += getint(arr.eachsize, i);
        
        for(int i=0; i<getint(arr.eachsize, pos); i++)
            appendchar(&str, arr.array[begin+i]);
        
        return str;
    }
    else
      return "\0";
}

void free_vecstr(vecstr *arr){
	free(arr->array);
	free_integer(&arr->eachsize);
}

void print_vecstr(vecstr arr){
	printf("{");
	for(int i=0; i<arr.len; i++){
		string val = get_vecstr(arr, i);
		printf("\"%s\"", val);
		free(val);
		if(i+1<arr.len)
		printf(", ");
	}
	printf("}");
}

