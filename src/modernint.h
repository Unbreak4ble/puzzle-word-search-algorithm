#include <string.h>
#include <stdlib.h>

/* INTEGER */
typedef struct {
	int *values;
	size_t size;
} integer;

void setint(integer *val, int pos, int value){
	if(pos < val->size)
	val->values[pos] = value;
	else{
    fprintf(stderr, "Error: Invalid position\n");
    exit(1);
    }
}

int getint(integer val, int pos){
	if(pos >= 0 && pos < val.size)
	return val.values[pos];
	else{
    fprintf(stderr, "Error: invalid position");
    exit(1);
    }
}

int getintsize(integer *val){
	return val->size;
}

void appendint(integer *val, int value){
	if(val){
		int size = val->size, *newval = (int*)malloc(size*sizeof(int)+sizeof(int));
		memcpy(newval, val->values, size*sizeof(int));
		newval[size] = value;
		val->values = realloc(val->values, size*sizeof(int)+sizeof(int));
		val->values = newval;
		val->size += 1;
	}
}

void removeint(integer *val, int pos){
	int size = val->size;
	if(!(pos >= 0 && pos < size)) return;
    int *newval = (int*)malloc((size-1)*sizeof(int)), currentpos=0;
	memset(newval, 0, size);
	for(int i=0; i<val->size; i++){
		if(i != pos){
			newval[currentpos] = val->values[i];
			++currentpos;
	    }
	}
	val->values = realloc(val->values, (size-1)*sizeof(int));
	val->values = newval;
	val->size -= 1;
}

integer makeint(int *val, size_t size){
	integer newinteger;
    newinteger.values = (int*)malloc(size);
    if(size > 0)
    memcpy(newinteger.values, val, size);
    newinteger.size = size/sizeof(int);
	return newinteger;
}