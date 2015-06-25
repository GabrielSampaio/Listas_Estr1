/**************************************
* Trabalho 4-AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Gabriel Amorim R. S. - matricula: 0050011378
* Josephus
***************************************/
#include <time.h>
#include "fila.h"

int main()
{       
    int i,num,retirado;
    srand((unsigned)time(NULL));
    
    //Declaracao da fila
	Fila* f;
    f=fila_cria();
    //   
    
	for (i=1;i<11;i++)
	{
       fila_insere(f,i+1);
    }
    
	while(f->quant!=1)// Sorteia e remove até sobrar 1 soldado
	{
		do
		{
			num=(1 + rand()%19)- 10;// Numero aleatorio de -9 a 9;
			if(num==0)
				puts("Numero sorteado foi 0, novo numero sera sorteado.");
			else
				printf("O numero %d foi sorteado.\n",num);
    	}while(num==0);
    	
		retirado=fila_retira(f,num);
		printf("%d, removido.\n\n",retirado);
		
	}
	
	
	retirado=fila_retira(f,num);
	printf("O Soldado %d foi escolhido\n",retirado);
system("pause");
return 0;
}
