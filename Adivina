#include<stdio.h>
#include<string.h>
#include<time.h> //Esta libreria es para que el sistema me pueda generar el numero
#include<stdlib.h> //Esta libreria es para poder usar la función system


int main()
{
	system("cls");
	system("color 3f"); //Esta linea es para cambiar el color de la terminal
	int i,j,ale,num,res;
	int vect[4];
	int vect2[4];
	int intentos=0;
	int posi=0;
	int coin=0;
	
    srand(time(NULL)); //Genera el numero aleatorio
	for(i=0;i<4;i++) //Este ciclo es para exeptuar los ceros y que no repita un digito
	{
		ale=1+rand()%((10)-1);
		for(j=0;j<i;j++)
		{
			while(ale==vect[j])
			{
				ale=1+rand()%((10)-1);
				j=0;
			}
		}
		vect[i]=ale;
	}
	
	printf("\n\nPresiona 1 para comenzar\n");
	scanf("%i",&res);
	
	while(res==1) //Comienzan las condiciones y bucles
	{
		printf("\nIngrese un numero de cuatro digitos, uno por uno sin repetir numero\n");
	    
	    coin=0;
	    posi=0;
	    
	    for(i=0;i<4;i++) //Pedir los digitos
	    {
		   scanf("%i",&vect2[i]);
	    }
	
	    for(i=0;i<4;i++) //Recorre e ingresa los numeros digitados por teclado
	    {
		   for(j=0;j<4;j++)
		   {
			  if(vect[i]==vect2[j]) //Compara haber si el numero ingresado esta en alguna posicion del vector aleatorio
			  {
			    coin=coin+1; //Si se cumple suma a la variable coincide
			  }
			  
		   }
		   
		   if(vect[i]==vect2[i]) //Compara si el numero ingresado esta en la misma posicion que el vector aleatorio
		   {  
			 posi=posi+1; //Si se cumple suma a la variable posicion
		   }  
	    }
	    
		if(posi==4) //Si gano
	    {
		   printf("¡¡¡ Felicidades, Adivinaste !!!\n");
		   res=0;
	    }
	    else //Si no
	    {
		   if((posi<4)&&(coin>0))
		   {
			  	intentos=intentos+1;
			  	printf("Casi,sigue intentando, llevas %i intentos\n",intentos);
			  	printf("Tienes %i digitos en la misma posicion\n",posi);
			 	printf("Tienes %i digitos iguales pero no en la posicion correcta\n",coin);
				printf("Deseas seguir intentadolo?, 1=SI - 0=NO\n");
	    		scanf("%i",&res);
		   } 
		   else if((posi<4)&&(coin=0))
		   {
				intentos=intentos+1;
			    printf("Casi,sigue intentando, llevas %i intentos\n",intentos);
			    printf("Tienes %i digitos en la misma posicion\n",posi);
			    printf("No tienes numeros iguales");
				printf("Deseas seguir intentadolo?, 1=SI - 0=NO\n");
	    		scanf("%i",&res);	
		   }  
	    }
	}
	printf("Hasta pronto\n");
}
