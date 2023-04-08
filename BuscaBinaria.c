#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome [50];
	char bairro[20];
	char regiao[15];
	char data[10] ;
	char dataRelativa[55];
	char inicio[7];
	char local[91];
	int publico;
	int anoPrimeiro;
} Bloco;

int buscaBinaria(Bloco *b, char *nome_bloco, int quantidade) {
	int inicio, fim, meio;
	inicio = 0;
	fim = quantidade - 1;
	while (inicio <= fim) {
		if (meio == 0 || strcmp(b[meio - 1].nome, nome_bloco) != 0){
		meio = (inicio + fim) / 2;
		if (strcmp(b[meio].nome, nome_bloco) == 0) {
			while (meio > 0 && strcmp(b[meio - 1].nome, nome_bloco) == 0)
			  meio--;
			return meio;
		}
		if (strcmp(nome_bloco, b[meio].nome) < 0) 
			fim = meio-1;
		else 
			inicio = meio+1;
	}}
	return -1;
}
	
int main(void){
	Bloco *b;
	
	FILE *arq;
	arq = fopen("BlocosdeRua_2016_ordenado.bin", "rb");
	if (arq == NULL){
		printf("Erro ao abrir o arquivo BlocosdeRua_2016_ordenado.bin");
		return 1;
	}
	int quantidade, tamanho, i;
	fseek(arq, 0,SEEK_END);
	tamanho = ftell(arq);
	b = (Bloco*) malloc(tamanho);
	quantidade = tamanho/sizeof(Bloco);
	fseek(arq, 0, SEEK_SET);
	fread(b, sizeof(Bloco), quantidade, arq);
	fclose(arq);
	
	for(i = 0; i < quantidade - 1;i++)
		if(strcmp(b[i].nome, b[i + 1].nome) != 0)
			printf("%s\n", &b[i].nome);
		
	char nome_bloco[tamanho];
    printf("\nDigite o nome do Bloco: ");
    scanf("%[^\n]", &nome_bloco);     
    
    int resultado = buscaBinaria(b, nome_bloco, quantidade);
    if (resultado == -1){
    	printf("Bloco nao encontrado.\n");
    	return 1;
	}
	
	
	printf("%s - %s - %s\n", b[resultado].nome, b[resultado].data, b[resultado].inicio);
	while (strcmp(b[resultado + 1].nome, b[resultado].nome) == 0){
		printf("%s - %s - %s\n", b[resultado + 1].nome, b[resultado + 1].data, b[resultado + 1].inicio);
		resultado++;
	}
	free(b);
	return 0;
}
