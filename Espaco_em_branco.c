#include <stdio.h>


// FUNÇÃO PARA TIRAR E COLOCAR OS ESPAÇOS DOS TEXTOS DIGITADOS
void TirarEspaco(char texto[]) 
{
	int i;
    for (i=0;i<strlen(texto);i++)
    {
		if (texto[i]==' ')
		{
			texto[i]='+';
		}
	}
}

void ColocarEspaco(char texto[]) 
{
	int i;
	for (i=0;i<strlen(texto);i++)
	{
		if (texto[i]=='+')
		{
			texto[i]=' ';
		}
	}
}
