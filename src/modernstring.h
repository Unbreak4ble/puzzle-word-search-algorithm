#include <string.h>
#include <stdlib.h>

#define string char*
#define getsize(arr) sizeof(arr)/sizeof(*arr)

/* STRING */
void appendchar(string *str, char c){
	if(str && c){
	int lenstr = strlen(*str), lenc = sizeof(char), total = lenstr+lenc;
    string newstr = (string)calloc(total, sizeof(char));
	memcpy(newstr, *str, lenstr);
    newstr[strlen(newstr)] = c;
      *str = realloc(*str, total);
      *str = newstr;
	}
}

void appendstr(string *dest, string src){
	if(dest && src){
	int destlen = strlen(*dest), srclen = strlen(src), total = destlen+srclen;
	if(srclen == 0) return;
	string newstr = (string)calloc(total, sizeof(char));
	memcpy(newstr, *dest, destlen);
	strcat(newstr, src);
    *dest = realloc(*dest, total);
    *dest = newstr;
   }
}

void removechar(string *dest, int pos){
	if(dest){
	int lenstr = strlen(*dest)-1, cp=0;
	if(!(pos >= 0 && pos <= lenstr)) return;
    string newstr = (string)calloc(lenstr, sizeof(char));
    memset(newstr, 0, lenstr-1);
    string destcp = (string)calloc(lenstr+1, sizeof(char));
    strcpy(destcp, *dest);
       for(int i=0; i<lenstr+1; i++){
       	if(i != pos){
       	  char c = destcp[i];
      	   newstr[cp] = c;
             ++cp;
           }
       }
        free(destcp);
        dest = realloc(dest, lenstr);
        memcpy(*dest, newstr, lenstr);
	}
}

void free_str(string *str){
	free(str);
}

string makestr(string str){
	string newstr = calloc(strlen(str), sizeof(char));
	strcpy(newstr, str);
	return newstr;
}

string reversestr(string str){
	int len = strlen(str);
	string newstr = makestr("");
	
	for(int i=len; i>=0; i--)
		appendchar(&newstr, str[i]);
	
	return newstr;
}
