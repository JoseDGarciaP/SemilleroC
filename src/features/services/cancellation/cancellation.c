//
// Created by JoseGarciaWPOSS on 6/03/2025.
//

#include <stdio.h>
#include <string.h>
#include "cancellation.h"

void cancellation() {
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
        count++;
        if (count >= MAX_TRANSACTIONS) break;  // Evitar overflow
    }
    fclose(file);

    if (count == 0) {
        printf("No hay transacciones para anular.\n");
        return;
    }

    //Solicitar número de referencia
    int ref_to_cancel;
    printf("\n===== ANULACION DE TRANSACCIONES =====\n");
    printf("Ingrese el numero de referencia de la transaccion que desea anular: ");
    scanf("%d", &ref_to_cancel);
    while (getchar() != '\n');  // Limpiar buffer

    //Buscar la transacción en el arreglo
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (transactions[i].reference == ref_to_cancel) {
            if (strcmp(transactions[i].status, "Anulada") == 0) {
                printf("La transaccion ya está anulada.\n");
            } else {
                strcpy(transactions[i].status, "Anulada");
                printf("La transaccion con referencia %d ha sido anulada.\n", ref_to_cancel);
                found = 1;
            }
            break;
        }
    }

    if (!found) {
        printf("No se encontro una transaccion con la referencia %d.\n", ref_to_cancel);
        return;
    }

    // Se guardan las transacciones actualizadas en el archivo
    file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Error al guardar las transacciones.");
        return;
    }
    fwrite(transactions, sizeof(Transaction), count, file);
    fclose(file);

    printf("Cambios guardados correctamente.\n");
}
