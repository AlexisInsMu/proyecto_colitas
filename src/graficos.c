/*
Autor: Edgardo Adri�n Franco Mart�nez
Versi�n 1.1 (02 de Octubre de 2013)
Descripci�n: Cabecera de la libreria para recrear presentaciones m�s agradables al usuario en el modo consola bajo Windows
Observaciones: Esta implementaci�n de la libreria solo es compatible con Windows y el compilador MinGW ya que utiliza la libreria "windows.h", la cu�l no es estandar.
Compilaci�n de la libreria: Windows (gcc -c presentacionWin.c)
*/
//LIBRERIAS
#include <windows.h>
#include "graficos.h"
#include "estilos.h"
#include <stdio.h>
#include <wchar.h>

//DEFINICI�N DE CONSTANTES
#define ALTO 24			//Se piensa en un pantalla de 24 filas x 79 columnas
#define ANCHO 79


#define TIEMPO_BASE 1	//
position_t posiciones_menu[4] = {{15, 12}, {15, 14}, {15, 16}, {15, 20}};


//DEFINICI�N DE FUNCIONES

//Funci�n para mover el cursor de escritura de pantalla, simulaci�n de la funci�n gotoxy() que se tenia en borland 3.0 en la libreria conio.h
void MoverCursor( int x, int y ) 
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y }; 
	SetConsoleCursorPosition( hStdout, position );
	return;
};

//Funci�n para esperar un tiempo en milisegundos, simulaci�n de la funci�n delay() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int t)
{
	Sleep(t);
	return;
}

//Funci�n para borrar la pantalla de la consola, simulaci�n de la funci�n clrscr() que se tenia en borland 3.0 en la libreria conio.h
void BorrarPantalla(void)
{
	system("cls");
	return;
}

void dibujar_presentacion(estilos_t estilo)
{
	int i;
	BorrarPantalla();
	for(i = 0; i < estilo.height; i++)
	{
		int j;
		for(j = 0; j < estilo.width; j++)
		{
			MoverCursor(j, i);
			wprintf(L"%lc", estilo.fondo_letra[i][j]);
			EsperarMiliSeg(TIEMPO_BASE);
		}
	}
}

void dibujar_flecha(int x, int y)
{
	MoverCursor(x, y);
	wprintf(L"-");
	MoverCursor(x +1 , y);
	wprintf(L"-");
	MoverCursor(x + 2, y);
	wprintf(L">");
}

void borrar_flecha(int x, int y)
{
	MoverCursor(x, y);
	wprintf(L" ");
	MoverCursor(x + 1, y);
	wprintf(L" ");
	MoverCursor(x + 2, y);
	wprintf(L" ");
}


void initialiar_pantalla(void)
{   
    BorrarPantalla();
    int columna, fila;

    for(columna=1;columna<ANCHO;columna++)
	{
		//Recorrer cada fila 
		for(fila=1;fila<ALTO;fila++)
		{
			//Mover el cursor, dibujar un * y esperar TIEMPO_BASE milisegundos
			MoverCursor(columna,fila);
			wprintf(L"*");
			EsperarMiliSeg(TIEMPO_BASE);
		};
	};
}

int interactuar_con_menu(void) {
	int opcion = 1;
	int x = 15, y = 12;
	dibujar_flecha(x, y);
	while (1) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            borrar_flecha(x, y);
			opcion = (opcion +2)%4+1;
			x = posiciones_menu[opcion - 1].x;
			y = posiciones_menu[opcion - 1].y;
			dibujar_flecha(x, y);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
           	borrar_flecha(x, y);
			opcion = (opcion % 4) +1;
			x = posiciones_menu[opcion - 1].x;
			y = posiciones_menu[opcion - 1].y;

			dibujar_flecha(x, y);
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			return opcion;
		}
        Sleep(100); // Pequeña pausa para evitar que el cursor se mueva demasiado rápido
    }

}
