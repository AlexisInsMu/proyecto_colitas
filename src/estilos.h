#ifndef ESTILOS_H
#define ESTILOS_H
 
#include <wchar.h>


typedef struct estilos_t
{
    wchar_t* nombre;
    int width;
    int height;
    wchar_t fondo_letra[24][80];
}estilos_t;


extern estilos_t pantalla_de_inicio;
extern estilos_t pantalla_de_presentacion;
extern estilos_t pantalla_de_final;
extern estilos_t pantalla_de_menu;
extern estilos_t pantalla_de_error;


#endif