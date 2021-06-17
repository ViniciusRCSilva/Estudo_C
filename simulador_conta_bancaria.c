#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*
** CENTRO UNIVERSIT�RIO DOS GUARARAPES - UNIFG
** Lista de Revis�o A2-N2
** Disciplina de T�cnicas de Programa��o
** Professor Renan Alencar
** Autores:
		Grupo 01:
		Alequissandra Rayane Farias Santos Silva - 202000574
		Beatriz Lira Martins - 2020002049
		Matheus Barros Cris�stomo - 202058447
		Paloma Corr�a Alves - 202000716
		Vinicius Rodrigues Cardoso - 202000632
		Thulio Mateus de Oliveira Queiroz - 202003804


Quest�o 11 - Escreva um programa em C que simule contas banc�rias, com as seguintes especifica��es:
	Ao iniciar o programa vamos criar contas banc�rias para tr�s clientes.
	Cada conta ter� o nome e o CPF do cliente associado a ela.
	No ato da cria��o da conta o cliente precisar� fazer um dep�sito inicial.
	Ap�s as contas serem criadas, o sistema dever� possibilitar realiza��es de saques ou dep�sitos nas contas.
	Sempre que uma opera��o de saque ou dep�sito seja realizada, o sistema dever� imprimir o nome do titular e o saldo final da conta.


/* constante para determinar o tamanho do vetor */
#define MAX 3

/* Define uma estrutura que representa uma conta banc�ria */

typedef struct {
        char nome[20];
		int numero_conta;
        int cpf;
        float saldo;
} conta;

/* Fun��o menu que mostra as op��es e retorna a op��o escolhida */
int menu() {
	int opcao;
	
	system("cls");
	printf("\n** MENU **\n");
	printf("\n1. Cadastrar contas");
	printf("\n2. Visualizar contas cadastradas");
	printf("\n3. Consulta saldo da conta e realiza deposito ou saque");
	printf("\n0. Sair");
	printf("\nDigite uma op��o: ");
	
	scanf("%d", &opcao);
	fflush(stdin);
	
	system("cls");
	
	return opcao;
}


/* Prodecimento que pausa a aplica��o */
void pausar() {
	printf("\nDigite qualquer tecla para continuar...");
	getchar();
}

int main() {
	setlocale(LC_ALL,"");
	
	// declara um vetor do tipo conta de tamanho MAX
	conta contas[MAX];
	// declara as vari�veis para representar:
	// op��o: opc
	// i: variavel de controle do loop
	// encontrou: vari�vel para indicar se encontrou conta com o nome buscado
	
	int opc, i, contador, CPF_buscado, result;

	// declara variavel para guardar o saque
	float saque = 0.0;
	
	// declara variavel para guardar o deposito
	float deposito = 0.0;
	
	// declara variavel para guardar o saldo atual
	float saldo_atual = 0.0;
	
	// opc recebe o n�mero retornado pela fun��o menu()
	opc = menu();
	
	// enquanto opc for diferente de zero, repita:
	while (opc != 0) {
		
		// testa a op��o digitada
		switch(opc) {
			case 1: // cadastra as contas dentro do vetor
				
				// percorre o vetor para preencher com os dados
				for (i = 0; i < MAX; i++) {
					printf("\n\n");
					
					printf("Digite o CPF do cliente: ");
					scanf("%d", &contas[i].cpf);
					fflush(stdin);

					printf("Digite o numero da conta: ");
					scanf("%d", &contas[i].numero_conta);
					fflush(stdin);
					
					printf("Digite nome do cliente: ");
					fgets(contas[i].nome, 20, stdin);
					fflush(stdin);
					
					printf("Digite o saldo a ser depositado na Conta: ");
					scanf("%f", &contas[i].saldo);
					fflush(stdin);
				}
				pausar();
			break;
				
			case 2: // exibe todas as contas cadastradas.
				for(i=0; i<MAX; i++){
					printf("\nCPF: %d", contas[i].cpf);
					printf("\nNumero conta: %d", contas[i].numero_conta);
					printf("\nNome: %s", contas[i].nome);
					printf("Saldo: R$%.2f\n", contas[i].saldo);			
				}
				
				pausar();
				break;
				
			case 3: // Consulta o CPF e mostra o saldo
				printf("Digite o CPF para a busca: ");
				scanf("%d", &CPF_buscado);
				fflush(stdin);

				contador = 0;
				
				// percorre o vetor para buscar o nome digitado
				for (i = 0; i < MAX; i++) {
					// compara o nome digitado com o nome da conta na posi��o 'i'
					if(CPF_buscado == contas[i].cpf) {
						printf("\n** EXIBI��O **\n");
						printf("\nCPF: %d", contas[i].cpf);
						printf("\nNumero conta: %d", contas[i].numero_conta);
						printf("\nNome: %s", contas[i].nome);
						printf("Saldo: R$%.2f\n", contas[i].saldo);
						contador++; // contador = contador + 1
						
						printf("\nDeseja realizar: Deposito (1) ou Saque (2)? ");
						scanf("%d", &result);
						
						switch(result){
							case 1:
								printf("\nQuanto deseja depositar: ");
								scanf("%f", &deposito);
								
								contas[i].saldo += deposito;
									
								printf("Saldo atual: %.2f", contas[i].saldo);
								
								pausar();
							break;
							
							case 2:
								printf("\nQuanto deseja sacar: ");
								scanf("%f", &saque);								

								if(saque < contas[i].saldo){
									contas[i].saldo -= saque;
									
									printf("Saldo atual: %.2f", contas[i].saldo);
																			
								}else{
									printf("\nSaldo insuficiente!");
									
								}
								pausar();
							break;	
						}
					}
				}
				
				// caso o nome n�o foi encontrado no vetor contas...
				if(contador == 0) {
					printf("\nCPF digitado n�o foi encontrado!");
				} 
							
				break;
				
			default:
				printf("\nOp��o digitada inv�lida!\n");
				pausar();
				break;
		}
		opc = menu();
	}
	
	return 0;
}
