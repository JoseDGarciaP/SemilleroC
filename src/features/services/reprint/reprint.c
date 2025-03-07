//
// Created by wposs on 6/03/2025.
//

#include<stdio.h>

#include "reprint.h"

#include <string.h>

void reprint_transactions() {
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
    printf("\n===== REIMPRESION DE TRANSACCIONES =====\n");
    printf("Cantidad de transacciones actuales: %d \n\n", count);

    for (int i = count - 1; i >= 0; i--) {
        printf("Referencia: %d\n", transactions[i].reference);

        //Validar PAN antes de mostrarlo
        if (strlen(transactions[i].pan) >= 16) {
            printf("Tarjeta: **** **** **** %s\n", &transactions[i].pan[12]); //Últimos 4 dígitos
        } else {
            printf("Tarjeta: %s\n", transactions[i].pan); //Mostrar lo que haya
        }

        printf("Monto: %.2f USD\n", transactions[i].amount / 100.0);
        printf("Estado: %s\n", transactions[i].status);
        printf("----------------------------\n");
    }
}
