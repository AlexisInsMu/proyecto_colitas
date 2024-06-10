#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "TADColaDin.h"  // Assuming this is the correct include for dynamic queue implementation

//DEFINICION DE CONSTANTES
#define TIEMPO_BASE 200    // Tiempo base en ms

int main(void) {
    unsigned int tiempo = 0;
    unsigned int cliente = 0;
    int i, fila, n, count = 0, cerrar = 0, tcliente;
    elemento e;

    // Inicializar la función rand
    srand(time(NULL));

    // Pedir el número de cajeras
    printf("\nEl numero de cajeras: ");
    scanf("%d", &n);

    // Crear n colas y arreglo para los tiempos de atención
    cola *cajera = malloc(sizeof(cola) * n);
    int *tiempos = malloc(sizeof(int) * n);

    // Inicializar ambas colas
    for (int j = 0; j < n; j++) {
        Initialize(&cajera[j]);
    }

    // Pedir los tiempos de atención para cada cajera
    printf("\nIngrese los tiempos de atención para cada cajera:\n");
    for (int i = 0; i < n; i++) {
        printf("Cajera %d: ", i);
        scanf("%d", &tiempos[i]);
    }

    // Pedir el tiempo de recepción de clientes
    printf("\nTiempo de recepcion de clientes: ");
    scanf("%d", &tcliente);

    // Ciclo principal
    while (!cerrar) {
        Sleep(TIEMPO_BASE);  // Esperar el tiempo base
        tiempo++;            // Incrementar el contador de tiempo

        // Revisar si es tiempo de atender a un cliente en alguna de las cajeras
        for (int tmp = 0; tmp < n; tmp++) {
            if (tiempo % tiempos[tmp] == 0) {
                if (!Empty(&cajera[tmp])) {
                    e = Dequeue(&cajera[tmp]);
                    printf("\n\n\nAtendi a: %d en caja %d", e.n, tmp);
                    count++;
                } else {
                    printf("\n\n\nNo hay alguien por atender en caja %d", tmp);
                }
            }
        }

        // Si es tiempo de llegada de un nuevo cliente
        if (tiempo % tcliente == 0) {
            cliente++;  // Incrementar el número de clientes
            e.n = cliente;  // Asignar el número que identifica al cliente
            fila = rand() % n;  // Escoger la fila para formarse aleatoriamente
            Queue(&cajera[fila], e);  // Formarse en la fila seleccionada
            printf("\n\n\nLlego el cliente: %d a la cola de la caja %d", e.n, fila);
        }

        // Mostrar los clientes en cada cola
        for (int l = 0; l < n; l++) {
            printf("\n\n%d clientes en cola %d: [", Size(&cajera[l]), l);
            for (i = 1; i <= Size(&cajera[l]); i++) {
                e = Element(&cajera[l], i);
                printf("%d\t", e.n);
            }
            printf("]");
        }

        // Si ya se atendieron 100 clientes, verificar si todas las colas están vacías
        if (count >= 100) {
            cerrar = 1;  // Suponer que se puede cerrar
            for (int i = 0; i < n; i++) {
                if (!Empty(&cajera[i])) {
                    cerrar = 0;  // Si alguna cola no está vacía, no se puede cerrar
                    break;
                }
            }
        }
    }

    // Liberar la memoria reservada
    printf("Cerrando el supermercado...");
    free(cajera);
    free(tiempos);

    return 0;
}
