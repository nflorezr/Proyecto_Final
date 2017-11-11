#include<stdio.h>
#include <stdlib.h>

int i,j,sum,posicion,acu=0,win=0;
char Jugador1='X';
char matriz[3][3];
	
void FILL()
{
	sum=1;
	for (i=0;i<=2;i++)
	{	
		for (j=0;j<=2;j++)
		{
			matriz[i][j]=sum;
			sum++;
		}
	}
	for (i=0;i<=2;i++)
	{	
		for (j=0;j<=2;j++)
		{
			printf("%d  ",matriz[i][j]);
		}
		printf("\n\n");
	}
}

void input()
{
	printf("Ingresa la posicion que deseas poner una %c!\n\n",Jugador1);
	scanf("%d",&posicion);
	printf("\n-------");
	while (posicion>9 or posicion<1)
	{
		printf("La posicion debe de estar entre 1 y 9");
		scanf("%d",&posicion);
	}
}

void trick()
{
	if (posicion==1 and matriz[0][0]==1)
	{
		matriz[0][0]=Jugador1;
	}
	else if (posicion==2 and matriz[0][1]==2)
	{
		matriz[0][1]=Jugador1;
	}
	else if (posicion==3 and matriz[0][2]==3)
	{
		matriz[0][2]=Jugador1;
	}
	else if (posicion==4 and matriz[1][0]==4)
	{
		matriz[1][0]=Jugador1;
	}
	else if (posicion==5 and matriz[1][1]==5)
	{
		matriz[1][1]=Jugador1;
	}
	else if (posicion==6 and matriz[1][2]==6)
	{
		matriz[1][2]=Jugador1;
	}
	else if (posicion==7 and matriz[2][0]==7)
	{
		matriz[2][0]=Jugador1;
	}
	else if (posicion==8 and matriz[2][1]==8)
	{
		matriz[2][1]=Jugador1;
	}	
	else if (posicion==9 and matriz[2][2]==9)
	{
		matriz[2][2]=Jugador1;
	}
	else
	{
	printf("\nLa posicion ya esta tomada\n");
	}
}

void graph()
{
	printf("\n");
	for (i=0;i<=2;i++)
	{
		for (j=0;j<=2;j++)
		{
			if (matriz[i][j]==1 or matriz[i][j]==2 or matriz[i][j]==3 or matriz[i][j]==4 or matriz[i][j]==5 or matriz[i][j]==6 or matriz[i][j]==7 or matriz[i][j]==8 or matriz[i][j]==9)
			{
				printf("%d  ",matriz[i][j]);
			}
			else
			{
				printf("%c  ",matriz[i][j]);
			}
		}
		if (i!=2)
		{
			printf("\n\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("-------\n");
}

void Cambio()
{
	if (Jugador1=='X')
	{
		Jugador1='O';
	}
	else
	{
		Jugador1='X';
	}
}

void WIN()
{ //Horizontales 
	if (matriz[0][0]==matriz[0][1] and matriz[0][0]==matriz[0][2])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
	if (matriz[1][0]==matriz[1][1] and matriz[1][0]==matriz[1][2])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
	if (matriz[2][0]==matriz[2][1] and matriz[2][0]==matriz[2][2])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
//Ahora Verticales
    if (matriz[0][0]==matriz[1][0] and matriz[0][0]==matriz[2][0])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
	if (matriz[0][1]==matriz[1][1] and matriz[0][1]==matriz[2][1])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
	if (matriz[0][2]==matriz[1][2] and matriz[0][2]==matriz[2][2])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
//Ahora Diagonales
	if (matriz[0][0]==matriz[1][1] and matriz[0][0]==matriz[2][2])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
	if (matriz[0][2]==matriz[1][1] and matriz[0][2]==matriz[2][0])
	{
		printf("El jugador de la %c es el ganador!",Jugador1) ;
		win=1;
	}
}

void TIE()
{
	for (i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			if (matriz[i][j]=='X' or matriz[i][j]=='O')
			acu+=1;
		}
	}
	if (acu==9)
	{
		printf("Empate!");
		win=1;
	}
	else 
	{
		acu=0;
	}
}


int main()
{	
	system("cls");
	printf("A escogido tick tack toe!\n\n");
	FILL();
	while (1)
	{
		input();	
		trick();
		graph();
		WIN();
		if (win==1)
		{
			break;
		}
		TIE();
		if (win==1)
		{
			break;
		}
		Cambio();
	}	
}
