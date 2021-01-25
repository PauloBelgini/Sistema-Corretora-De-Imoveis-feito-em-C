// FUNÇÃO PARA LIMITAR A QUANTIDADE DE CARACTERES INSERIDOS PARA O CAMPO EM QUE A FUNÇÃO FOR CHAMADA

void scanfsmax(char *valor, int tam)
{
		
	int c=0;
	char letra='\0';
	
	while(letra!=13) // sai quando da enter
	{
		letra = getch();

		switch(letra)
		{
			case 8: //backspace
				
				if(c>0) // se chegou no zero, n?o volta mais
				{
					// volta, limpar o caracter e volta de novo
					printf("%c%c%c", letra, 32, letra);
					c--;
				}
				
				break;

			case 13: //enter
				printf("\n"); // pula linha
			    break;

			default:
				if (c<(tam-1)) // se não tem mais espa?o, ignora
				{
					printf("%c", letra);
					valor[c] = letra;
					c++;
				}
				break;
		}

	}

	valor[c]='\0';
}
