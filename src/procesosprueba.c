#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "TADColaDin.h"  

// DEFINICION DE CONSTANTES
#define TIEMPO_BASE 200    // Tiempo base en ms

int main(void) {
    int tiempo = 0;
    char opcion = 'S';
    elemento prog;
    cola listos, ejecucion, finalizados;
    Initialize(&listos);
    Initialize(&ejecucion);
    Initialize(&finalizados);

    while (opcion == 'S' || opcion == 's') {
        printf("\nIntroducir el nombre del proceso: ");
        fgets(prog.nombre, 200, stdin);
        prog.nombre[strcspn(prog.nombre, "\n")] = '\0';  // Remove newline character

        printf("\nIntroducir el tiempo del proceso: ");
        scanf("%d", &prog.tiempo);

        getchar();  // Clear the newline left by scanf
        printf("\nIntroducir la actividad del proceso: ");
        fgets(prog.actividad, 200, stdin);
        prog.actividad[strcspn(prog.actividad, "\n")] = '\0';  // Remove newline character

        printf("\nIntroducir el ID del proceso: ");
        fgets(prog.id, 20, stdin);
        prog.id[strcspn(prog.id, "\n")] = '\0';  // Remove newline character

        Queue(&listos, prog);

        printf("Deseas añadir otro programa? S/N: ");
        scanf(" %c", &opcion);
        getchar();  // Clear the newline left by scanf
    }

    printf("\nIniciando procesos de ejecucion...\n");

    while (!Empty(&listos)) {
        Queue(&ejecucion, Dequeue(&listos));
        tiempo++;
        printf("\nEjecutando el programa: ");
        puts(Front(&ejecucion).nombre);

        elemento e = Dequeue(&ejecucion);
        e.tiempo--;
        
        if (e.tiempo > 0) {
            Queue(&listos,e);
        } else {
            Queue(&finalizados,e);
            printf("\nEl programa de id %s ha finalizado en un tiempo de %d.\n", e.id, tiempo);
        }

        Sleep(TIEMPO_BASE);  // Adding a delay for simulation purposes
    }

    printf("\nTodos los procesos han finalizado.\n");
    return 0;
}
