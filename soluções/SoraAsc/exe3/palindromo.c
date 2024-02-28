#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int verificar_palindromo(char *str, int start, int end);
void remover_caracteres(char *str);

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	char string_test[] = "Á. grama,. é amarga,.,";
	remover_caracteres(string_test);
	printf("\nString Modificada: %s\n", string_test);
	
	int v = verificar_palindromo(string_test, 0, strlen(string_test)-1);
	if(v == 1) printf("E um Palindromo");
	else printf("Nao e um Palindromo");
	
	return 0;
}

int verificar_palindromo(char *str, int start, int end)
{
	if( (start == end) || (abs(start-end) == 1 && str[start] == str[end]) ) return 1;
	else if(str[start] == str[end]) return verificar_palindromo(str, start+1, end-1);
	return 0;
}

char trocar_caracteres_especiais(char letter)
{
	switch(letter)
	{
		case 'á': case 'à': case 'ã': case 'â': case 'ä': return 'a';
		case 'é': case 'è': case 'ê': case 'ë': return 'e';	
		case 'í': case 'ì': case 'î': return 'i';
		case 'ó': case 'ò': case 'õ': case 'ô': case 'ö': return 'o';
		case 'ú': case 'ù': case 'û': case 'ü': return 'u';
		case 'ç': return 'c';
		default: return letter;
	}
}

void remover_caracteres(char *str)
{
	int i = 0, str_index = 0;
	int str_len = strlen(str);
	char* temp_str = (char *)malloc((str_len + 1) * sizeof(char));
	while(i < str_len)
	{
		if(str[i] != ' ' && str[i] != '.' && str[i] != ',')
		{
			temp_str[str_index] = trocar_caracteres_especiais(tolower(str[i]));
			str_index++;
		}
		i++;
	}
	temp_str[str_index] = '\0';
	strcpy(str, temp_str);
	free(temp_str);
}