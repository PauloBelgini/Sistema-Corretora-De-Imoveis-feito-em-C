#include <stdio.h>

FILE *arqimovel;
char desc_imv[500], nome_imv[50], cpf_imv[15],vend_alug[10],email_imv[50], contato_imv[25];
int opcao,id_imv;
float valor_imv;

// VARIAVEIS GLOBAIS

void tela_imovel()
{
	printf("=========================================\n");
	printf("              MENU IMOVEIS               \n"); //Titulo
	printf("=========================================\n\n");
	
	printf("(1) Incluir Imovel\n");
	printf("(2) Consultar Imovel\n");
	printf("(3) Alterar Imovel\n");
	printf("(4) Excluir Imovel\n");
	printf("(5) Listar Imoveis\n");	
	printf("(6) Voltar\n");
	printf("\nOpção: ");scanf("%i",&opcao);
	getchar();
}


void incluir_imo()
{	int cod_imv = 0;
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
	
	printf("\n Codigo de cadastro do imovel: > %i <",cod_imv); id_imv = cod_imv;
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
}

void consultar_imo()
{
	int chave;
	arqimovel = fopen("bd_imoveis_pim.txt", "r");
	printf("=========================================\n");
	printf("      CONSULTAR IMÓVEL\n"); //Titulo
	printf("=========================================\n\n");
		
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
}

void alterar_imo()
{
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

	printf("\n Novo codigo de cadastro do imovel: > %i <",cod_imv); id_imv = cod_imv; 
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

}

 excluir_imo()
{
	int chave;
	
	printf("=========================================\n");
	printf("      EXCLUSÃO DE CADASTRO DE IMÓVEL\n");
	printf("=========================================\n\n"); 
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
}

void exibir_imo()
{	
	float min, max;
	

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
}
	


