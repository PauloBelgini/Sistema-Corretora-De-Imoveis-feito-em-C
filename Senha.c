#include <stdio.h>

int numsenha;

void cadastrar_user()
{
	char nome_user[50], login_user[10], senha_user[9],senha_vald[9], senha1[9],login1[10], Glogin[10], Gsenha[9];
	int id_user,cod_user = 0,c=4,i=0,div;
	FILE *arquivosenha,*arquivosenhapai;
	//int sair=0;
	
	printf("=========================================\n");
	printf("          CADASTRO DE NOVO USUARIO       \n"); 
	printf("=========================================\n\n");
	
	printf("	===>Para cadastro de novo usuario, necessario acesso do Administrador<===\n\n");
	
	printf("Login: "); scanfsmax(Glogin,10); // SOLICITA AO USUARIO LOGIN E SENHA, ABRINDO O ARQUIVO E COMPARANDO COM DO ARQUIVO PARA DAR ACESSO A DEMAIS ETAPAS
	printf("Senha: "); getSenha(Gsenha,'*',9);
	
	arquivosenhapai = fopen("bd_senha_pai_pim.txt","r");
	

	
	while(!feof(arquivosenhapai)){
		fscanf(arquivosenhapai,"%i %s %s %s\n", &id_user,nome_user, login1, senha1);
		if(strcmp(Glogin,login1)==0 && strcmp(Gsenha,senha1)==0)
			{	fclose(arquivosenhapai);system("cls"); 
			
				arquivosenha = fopen("bd_senha_pim.txt","r");
				while(!feof(arquivosenha))
				{
				fscanf(arquivosenha,"%i %s %s %s\n",&id_user,nome_user, login1, senha1);
				}				
				fclose(arquivosenha);
				
				cod_user = id_user + 1; //ABRE O ARQUIVO EM MODO LEITURA PARA PARA PEGAR  O ULTIMO CODIGO CADASTRADO PARA SER INCREMENTADO O PROXIMO
				id_user = cod_user;
			
				senha_user[0] = 'E'; senha_vald[0] = 'S'; // VARIAVEIS PARA VALIDAR AS SENHAS QUE PEDIMOS PARA O USER ESTEJAM IGUAIS, FAZENDO ENTRAR E SAIR DO LOOP
			
				while(strcmp(senha_user,senha_vald)!=0)
				{
	
				printf("=========================================\n");
				printf("          CADASTRO DE NOVO USUARIO       \n");
				printf("=========================================\n\n"); // SOLICITA OS DADOS DO NOVO CADSTRO PARA O USER
			
				printf("\n Insira o nome completo do usuario: "); scanfsmax(nome_user,50);
				//printf("\n Insira o login desejado: "); scanfsmax(login_user,10);
				printf("\n Insira a senha: "); getSenha(senha_user,'*',9);
				printf("\n Confirme a senha: "); getSenha(senha_vald,'*',9); // CHECA SE AS SENHAS CONFEREM PARA PODER SAIR DO LOOP CITADO
				
				if(strcmp(senha_user,senha_vald)!=0)
				{
				printf("\n\t\t\t Senhas não conferem, digite novamente!");getch();
				system("cls");
				}
				}	// NESTA PARTE SERA GERADO O LOGIN PARA USER COM 3 PRIMEIRAS LETRAS DO NOME JUNTO AO "_" E O NUMERO DO CODIGO CADASTRADO						
				
				login_user[0] = nome_user[0];
				login_user[1] = nome_user[1];
				login_user[2] = nome_user[2];
				login_user[3] = '_';
				
				
				if(id_user < 10)
				{			// VERIFICA SE O CODIGO É MENTO QUE 10 PARA PODER SER CONVERTIDO UM int em string USANDO A TABELA ASCII
				login_user[4] = cod_user + 48;
				login_user[5] = '\0';
				} 
					else 
					{	div = cod_user;
						while(div>0)
						{
							div= div/10; //TRANFORMA UM NUMEOR MAIOR QUE 10 PARA QUE POSSA SER CONVERRIDO EM string INDIVIDUALMENTE E CONTA QUANTOS NUMEROS SERÃO
							i++;
						}
						
						while(cod_user>0) // COMO A FUNÇÃO TRAZ INVERTIDO O NUMERO A FUNÇÃO COM AUXILIO DA QTD DE NUMERO QUE FOI DADO, INVERTE O NUMEROS PARA QUE APAREÇA NA SEQUENCIA CORRETA NO LOGIN
						{
							
						i--;
					 	login_user[4+i] = (cod_user%10) + 48;		 	
					 	cod_user= cod_user/10;	
						c++; 	 	
					 	}
					 	
						login_user[c] = '\0';						
					}	
				
				arquivosenha = fopen("bd_senha_pim.txt", "a+"); // ABRE E SALVA O NOVO CADATRO E PRINTA NA TELA OS DADOS USER E SENHA DO USUARIO CADASTRADO
				TirarEspaco(nome_user);
				fprintf(arquivosenha,"%i %s %s %s\n", id_user,nome_user, login_user, senha_user);
				fclose(arquivosenha);
				printf("\n=========================================\n");
				printf("\n    Usuario cadastrado com sucesso!!     \n");
				printf("\n Login: %s                               \n",login_user);
				printf("\n Senha: %s                               \n",senha_user);
				printf("\n=========================================\n\n");
				printf("\n\t\t\t Pressione qualquer tecla para continuar");getch();
				system("cls");
				login_senha();
				return;
			}
		}
		 
			fclose(arquivosenhapai);
			printf("\n\t\t\tLogin/senha incorreto(s) - Pressione ENTER para continuar");getch();
			system("cls");
			cadastrar_user();
}


void login_senha(){
	
	char login[10],login1[10], nome_user[50];
	char senha[9],senha1[9];
	int opcao, id_user,entrar=0;
	FILE *arquivosenha;

	printf("=========================================\n");
	printf("              INCIO AO SISTEMA           \n"); // SOLICITA AO USUARIO O LOGIN E SENHA 
	printf("=========================================\n\n");

printf("	===>Para iniciar o sistema informe o acesso<===\n\n");

	printf("Login: "); scanfsmax(login,10);
	printf("Senha: "); getSenha(senha,'*',9); 
	
	arquivosenha = fopen("bd_senha_pim.txt","r");
	
	while(!feof(arquivosenha)){
		fscanf(arquivosenha,"%i %s %s %s\n",&id_user,nome_user, login1, senha1); // ABRE O ARQUIVO PARA VALIDAR A SENHA 
		if(strcmp(login,login1)==0 && strcmp(senha,senha1)==0)
			{	
				system("cls");
				ColocarEspaco(nome_user);
				printf("BEM VINDO %s!\n\n",nome_user);
				numsenha = 1;
				main();
				return;
			}
			
		}
		
	fclose(arquivosenha);
	
	
	system("cls");
	printf("=========================================\n");
	printf("              INCIO AO SISTEMA           \n");
	printf("=========================================\n\n"); // CASO NÃO VALIDE A SENHA ABRE A TELA COM OPÇÃO PARA DIGITAR NOVAMENTE OU CADASTRO NOVO USER CHAMANDO A FUNCÃO JÁ CITADA
	
	printf("	===>Login/senha incorreto(s) ou usurio nao cadastrado<===\n\n");
	printf("(1) Digitar novavemente dados\n");
	printf("(2) Cadastrar novo usuario\n\n");
	printf("Opcao: "); scanf("%i",&opcao);getchar();
	
	switch(opcao)
			{
				case 1: 
				system("cls");
				login_senha();				
				break;
				
				case 2: 
				system("cls");
				cadastrar_user();
				break;
				
				default: system("cls"); login_senha();
				break;
			}
	
}
