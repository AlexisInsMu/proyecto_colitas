#ifndef GRAFICOS_H
#define GRAFICOS_H

typedef struct position_t
{
    int x;
    int y;
} position_t;  

extern position_t posiciones_menu[4];
//Funci�n para esperar un tiempo en milisegundos, simulaci�n de la funci�n delay() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int );

//Funci�n para borrar la pantalla de la consola, simulaci�n de la funci�n clrscr() que se tenia en borland 3.0 en la libreria conio.h
void BorrarPantalla(void);


void dibujar_presentacion(estilos_t);

void initialiar_pantalla(void);

int interactuar_con_menu(void);


#endif // GRAFICOS_H