#include "program.h"
#include <stdio.h>
void bss(int ascii)
{
	char base[] = "01";
	char bin[8];
	int i = 0;
    char c;

	if (ascii < 2)
		printf("%c", base[0 + ascii]);
	else
	{
        
		bss(ascii / 2);
		printf("%c",base[ascii % 2]);
	}
	i++;
}

int main()
{
    bss('a');
}