#include <windows.h>
#include "graficos.h"
#include "estilos.h"

int main()
{   
    initialiar_pantalla();
    EsperarMiliSeg(1000);
    BorrarPantalla();
    dibujar_presentacion(pantalla_de_inicio);
    EsperarMiliSeg(1000);
    BorrarPantalla();
    dibujar_presentacion(pantalla_de_presentacion);
    
    EsperarMiliSeg(1000);
    BorrarPantalla();



    dibujar_presentacion(pantalla_de_error);
    EsperarMiliSeg(1000);
    BorrarPantalla();
    dibujar_presentacion(pantalla_de_menu);
    EsperarMiliSeg(1000);
    BorrarPantalla();


    dibujar_presentacion(pantalla_de_final);
    return 0;
}