#include <stdio.h>

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 5; i++)
	{
	  for (int j = 1; j <= 3; j++)
	  	{
	  		for (int k = 1; k <= 5; k++)
	  		{
	  			printf("*");
	  		}
	  		printf("\n");
	  	}
	  	printf("\n");
	}
	return 0;
}
