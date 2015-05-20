/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Gabriel Amorim R. S. - matricula: 0050011378
* Listas
***************************************/
#include <stdio.h>
#include <stdlib.h>

struct lista{
       int info;
       struct lista *prox;
       };   
       
       typedef struct lista Lista;



//Função de criação da lista
Lista * lst_cria()
{    
     return NULL;
}

//Função para inserir valores na lista
Lista *lst_insere(Lista *p,int valor)
{
    Lista *a=(Lista*) malloc(sizeof(Lista));
    a->info = valor;
    a->prox= p;
   return a;
} 

//Função somente para imprimir
void lst_imprime(Lista *p)
{
    Lista *a;
    for(a=p;a!=NULL;a=a->prox)
    {
    	printf("%d",a->info);
    	if(a->prox!=NULL)
    		printf(" -> ");
    	else
    		printf(" -> NULL\n");
	}

}

//Função para busca, retornando a lista na posição do encontrado ou NULL se não existir
Lista *lst_buscar(Lista *p, int chv)
{
    Lista *a;
    for(a=p;a!=NULL;a=a->prox)
    {
       if(chv==a->info)
         return a;
    }
    
    return NULL;
}


//Função para separar apartir de algum número
Lista *separar(Lista *l,int n)
{
	Lista *a=l,*b=NULL;
	a=lst_buscar(l,n);
	if(a==NULL)
	{
		puts("Valor nao encontrado");
		return NULL;
	}
	else
	{
		if(a->prox==NULL)
		{
			return b;
		}
		else
		{
			b=a->prox;
		}
		a->prox=NULL;
		return b;	
	}
	
	
}
