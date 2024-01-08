#include <stdio.h> //biblioteca de comunicaÃ§Ã£o com o usuÃ¡rio
#include <stdlib.h> //biblioteca de alocaÃ§Ã£o de espaÃ§o em memÃ³ria
#include <locale.h> //biblioteca de alocaÃ§Ãµes de texto por regiÃ£o
#include <string.h> //biblioteca responsÃ¡vel por cuidar das string
		
int registro()//função respossavel por cadrasta os usuarios no sistema
{
	// inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// fim  da criação de variaveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");// coletado informação dos usuarios
	scanf("%s", cpf);//%s refere as string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo ("w" significa escrever)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  // cria o arquivo ("a" significa alterar )
	fprintf(file,",");// salvo o valor da variavel
	fclose(file);// fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");// coletado informação dos usuarios
	scanf("%s",nome);//%s refere as string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{

setlocale(LC_ALL, "Portuguese");
	
 char cpf[40];  
 char conteudo[200];
 
 printf("digite o cpf a ser consultado: ");
 scanf("%s",cpf);
 
 FILE *file;
 file = fopen(cpf,"r");
 	
 if(file == NULL)
 {
 	printf("nao foi possivel abrir o arquivo, nao localizado.\n");
 	system("pause");
 }
 	
 	while(fgets(conteudo, 200, file) != NULL)
 {
 
 	printf("\n Essa são as informações do usuario: ");
 	printf("%s", conteudo);
 	printf("\n\n");
 	
 }
	fclose(file);
	system("pause");
}


int deletar()
{

char cpf [ 11 ] ; 
 
    printf ( "Digite o CPF a ser deletado: " ) ;
    scanf ( "%s" , cpf ) ;
    
    if ( remover ( cpf )  ==  0 )  
	{
        printf ( "CPF excluído com sucesso! \n " ) ;
        system("pause");
    }
	  
	{
        printf ( "CPF não encontrado \n " ) ;
		system("pause");
	}
}

	
int main()
	{
	int opcao=0; //Definindo variÃ¡veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opçãoo desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção nao esta disponivel! \n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
