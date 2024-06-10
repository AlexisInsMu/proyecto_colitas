#ifndef ESTILOS_H
#define ESTILOS_H



typedef struct estilos_t
{
    char* nombre;
    int width;
    int height;
    char fondo_letra[24][80];
}estilos_t;


extern estilos_t pantalla_de_inicio;
extern estilos_t pantalla_de_presentacion;
extern estilos_t pantalla_de_final;
extern estilos_t pantalla_de_menu;
extern estilos_t pantalla_de_error;


#endif