#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 100
#include"Imoveis.c"
#include"Espaco_em_branco.c"
#include"Senha.c"
#include"Get_senha.c"
#include"Max_Cararacter.c"




FILE *arqimovel;
char desc_imv[500], nome_imv[50], cpf_imv[15],vend_alug[10],email_imv[50], contato_imv[25];
int opcao,id_imv;
float valor_imv;


int opcao=0, opclogin, opcgerente, opccliente, opccorretor, opcvenda;
char referenciaimovel[100],cep[15], area[10], numero[10], valor[15], pagamento[20];//variaveis da funçoes
char bairro[30],cpf[100],cnpj[TAM], tipoimovel[50],datanasc[11],cadnumimovel[100],login1[50], senha1[50],rvendas[500],rvendas1[500];
char login[50],senha[50], email[TAM], creci[20], nome[TAM], sobrenome[TAM], nomej[TAM];
FILE *imoveis;
FILE *arquivo;
FILE *clientesPF;
FILE *clientesPJ;
FILE *cadastrarvenda;
FILE *excluirvenda;
FILE *logincorretor;
FILE *arqcorretor;




int TipoLogin() //Função para escolher o tipo de login
{

	system("color 09");
	
	system("cls");
	
	printf("******************************\n");
  	
	printf("*      Seja Bem Vindo!       *\n");
  	
	printf("******************************\n");
	
	printf("Escolha a opção desejada.\n\n");
	
	printf("1-Login Gerente.\n");
	
	printf("2-Login Corretor.\n");
	
	printf("3-Sair.\n");	
	
		scanf("%i",&opclogin);
	
	getchar();

	while(opclogin!=3)
	{
		
	switch(opclogin){
		case 1:
			LogarGerente(); //Chama a função de logar o gerente
			break;
			
		case 2:
			if (arquivo_existe("Cadastro_corretor.txt")==0) // Verifica se existe um corretor cadastrado, se sim, chama a função de logar corretor.
			{
				printf("Não a corretores cadastrado");
				getch();
				TipoLogin();
			}
			else{
			
			LogarCorretor();
			}
		break;
		
		case 3:
			break;
		
		default:
			printf("Opção Invalida, enter para voltar. ");
	
			getch();
	
		TipoLogin();
			break;
		
	}
	
	}
	
}




int arquivo_existe(char nmarq[]) { // Função para verificar se um arquivo existe
	
	FILE* arq = fopen(nmarq, "r");
    
	if (arq) {
        fclose(arq);
        return 1;
    }
    return 0;
}





void LogarCorretor() // Função de logar o corretor
{
		system("color 0C");
		system("cls");


	printf("Login:"); 
	scanfsmax(login1,20);
	
	printf("Senha: ");
	
		getSenha(senha1,'*',15);
	
	FILE *logincorretor;
	
	logincorretor = fopen("Login_corretor.txt","r"); // abrir arquivo em modo leitura
	
	while(!feof(logincorretor))
	{
		fscanf(logincorretor,"%s %s\n", login, senha); // acessar os dados
	}
	if (strcmp(login1, login)==0&&(strcmp(senha1, senha)==0)){
		
		MenuCorretor();
		
			
		}
		else{
			printf("Login ou senha incorretos");
			getch();
		}
		
	
		fclose(logincorretor);
}




void LogarGerente()

{
	system("color 0C");
	
	system("cls");
	
	char loging[20], senhag[20]; // variaveis do login do gerente e senha do gerente
	
	int loginerrado = 1, tentativalogingerente; //enquanto loginerrado for igual a 1 irá pedir login e senha
	
	while(loginerrado==1)
	{
		printf("Login: ");
		
		scanfsmax(loging,10); // pega o login do gerente
		
		printf("Senha: ");
		getSenha(senhag,'*',9); //pega a senha do gerente
		
		if(strcmp(loging, "adm")==0) // se for "adm" e "123" o login é feito
		{
			if (strcmp(senhag, "123")==0)
			{
				loginerrado = 0;
				system("cls"); // Limpa tela
				
				MenuGerente();
			}
			
		}
		if (loginerrado==1) // se login ou senha estiverem errados essa tela aparece.
		{
			system("cls");
			
			printf("Login ou senha inválido! Pressine (1) para tentar novamente ou (2) para voltar.\n\n");
	  scanf("%i",&tentativalogingerente);
			getchar();
			switch(tentativalogingerente) // switch para pegar a opção selecionada e chamar a função correspondente
			{
				case 1: 
				LogarGerente();
				break;
				
				case 2:
				TipoLogin();
				getchar();

				break;
				
				default:
				printf("Opção Invalida.");
				break;
			}
			
			
		}
		
	}

	printf("\n\n");
}





void CadastroCorretor()

{
	

	system("cls"); // Limpa tela
	
	system("color 05"); // Altera a cor do menu
	
	printf("Cadastro de Corretor\n\n"); 
	
	printf("CPF: ");
		
		gets(cpf); // Pega a cpf
	
	printf("Primeiro nome: ");
	
		gets(nome); // Pega o nome
	
	printf("Sobrenome: ");
	
		gets(sobrenome); // Pega o sobrenome
	
	printf("Registro CRECI: ");
		
		gets(creci); // Pega o registro CRECI
	
	
	printf("Insira um Login: ");
		
		gets(login); // Pega o login
		
	
	printf("Insira uma senha: ");
		
		gets(senha); // Pega a senha
		
		
	
	FILE *logincorretor; // cria um arquivo para armazenar login e senha do corretor
	
	logincorretor = fopen("Login_corretor.txt", "a+");
	
	fprintf(logincorretor,"%s %s\n", login, senha);
	
	printf("Login de corretor cadastrado com sucesso!\n\nEnter para voltar.");
	
	
	FILE *corretor; //cria um arquivo para armazenar os outros dados do corretor
	
	corretor = fopen("Cadastro_corretor.txt", "a+");
	
	fprintf(corretor,"%s %s %s %s\n", cpf,nome,sobrenome,creci);
	
	fclose(logincorretor);
	
	fclose(corretor);
	
	getchar();	
	
		MenuGerente();//Volta para o menu gerente

	
		
}





void AlterarVenda()
{		
		system("cls");
		system("color 0A");
	
	int chave,cod_corr=0;
	
	printf("*********************************************\n");
	printf("    Alteração de cadastro de venda    ");
    printf("*********************************************\n\n");
    printf("Informe o registro de creci do corretor para fazer a alteração");
    scanf("%i",&chave);
    
    arqcorretor=fopen("Cadastro_corretor.txt","r");
    FILE*arqcorretorNovo=fopen("Cadastro_corretor_novo.txt","w");
    
    	while(!feof(arqcorretor))
    	{
    		fscanf(arqcorretor,"%s %s %s %s\n", cpf,nome,sobrenome,creci);
    		if(creci!=chave)
    		{
    			fprintf(arqcorretorNovo,"%s %s %s %s\n", cpf,nome,sobrenome,creci);
			}
		}
	fclose(arqcorretor);
	fclose(arqcorretorNovo);
	
	system ("del Cadastro_corretor.txt");
	system ("rename Cadastro_corretor_novo.txt Cadastro_corretor.txt");
	
	arqcorretor=fopen("Cadastro_corretor.txt","r");
	
	while(!feof(arqcorretor))
	{
		
	}
	
	fclose(arqcorretor);
	
}







void AlterarCorretor()
{		
		
	
}


void MenuVendas()
{

	system("cls"); // Limpa tela
	system("color 0A"); // Altera a cor do menu

	printf("Menu de vendas\n\nSelecione a opção desejada.\n\n");

	printf("1-Cadastro de vendas pessoa física.\n2-Cadastro de vendas pessoa jurídica.\n3-Listar venda de imóvel de pessoa jurídica\n4-Listar venda de imóvel pessoa física.\n5-Alterar venda de imóvel.\n6-Excluir venda de imóvel pessoa física.\n7-Excluir venda de imóvel pessoa jurídica.\n8-Voltar.");

	scanf("%i",&opcvenda); // Armazena a opção escolhida

	getchar();
	
	switch(opcvenda){// Chama uma das funções baseado na opção escolhida.
	
		case 1:
			CadastroVendaPessoaFisica(); 
		
			break;
	
		case 2:
			CadastroVendaPessoaJuridica();
		
			break;
			
		case 3:
			ListarVendasJuridicaGerente();
			break;
		
		case 4:
			ListarVendasFisicaGerente();
			break;
		
		case 5:
			AlterarVenda();
			break;
		
		case 6:
			ExcluirVendasFisicaGerente();
			break;
		
		case 7:
			ExcluirVendasJuridicaGerente();
			break;
		
		case 8:
			MenuGerente();
			
			break;
		
		default:
			printf("Opção inválida! Enter para voltar.");
			
			getch();
			
			MenuVendas();
		}
		
		MenuVendas();	
}


void AlterarVendas()
{
	char rvendasalterar[80], novodado[50];
	int opcalterar;
	printf("\nAlterar registro de vendas\n\n"); 
	
	printf("Informe o registro de venda que deseja alterar: ");
	 gets(rvendasalterar); // Pega o registro da venda que vai alterar
	 
	 cadastrarvenda = fopen("vendas_pessoa_fisica.txt","r"); // abrir arquivo em modo leitura
	 FILE* arquivoNovo;
	arquivoNovo = fopen("vendas_pessoa_fisica_novo.txt","w"); // abrir arquivo em modo escrita
	 
	 printf("\n1-Alterar tipo de imóvel.\n2-Alterar cep.\n3-Alterar número.\n4-Alterar valor.\n5-Alterar cpf do comprador.\n6-Alterar forma de pagamento.");
	 scanf("%i", &opcalterar);
	 
	 getchar();
	 
	 printf("\nInsira o novo dado:");
	 
	 gets(novodado); // Pega o novo dado que será alterado
	 
	 switch(opcalterar){// Baseado na opção escolhida chama uma das funções
	 	
	 	case 1:
	 		while(!feof(cadastrarvenda)){
			 
	 		
	 		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // acessar os dados
	 		
	 		if(strcmp(novodado, tipoimovel)!=0&&strcmp(rvendasalterar, rvendas)!=0){// compara o novo dado com o dado que sera alterado, se for diferente ele altera
	 			
	 			fprintf(arquivoNovo, "%s %s %s %s %s %s %s\n", rvendas, novodado, cep, numero, valor, cpf, pagamento);
			 }
			 
			else{
				
				fprintf(arquivoNovo,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // se o dado for igual ele passa como o dado antigo
			
			break;
			}
		
		
		
		
		
		
		
		
		default:
			printf("Opção inválida. Enter para voltar.");
			
			getch();
			
			AlterarVenda();
			
			break;	
	 		
}
	 }
	
	fclose(cadastrarvenda); // fechar o uso do arquivo
	
	fclose(arquivoNovo); // fechar o uso do arquivo
	
	system("del vendas_pessoa_fisica.txt"); // Deleta o arquivo antigo
	
	system("rename vendas_pessoa_fisica_novo.txt vendas_pessoa_fisica.txt"); // Renomeia o arquivo novo com o nome do antigo
				
	printf("Fim da exclusão!\n\nEnter para voltar.");
	
	getch();
	
	MenuVendas(); // retorna ao menu de vendas
}


void ExcluirVendasFisicaGerente()
{
	char rvendasexcluir[80];
	
	printf("\nExclusão do cadastro\n\n"); 
	
	printf("Informe o registro de venda que deseja remover: ");
		gets(rvendasexcluir); // recebe o registro da venda que será excluida
		
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt","r"); // abrir arquivo em modo leitura
	
	FILE* arquivoNovo;
	arquivoNovo = fopen("vendas_pessoa_fisica_novo.txt","w"); // abrir arquivo em modo escrita
	
	while(!feof(cadastrarvenda))
	{
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // acessar os dados
	
		if (strcmp(rvendas, rvendasexcluir)!=0) // se o Registro de venda lido for diferente do desejado para exluir, grava no arquivo novo
		{
		fprintf(arquivoNovo,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // escrever dados no arquivo novo
		}
	}
	
	
	fclose(cadastrarvenda); // fechar o uso do arquivo
	
	fclose(arquivoNovo); // fechar o uso do arquivo
	
	system("del vendas_pessoa_fisica.txt"); // Deleta o arquivo antigo
	
	system("rename vendas_pessoa_fisica_novo.txt vendas_pessoa_fisica.txt"); // Renomeia o arquivo novo com o nome do antigo
				
	printf("Fim da exclusão!\n\nEnter para voltar.");
	
	getch();
	
	MenuVendas();
}

void ExcluirVendasJuridicaGerente()
{
	char rvendasexcluir[80];
	
	printf("\nExclusão do cadastro\n\n"); 
	
	printf("Informe o registro de venda que deseja remover: ");
		gets(rvendasexcluir);
		
	cadastrarvenda = fopen("vendas_pessoa_juridica.txt","r"); // abrir arquivo em modo leitura
	
	FILE* arquivoNovo;
	arquivoNovo = fopen("vendas_pessoa_juridica_novo.txt","w"); // abrir arquivo em modo escrita
	
	while(!feof(cadastrarvenda))
	{
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cnpj, pagamento); // acessar os dados
	
		if (strcmp(rvendas, rvendasexcluir)!=0) // se o Registro de imovel lido for diferente do desejado para exluir, grava no arquivo novo
		{
		fprintf(arquivoNovo,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cnpj, pagamento); // escrever dados no arquivo novo
		}
	}
	
	
	fclose(cadastrarvenda); // fechar o uso do arquivo
	
	fclose(arquivoNovo); // fechar o uso do arquivo
	
	system("del vendas_pessoa_juridica.txt"); // Deleta o arquivo antigo
	
	system("rename vendas_pessoa_juridica_novo.txt vendas_pessoa_juridica.txt"); // Renomeia o arquivo novo com o nome do antigo
				
	printf("Fim da exclusão!\n\nEnter para voltar.");
	
	getch();
	
	MenuVendas();
}

void ExcluirVendasFisicaCorretor()
{
	char rvendasexcluir[80];
	
	printf("\nExclusão do cadastro\n\n"); 
	
	printf("Informe o registro de venda que deseja remover: ");
		gets(rvendasexcluir);
		
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt","r"); // abrir arquivo em modo leitura
	
	FILE* arquivoNovo;
	arquivoNovo = fopen("vendas_pessoa_fisica_novo.txt","w"); // abrir arquivo em modo escrita
	
	while(!feof(cadastrarvenda))
	{
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // acessar os dados
	
		if (strcmp(rvendas, rvendasexcluir)!=0) // se o Registro de imovel lido for diferente do desejado para exluir, grava no arquivo novo
		{
		fprintf(arquivoNovo,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // escrever dados no arquivo novo
		}
	}
	
	
	fclose(cadastrarvenda); // fechar o uso do arquivo
	
	fclose(arquivoNovo); // fechar o uso do arquivo
	
	system("del vendas_pessoa_fisica.txt");// Deleta o arquivo antigo
	
	system("rename vendas_pessoa_fisica_novo.txt vendas_pessoa_fisica.txt"); // Renomeia o arquivo novo com o nome do antigo
				
	printf("Fim da exclusão!\n\nEnter para voltar.");
	
	getch();
	
	MenuVendasCorretor();
}

void ExcluirVendasJuridicaCorretor()
{
	char rvendasexcluir[80];
	
	printf("\nExclusão do cadastro\n\n"); 
	
	printf("Informe o registro de venda que deseja remover: ");
		gets(rvendasexcluir);
		
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt","r"); // abrir arquivo em modo leitura
	
	FILE* arquivoNovo;
	arquivoNovo = fopen("vendas_pessoa_fisica_novo.txt","w"); // abrir arquivo em modo escrita
	
	while(!feof(cadastrarvenda))
	{
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cnpj, pagamento); // acessar os dados
	
		if (strcmp(rvendas, rvendasexcluir)!=0) // se o Registro de imovel lido for diferente do desejado para exluir, grava no arquivo novo
		{
		fprintf(arquivoNovo,"%s %s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cnpj, pagamento); // escrever dados no arquivo novo
		}
	}
	
	
	fclose(cadastrarvenda); // fechar o uso do arquivo
	
	fclose(arquivoNovo); // fechar o uso do arquivo
	
	system("del vendas_pessoa_juridica.txt");// deleta o arquivo antigo
	
	system("rename vendas_pessoa_juridica_novo.txt vendas_pessoa_juridica.txt"); // Renomeia o arquivo novo com o nome do antigo
				
	printf("Fim da exclusão!\n\nEnter para voltar.");
	
	getch();
	
	MenuVendasCorretor();
}




void ListarVendasFisicaCorretor()
{

	system("cls");
	system("color 0D");
	if (!arquivo_existe("vendas_pessoa_fisica.txt")) // Verifica se o arquivo existe
	{
		printf("\nNão existe vendas cadastradas! "); // se não existir apresente essa mensagem
		system("pause");
		MenuVendasCorretor();
	}
		printf("Listagem de vendas\n"); 
	
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(cadastrarvenda)) // enquanto não for o fim do arquivo, lê todos os dados do arquivo
	{
		
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s ", rvendas1, tipoimovel, cep, numero, valor, cpf, pagamento); // enquanto não for o fim do arquivo, lê todos os dados do arquivo
		printf("\n\nRegistro da venda: %s\nTipo do imóvel: %s\nCEP: %s\nNúmero: %s\nValor: %s\nCNPJ::%s\nPagamento: %s\n ",rvendas1,tipoimovel, cep, numero, valor, cnpj, pagamento); // exibir na tela os dados do arquivo
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(cadastrarvenda); // fecha o uso do arquivo
	
	
	
	MenuVendasCorretor();	

	
	

}



void ListarVendasJuridicaCorretor()
{

	system("cls");
	system("color 0D");
	if (!arquivo_existe("vendas_pessoa_juridica.txt")) // Verifica se o arquivo existe
	{
		printf("\nNão existe vendas cadastradas! "); // se não existir apresente essa mensagem
		system("pause");
		MenuVendasCorretor();
	}
		printf("Listagem de vendas\n"); 
	
	cadastrarvenda = fopen("vendas_pessoa_juridica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(cadastrarvenda)) // enquanto não for o fim do arquivo, lê todos os dados do arquivo
	{
		
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s ", rvendas1, tipoimovel, cep, numero, valor, cnpj, pagamento); // enquanto não for o fim do arquivo, lê todos os dados do arquivo
		printf("\n\nRegistro da venda: %s\nTipo do imóvel: %s\nCEP: %s\nNúmero: %s\nValor: %s\nCNPJ::%s\nPagamento: %s\n ",rvendas1,tipoimovel, cep, numero, valor, cnpj, pagamento); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	
	getchar();
	
	fclose(cadastrarvenda); // fecha o uso do arquivo
	
	
	
	MenuVendasCorretor();	

	
	

}

 

void ListarVendasFisicaGerente()
{

	system("cls");
	system("color 0D");
	if (!arquivo_existe("vendas_pessoa_fisica.txt")) // Verifica se o arquivo existe
	{
		printf("\nNão existem vendas cadastradas! "); // abre o arquivo em modo leitura
		system("pause");
		MenuVendas();
	}
		printf("Listagem de vendas\n"); 
	
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(cadastrarvenda)) // enquanto não for o fim do arquivo, lê todos os dados do arquivo
	{
		
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s ", rvendas, tipoimovel, cep, numero, valor, cpf, pagamento); // enquanto não for o fim do arquivo, lê todos os dados do arquivo
		printf("\n\nRegistro da venda: %s\nTipo do imóvel: %s\nCEP: %s\nNúmero: %s\nValor: %s\nCNPJ::%s\nPagamento: %s\n ",rvendas,tipoimovel, cep, numero, valor, cpf, pagamento); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(cadastrarvenda); // fecha o uso do arquivo
	
	
	
	MenuVendas();	

	
	

}




void ListarVendasJuridicaGerente()
{

	system("cls");
	system("color 0D");
	if (!arquivo_existe("vendas_pessoa_juridica.txt")) // Verifica se o arquivo existe
	{
		printf("\nNão existe vendas cadastradas! "); // abre o arquivo em modo leitura
		system("pause");
		MenuVendas();
	}
		printf("Listagem de vendas\n"); 
	
	cadastrarvenda = fopen("vendas_pessoa_juridica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(cadastrarvenda))  // enquanto não for o fim do arquivo, lê todos os dados do arquivo
	{
		
		fscanf(cadastrarvenda,"%s %s %s %s %s %s %s ", rvendas, tipoimovel, cep, numero, valor, cnpj, pagamento); // enquanto não for o fim do arquivo, lê todos os dados do arquivo
		printf("\n\nRegistro da venda: %s\nTipo do imóvel: %s\nCEP: %s\nNúmero: %s\nValor: %s\nCNPJ::%s\nPagamento: %s\n ",rvendas,tipoimovel, cep, numero, valor, cnpj, pagamento); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(cadastrarvenda); // fecha o uso do arquivo
	
	
	
	MenuVendas();	

	
	

}





void MenuVendasCorretor()
{


	system("cls");
	
	
	system("color 0A");
	
	
	printf("Menu de vendas\n\nSelecione a opção desejada.\n\n");

printf("1-Cadastrar venda de imóvel para pessoa física.\n2-Cadastrar venda de imóvel de pessoa jurídica.\n3-Listar venda de imóvel de pessoa jurídica\n4-Listar venda de imóvel pessoa física.\n5-Alterar venda de imóvel.\n6-Excluir venda de imóvel pessoa física.\n7-Excluir cenda de imóvel pessoa jurídica.\n8-Voltar.");
	scanf("%i",&opcvenda); // recebe a opção selecionada

	getchar();
	
	switch(opcvenda){ // baseado na opção selecionada chama a função
	
		case 1:
			CadastroVendaPessoaFisicaCorretor(); // cadastra venda para pessoa fisica
		
			break;
	
		case 2:
			CadastroVendaPessoaJuridicaCorretor(); // cadastra venda para pessoa juridica
		
			break;
			
		case 3:
			ListarVendasJuridicaCorretor(); // lista vendas para pessoas juridicas
			break;
		
		case 4:
			ListarVendasFisicaCorretor(); // lista vendas para pessoas fisicas
			break;
		
		case 6:
			ExcluirVendasFisicaCorretor(); // exclui uma venda para pessoa fisica
			break;
		
		case 7:
			ExcluirVendasJuridicaCorretor(); // exclui uma venda para pessoa juridica
			break;
		
		case 8:
			MenuCorretor(); // volta para o menu do corretor
			
			break;
		
		default:
			printf("Opção inválida! Enter para voltar."); // apresenta essa mensagem caso seja escolhido uma opção inexistente
			
			getch();
			
			MenuVendasCorretor(); // volta para o menu de vendas
		}
			
}
			





void CadastroVendaPessoaFisica()

{
	

	system("cls");
	
	system("color 05");
	
	printf("Cadastro de venda\n\n");
	
	printf("Insira Registro da Venda: ");
		
		gets(rvendas); // recebe um registro para a venda
	
	printf("Tipo do imóvel: ");
		
		gets(tipoimovel); // recebe o tipo de imovel sendo vendido
	
	printf("CEP: ");
	
		gets(cep); // recebe o cep do imovel
	
	printf("Número: ");
	
		gets(numero); // recebe o numero do imovel
	
	printf("Valor do imóvel: ");
		
		gets(valor); // recebe o valor de venda do imovel
	
	
	printf("Insira o CPF do comprador: ");
		
		gets(cpf); // recebe o cpf do comprador
		
	
	
		
		
	
	
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt", "a+");
	
	fprintf(cadastrarvenda,"%s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cpf);
	
	printf("Venda cadastrada com sucesso!");
	
	
	
	fclose(cadastrarvenda);
	
	getchar();	
	
		MenuVendas();

	
		
}






void CadastroVendaPessoaFisicaCorretor()

{
	

	system("cls");
	
	system("color 05");
	
	printf("Cadastro de venda\n\n");
	 	
	printf("Insira Registro da Venda\n");
		
		gets(rvendas1);
	
	
	printf("Tipo do imóvel: ");
		
		gets(tipoimovel);
	
	printf("CEP: ");
	
		gets(cep);
	
	printf("Número: ");
	
		gets(numero);
	
	printf("Valor do imóvel: ");
		
		gets(valor);
	
	
	printf("Insira o CPF do comprador: ");
		
		gets(cpf);
		
	

		
		
	
	
	
	cadastrarvenda = fopen("vendas_pessoa_fisica.txt", "a+");
	
	fprintf(cadastrarvenda,"%s %s %s %s %s %s\n", rvendas1,tipoimovel, cep, numero, valor, cpf);
	
	printf("Venda cadastrada com sucesso! Enter para voltar.");
	
	
	
	fclose(cadastrarvenda);
	
	getchar();	
	
		MenuVendasCorretor();

	
		
}






void CadastroVendaPessoaJuridica()

{
	

	system("cls");
	
	system("color 05");
	
	printf("Cadastro de venda\n\n");
	
	printf("Registro da venda: ");
		
		gets(rvendas);
	
	printf("Tipo do imóvel: ");
		
		gets(tipoimovel);
	
	printf("CEP: ");
	
		gets(cep);
	
	printf("Número: ");
	
		gets(numero);
	
	printf("Valor do imóvel: ");
		
		gets(valor);
	
	
	printf("Insira o cnpj do comprador: ");
		
		gets(cnpj);
		

		
		
	
	
	
	cadastrarvenda = fopen("vendas_pessoa_juridica.txt", "a+");
	
	fprintf(cadastrarvenda,"%s %s %s %s %s %s\n", rvendas, tipoimovel, cep, numero, valor, cnpj);
	
	printf("Venda cadastrada com sucesso! Enter para voltar.");
	
	
	
	fclose(cadastrarvenda);
	
	getchar();	
	
		MenuVendas();

	
		
}





void CadastroVendaPessoaJuridicaCorretor()

{
	

	system("cls");
	
	system("color 05");
	
	printf("Cadastro de venda\n\n");
	
	printf("Insira o registro da venda: ");
	
	gets(rvendas);
	
	printf("Tipo do imóvel: ");
		
		gets(tipoimovel);
	
	printf("CEP: ");
	
		gets(cep);
	
	printf("Número: ");
	
		gets(numero);
	
	printf("Valor do imóvel: ");
		
		gets(valor);
	
	
	printf("Insira o cnpj do comprador: ");
		
		gets(cnpj);
		
		
		
	
	
	
	cadastrarvenda = fopen("vendas_pessoa_juridica.txt", "a+");
	
	fprintf(cadastrarvenda,"%s %s %s %s %s %s\n",rvendas, tipoimovel, cep, numero, valor, cnpj);
	
	printf("Venda cadastrada com sucesso! Enter para voltar.");
	
	
	
	fclose(cadastrarvenda);
	
	getchar();	
	
		MenuVendasCorretor();

	
		
}




void AlterarImovel()
{
	system("color 0A");
	system("cls");
	
	int chave,cod_imv = 0;
	
	printf("=========================================\n");
	printf("      ALTERAR CADASTRO DE IMOVEIS\n");
	printf("=========================================\n\n"); 
	printf("Informe o código do cliente que deseja fazer a alteração: "); scanf("%i", &chave);
	
	arqimovel = fopen("bd_imoveis_pim.txt","r"); 
	FILE*arqimovelNovo = fopen("bd_imoveis_pim_novo.txt","w"); 
		
		while(!feof(arqimovel)) 
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
			if(id_imv!=chave)  
			{
				fprintf(arqimovelNovo,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
			}
		}
	fclose(arqimovel); 
	fclose(arqimovelNovo); 
	system("del bd_imoveis_pim.txt"); 
	system("rename bd_imoveis_pim_novo.txt bd_imoveis_pim.txt");
	
	arqimovel = fopen("bd_imoveis_pim.txt", "r");	
	while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
		}
	fclose(arqimovel);
	
	cod_imv = id_imv + 1;

	printf("\nPreencha o novo cadastro do imovel\n");

	printf("\n Nova Chave de cadastro do imovel:  %i ",cod_imv); id_imv = cod_imv; 
	printf("\n\n Insira o nome do proprietario: "); scanfsmax(nome_imv,50);
	printf("\n Insira o CPF do proprietario: "); scanfsmax(cpf_imv,15);
	printf("\n Insira o e-mail do proprietario: "); scanfsmax(email_imv,50);
	printf("\n Insira o contato do proprietario: "); scanfsmax(contato_imv,25);	
	printf("\n Insira a descrição do imovel: "); scanfsmax(desc_imv,500);
	printf("\n Deseja: Vender // Alugar: "); scanfsmax(vend_alug,10);
	printf("\n Valor do imovel: "); scanf("%f", &valor_imv);getchar();							
	arqimovel = fopen("bd_imoveis_pim.txt", "a+");	
	TirarEspaco(nome_imv);
	TirarEspaco(desc_imv);
	TirarEspaco(vend_alug);
	fprintf(arqimovel,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
	fclose(arqimovel); //fecha o arquivo
	
	printf("\n\t\t\t Cadastro do imovel alterado com sucesso!!\n\n");
	getch();
	MenuGerente();

}

void AlterarImovelCorretor()
{
	system("color 0A");
	system("cls");
	
	int chave,cod_imv = 0;
	
	printf("=========================================\n");
	printf("      ALTERAR CADASTRO DE IMOVEIS\n");
	printf("=========================================\n\n"); 
	printf("Informe o código do cliente que deseja fazer a alteração: "); scanf("%i", &chave);
	
	arqimovel = fopen("bd_imoveis_pim.txt","r"); 
	FILE*arqimovelNovo = fopen("bd_imoveis_pim_novo.txt","w"); 
		
		while(!feof(arqimovel)) 
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
			if(id_imv!=chave)  
			{
				fprintf(arqimovelNovo,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
			}
		}
	fclose(arqimovel); 
	fclose(arqimovelNovo); 
	system("del bd_imoveis_pim.txt"); 
	system("rename bd_imoveis_pim_novo.txt bd_imoveis_pim.txt");
	
	arqimovel = fopen("bd_imoveis_pim.txt", "r");	
	while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
		}
	fclose(arqimovel);
	
	cod_imv = id_imv + 1;

	printf("\nPreencha o novo cadastro do imovel\n");

	printf("\n Nova Chave de cadastro do imovel:  %i ",cod_imv); id_imv = cod_imv; 
	printf("\n\n Insira o nome do proprietario: "); scanfsmax(nome_imv,50);
	printf("\n Insira o CPF do proprietario: "); scanfsmax(cpf_imv,15);
	printf("\n Insira o e-mail do proprietario: "); scanfsmax(email_imv,50);
	printf("\n Insira o contato do proprietario: "); scanfsmax(contato_imv,25);	
	printf("\n Insira a descrição do imovel: "); scanfsmax(desc_imv,500);
	printf("\n Deseja: Vender // Alugar: "); scanfsmax(vend_alug,10);
	printf("\n Valor do imovel: "); scanf("%f", &valor_imv);getchar();							
	arqimovel = fopen("bd_imoveis_pim.txt", "a+");	
	TirarEspaco(nome_imv);
	TirarEspaco(desc_imv);
	TirarEspaco(vend_alug);
	fprintf(arqimovel,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
	fclose(arqimovel); //fecha o arquivo
	
	printf("\n\t\t\t Cadastro do imovel alterado com sucesso!!\n\n");
	getch();
	MenuCorretor();

}


void ExcluirImovel()
{
	system("color 04");
	system("cls");
	
	int chave;
	
	printf("*******************************************\n");
	printf("*     EXCLUSÃO DE CADASTRO DE IMÓVEL      *\n");
	printf("*******************************************\n\n"); 
	printf("Informe o código do imovel que deseja remover: "); scanf("%i", &chave);
	
	arqimovel = fopen("bd_imoveis_pim.txt","r"); 
	FILE*arqimovelNovo = fopen("bd_imoveis_pim_novo.txt","w"); 
		
		while(!feof(arqimovel)) 
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
			if(id_imv!=chave) 
			{
				fprintf(arqimovelNovo,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
			}
		}
	fclose(arqimovel);  
	fclose(arqimovelNovo);
	
	system("del bd_imoveis_pim.txt");
	system("rename bd_imoveis_pim_novo.txt bd_imoveis_pim.txt"); 

	printf("\n\t\t\t Imovel excluido com sucesso!!\n\n");
	getch();
	
	MenuGerente();
}





void ExcluirImovelCorretor()
{
	char riExcluir[80];
	
	printf("\nExclusão do cadastro\n\n"); 
	
	printf("Informe o registro de imóvel que deseja remover: ");
		
		gets(riExcluir); //chama a função que exclui o registro de imóvel
	
	imoveis = fopen("imoveis.txt","r"); // abrir arquivo em modo leitura
	
	FILE* arquivoNovo = fopen("imoveis_novo.txt","w"); // abrir arquivo em modo escrita
	
	while(!feof(imoveis))
	{
		fscanf(imoveis,"%s %s %s %s %s\n", cadnumimovel, cep, bairro, tipoimovel, &area); // acessar os dados
	
		if (strcmp(cadnumimovel, riExcluir)!=0) // se o Rregistro de imovel lido for diferente do desejado para exluir, grava no arquivo novo
		{
			fprintf(arquivoNovo,"%s %s %s %s %s\n", cadnumimovel, cep, bairro, tipoimovel,area); // escrever dados no arquivo novo
		}
	}
	fclose(imoveis); // fechar o uso do arquivo
	
	fclose(arquivoNovo); // fechar o uso do arquivo
	
	system("del imoveis.txt"); // deleta o arquivo antigo 
	
	system("rename imoveis_novo.txt imoveis.txt"); // renomeia o arquivo novo com o nome do antigo
				
	printf("Fim da exclusão!\n\nEnter para voltar.");
	
	getch();
	
	MenuCorretor(); // volta para o menu corretor
}






void CadastroImovel()
{
	system("color 05");
	
	system("cls");
	
	
	int cod_imv = 0;
	printf("=========================================\n");
	printf("      INCLUSÃO DE CADASTRO DE IMÓVEL     \n");
	printf("=========================================\n\n");

	arqimovel = fopen("bd_imoveis_pim.txt", "r");	
	while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug);  //ABRE O ARQUIVO EM MODO LEITURA PARA PARA PEGAR  O ULTIMO CODIGO CADASTRADO PARA SER INCREMENTADO O PROXIMO
		}
	fclose(arqimovel);
	
	cod_imv = id_imv + 1;
	
	printf("\n Chave de cadastro do imovel:  %i ",cod_imv); id_imv = cod_imv;
	printf("\n\n Insira o nome do proprietario: "); scanfsmax(nome_imv,50);
	printf("\n Insira o CPF do proprietario: "); scanfsmax(cpf_imv,15);
	printf("\n Insira o e-mail do proprietario: "); scanfsmax(email_imv,50);
	printf("\n Insira o contato do proprietario: "); scanfsmax(contato_imv,25);	
	printf("\n Insira a descrição do imovel: "); scanfsmax(desc_imv,500);
	printf("\n Deseja: Vender // Alugar: "); scanfsmax(vend_alug,10);
	printf("\n Valor do imovel: R$"); scanf("%f", &valor_imv);getchar();						
	arqimovel = fopen("bd_imoveis_pim.txt", "a+");
	TirarEspaco(nome_imv);
	TirarEspaco(desc_imv);
	TirarEspaco(vend_alug);
	fprintf(arqimovel,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
	fclose(arqimovel); 
	
	printf("\n\t\t\t Imovel cadastrado com sucesso!!\n\n");
	getch();
	
	MenuGerente();
	
}


void CadastroImovelCorretor()
{
	system("color 05");
	
	system("cls");
	
	
	int cod_imv = 0;
	printf("=========================================\n");
	printf("      INCLUSÃO DE CADASTRO DE IMÓVEL     \n");
	printf("=========================================\n\n");

	arqimovel = fopen("bd_imoveis_pim.txt", "r");	
	while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug);  //ABRE O ARQUIVO EM MODO LEITURA PARA PARA PEGAR  O ULTIMO CODIGO CADASTRADO PARA SER INCREMENTADO O PROXIMO
		}
	fclose(arqimovel);
	
	cod_imv = id_imv + 1;
	
	printf("\n Chave de cadastro do imovel:  %i ",cod_imv); id_imv = cod_imv;
	printf("\n\n Insira o nome do proprietario: "); scanfsmax(nome_imv,50);
	printf("\n Insira o CPF do proprietario: "); scanfsmax(cpf_imv,15);
	printf("\n Insira o e-mail do proprietario: "); scanfsmax(email_imv,50);
	printf("\n Insira o contato do proprietario: "); scanfsmax(contato_imv,25);	
	printf("\n Insira a descrição do imovel: "); scanfsmax(desc_imv,500);
	printf("\n Deseja: Vender // Alugar: "); scanfsmax(vend_alug,10);
	printf("\n Valor do imovel: R$"); scanf("%f", &valor_imv);getchar();						
	arqimovel = fopen("bd_imoveis_pim.txt", "a+");
	TirarEspaco(nome_imv);
	TirarEspaco(desc_imv);
	TirarEspaco(vend_alug);
	fprintf(arqimovel,"%i %s %s %s %s %s %f %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
	fclose(arqimovel); 
	
	printf("\n\t\t\t Imovel cadastrado com sucesso!!\n\n");
	getch();
	
	MenuCorretor();
	
}



void CadastroPessoaFisica(){

	
	
	system("cls"); // limpa a tela
	
	system("color 05"); // altera a cor do texto
	
	printf("Cadastro de pessoa física\n\n");
	
	printf("CPF: ");
		gets(cpf); // armazena o cpf
	
	printf("Primeiro nome: ");
	
		gets(nome); // armazena o nome
	
	printf("Sobrenome: ");
	
		gets(sobrenome); // armazena o sobrenome
	
	printf("Data de nascimento(DD/MM/AAAA): ");
	
		gets(datanasc); // armazena a data de nascimento
	
	printf("Email: ");
	
		gets(email); // armazena o e-mail
	
	
	
	
	
	clientesPF = fopen("Clientes_Pessoa_Fisica.txt", "a+"); // cria o arquivo do cadastro de pessoa fisica
	
	fprintf(clientesPF,"%s %s %s %s %s ", cpf, nome, sobrenome, datanasc, email); // salva os dados no arquivo
	
	printf("Cadastrado com sucesso!\n\nEnter para voltar");

	fclose(clientesPF); // fecha o arquivo
	
	getchar();	
	
	MenuCliente(); // retorna ao menu cliente
}






void CadastroPessoaFisicaCorretor(){

	
	
	system("cls"); // limpa a tela
	
	system("color 05"); // altera a cor do texto
	
	printf("Cadastro de pessoa física\n\n");
	
	printf("CPF: ");
		gets(cpf); // armazena o cpf
	
	printf("Primeiro nome: ");
	
		gets(nome); // armazena o nome
	
	printf("Sobrenome: ");
	
		gets(sobrenome); // armazena o sobrenome
	
	printf("Data de nascimento(DD/MM/AAAA): ");
	
		gets(datanasc); // armazena a data de nascimento
	
	printf("Email: ");
	
		gets(email); // armazena o e-mail
	
	
	
	
	
	clientesPF = fopen("Clientes_Pessoa_Fisica.txt", "a+"); // cria o arquivo do cadastro de pessoa fisica
	
	fprintf(clientesPF,"%s %s %s %s %s ", cpf,nome,sobrenome,datanasc,email); // salva os dados no arquivo
	
	printf("Cadastrado com sucesso!\n\nEnter para voltar");

	fclose(clientesPF); // fecha o arquivo
	
	getchar();	
	
	MenuClienteCorretor(); // retorna ao menu cliente
}







void CadastroPessoaJuridica(){
	

	
	system("cls");
	
	system("color 06");
	
	printf("Cadastro de pessoa jurídica\n\n");
	
	printf("CNPJ: ");
	
		gets(cnpj); // armazena o cnpj
	
	printf("Nome da empresa: ");
	
		gets(nomej); // armazena o nome da empresa
	
	printf("E-mail da empresa: ");
		gets(email);

	
	

	
	clientesPJ = fopen("Clientes_Pessoa_Juridica.txt", "a+"); // cria o arquivo
	
	fprintf(clientesPJ,"%s %s %s ", cnpj, nomej, email); // armazena os dados no arquivo
	
	printf("Cliente cadastrado com sucesso!\n\nEnter para voltar.");
	
	fclose(clientesPJ); // fecha o arquivo
	
	getch();
	
	MenuCliente(); // retorna ao menu cliente
}




void CadastroPessoaJuridicaCorretor(){
	

	
	system("cls");
	
	system("color 06");
	
	printf("Cadastro de pessoa jurídica\n\n");
	
	printf("CNPJ: ");
	
		gets(cnpj); // armazena o cnpj
	
	printf("Nome da empresa: ");
	
		gets(nomej); // armazena o nome da empresa
	
	printf("E-mail da empresa: ");
	
		gets(email); // armazena o email da empresa
	
	
	
	
	clientesPJ = fopen("Clientes_Pessoa_Juridica.txt", "a+"); // cria o arquivo
	
	fprintf(clientesPJ,"%s %s %s ", cnpj, nomej, email); // armazena os dados no arquivo
	
	fclose(clientesPJ); // fecha o arquivo
	
	printf("Cliente cadastrado com sucesso!\n\nEnter para voltar.");
	
	getch();
	
	MenuClienteCorretor(); // retorna ao menu cliente
}







void MenuGerente(){
	
	system("cls");
	
	system("color 0A");
	
	printf("**************************\n");
	
	printf("*   Bem vindo Gerente !  *\n");
	
	printf("**************************\n");
	
	printf("Escolha a opção desejada.\n\n"); // Menu para escolher as funções
	
	printf("1-Menu Imóveis.\n");
	
	printf("2-Cadastro de corretor.\n");
	
	printf("3-Menu de clientes.\n");
	
	printf("4-Simular financiamento.\n");
	
	printf("5-Menu de vendas.\n");
	
	printf("6-Deslogar.\n");
	
	scanf("%i",&opcgerente); // armazena a opção escolhida
	
	getchar();
	
	
	switch(opcgerente){ // baseado na opção, chama a função correspondente
	
		case 1:
			MenuImoveis(); // chama a função de cadastrar imóvel
			break;
	
		case 2:
			CadastroCorretor(); // chama a função de cadastrar corretor
			break;
	
		case 3:
			MenuCliente(); // chama o menu de cadastro de cliente
			break;
	
		case 4:
			Financiamentos(); // chama a função de simular financiamento
			break;
	
		case 5:
			MenuVendas(); // chama o menu de vendas
			break;
			
		case 6:
			TipoLogin(); // chama a função tipo login
			break;
		
		default:
			printf("Opção inválida, enter para continuar.");
			
			getch();
			
			MenuGerente();	
		
			
	}
}









	MenuImoveis()
{
	
	
	system("color 0A");
	system("cls");
	printf("********************************************\n");
	printf("*              Menu de Imóveis             * \n"); //Titulo
	printf("********************************************\n\n");
	
	printf("1- Cadastrar Imovel\n");
	printf("2- Pesquisar Imovel\n");
	printf("3- Alterar Imovel\n");
	printf("4- Excluir Imovel\n");
	printf("5- Listar Imoveis\n");	
	printf("6- Voltar\n");
	printf("\nOpção: ");scanf("%i",&opcao);
	getchar();
	
	switch(opcao)
	{
		case 1:
			CadastroImovel();
		break;
		
		case 2:
			PesquisarImovel();
			break;
		case 3 :
			AlterarImovel();
			break;
			
			case 4:
				ExcluirImovel();
			break;
		
		case 5:
			ListarRegistrosImoveis();
			break;
			
		case 6:
			MenuGerente();
			break;
			
			
	}
	
}

	MenuImoveisCorretor()
{
	
	
	system("color 0A");
	system("cls");
	printf("********************************************\n");
	printf("*              Menu de Imóveis             * \n"); //Titulo
	printf("********************************************\n\n");
	
	printf("1- Cadastrar Imovel\n");
	printf("2- Pesquisar Imovel\n");
	printf("3- Alterar Imovel\n");
	printf("4- Excluir Imovel\n");
	printf("5- Listar Imoveis\n");	
	printf("6- Voltar\n");
	printf("\nOpção: ");scanf("%i",&opcao);
	getchar();
	
	switch(opcao)
	{
		case 1:
			CadastroImovelCorretor();
		break;
		
		case 2:
			PesquisarImovelCorretor();
			break;
		case 3 :
			AlterarImovelCorretor();
			break;
			
			case 4:
				ExcluirImovelCorretor();
			break;
		
		case 5:
			ListarRegistrosImoveisCorretor();
			break;
			
		case 6:
			MenuCorretor();
			break;
			
			
	}
	
}






void MenuCliente(){

	system("cls");

	printf("Menu de clientes\n\nSelecione a opção desejada.\n\n");

	printf("1-Cadastro de pessoa física.\n2-Cadastro de pessoa jurídica.\n3-Listar clientes pessoa física.\n4-Listar clientes pessoa jurídica.\n5-Voltar.\n");

	scanf("%i",&opccliente); // armazena a opção escolhida

	getchar();
	
	switch(opccliente){ // baseado na opção, chama a função correspondente
	
		case 1:
			CadastroPessoaFisica();
		
			break;
	
		case 2:
			CadastroPessoaJuridica();
		
			break;
	
		case 3:
			ListarPessoaFisica();
		
			break;
		
		case 4:
			ListarPessoaJuridica();
		
			break;
		
		case 5:
			MenuGerente();
		
			break;
		default:
		
			printf("Opção inválida, enter para continuar.");
			
			getch();
			
			return MenuCliente();	
	}
	
	
}







int MenuCorretor(){
	
	system("cls");
	
	system ("color 0A");
	
	// apresenta o menu do corretor
	
	printf("**************************\n");
	
	printf("*   Bem vindo Corretor !  *\n");
	
	printf("**************************\n");
	
	printf("Escolha a opção desejada.\n\n"); // Menu para escolher as funções
	
	printf("1-Menu de Imóveis.\n");
	
	printf("2-Menu de clientes.\n");
	
	printf("3-Simular financiamento.\n");
	
	printf("4-Menu de vendas.\n");
	
	printf("5-Deslogar.\n");
	
	scanf("%i",&opccorretor); // armazena a opção escolhida
	
	getchar();
	
	switch(opccorretor){ // baseada na opção chama a função correspondente
		
		case 1:
			MenuImoveisCorretor();
			break;
	
		
		case 2:
			MenuClienteCorretor();
			break;
		
		case 3:
			FinanciamentosCorretor();
			break;
	
		case 4:
			MenuVendasCorretor();
			break;
			
		case 5:
			TipoLogin();
			break;
		
		
		default:
			printf("Opção inválida, enter para voltar.");
			
			getch();
		
			MenuCorretor();
}
}












void MenuClienteCorretor(){
	
	system("cls");

	printf("Cadastro de clientes\n\nSelecione a opção desejada.\n\n");

	printf("1-Cadastro de pessoa física.\n2-Cadastro de pessoa jurídica.\n3-Listar clientes pessoa física.\n4-Listar clientes pessoa jurídica.\n5-Voltar.\n");

	scanf("%i",&opccliente); // armazena a opção escolhida

	getchar();
	
	switch(opccliente){ // chama a função baseada na opção

		case 1:
			CadastroPessoaFisicaCorretor();
			break;

		case 2:
			CadastroPessoaJuridicaCorretor();
			
			break;

		case 3:
			ListarPessoaFisicaCorretor();
			
			break;
		
		case 4:
			ListarPessoaJuridicaCorretor();
			
			break;
			
		case 5:
			MenuCorretor();
			
			break;
			
		default:
			printf("Opção inválida, enter para continuar.");
			
			getch();
			
			return MenuClienteCorretor();	
	}
		
}


void PesquisarImovel()
{
	system("color 06");
	system("cls");

int chave;
	arqimovel = fopen("bd_imoveis_pim.txt", "r");
	printf("*********************************\n");
	printf("*        Pesquisar Imovel       *\n"); //Titulo
	printf("*********************************\n\n");
		
		printf("\n Insira o codigo do imovel: ");scanf("%i",&chave);
		while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
			if(chave==id_imv && id_imv != 0)	
			{
				ColocarEspaco(nome_imv);
				ColocarEspaco(desc_imv);
				ColocarEspaco(vend_alug);

				
				printf(" \n\nCódigo: %i\nNome: %s\nCPF: %s \nE-mail: %s \nContato: %s\nDescrição: %s\nValor: %f\nVender/Alugar: %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
			}
		}
	fclose(arqimovel);	
	printf("\n\t\t\t Imovel consultado com sucesso!!\n\n");
	getch();
	MenuGerente();
}


void PesquisarImovelCorretor()
{
	system("color 06");
	system("cls");

int chave;
	arqimovel = fopen("bd_imoveis_pim.txt", "r");
	printf("*********************************\n");
	printf("*        Pesquisar Imovel       *\n"); //Titulo
	printf("*********************************\n\n");
		
		printf("\n Insira o codigo do imovel: ");scanf("%i",&chave);
		while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
			if(chave==id_imv && id_imv != 0)	
			{
				ColocarEspaco(nome_imv);
				ColocarEspaco(desc_imv);
				ColocarEspaco(vend_alug);

				
				printf(" \n\nCódigo: %i\nNome: %s\nCPF: %s \nE-mail: %s \nContato: %s\nDescrição: %s\nValor: %f\nVender/Alugar: %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
			}
		}
	fclose(arqimovel);	
	printf("\n\t\t\t Imovel consultado com sucesso!!\n\n");
	getch();
	MenuCorretor();
}



void ListarRegistrosImoveis()
{
	float min, max;
	
	system("color 06");
	system("cls");
	
	printf("=========================================\n");
	printf("              LISTA DE IMOVEIS           \n"); // FUNCÃO QUE IMPRIMI TODOS O CADASTRO COM AS METRICAS QUE SOLITADO PARA O USER VALOR MAX E VALOR MIN PRESENTE NO BANCO DE DADOS TXT.
	printf("=========================================\n\n");
	
	printf("Insira a faixa de preço desejada\n");
	printf("Mínimo: R$");scanf("%f",&min);getchar(); 
	printf("Máximo: R$");scanf("%f",&max);getchar();
	
	arqimovel = fopen("bd_imoveis_pim.txt", "r");
	
	while(!feof(arqimovel))  
		{
			fscanf(arqimovel,"%i %s %s %s %s %s %f %s\n", &id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, &valor_imv, vend_alug); 
			if(valor_imv>=min && valor_imv<=max && id_imv>0)	
			{
				ColocarEspaco(nome_imv);
				ColocarEspaco(desc_imv);
				ColocarEspaco(vend_alug);

				printf("\nCódigo: %i\nNome: %s\nCPF: %s \nE-mail: %s \nContato: %s\nDescrição: %s\nValor: %f\nVender/Alugar: %s\n", id_imv, nome_imv, cpf_imv, email_imv, contato_imv, desc_imv, valor_imv, vend_alug); 
				printf("=========================================\n\n");			
			}
		}
	fclose(arqimovel);	
	printf("\n\t\t\t Listagem de imoveis concluida!!\n\n");
	getch();
	MenuGerente();

	
	
}




void ListarRegistrosImoveisCorretor()
{
	system("cls");
	system("color 0D");
	if (!arquivo_existe("imoveis.txt"))// verifica se o arquivo existe
	{
		printf("\nNão existe imoveis cadastrados! ");
		system("pause");
		MenuGerente();
	}
		printf("Listagem de Imoveis\n"); 
	
	imoveis = fopen("imoveis.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(imoveis))
	{
		fscanf(imoveis,"%s %s %s %s %s\n", cadnumimovel, cep, bairro, tipoimovel, area);
		printf("\n\nNúmero de registro do imovel %s\nCEP: %s\nBairro: %s\nTipo do Imovel:%s\nArea (m2):%s\n\n ",cadnumimovel,cep,bairro,area); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(imoveis);
	
	
	
	MenuClienteCorretor();

	
	
}


void Financiamentos(){
	
	int opcfinanc;
	
	system("cls");
	system("color 06");
	
	printf("=======================================\n");
	printf("    Simulação de financiamentos        \n");
	printf("=======================================\n\n");
	
	printf("Escolha a opção desejada\n");
	
	printf("[1]-Financiamento tabela SAC.\n");
	printf("[2]-Financiamento tabela PRICE.\n");
	printf("[3]-Voltar.\n");
	
	printf("Opção:"); scanf("%i", &opcfinanc);
	
	switch(opcfinanc){
		
		case 1:
			SimularFinanciamentoGerenteSAC();
			break;
			
		case 2:
			SimularFinanciamentoGerentePRICE();
			break;
			
		case 3:
			MenuGerente();
			break;
			
		default:
			printf("Opção inválida, enter para voltar.");
			getch();
			Financiamentos();
			
				
	}
}


void FinanciamentosCorretor(){
	
	int opcfinanc;
	
	system("cls");
	system("color 06");
	
	printf("=======================================\n");
	printf("    Simulação de financiamentos        \n");
	printf("=======================================\n\n");
	
	printf("Escolha a opção desejada\n");
	
	printf("[1]-Financiamento tabela SAC.\n");
	printf("[2]-Financiamento tabela PRICE.\n");
	printf("[3]-Voltar.\n");
	
	printf("Opção:"); scanf("%i", &opcfinanc);
	
	switch(opcfinanc){
		
		case 1:
			SimularFinanciamentoCorretorSAC();
			break;
			
		case 2:
			SimularFinanciamentoCorretorPRICE();
			break;
			
		case 3:
			MenuCorretor();
			break;
			
		default:
			printf("Opção inválida, enter para voltar.");
			getch();
			FinanciamentosCorretor();
			
				
	}
}

void SimularFinanciamentoGerenteSAC(){
 
	system("cls");
	system("color 06");

	int par, i;
	float sald, amortiz, p[360], jur,juro, entr,totjuro = 0;  //p possui 360 valores, máximo de parcelas permitidas
	
	printf("-----------------------------------------\n");
	printf("             SAC         \n");
	printf("----------------------------------------- \n\n");
	
	printf("Valor do imóvel em R$: ");
	scanf("%f",&sald);
	printf("Entrada: ");
	scanf("%f",&entr);
	printf("Total parcelas: ");
	scanf("%i", &par);
	printf("Juros: ");
	scanf("%f",&jur);
	
		sald-=entr;  // o saldo devedor será subtraído pela entrada

	
	if(par>360){  //se o valor das parcelas for maior que 360, uma mensagem aparece para alertar o usuário
		printf("Máximo: 360 parcelas.\n");
		printf("Total parcelas: ");
		scanf("%i", &par);
		}
		else{  //se não, o orçamento é realizado
			
	amortiz = sald/par;  //calcula a amortização, que nesse sistema, é fixa, se da pela divisão do valor total do imóvel pela quantidade de parcelas
	juro=jur/1000;
	for(i=1; i<=par; i++){ // loop para mostrar o valor de cada parcela					
		p[i] = amortiz + sald*juro;
		sald = sald - amortiz; // armotização é o que abate o saldo devedor, depois do pagamento de cada parcela
		printf("\n%i°parcela: %.2f", i, p[i]);
		printf("\nAmortização: %.2f",amortiz);
		printf("\nJuros: %.2f\n",p[i]-amortiz);
		totjuro+=p[i]; //Acumula o valor de cada parcela
		printf("-----------------------------------------\n");
	}
	printf("\nTotal pago: %.2f\n",totjuro); // Valor pago pelo imóvel no final do financiamento
	}

	
system("pause");

MenuGerente();
}

int SimularFinanciamentoGerentePRICE()
{		
float valor_imov, juros, valor_prestacao, p1, poW, amortizacao, saldo_devedor, entrada = 0,juros_prest,totjur = 0; //orçamento em tabela price
int p, cont;	
	
	system("cls");
	system("color 06");
	
	printf("=========================================\n");
	printf("         TABELA PRICE         \n");
	printf("=========================================\n\n");
	
	
	printf("Valor do imóvel em R$: ");  //pede os dados necessários para fazer o orçamento
	scanf("%f", &valor_imov);
	printf("Entrada: ");
	scanf("%f",&entrada);
	printf("Juros: ");
	scanf("%f", &juros);
	printf("Prestações: ");
	scanf("%i", &p);
	system("cls");
	
	valor_imov-=entrada;  //valor do imóvel será subtraído pela entrada
	
	
	printf("=========================================\n");
	printf("           TABELA PRICE         \n");
	printf("=========================================\n\n");
	

	juros=juros/1000;  //transforma os dados coletados de maneira que o cálculo da prestacao possa ser feito de forma correta
	p1=1+juros;
	poW=pow(p1, p);
	valor_prestacao=(valor_imov*poW*juros)/(poW-1);
	
			for (cont=1;cont<=p;cont++)
			{
	        amortizacao=valor_prestacao-(valor_imov*juros);  //realiza os cálculos necessários para o financiamento
	        saldo_devedor=valor_imov-amortizacao;
	        juros_prest=valor_imov*juros;	
		 	valor_imov=valor_imov-amortizacao;
		 	printf("%i\º MES \n", cont);
			printf("Valor da prestação: %.2f\n", valor_prestacao);
			printf("Juros: %.2f\n", juros_prest);
			printf("Amortização: %.2f\n", amortizacao);
			printf("Saldo Devedor: %.2f\n\n", saldo_devedor);
			printf("-----------------------------\n");
			totjur+=valor_prestacao;
			}
			printf("\nTotal pago: %.2f\n",totjur);  //mostra valor pago ao término do financiamento
			
			
			system("pause");
			
			MenuGerente();
}






void SimularFinanciamentoCorretorSAC(){

system("cls");
	system("color 06");

	int par, i;
	float sald, amortiz, p[360], jur,juro, entr,totjuro = 0;  //p possui 360 valores, máximo de parcelas permitidas
	
	printf("-----------------------------------------\n");
	printf("             SAC         \n");
	printf("----------------------------------------- \n\n");
	
	printf("Valor do imóvel em R$: ");
	scanf("%f",&sald);
	printf("Entrada: ");
	scanf("%f",&entr);
	printf("Total parcelas: ");
	scanf("%i", &par);
	printf("Juros: ");
	scanf("%f",&jur);
	
		sald-=entr;  // o saldo devedor será subtraído pela entrada

	
	if(par>360){  //se o valor das parcelas for maior que 360, uma mensagem aparece para alertar o usuário
		printf("Máximo: 360 parcelas.\n");
		printf("Total parcelas: ");
		scanf("%i", &par);
		}
		else{  //se não, o orçamento é realizado
			
	amortiz = sald/par;  //calcula a amortização, que nesse sistema, é fixa, se da pela divisão do valor total do imóvel pela quantidade de parcelas
	juro=jur/1000;
	for(i=1; i<=par; i++){ // loop para mostrar o valor de cada parcela					
		p[i] = amortiz + sald*juro;
		sald = sald - amortiz; // armotização é o que abate o saldo devedor, depois do pagamento de cada parcela
		printf("\n%i°parcela: %.2f", i, p[i]);
		printf("\nAmortização: %.2f",amortiz);
		printf("\nJuros: %.2f\n",p[i]-amortiz);
		totjuro+=p[i]; //Acumula o valor de cada parcela
		printf("-----------------------------------------\n");
	}
	printf("\nTotal pago: %.2f\n",totjuro); // Valor pago pelo imóvel no final do financiamento
	}

	
system("pause");

MenuCorretor();
}

int SimularFinanciamentoCorretorPRICE()
{		
float valor_imov, juros, valor_prestacao, p1, poW, amortizacao, saldo_devedor, entrada = 0,juros_prest,totjur = 0; //orçamento em tabela price
int p, cont;	
	
	system("cls");
	system("color 06");
	
	printf("=========================================\n");
	printf("         TABELA PRICE         \n");
	printf("=========================================\n\n");
	
	
	printf("Valor do imóvel em R$: ");  //pede os dados necessários para fazer o orçamento
	scanf("%f", &valor_imov);
	printf("Entrada: ");
	scanf("%f",&entrada);
	printf("Juros: ");
	scanf("%f", &juros);
	printf("Prestações: ");
	scanf("%i", &p);
	system("cls");
	
	valor_imov-=entrada;  //valor do imóvel será subtraído pela entrada
	
	
	printf("=========================================\n");
	printf("           TABELA PRICE         \n");
	printf("=========================================\n\n");
	

	juros=juros/1000;  //transforma os dados coletados de maneira que o cálculo da prestacao possa ser feito de forma correta
	p1=1+juros;
	poW=pow(p1, p);
	valor_prestacao=(valor_imov*poW*juros)/(poW-1);
	
			for (cont=1;cont<=p;cont++)
			{
	        amortizacao=valor_prestacao-(valor_imov*juros);  //realiza os cálculos necessários para o financiamento
	        saldo_devedor=valor_imov-amortizacao;
	        juros_prest=valor_imov*juros;	
		 	valor_imov=valor_imov-amortizacao;
		 	printf("%i\º MES \n", cont);
			printf("Valor da prestação: %.2f\n", valor_prestacao);
			printf("Juros: %.2f\n", juros_prest);
			printf("Amortização: %.2f\n", amortizacao);
			printf("Saldo Devedor: %.2f\n\n", saldo_devedor);
			printf("-----------------------------\n");
			totjur+=valor_prestacao;
			}
			printf("\nTotal pago: %.2f\n",totjur);  //mostra valor pago ao término do financiamento
			
			
			system("pause");
			
			MenuCorretor();
}




void ListarPessoaFisica()
{
	system("cls");
	system("color 0D");
	if (!arquivo_existe("Clientes_Pessoa_Fisica.txt")) //verifica se o arquivo existe
	{
		printf("\nNão existe clientes cadastrados! ");
		system("pause");
		MenuCliente();
	}
		printf("Listagem de clientes\n"); 
	
	clientesPF = fopen("Clientes_Pessoa_Fisica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(clientesPF))
	{
		fscanf(clientesPF,"%s %s %s %s %s\n", cpf, nome, sobrenome, datanasc, email);
		printf("\n\nCPF: %s\nNome: %s %s\nData de nascimento:%s\nE-mail:%s\n\n ", cpf, nome, sobrenome, datanasc, email); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(clientesPF);
	
	
	
	MenuCliente();

	
	
}





void ListarPessoaFisicaCorretor()
{
	system("cls");
	system("color 0D");
	if (!arquivo_existe("Clientes_Pessoa_Fisica.txt")) //verifica se o arquivo existe
	{
		printf("\nNão existe clientes cadastrados! ");
		system("pause");
		MenuGerente();
	}
		printf("Listagem de clientes\n"); 
	
	arquivo = fopen("Clientes_Pessoa_Fisica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(arquivo))
	{
		fscanf(arquivo,"%s %s %s %s %s\n", cpf, nome, sobrenome, datanasc, email);
		printf("\n\nCPF: %s\nNome: %s %s\nData de nascimento:%s\nE-mail:%s\n\n ",cadnumimovel,cep,bairro,area); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(arquivo);
	
	
	
	MenuClienteCorretor();

	
	
}





void ListarPessoaJuridica()
{
	system("cls");
	system("color 0D");
	if (!arquivo_existe("Clientes_Pessoa_Juridica.txt")) // verifica se o arquivo existe
	{
		printf("\nNão existe clientes cadastrados! ");
		system("pause");
		MenuCliente();
	}
		printf("Listagem de clientes\n"); 
	
	clientesPJ = fopen("Clientes_Pessoa_Juridica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(clientesPJ))
	{
		fscanf(clientesPJ,"%s %s %s\n", cnpj, nomej, email);
		printf("\n\nCNPJ: %s\nNome: %s\nE-mail:%s\n\n ", cnpj, nomej, email); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(clientesPJ);
	
	
	
	MenuCliente();

	
	
}






void ListarPessoaJuridicaCorretor()
{
	system("cls");
	system("color 0D");
	if (!arquivo_existe("Clientes_Pessoa_Juridica.txt")) // verifica se o arquivo existe
	{
		printf("\nNão existe clientes cadastrados! "); // se não apresenta essa mensagem
		system("pause");
		MenuClienteCorretor(); // retorna ao meno
	}
		printf("Listagem de clientes\n"); 
	
	clientesPJ = fopen("Clientes_Pessoa_Juridica.txt","r"); // abre o arquivo em modo leitura
	
	while(!feof(clientesPJ))
	{
		fscanf(clientesPJ,"%s %s %s\n", cnpj, nomej, email);
		printf("\n\nCNPJ: %s\nNome: %s\nE-mail:%s\n\n ", cnpj, nomej, email); // exibir na tela
	}
	printf("Fim da listagem!\n\nEnter para voltar.");
	getchar();
	fclose(clientesPJ);
	
	
	
	MenuClienteCorretor();

	
	
}





int main () //função principal do pim
{
	setlocale(LC_ALL, "Portuguese");
	
	TipoLogin();
	
}
	
