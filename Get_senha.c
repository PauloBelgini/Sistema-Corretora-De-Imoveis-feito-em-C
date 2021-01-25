
// FUNÇÃO PARA TORNAR A SENHA DIGITADA CODIFICADA COM O CARACTERE DESJADO

void getSenha(char *senha, char caractere,int tam)
{	
    
	int c = 0;
    char letra='\0';  
    
    while(letra!=13)
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
					printf("%c", caractere);
					senha[c] = letra;
					c++;
				}
				break;
    	}
	}
    
	senha[c] = '\0';
    
    
}
