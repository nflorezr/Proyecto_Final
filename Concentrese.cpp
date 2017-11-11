#include<iostream>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

bool Ver(int num,int vector[])
{
	int i;
	for(i=0;i<16;i++)
	{
		if(num==vector[i])
		{
			return true;
		}
	}
	return false;
}

void inicio(string* j1); //DECLARAMOS FUNCION INICIO LA CUAL RECIBE DOS APUNTADORES COMO PARAMETROS
void over (void); //DECLARAMOS FUNCION OVER VACIA Y SIN PARAMETROS

class Jugador //CLASE PARA JUGADORES
{
	private: //DOS ATRIBUTOS PRIVADOS
		int puntos;
		string Nombre;
	public: //CUATRO METODOS PUBLICOS
		void In_Pun(int);
		int Out_Pun(void);
		void In_Nom(string);
		string Out_Nom(void);
};

void Jugador::In_Pun(int P) //METODO PARA AUMENTAR 1 A LA CANTIDAD DE PUNTOS DEL JUGADOR
{
	if(P==5)
	{
		puntos=puntos+5;	
	}
}
int Jugador::Out_Pun() //REPORTA CANTIDAD DE PUNTOS DEL JUGADOR
{
	return(puntos);
}

void Jugador::In_Nom(string N) //PARA INGRESAR UN NOMBRE AL JUGADOR
{
	Nombre=N; //TOMA UNA CADENA N Y LA HACE EL ATRIBUTO NOMBRE
}
string Jugador::Out_Nom(void) //REPORTA EL NOMBRE DEL JUGADOR
{
	return(Nombre);
}

int main()
{ //BASE DE DATOS NECESARIA
	system("cls");
	string Numeros[]={"","1","2","3","4","5","6","7","8","1","2","3","4","5","6","7","8"};
	string NewAni[17]; //AQUI SE ALMACENAN LOS NUMEROS REVUELTOS
	string Posicion[]={"","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"};
	int Ale[17];
	int NumA; //VARIABLES DE AUXILIO Y CONTADORES
	srand(time(0)); //VARIABLES DE AUXILIO Y CONTADORES
	string AuxP,AuxS; //VARIABLES DE AUXILIO Y CONTADORES
	int i=0,P,S,p; //VARIABLES DE AUXILIO Y CONTADORES
	int rep; //VARIABLES DE AUXILIO Y CONTADORES
	int pares=0; //VARIABLES DE AUXILIO Y CONTADORES
	int PJ1=0, Err=0; //VARIABLES DE AUXILIO Y CONTADORES
	string NJ1; //VARIABLES DE AUXILIO Y CONTADORES
	int ocupados[17]={0}; //VARIABLES DE AUXILIO Y CONTADORES
	int z=1,r=0,yaesta=0; //VARIABLES DE AUXILIO Y CONTADORES
	
	Jugador Jug_1;  //CREAMOS DOS OBJETOS DE LA CLASE JUGADORES
	inicio(&NJ1); //INVOCAMOS FUNCION INICIO
	Jug_1.In_Nom(NJ1); //INTRODUCIMOS LAS CADENAS DE NOMBRE PARA JUGADOR 1 Y 2
	
	Sleep(1000); //DISEÑO DE VISUALIZACION
	
	Ale[0]=0;
	for(i=1;i<17;i++)
	{
		NumA=1+rand()%(17-1); //GENERAMOS NUMEROS ALEATOREOS
		while (Ver(NumA,Ale)==true)	
		{
			NumA=1+rand()%(17-1);
		}
		Ale[i]=NumA;
	}
	
	cout<<"\n\n\n";
	for (i=0;i<17;i++) //MEDIANTE UN CICLO
	{
		NewAni[i]=Numeros[Ale[i]]; //ALMACENAMOS LOS NUMEROS EN BASE A LOS NUMEROS ALEATORIOS  EN UN NUEVO ARREGLO
	}
	cout<<"\n\n";
	i=1;
	
	while(i<=16) //CICLAMOS OTRA VEZ
	{
		cout<<" \t"<<Posicion[i]; //IMPRIMIMOS EN PANTALLA LAS POSICIONES DE LOS NUMEROS
		if(i==4 || i==8 || i==12 || i==16)cout<<"\n\n\n"; //CADA VEZ QUE NUESTRO CONTADOR A LLENADO UN RENGLON CON 4, AGREGAMOS UN SALTO 
		i++;
	}
	
	Err=0;
	//Err<3	
	
	while(Err<3) //CONDICIONAMOS UN CICLO QUE SE COMPLETA CUANDO LOS 8 PARES HAN SIDO ENCONTRADOS
	{
		cout<<"\n\n";
		if(Err<3) //COMPROBAMOS SI EL CONTADOR TURNO ES PAR O NON (SE INICIALIZO EN PAR)
		{
			cout<<"Tienes "<<Err<<" Errores"; //SI ES PAR TOCA EL JUGADOR 1
		}
		cout<<"\nEscoge 2 numeros que quieres:\nN1:"; //PEDIMOS AL USUARIO DOS NUMEROS
		cin>>P;
		cout<<"\nN2:";
		cin>>S;
		
		for(r=0;r<=z;r++) //MEDIANTE UN CICLO
		{
			if(ocupados[r]==P||ocupados[r]==S) //COMPROBAMOS SI LOS NUMEROS SELECCIONADOS NO HAN SIDO INTRODUCIDOS YA
			{
				yaesta=1; //SI YA HAN SIDO INTRODUCIDOS, LEVANTAMOS UNA BANDERA
			}
		}
		
		system("cls"); //LIMPIAMOS PANTALLA
		rep=1;
		while(rep==1)
		{
			if(P==S || P>17 || P<1 || S>17 || S<1 || yaesta==1) //COMPROBAMOS MEDIANTE UN IF SI LOS NUMEROS SELECCIONADOS NO HA SIDO HECHOS
			{
				cout<<"\nERROR AL INTRODUCIR LOS DATOS\nIngresa otros 2:\n\n"; //VOLVEMOS A PEDIR NUEVOS NUMEROS AL USUARIO
				cout<<"N1:";
				cin>>P;
				cout<<"\nN2:";
				cin>>S;
				system("cls");
				yaesta=0;
			}
			else //EL CICLO SE REPITE HASTA QUE SE INTRODUZCAN DOS NUMEROS NO REPETIDOS EN LOS PARES QUE YA HAN SIDO HECHOS
			{
			rep=2;
			} 
		}
		if(NewAni[P]==NewAni[S]) //SI LAS CADENAS DE LOS NUMEROS SELECCIONADOS FORMAN UN PAR
		{
			ocupados[z]=P; //ALMACENAMOS LOS NUMEROS USADOS EN UN ARREGLO, DICHOS NUMEROS SE ALMACENAN EN EL ORDEN QUE HAYA SIDO SELECCIONADOS
			ocupados[z+1]=S;
			z+=1;
			
			pares=pares+1; //SE SUMA UNO A LA CANTIDAD DE PARES EXISTENTES
			Jug_1.In_Pun(5);
			
			system("cls"); //LIMPIAMOS LA PANTALLA
			cout<<"\n\n\tCORRECTO!!\n\n"; //FELICITAMOS AL USUARIO
			Posicion[P]=NewAni[P]; //CAMBIAMOS LOS NUMEROS QUE SE HALLAN ENCONTRADO POR SU IMAGEN EN LA POSICION
			Posicion[S]=NewAni[S];
			i=1;
			cout<<"\n";
			while(i<=16) //MEDIANTE UN CICLO IMPRIMIMOS NUEVAMENTE LAS POSICIONES, AHORA MUESTA LOS PARES QUE YA SE HAN ENCONTRADO
			{
				cout<<"\t"<<Posicion[i];
				if(i==4 || i==8 || i==12 || i==16)cout<<"\n\n\n";
				{
					i++;	
				}	
			}
		}
		else //SI NO FORMAN PAR LOS NUMEROS EN LAS POSICIONES SELECCIONADAS
		{
			Err++;
			AuxP=Posicion[P]; //GUARDAMOS EN UN AUXILIAR LAS POSICIONES SELECCIONADAS
			AuxS=Posicion[S];
			Posicion[P]=NewAni[P]; //CAMBIAMOS LAS POSICIONES POR LOS NOMBRES PARA DESPUES
			Posicion[S]=NewAni[S];
			i=1;
			cout<<"\n";
			while(i<=16) //MEDIANTE UN CICLO
			{
				cout<<"\t"<<Posicion[i]; //MOSTRAMOS AL USUARIO QUE NUMERO SELECCIONO Y QUE NO HACEN PAR 
				if(i==4 || i==8 || i==12 || i==16)cout<<"\n\n\n";
				i++;
			}
			Posicion[P]=AuxP; //REGRESAMOS LAS POSICIONES QUE NO HAN HECHO PAR A SU "TAPA" ORIGINAL
			Posicion[S]=AuxS;
			Sleep(2000); //TIEMPO QUE TIENE EL USUARIO PARA VER SU ERROR
			system("cls"); //VOLVEMOS A LIMPIAR LA PANTALLA
			i=1;
			while(i<=16)
			{
				cout<<"\t"<<Posicion[i]; //VOLVEMOS A MOSTRA EL TABLERO CON LAS TAPAS RESTANTES Y LOS PARES ENCONTRADOS
				if(i==4 || i==8 || i==12 || i==16)cout<<"\n\n\n";
				i++;
			} 	//FINAL DEL JUEGO LOS PARES HAN LLEGADO A 8	
		}
		cout<<"\n"<<Jug_1.Out_Nom()<<" tu puntaje es: "<<Jug_1.Out_Pun(); //MOSTRAMOS CUANTOS PUNTOS TIENE CADA JUGADOR
	}
	Sleep(2000); //ESPERAMOS UN POCO
	system("cls");
	for(p=0;p<10;p++) //IMPRIMIMOS UN BONITO ANUNCIO DE FIN DEL JUEGO
	{
		Sleep(500);
		cout<<"Hiciste "<<pares<<" pares\n";
		over();
		Sleep(500);
		system("cls");
	}
}
	
void over(void) //FUNCION QUE DESPLIEGA EL ANUNCIO DE FIN DE JUEGO
	{
		cout<<"Tienes 3 errores";
		cout<<"\t\n*****  *****  *     *  *****  *****  *   *  *****  *****\n";
		cout<<"*      *   *  **   **  *      *   *  *   *  *      *   *\n";
		cout<<"*  **  *****  *  *  *  *****  *   *  *   *  *****  *****\n";
		cout<<"*   *  *   *  *     *  *      *   *   * *   *      *  * \n";
		cout<<"*****  *   *  *     *  *****  *****    *    *****  *   *\n";
	}
	
void inicio (string* j1) //FUNCION DE INICIO DEL JUEGO
	{
		//IMPRIMIMOS LA BIENVENIDA	
		cout<<"****  ****  ****  *   *  *  *  ****  *   *  ****  ***   ****  ****\n";
		cout<<"*   *  **   *     **  *  *  *  *     **  *   **   *  *  *  *  *   \n";
		cout<<"****   **   ****  * * *  *  *  ****  * * *   **   *  *  *  *  ****\n";
		cout<<"*   *  **   *     *  **  *  *  *     *  **   **   *  *  *  *     *\n";
		cout<<"****  ****  ****  *   *   **   ****  *   *  ****  ***   ****  ****\n";
		
		Sleep(1000);
		cout<<"\n\n\n\n\t\t\t\tNOMBRE JUGADOR: "; //PEDIMOS LOS NOMBRES DE LOS JUGADORES
		cin>> *j1; //POR MEDIO DE APUNTADORES LOS ALMACENAMOS EN VARIABLES LOCALES EN EL MAIN
		
		cout<<"\n\n\n\t\t";
		system("PAUSE"); //ESPERAMOS A QUE EL USUARIO ESTE LISTO PARA CONTINUAR
		system("cls"); //LIMPIAMOS PANTALLA
	}
