#include <stdio.h>
#include <stdlib.h>

int main()
{
	int op;
	printf ("MENU:\n");
	printf ("1 - Tres en Linea\n");
	printf ("2 - Adivinanza\n");
	printf ("3 - Concentrese\n");
	scanf("%d",&op);
	switch (op)
	{
		case 1:
			system("TrickTrackToe.exe");
			break;
		case 2:
			system("Adivina.exe");
			break;
		case 3:
			system("Concentrese.exe");
			break;
		default:
			printf("Error");
			break;
	}
}
