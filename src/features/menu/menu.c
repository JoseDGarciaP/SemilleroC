//
// Created by wposs on 6/03/2025.
//

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdbool.h>

#include "menu.h"

/*
 *
 */
void menu() {
    short option; //Variable para el menu de opciones
    bool exit = false; //Salida del do-while

    do {
        printf(" ***** Menu *****\n\n");
        printf(" Oprima la opcion deseada:\n");
        printf(" 1. Compra\n");
        printf(" 2. Anulacion\n");
        printf(" 3. Cierre\n");
        printf(" 4. Reimpresion\n");
        printf(" 5. Reporte de totales\n");
        printf(" 6. Salir\n\n");

        printf("Opcion selecionada: ");
        scanf("%hd", &option);
        fflush(stdin);

        switch (option) {
            case 1: //Compra
                system("cls");
                printf("Presiona cualquier tecla para continuar...\n");
                getch();
                system("cls");
                break;

            case 2: //Anulacion
                system("cls");
                printf("Presiona cualquier tecla para continuar...\n");
                getch();
                system("cls");
                break;

            case 3: //Cierre
                system("cls");
                printf("Presiona cualquier tecla para continuar...\n");
                getch();
                system("cls");
                break;

            case 4: //Reimpresion
                system("cls");
                printf("Presiona cualquier tecla para continuar...\n");
                getch();
                system("cls");
                break;

            case 5: //Reporte de totales
                system("cls");
                printf("Presiona cualquier tecla para continuar...\n");
                getch();
                system("cls");
                break;

            case 6: //Finalizar ejecucion
                system("cls");
                printf("Finalizando ejecucion...\n");
                printf("Gracias por usar nuestros servicios\n");
                printf("--------------------------------------------------\n");
                printf("Presiona cualquier tecla para continuar...\n");
                getch();
                exit = true;
                break;


            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (exit == false);
}
