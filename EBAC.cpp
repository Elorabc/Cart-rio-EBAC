#include <stdio.h> // bibloteca de comunica��o com o usu�rio; esse texto ap�s barras s�o coment�rios, n�o aparecem no c�digo
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	char arquivo[40]; //in�cio cria��o de vari�veis (string � um conjunto de vari�vel)
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; //fim cria��o de vari�veis (string � um conjunto de vari�vel)
	
	printf("Digite o CPF:"); //coletando info do usu�rio
	scanf("%s", cpf); //%s refere-se a string	
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria o arq
	file = fopen(arquivo, "w"); //w � para write, ou seja, incluir nome do arquivo novo
    fprintf(file, "CPF:");
	fprintf(file, cpf); //salva o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //a de atualizar
    fprintf(file, "\n"); //espa�o entre categorias
	fclose(file); //fecha arquivo
	
    printf("Digite o Nome:"); //info do usu�rio
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

int consulta() //fun��o para consultar
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
		printf("N�o foi poss�vel localizar o arquivo\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //repeti��o da fun��o
	{   printf("\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //fun��o para deletar usu�rios
{
	char cpf [40]; //char aceita numeros e pra string ele � melhor
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //j� existe na biblioteca
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nUsu�rio n�o encontrado\n");
		system("pause");		
	}
	
	else //tudo que n�o encaixar na fun��o if
	{
		printf("\nUsu�rio deletado com sucesso\n\n");
		system("pause");
	}
}

int main() //fun��o principal, com o desenvolvimento do programa
{
	int opcao=0; //vari�vel (um = � pra definir, == � pra comparar)
	int x=1; //repeti��o
	
	for(x=1;x=1;) //quando a entrada e sa�da forem iguais, o programa sempre vai repetir
	{
		
	 	system("cls"); //limpar tela
	 
		setlocale(LC_ALL, "Portuguese"); //linguagem
	
		printf("## Cart�rio da EBAC ## \n\n"); //in�cio menu
		printf("Escolha a op��o desejada:\n\n");
		printf("\t1 - Incluir usu�rios\n");
		printf("\t2 - Consultar usu�rios\n");
		printf("\t3 - Deletar usu�rios\n\n"); 
		printf("Selecionar op��o:"); //fim menu
	
		scanf("%d" , &opcao); //armazenamento da escolha em string
	
		system("cls"); //limpa a tela ap�s rodar a escolha	
	
		switch(opcao) //permite escolher as op��es de escolha no projeto
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();	
			break;
			
			default: //tudo que n�o estiver nos casos principais
			printf("Voc� selecionou uma op��o inv�lida\n\n");
			break;
			//fim da sele��o
		}	
	}
}
