#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"

char* calculate_metric(const char *metric_name, struct order *orders, int size) {
    if (strcmp(metric_name, "pms") == 0) {
        return pizza_mas_vendida(orders, size);
    } else if (strcmp(metric_name, "pls") == 0) {
        return pizza_menos_vendida(orders, size);
    }
    // Agregar más métricas según sea necesario
    return NULL; // Métrica no reconocida
}

char* pizza_mas_vendida(struct order *orders, int size) {
    int max_quantity = 0;
    char *most_sold_pizza = malloc(50);

    for (int i = 0; i < size; i++) {
        if (orders[i].quantity > max_quantity) {
            max_quantity = orders[i].quantity;
            strcpy(most_sold_pizza, orders[i].pizza_name);
        }
    }
    return most_sold_pizza;
}

