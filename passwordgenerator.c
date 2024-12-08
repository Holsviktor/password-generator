#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#define CHARSET_ASCII "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
#define CHARSET_WEIGHTED "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz{|}~[\\]^_`!\"#$%&'()*+,-./01234567890123456789:;<=>?@"
#define USAGE "Usage: pgen {charactercount}\n"
#define CURRENT_CHARSET CHARSET_WEIGHTED
int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf(USAGE);
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < strlen(argv[1]); i++)
	{
		char currentChar = argv[1][i];
		if (!(currentChar <= '9' && currentChar >= '0'))
		{
			printf("Found non-digit %c\n", currentChar);
			printf(USAGE);
			exit(EXIT_FAILURE);
		}
	}

	errno = 0;
	long passwordLength = strtol(argv[1], NULL, 10); 
	if (errno != 0 || passwordLength == 0)
	{
		printf("Invalid number\n");
		exit(EXIT_FAILURE);
	}
	srand(time(NULL));
	int maxNumber = strlen(CURRENT_CHARSET) - 1;
	char currentChar;
	for (int i = 0; i < passwordLength; i++)
	{
		currentChar = CURRENT_CHARSET[rand() % maxNumber];
		printf("%c", currentChar);
	}
	printf("\n");
	return 0;
}
