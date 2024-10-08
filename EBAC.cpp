#include <stdio.h> // bibloteca de comunicação com o usuário; esse texto após barras são comentários, não aparecem no código
#include <stdlib.h> //biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	char arquivo[40]; //início criação de variáveis (string é um conjunto de variável)
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //fim criação de variáveis (string é um conjunto de variável)
	
	printf("Digite o CPF:"); //coletando info do usuário
	scanf("%s", cpf); //%s refere-se a string	
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arq
	file = fopen(arquivo, "w"); //w é para write, ou seja, incluir nome do arquivo novo
    fprintf(file, "CPF:");
	fprintf(file, cpf); //salva o valor da variável
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //a de atualizar
    fprintf(file, "\n"); //espaço entre categorias
	fclose(file); //fecha arquivo
	
    printf("Digite o Nome:"); //info do usuário
    scanf("%s" , nome); //registra a info em uma string
    
    file = fopen(arquivo, "a");
    fprintf(file, "Nome:");
	fprintf(file, nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, "\n"); 
	fclose(file);
	
	printf("Digite o Sobrenome:");
    scanf("%s" , sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, "Sobrenome:");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
    fprintf(file, "\n"); 
	fclose(file);
	
	printf("Digite o Cargo:");
    scanf("%s" , cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, "Cargo:");
	fprintf(file, cargo);
	fclose(file); 
	
	system("pause"); //pausa o sistema na tela 
}

int consulta() //função para consultar
{
	setlocale(LC_ALL, "Portuguese"); //linguagem
	
	char cpf[40]; 
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:"); //info
	scanf("%s", cpf); //registrar info em string
	
	FILE *file; //cria o arquivo
	file  = fopen(cpf,"r"); //r de read
	
	if(file == NULL) //NULL= nulo
	{
		printf("Não foi possível localizar o arquivo\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //repetição da função
	{   printf("\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //função para deletar usuários
{
	char cpf [40]; //char aceita numeros e pra string ele é melhor
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //já existe na biblioteca
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nUsuário não encontrado\n");
		system("pause");		
	}
	
	else //tudo que não encaixar na função if
	{
		printf("\nUsuário deletado com sucesso\n\n");
		system("pause");
	}
}

int main() //função principal, com o desenvolvimento do programa
{
	int opcao=0; //variável (um = é pra definir, == é pra comparar)
	int x=1; //repetição
	
	for(x=1;x=1;) //quando a entrada e saída forem iguais, o programa sempre vai repetir
	{
		
	 	system("cls"); //limpar tela
	 
		setlocale(LC_ALL, "Portuguese"); //linguagem
	
		printf("## Cartório da EBAC ## \n\n"); //início menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1 - Incluir usuários\n");
		printf("\t2 - Consultar usuários\n");
		printf("\t3 - Deletar usuários\n\n"); 
		printf("Selecionar opção:"); //fim menu
	
		scanf("%d" , &opcao); //armazenamento da escolha em string
	
		system("cls"); //limpa a tela após rodar a escolha	
	
		switch(opcao) //permite escolher as opções de escolha no projeto
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();	
			break;
			
			default: //tudo que não estiver nos casos principais
			printf("Você selecionou uma opção inválida\n\n");
			break;
			//fim da seleção
		}	
	}
}
