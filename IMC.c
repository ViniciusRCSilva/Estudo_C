#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

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


Quest�o 09 - Escrever um programa em C que cadastre o nome, a altura, o peso, o CPF e sexo de algumas pessoas. 
				Com os dados cadastrados, em seguida localizar uma pessoa atrav�s do seu CPF e imprimir o seu IMC.*/


/* constante para determinar o tamanho do vetor */
#define TAM 5

// Declara um registro para armazenar os dados do Cadastro.
typedef struct {
    char nome[30];
    int sexo;
    int CPF;
    float altura;
    float peso;
} Cadastro;

//Fun��o Menu que retorna a op��o escolhida pelo usu�rio
int Menu(){
	int opcao;
	
	system("cls");
    printf(" ====== Menu ====== \n");
    printf("\n1 - Cadastrar os Usu�rios\n");
    printf("\n2 - Consultar o CPF e retornar o IMC\n");
    printf("\n0. Sair do programa");
	printf("\n\nDigite uma opcao: ");
    printf(" ================== \n");
    
    scanf("%d", &opcao);
    fflush(stdin);
    
	system("cls");
	return opcao;
}
	
	
//Prodecimento que pausa a aplica��o 
void pausar() {
	printf("\nDigite qualquer tecla para continuar...");
	getchar();
}

//Fun��o Principal
int main(){
	
	setlocale(LC_ALL, "");
	
	// declara um vetor do tipo Cadastro
    Cadastro cadastro_user[TAM];
    
	// declara vari�veis de controle
	int i, opc, contador;
	
	// declara int CPF para realizar a busca no cadastro
	int CPF_buscado;
	
	// decalra vari�vel para calculo do IMC
	float imc_Cadastrado = 0.0;
	
	// chama a fun��o que retorna a op��o escolhida
	opc = Menu();
    
    
    // enquanto op��o for diferente de zero, fa�a:
    while (opc != 0) {
    
        switch(opc){
            case 1:
               
				printf(" ==== Cadastro ==== \n");
                
				// percorre o vetor para preencher com os dados
				for(i = 0; i<TAM; i++) 
				{
                    printf(" ====== %d/%d ======\n", i+1, TAM);
                    
                    printf("Digite o nome: ");
                    fgets(cadastro_user[i].nome, 20, stdin);
                    fflush(stdin);
					                   
                    printf("Digite sexo ((0)- feminino e (1) - masculino: ");
                    scanf("%d", &cadastro_user[i].sexo);
                    fflush(stdin);
                    
                    printf("Digite o CPF: ");
                    scanf("%d", &cadastro_user[i].CPF);
                    fflush(stdin);
                    
                    printf("Digite a altura em centimetros(cm): ");
                    scanf("%f", &cadastro_user[i].altura);
                    fflush(stdin);
                    
                    printf("Digite o peso em quilos(kg): ");
                    scanf("%f", &cadastro_user[i].peso);
                    fflush(stdin);
                }
               	
				pausar();
			break;

            case 2:
                
				printf("Digite o CPF para consultar o cadastro: ");
				scanf("%d", &CPF_buscado);
                fflush(stdin);
                
				contador = 0;
				
				// percorre o vetor para buscar o CPF digitado
				for (i = 0; i < TAM; i++) 
				{
					// compara o CPF digitado com o CPF do Cadastro na posi��o 'i'
					if(CPF_buscado == cadastro_user[i].CPF) 
					{
						printf("\n** EXIBI��O **\n");
						printf("\nNome: %s", cadastro_user[i].nome);
						printf("\nAltura: %.2f", cadastro_user[i].altura);
						printf("\nPeso: %.2f", cadastro_user[i].peso);						
						//imc_Cadastrado = cadastro_user[i].peso / (cadastro_user[i].altura*cadastro_user[i].altura);
						printf("\nIMC: %.2f", cadastro_user[i].peso / ((cadastro_user[i].altura/100)*(cadastro_user[i].altura/100)));
						contador++; // contador = contador + 1													
					} 
				}	


				
				// caso o CPF n�o for encontrado no vetor...
				if(contador == 0) {
						printf("\nCPF digitado n�o foi encontrado!");
				} 
				
				pausar();
			break;
					
            default:
				printf("\nOpcao invalida!\n");
				pausar();
				break;
		}
		
		opc = Menu();
	}	
	return 0;
}
