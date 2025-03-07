//
// Created by wposs on 6/03/2025.
//

#ifndef PURCHASE_H
#define PURCHASE_H

#define MAX_TRANSACTIONS 20
#define FILE_NAME "transactions.txt"

typedef struct {
    int reference;
    char pan[17];
    char cvv[4];
    char exp_date[6]; //MM/YY
    int amount; //Últimos dos dígitos son decimales
    char status[10]; //"Aprobada" o "Anulada"
} Transaction;

void purchase();

#endif //PURCHASE_H
