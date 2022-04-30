# descrição
Criei esse algoritmo para resolver problemas de caça palavras da escola

# manual
### estruturas
#### • words_t
```C
struct {
	vecstr words;
	integer begin_pos;
	integer end_pos;
} words_t;
```

#### • integer
```C
struct {
	int *values;
	size_t size;
} integer;
```

#### • vecstr
```C
struct {
	string array;
	integer eachsize;
	size_t size;
	int len;
} vecstr;
```

#### • string
```C
typedef string char*
```

### funções #table.h
#### • Table maketable(int v, int h)
 cria uma tabela (v)vertical x (h)horizontal.
 
 #### • void free_t(Table*)
 Elimina a tabela da memória.
 
 #### • void clone_t(Table*, Table)
 Cópia uma tabela para a outra.

#### • void printTable(Table)
 imprime a tabela.

#### • void add_tval(Table*, char)
 adiciona um caractere a tabela.

#### • int get_tlen(Table*)
Obtem tamanho da tabela.

#### • void set_tval(Table*, char, int v, int h)
 define um caractere em uma posição v e h.


#### • char get_tval(Table*, int v, int h)
 obtem o caractere na posição v e h.
 
 #### • void add_more_tval(Table*, int, char ...)
 Variadic function, serve para adicionar mais caractere a tabela, o segundo argumento se trata do tamanho de caracteres a ser adicionado.
 
 #### • int* toXY_t(Table, int)
 Converte a posição (número passado pelo segundo argumento) para posições bidimensional.
 
 ### funções #puzzle_ws.h

#### • void fillrand_t(Table*, char*)
 preenche a tabela com caracteres aleatórios contido no segundo argumento.

#### • words_t findwords_t(Table*, vecstr)
 busca por palavras na tabela.
 
 #### • int getword_len_t(words_t)
 Obtem a contagem de palavras achadas

#### • int* getword_pos_t(Table*, int)
 obtem a posição inicial e a final. Retorna um array onde o primeiro valor é a posição inicial e a segunda (e última) é a posição final.

#### • string getword_t(words_t, int)
 obtem a palavra achada pela posição passada no segundo argumento.
 
 #### • int* toXY(words_t, int)
 Converte a posição (número do segundo argumento) para posições bidimensional.
 
 #### • void free_words_t(words_t*)
 Elimina os dados do ponteiro na memória.
 
#### • string getword_slide_t(words_t, int)
Obtem a direção da palavra achada.


### funções #arrstr.h

#### • vecstr makevecstr()
Cria um vetor de string.

#### • void append_vecstr(vecstr*, string) 
Adiciona uma string para o vetor.

#### • int get_lenstr(vecstr*, int)
Obtem o tamanho da string na posição.

#### • int get_lenvecstr(vecstr*)
Obtem as posições do vetor.

#### • int get_sizevecstr(vecstr*)
Obtem o tamanho do vetor.

#### • string get_vecstr(vecstr*, int)
Obtem a string do vetor pela posição.

#### • void free_vecstr(vecstr*)
Elimina o vetor da memória.

#### • void print_vecstr(vecstr)
Imprime o vetor.
