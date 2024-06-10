/*
AUTOR ORIGINAL: Edgardo Adrián Franco Martínez (C) Septiembre 2012
AUTOR MODIFICADOR: EQUIPO DINO y EQUIPO 
VERSIÓN: 1.4

DESCRIPCIÓN: Ejemplo de atención de colas de clientes, ususaruiso y preferenciales en un banco, la simulación
de tiempo se reliza con la función Sleep(Solo funciona en Windows), cada X
tiempo llega un cliente y escoje por prioridad una cola y el tiempo 
de atención es Y.

OBSERVACIONES: Se puede emplear la libreria TADColaEst.h, TADPilaEstCir.h o TADColaDin.h implementadas
en clase. Ambas estructuras elemento, ya sea la de las implementaciónes estáticas o dinámica deberán 
tener un campo int n;

COMPILACIÓN: 	gcc -o Cajeras Cajeras.c TADCola/TADCola(Din|Est|EstCirc).o (Si se tiene el objeto de la implementación)
				gcc -o Cajeras Cajeras.c TADCola/TADCola(Din|Est|EstCirc).c (Si se tiene el fuente de la implementación)

EJECUCIÓN: Cajeras.exe (En Windows)
*/

//LIBRERAS
#include <stdio.h>
#include <windows.h>
#include <time.h>				//Funciona unicamente en Windows para usar la función Sleep()
//#include "TADCola/TADColaEst.h" 	//Si se usa la implemtentación dinámica (TADColaDin.c)
#include "TADColaDin.h" 	//Si se usa la implemtentación estática (TADColaEst.c|TADColaEstCirc.c)

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE	10		//Tiempo base en ms
#define MAX_PRE_CLI	5		//Tiempo maximos de preferentes y clientes antes de un usuario
#define VACIA 0				
#define OCUPADAP	1
#define OCUPADAC	2
#define OCUPADAU	3

int main(void)
{
	unsigned int tiempo = 0;
	unsigned int t_caja[10];
	unsigned int preferentes = 0;
	unsigned int cliente = 0;
	unsigned int usuarios = 0;

	int i,n,filas,p,c,u;
	int TIEMPO_ATENCION,TIEMPO_USUARIOS,TIEMPO_CLIENTE,TIEMPO_PREFERENTES;
	int cont=0; 
	elemento e;
	//Crear 3 colas preferentes '0', clientes '1', usuarios '2'
	cola fila[3];
	
	//Inicializar tres colas colas
	Initialize(&fila[0]); //preferentes
	Initialize(&fila[1]); //clientes 
	Initialize(&fila[2]); //usuarios
	
	
	printf("¿Cuantas cajas tiene abierto el banco? 'Un máximo de 10'\n");
	scanf("%d",&n);
	int caja[n];
	printf("Tiempo de atencion en milisegundos de cada cajero 'Solo múltiplos de 10'\n");
	scanf("%d",&TIEMPO_ATENCION);
	printf("Tiempo de atencion en milisegundos de llegada de los usuarios del banco 'Solo múltiplos de 10'\n");
	scanf("%d",&TIEMPO_USUARIOS);
	printf("Tiempo de atencion en milisegundos de llegada de los clientes del banco 'Solo múltiplos de 10'\n");
	scanf("%d",&TIEMPO_CLIENTE);
	printf("Tiempo de atencion en milisegundos de llegada de los preferentes del banco'Solo múltiplos de 10'\n");
	scanf("%d",&TIEMPO_PREFERENTES);
	
	
	for (i=0;i<n;i++) //RELLENAMOS LAS CAJAS EN VACIAS y sus tiempos de atencion en 0
	{
		caja[i]=VACIA;
		t_caja[i]=0;
	}
	//Ciclo infinito
	while (1)
	{
		Sleep(TIEMPO_BASE);		//Esperar el tiempo base
		tiempo++;				//Incrementar el contador de tiempo
		//Si el tiempo es multiplo del de llegada de los clientes
		if (tiempo % TIEMPO_CLIENTE == 0)
		{
			cliente++;				//Incrementar el numero de clientes
			e.n = cliente;			//Dar el numero que identifica al cliente		
			Queue(&fila[1], e);		//Formarse en la fila seleccionada
			printf("\n\n\nLlego el cliente: %d a la cola de la fila de clientes", e.n);
		}
		if (tiempo % TIEMPO_USUARIOS == 0)
		{
			usuarios++;				//Incrementar el numero de usuarios
			e.n = usuarios;			//Dar el numero que identifica al usuario		
			Queue(&fila[2], e);		//Formarse en la fila seleccionada
			printf("\n\n\nLlego el usuario: %d a la cola de la fila de usuarios", e.n);
		}
		if (tiempo % TIEMPO_PREFERENTES == 0)
		{
			preferentes++;				//Incrementar el numero de preferentes
			e.n = preferentes;			//Dar el numero que identifica al preferente		
			Queue(&fila[0], e);		//Formarse en la fila seleccionada
			printf("\n\n\nLlego el preferente: %d a la cola de la fila de preferentes", e.n);
		}
		
		//Mostrar los clientes en cada cola
		printf("\n\n%d usuarios en la fila de usuarios: [",Size(&fila[2]));
		for (i=1;i<=Size(&fila[2]);i++)
		{
			e=Element(&fila[2],i);
			printf("%d\t", e.n);
		}
		printf("]");
		
		
		printf("\n\n%d clientes en la fila de clientes: [",Size(&fila[1]));
		for (i=1;i<=Size(&fila[1]);i++)
		{
			e=Element(&fila[1],i);
			printf("%d\t", e.n);
		}
		printf("]");
		
		printf("\n\n%d preferentes en la fila de preferentes: [",Size(&fila[0]));
		for (i=1;i<=Size(&fila[0]);i++)
		{
			e=Element(&fila[0],i);
			printf("%d\t", e.n);
		}
		printf("]");
		//PASAMOS A LAS CAJAS
		for(i=0;i<n;i++)
		{
			if (caja[i]==VACIA)
			{
				if ((!Empty(&fila[0])) && (cont<MAX_PRE_CLI)) //si la fila de preferentes tiene elementos y su contador de atencion es 
				{
					e=Dequeue(&fila[0]);//La caja atendera al cliente de la fila de preferentes
					caja[i]=OCUPADAP; //la caja estara ocupada con ese preferente
					p=e.n;
					printf("\n La caja %d esta ocupada con el preferencial %d \n",i+1,p);
					cont++;
				}
				else if((!Empty(&fila[1])) && (cont<MAX_PRE_CLI))// si la fila de clientes tiene elementos
				{
					e=Dequeue(&fila[1]);//La caja atendera al cliente de la fila de clientes
					caja[i]=OCUPADAC; //la caja estara ocupada con ese cliente
					c=e.n;
					printf("\n La caja %d esta ocupada con el cliente %d \n",i+1,c);
					cont++;
				}
				else if(!Empty(&fila[2]))// si la fila de ususarios tiene elementos
				{
					e=Dequeue(&fila[2]);//La caja atendera al cliente de la fila de ususario
					caja[i]=OCUPADAU; //la caja estara ocupada con ese usuario
					u=e.n;
					printf("\n La caja %d esta ocupada con usuario %d \n",i+1,u);
					cont=0;
				}
				else 
				{
					printf("\n La caja %d esta sin ningun cliente porque no hay nadie formado\n",i+1);
				}
			}  
			else if (caja[i]==OCUPADAU)
			{
				printf("\n\nLa caja %d esta ocupada con el usuario %d \n",i+1,u);
			}
			else if (caja[i]==OCUPADAC)
			{
				printf("\n\nLa caja %d esta ocupada con el cliente %d \n",i+1,c);
			}
			else if (caja[i]==OCUPADAP)
			{
				printf("\n\nLa caja %d esta ocupada con el preferencial %d \n",i+1,p);
			}
		}
		//Para vaciar la caja despues del tiempo de atencion
		for(i=0;i<n;i++)
		{
			if (caja[i]==OCUPADAC || caja[i]==OCUPADAP || caja[i]==OCUPADAU)
			{
				t_caja[i]++;
				if (t_caja[i] % TIEMPO_ATENCION == 0)
				{
					caja[i]=VACIA;
				}
			}
		}
	}
	return 0;
}
