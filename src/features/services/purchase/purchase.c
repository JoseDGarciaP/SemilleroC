//
// Created by wposs on 6/03/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "purchase.h"

//Función para validar la fecha de expiración
int validate_exp_date(const char *exp_date) {
    int month, year;
    scanf(exp_date, "%2d/%2d", &month, &year);

    //Obtener la fecha actual
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int current_year = tm.tm_year % 100; //Tomamos los dos últimos dígitos
    int current_month = tm.tm_mon + 1;   //Meses van de 0 a 11, sumamos 1

    //Verificar fecha valida
    if (year > current_year || (year == current_year && month >= current_month)) {
        return 1;
    }
    return 0;
}

//Obtiene el siguiente número de referencia
int get_next_reference() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) return 1; // Si no existe, empezamos en 1

    Transaction last;
    fseek(file, -(long)sizeof(Transaction), SEEK_END);
    fread(&last, sizeof(Transaction), 1, file);
    fclose(file);

    return last.reference + 1;
}

//Función principal de compra
void purchase() {
    if (get_next_reference() > MAX_TRANSACTIONS) {
        printf("¡Maximo de transacciones alcanzado!\n");
        return;
    }

    Transaction new_transaction;
    new_transaction.reference = get_next_reference();
    strcpy(new_transaction.status, "Aprobada");

    printf("Ingrese el monto en dolares (sin punto decimal, ej. 10050 para 100.50): ");
    scanf("%d", &new_transaction.amount);
    while (getchar() != '\n');

    //Validar PAN (16 dígitos)
    do {
        printf("Ingrese el PAN de la tarjeta (16 digitos): ");
        scanf("%16s", new_transaction.pan);
        while (getchar() != '\n');
        if (strlen(new_transaction.pan) != 16 || strspn(new_transaction.pan, "0123456789") != 16){
            printf("La cantidad de digitos ingresados es invalida\n");
        }
    } while (strlen(new_transaction.pan) != 16 || strspn(new_transaction.pan, "0123456789") != 16);

    //Validar CVV (3 dígitos)
    do {
        printf("Ingrese el CVV (3 digitos): ");
        scanf("%3s", new_transaction.cvv);
        while (getchar() != '\n');
        if (strlen(new_transaction.cvv) != 3 || strspn(new_transaction.cvv, "0123456789") != 3) {
            printf("La cantidad de digitos ingresados es invalida\n");
        }
    } while (strlen(new_transaction.cvv) != 3 || strspn(new_transaction.cvv, "0123456789") != 3);

    do {
        printf("Ingrese la fecha de expiracion (MM/YY): ");
        scanf("%5s", new_transaction.exp_date);
    } while (!validate_exp_date(new_transaction.exp_date));

    //Guardar la transacción en archivo
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        printf("Error al guardar la transaccion.\n");
        return;
    }
    fwrite(&new_transaction, sizeof(Transaction), 1, file);
    fclose(file);

    printf("\nCompra realizada con exito. Referencia de compra: %d\n", new_transaction.reference);
}
