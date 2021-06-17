#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Disciplina Técnicas de Programação
*/

/*
Questão 12: Uma escola deseja implementar um sistema que possua um menu com as seguintes opções:
a. Caso seja escolhida a opção 1 o sistema deve: Ler 2 notas e nomes de 5 alunos e armazenar em um vetor;
b. Caso seja escolhida a opção 2 o sistema deve: Exibir média geral de todos os alunos;
c. Caso seja escolhida a opção 3 o sistema deve: Exibir uma lista com o nome e as notas de todos os alunos;
d. Caso seja escolhida a opção 4 o sistema deve: Exibir uma lista com o nome e as médias de todos os
alunos; se a média for maior igual 7 mostrar na tela “Aprovado”, senão imprimir na tela “Reprovado”.
*/

/*
Grupo 03:
1 - Vinicius Rodrigues Cardoso Silva - 202000632
2 - Vitor Fernandes da Paz - 202000604
3 - Nicolas Barretto de Souza - 201908847
4 - Odilon Roberto de Oliveira Gomes - 202058513
5 - João Victor Cavalcanti Lemos - 202002341
6 - Paola Maria Oliveira De Andrade - 202002820 
*/

int main() {
	int   opcao;       // Variavel de resposta do menu;
	char  nome[5][20]; // Vetor de ponteiros para strings que armazena 5 nomes;
	char  resp;        // String para voltar ao menu ao fim da operacao;
	float nota1[5];    // Variavel que armazena a nota 1 dos 5 alunos;
	float nota2[5];    // Variavel que armazena a nota 2 dos 5 alunos;
	float media[5];    // Variavel que armazena a media de cada aluno;
	float mediaGeral;  // Variavel que armazena a media geral da turma;
	
	do{
		do{
			system("cls");
			printf("========== MENU ==========\n");
			printf("1- Registrar nome e nota dos alunos.\n");
			printf("2- Media geral da turma.\n");
			printf("3- Lista de alunos e notas.\n");
			printf("4- Lista de aprovados de reprovados.\n");
			printf("0- Sair.\n");                             
			printf("==========================\n");
			printf("- ");
			scanf("%d", &opcao);
			fflush(stdin);	
		}while(opcao<0 || opcao>4);
		
		if(opcao==0){
			return 0;
		}
		
		switch(opcao){
			case 1:
				system("cls");
				for(int i=0; i<5; i++){
					fflush(stdin);					
					printf("Digite o nome do aluno %d: ", i+1);
					scanf("%s", nome[i]);
					printf("Digite a nota 1: ");
					scanf("%f", &nota1[i]);
					printf("Digite a nota 2: ");
					scanf("%f", &nota2[i]);
					printf("\n");
				}
			break;
			
			case 2:
				system("cls");
				for(int i=0; i<5; i++){
					media[i] = (nota1[i]+nota2[i])/2;
					mediaGeral += media[i];
				}
				printf("Media geral da turma: %.2f\n\n", mediaGeral/5);
			break;
			
			case 3:
				system("cls");
				for(int i=0; i<5; i++){
					printf("Nome: %s | Nota 1: %.2f | Nota 2: %.2f\n\n", nome[i], nota1[i], nota2[i]);
				}
			break;
			
			case 4:
				system("cls");
				for(int i=0; i<5; i++){
					media[i] = (nota1[i]+nota2[i])/2;
					printf("Nome: %s | Nota 1: %.2f | Nota 2: %.2f | Media: %.2f\n", nome[i], nota1[i], nota2[i], media[i]);
					
					if(media[i]>=7){
						printf("Situacao: APROVADO!\n\n");
					}else{
						printf("Situacao: REPROVADO!\n\n");
					}
				}			
			break;	
		}
		
		printf("Deseja voltar ao menu? (S/N)\n");
		printf("- ");
		scanf(" %c", &resp);
		
	}while(resp!='n');
	
	return 0;
}
