#include <stdio.h>
#include <stdlib.h>

struct lista{
       int info;
       struct lista *prox;
       };   
       
       typedef struct lista Lista;


Lista * lst_cria()
{    
     return NULL;
}

Lista *lst_insere(Lista *p,int valor)
{
    Lista *a=(Lista*) malloc(sizeof(Lista));
    a->info = valor;
    a->prox= p;
   return a;
} 

void lst_imprime(Lista *p)
{
    Lista *a;
    printf("[");
    for(a=p;a!=NULL;a=a->prox)
    {
    	printf("%d",a->info);
    	if(a->prox!=NULL)
    		printf(",");
	}
	printf("]\n");

}

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
