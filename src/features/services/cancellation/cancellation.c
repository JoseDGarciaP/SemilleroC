//
// Created by wposs on 6/03/2025.
//

#include<stdio.h>
#include<string.h>


#include "cancellation.h"

void cancellation(){
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Error al abrir transactions.txt");
        printf("No hay transacciones registradas.\n");
        return;
    }

    Transaction transactions[MAX_TRANSACTIONS];
    int count = 0;

    //Leer las transacciones en memoria
    while (fread(&transactions[count], sizeof(Transaction), 1, file) == 1) {
        printf("Leida transaccion %d con referencia: %d\n", count, transactions[count].reference);
        count++;
        if (count >= MAX_TRANSACTIONS) break;  //Evitar overflow
    }
    fclose(file);

    if (count == 0) {
        printf("No hay transacciones para mostrar.\n");
        return;
    }

    //Imprimir en orden descendente
    printf("\n===== ANULACION DE TRANSACCIONES =====\n");

    printf("Ingrese el numero de la referencia de la transaccion que desea anular: ");
    scanf("%d", &count);
    while (getchar() != '\n');

    for (int i = count - 1; i >= 0; i--) {
         if (count == transactions[i].reference ) {
             strcpy(transactions[i].status, "Anulada");
             printf("Estado: %s\n", transactions[i].status);
             printf("\n----------------------------\n");
         }


    }

};

