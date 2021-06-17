// CENTRO UNIVERSIT�RIO DOS GUARARAPES - UNIFG
// T�cnicas de Programa��o
// Lista de Revis�o A2-N2
// Autores:
// Grupo 01:
//	Alequissandra Rayane Farias Santos Silva - 202000574
//	Beatriz Lira Martins - 2020002049
//	Matheus Barros Cris�stomo - 202058447
//	Paloma Corr�a Alves - 202000716
//	Vinicius Rodrigues Cardoso Silva - 202000632 
//	Thulio Mateus de Oliveira Queiroz - 202003804
//
// Quest�o 12:
// Escreva um programa em C que cadastre usu�rios que ir�o utilizar o programa de Mensagens desenvolvidos na APS. Estes usu�rios cadastrados 
// dever�o ser salvos no arquivo usuarios.dat.
//
// Ao iniciar o programa dever� ser mostrado um menu com as seguintes op��es:
// Cadastro de login
// Consultar login
// Listar todos os logins
// Excluir um login
// Sair
//
// Para o cadastro de login, usu�rio dever� digitar um nome de login e senha. Logo depois do cadastro, o programa dever� retornar ao menu.
// Para a consultar de login, o usu�rio dever� digitar um nome de login. Logo depois da busca, o programa retornar� ao menu.
// Ao listar todos os logins, dever� ser impresso na tela nome de login e senha de cada usu�rio. Ao finalizar a lista, dever� ser impresso 
// uma mensagem para que o usu�rio aperte qualquer tecla para retornar ao menu.
// Por fim, ao excluir um login, o usu�rio dever� fornecer um nome de login para que realize uma busca e apague do arquivo usuarios.dat o login 
// desejado. Ao finalizar a exclus�o, o programa dever� retornar ao menu principal.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define QUANT_CADASTROS 3

typedef struct{
    char login[20];
    int senha[3][6];
} Cadastro;

void cls(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int menu(){
    int opcao;
    
    printf("\n\n===== MENU =====\n");
    printf("1 - Cadastro de login\n");
    printf("2 - Consultar login\n");
    printf("3 - Lista de todos os logins\n");
    printf("4 - Excluir login\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    fflush(stdin);
    
    //cls();
    
    return opcao;
}

int main()
{
    int opc, i, encontrou; 
    char nome_login[20];

    Cadastro cadastros[QUANT_CADASTROS];
    
    opc = menu();
    
    while(opc != 0){
        switch(opc){
            case 1:
                printf("\n\nCadastrar usuario:\n\n");
                
                for(i=0; i<QUANT_CADASTROS; i++){
                    printf("Login usuario %d: ", i+1);
                    fgets(cadastros[i].login, 20, stdin);
                    fflush(stdin);
                    
                    printf("Senha: ");
                    scanf("%d", &cadastros[i].senha);
                    fflush(stdin);
                }
            break;
                
            case 2:
                printf("\n\nConsultar usuario:\n\n"); 
                
                printf("Digite o login: ");
                fgets(nome_login, 20, stdin);
                fflush(stdin);
                
                for(i=0; i<QUANT_CADASTROS; i++){
                    if(strcmp(nome_login, cadastros[i].login) == 0){
                        printf("\nUsuario encontrado: %s.", cadastros[i].login);
                        encontrou++;
                    }else{
                        printf("\nUsuario n/ cadastrado.");
                    }
                }
            break;
            
            case 3:
            	printf("\n\nLista de logins\n\n");
                for(i=0; i<QUANT_CADASTROS; i++){
                    printf("Login usuario %d: %s\nSenha: %d\n\n", i+1, cadastros[i].login, cadastros[i].senha);
                }
            break;
			
			case 4:
				
			break;	
        }
        opc = menu();
    }
    
    
  return 0;
}
