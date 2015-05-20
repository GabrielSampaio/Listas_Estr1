/**************************************
* Trabalho 1-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Gabriel Amorim R. S. - matricula: 0050011378
* Listas
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main()
{	
	int x;
    Lista *l1,*l2; //Declarando 2 listas
    
    //Lista 1
    l1=lst_cria();
    
	//Inserindo os valores na lista
    l1=lst_insere(l1,50);
    l1=lst_insere(l1,40);
    l1=lst_insere(l1,30);
    l1=lst_insere(l1,20);
    l1=lst_insere(l1,10);
    
    printf("\nLista normal:");
    //Imprimi a Lista normal
    
    puts("\n/***************/\n");
	lst_imprime(l1);
    puts("\n/***************/\n");

    
    //Separa apartir do valor pedido
    l2=lst_cria();
    puts("Apartir de qual valor voce quer separar?");
    scanf("%d",&x);
	l2=separar(l1,x);
    
    
    printf("Separado apartir do %d:\n",x);
    //Segunda lista apos separação
    puts("\n/***************/\n");
    lst_imprime(l1);
	lst_imprime(l2);
    puts("\n/***************/\n");

return 0;
}
