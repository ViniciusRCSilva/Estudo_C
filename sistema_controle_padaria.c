#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Construa um sistema de controle de estoque de uma pequena padaria. Seu programa deve oferecer um menu para (a) cadastrar um novo produto;
(b) aumentar o estoque de um produto cadastrado (quando há compras); (c) diminuir o estoque de um produto cadastrado (quando há vendas); 
e (d) imprimir os produtos cadastrados e suas características. De cada produto deseja-se cadastrar: nome (tamanho máximo 50 caracteres) e
preço (número real) além, da quantidade do estoque. Assuma que a padaria venderá no máximo, 100 produtos diferentes.
OBS: Para facilitar a localização de um produto (para as funçoes (b) e (c)), use a posição dos mesmos no vetor que representa o estoque 
como código do produto, informando-a ao fim do cadastro. Então peça ao usuário para digitar o código do produto que deseja aumentar/diminuir
o estoque. 
*/

#define MAX 100 

struct produto{
	char nome[50];
	float preco;
	int quantidade;
};
struct produto produtos[MAX];

int quant_produtos = 0;

char menu(){
	char opc;
	
	printf("\nMENU\n");
	printf("(a) Cadastrar um novo produto\n");
	printf("(b) Aumentar o estoque de um produto cadastrado\n");
	printf("(c) Diminuir o estoque de um produto cadastrado\n");
	printf("(d) Imprimir os produtos cadastrados e suas caracteristicas\n");
	printf("(s) Sair\n");
	printf("- ");
	scanf("%c", &opc);
	fflush(stdin);
	
	return opc;
}

void cadastrar_produto(){
	int tamanho_nome;
	char opc = ' ';
	
	while(opc != 'n'){	
		printf("\nDigite o nome do produto: ");
		fgets(produtos[quant_produtos].nome, 50, stdin);
		fflush(stdin);
		tamanho_nome = strlen(produtos[quant_produtos].nome);
		
		while(tamanho_nome > 50){
			printf("Tamanho de caracteres excedido!\n");
			printf("Digite o nome do produto: ");
			fgets(produtos[quant_produtos].nome, 50, stdin);
			fflush(stdin);
		}

		printf("Digite o preco do produto: ");
		scanf("%f", &produtos[quant_produtos].preco);
		fflush(stdin);
		
		printf("Digite a quantidade no estoque: ");
		scanf("%d", &produtos[quant_produtos].quantidade);
		fflush(stdin);	
		
		quant_produtos++;
		
		printf("\nProduto cadastrado com sucesso!\n");

		printf("\nDeseja cadastrar um novo produto? (s - n)\n- ");
		scanf("%c", &opc);
		fflush(stdin);		
	}

}

void aumentar_estoque(int quantidade){
	int codigo;
	int compra;
	int i;

	if(quantidade == 0){
		printf("\nNenhum produto cadastrado!\n");
	}else{
		printf("\nSe o codigo do produto nao existir, o programa voltara ao MENU.\n");	
		printf("\nInforme o codigo do produto: ");
		scanf("%d", &codigo);
		fflush(stdin);
		
		codigo -= 1;
		
		for(i=0; i<quantidade; i++){
			if(codigo == i){
				printf("Informe as unidades compradas: ");
				scanf("%d", &compra);
				fflush(stdin);
				
				produtos[i].quantidade += compra;
				
				printf("\nQuantidade atualizada!\n");			
			}
		}		
	}
	
}

void diminuir_estoque(int quantidade){
	int codigo;
	int venda;
	int i;
	
	if(quantidade == 0){
		printf("\nNenhum produto cadastrado!\n");
	}else{
		printf("\nSe o codigo do produto nao existir, o programa voltara ao MENU.\n");
		printf("\nInforme o codigo do produto: ");
		scanf("%d", &codigo);
		fflush(stdin);
		
		codigo -= 1;
		
		for(i=0; i<quantidade; i++){
			if(codigo == i){
				printf("Informe as unidades vendidas: ");
				scanf("%d", &venda);
				fflush(stdin);
				
				produtos[i].quantidade -= venda;
				
				printf("\nQuantidade atualizada!\n");			
			}
		}
	}	
}


void listar_produtos(int quantidade){
	int i;
	
	if(quantidade == 0){
		printf("\nNenhum produto cadastrado!\n");
	}else{
		printf("\nLista de produtos cadastrados:\n");
		
		for(i=0; i<quantidade; i++){
			printf("\nCodigo: %d - Nome: %s - Preco: %.2f - Quantidade: %d\n", i+1, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);		
		}		
	}
	
}

int main() {
	char opcao;
	
	opcao = menu();
	
	while(opcao != 's'){
		switch(opcao){
			case 'a':
				cadastrar_produto();		
			break;
		
			case 'b':
				aumentar_estoque(quant_produtos);
			break;
		
			case 'c':
				diminuir_estoque(quant_produtos);	
			break;
		
			case 'd':
				listar_produtos(quant_produtos);	
			break;
			
			default:
				printf("Opcao Invalida!\n");	
			break;
		}
		opcao = menu();		
	}
	
	return 0;
}
