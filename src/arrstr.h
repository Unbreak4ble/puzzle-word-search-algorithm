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
		arr->array = array;
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

int isEqual_vecstr(string str, vecstr array){
	int len = strlen(str);
	for(int i=0; i<get_lenvecstr(array); i++){
		int len2 = get_lenstr(array, i);
		if(len == len2){
		int c=0;
		for(int j=0; j<len2; j++){
			if(str[j] == (get_vecstr(array, i))[j]){
				++c;
			}
		}
		if(c == len)
		return 1;
		}
	}
	
	return 0;
}

string get_vecstr(vecstr arr, int pos){
	if(pos >= 0 && pos <= arr.len-1)
    {
    	int begin=0;
        string str = calloc(getint(arr.eachsize, pos), sizeof(char));
    	for(int i=0; i<pos; i++)
    	    begin += getint(arr.eachsize, i);
        
        for(int i=0; i<getint(arr.eachsize, pos); i++)
        	str[i] = arr.array[begin+i];
        
        return str;
    }
    else
      return "\0";
}

void print_vecstr(vecstr arr){
	printf("{");
	for(int i=0; i<arr.len; i++){
		printf("\"%s\"", get_vecstr(arr, i));
		if(i+1<arr.len)
		printf(", ");
	}
	printf("}");
}

