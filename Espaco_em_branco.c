#include <stdio.h>


// FUN��O PARA TIRAR E COLOCAR OS ESPA�OS DOS TEXTOS DIGITADOS
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
