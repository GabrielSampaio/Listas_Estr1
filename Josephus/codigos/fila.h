/**************************************
* Trabalho 4-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Gabriel Amorim R. S. - matricula: 0050011378
* Josephus
***************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct fila{
    int quant;
    int info[MAX];
    int ini;
};

typedef struct fila Fila;

Fila* fila_cria(void)
{
    Fila* f=(Fila*)malloc(sizeof(Fila));
    f->quant=0;
    f->ini=0;
    return f;
}

void fila_insere(Fila* f,int v)
{
    int fim;
    if(f->quant==MAX){
        puts("Sem espaco");
        exit(1);
    }
    fim=(f->ini+f->quant)%MAX;
    f->info[fim]=v;
    f->quant++;
}

int fila_retira(Fila*f,int rand)
{
	int v,i;
			
	if(rand<0)
		rand+=f->quant;
		
	v=f->info[(rand+f->quant)%f->quant];
	f->ini=(rand+f->quant)%f->quant;
	
	for(i=f->ini;i<f->quant;i++)
		f->info[i]=f->info[i+1];

	f->quant--;
	
return v;
}

void fila_imprime(Fila* f){
    int i;
		for(i=f->ini;i<f->quant;i++)
        printf("->%d",f->info[i]);
    
}
