#include <locale.h>
#include <stdio.h>
#include "graficos.h"
#include "estilos.h"
#include <windows.h>

int main()
{   
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    // initialiar_pantalla();
    // EsperarMiliSeg(1000);
    // BorrarPantalla();
    // dibujar_presentacion(pantalla_de_inicio);
    // EsperarMiliSeg(1000);
    // BorrarPantalla();
    // dibujar_presentacion(pantalla_de_presentacion);
    
    // EsperarMiliSeg(1000);
    // BorrarPantalla();



    // //dibujar_presentacion(pantalla_de_error);
    // //EsperarMiliSeg(1000);
    // //BorrarPantalla();
    BorrarPantalla();
    dibujar_presentacion(pantalla_de_menu);
    EsperarMiliSeg(1000);
    while(1){
        switch (interactuar_con_menu())
        {
        case 1:
            //arrancar_simul_1();
            //printf("Simulacion 1\n");
            break;
        
        case 2:
            //arrancar_simul_2();
            //printf("Simulacion 2\n");
            break;

        case 3:
            //printf("Simulacion 3\n");
            //arrancar_simul_3();
            break;

        case 4:
            dibujar_presentacion(pantalla_de_final);
            EsperarMiliSeg(4000);
            exit(1);
            break;
        default:
            dibujar_presentacion(pantalla_de_error);
            EsperarMiliSeg(1000);
            exit(1);
            break;
        }
        EsperarMiliSeg(1000);
    }


    dibujar_presentacion(pantalla_de_final);
    return 0;
}