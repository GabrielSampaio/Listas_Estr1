/**************************************
* Trabalho 3 - AV2 de Estrutura de Dados I
* Curso de Sistemas da informacao
* Aluno: Gabriel Amorim R. S. - matricula: 0050011378
* Fila - Quiz
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fila.h"
int main()
{
	int op=0,i,j;
	char nome[50],insere[50];
	int pergunta,jogadores=0;
	char resp;
	Fila* n;
	char perguntas[3][100] = { {"Em que ano inventaram a linguagem C?\na)1265\nb)1750\nc)1985\nd)1978\n"},
						{"Segundo o calendario chines, qual e o animal de 2015?\na)Cabra\nb)ovelha\nc)cao\nd)falcao\n"},
						{"Com quantos votos validos Dilma foi reeleita?\na)49%\nb)42%\nc)44%\nd)50%\n"}};
	char gabarito[3][2] = { {"d"},
							{"a"},
							{"c"} };
	printf("%c",gabarito[0][1]);
	n=fila_cria();
	do
	{
		puts("\nInforme o que deseja fazer!");
		puts("1- Inserir participantes.\n2- Comecar jogo!\n3- Sair");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
			do
			{
				printf("Informe o nome do participante. Digite 'sair' quando acabar os participantes.\n");
				scanf("%s",&nome);
				fflush(stdin);
			
				if(strcmp(nome,"sair")==0)
					break;
				else	
				{
					jogadores++;
					fila_insere(n,nome);
				}
			}while(1);
			break;
		case 2:
			if(fila_vazia(n))
			{
				puts("Nao existem participantes");
				exit(1);
			}
			else
			{
				while(jogadores!=1)
				{
					printf("Jogadores restantes: %d\n",jogadores);
					fila_retira(n,nome);
					jogadores--;
					printf("%s, responda a pergunta.",nome);
					pergunta= rand() % 3;
					
					for (j=0;perguntas[pergunta][j]!='\0';j++)
						printf("%c",perguntas[pergunta][j]);
					scanf("%s",&resp);
					fflush(stdin);
					
					if(gabarito[pergunta][0]==resp)
					{
						strcpy(insere,nome);
						puts("Resposta correta!");
						fila_insere(n,insere);
						jogadores++;
					}
					else
						puts("Resposta Errada!");
					
					if(jogadores==1)
					{
						jogadores=0;
						fila_retira(n,nome);
						printf("Parabens %s, você foi o vencedor do nosso QUIZ!!!",nome);
						break;
					}
					
				}
					
			}
				break;
		case 3:
			fila_libera(n);
			return 0;
		}//Switch fim
	}while(1);
	
fila_libera(n);
system("pause");
return 0;
}
