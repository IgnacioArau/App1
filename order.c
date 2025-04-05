// order.c
#include "order.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order* create_order_from_csv(const char* csv_line) {
    struct order* new_order = (struct order*)malloc(sizeof(struct order));
    if (new_order == NULL) {
        perror("Error al asignar memoria para la orden");
        return NULL;
    }

    char* line = strdup(csv_line);
    if (line == NULL) {
        perror("Error al duplicar la línea CSV");
        free(new_order);
        return NULL;
    }

    char* token;
    int i = 0;

    token = strtok(line, ",");
    while (token != NULL && i < 12) {
        switch (i) {
            case 0:
                new_order->pizza_id = strtod(token, NULL);
                break;
            case 1:
                new_order->order_id = strtod(token, NULL);
                break;
            case 2:
                new_order->pizza_name_id = strdup(token);
                break;
            case 3:
                new_order->quantity = strtod(token, NULL);
                break;
            case 4:
                new_order->order_date = strdup(token);
                break;
            case 5:
                new_order->order_time = strdup(token);
                break;
            case 6:
                new_order->unit_price = strtod(token, NULL);
                break;
            case 7:
                new_order->total_price = strtod(token, NULL);
                break;
            case 8:
                new_order->pizza_size = strdup(token);
                break;
            case 9:
                new_order->pizza_category = strdup(token);
                break;
            case 10:
                new_order->pizza_ingredients = strdup(token);
                break;
            case 11:
                new_order->pizza_name = strdup(token);
                break;
        }
        token = strtok(NULL, ",");
        i++;
    }

    free(line);

    if (i != 12) {
        fprintf(stderr, "Advertencia: No se pudieron parsear todos los campos de la línea CSV.\n");
        free_order(new_order);
        return NULL;
    }

    return new_order;
}

void free_order(struct order* order) {
    if (order != NULL) {
        free(order->pizza_name_id);
        free(order->order_date);
        free(order->order_time);
        free(order->pizza_size);
        free(order->pizza_category);
        free(order->pizza_ingredients);
        free(order->pizza_name);
        free(order);
    }
}

void print_order(const struct order* order) {
    if (order != NULL) {
        printf("Pizza ID: %.2f\n", order->pizza_id);
        printf("Order ID: %.2f\n", order->order_id);
        printf("Pizza Name ID: %s\n", order->pizza_name_id);
        printf("Quantity: %.2f\n", order->quantity);
        printf("Order Date: %s\n", order->order_date);
        printf("Order Time: %s\n", order->order_time);
        printf("Unit Price: %.2f\n", order->unit_price);
        printf("Total Price: %.2f\n", order->total_price);
        printf("Pizza Size: %s\n", order->pizza_size);
        printf("Pizza Category: %s\n", order->pizza_category);
        printf("Pizza Ingredients: %s\n", order->pizza_ingredients);
        printf("Pizza Name: %s\n", order->pizza_name);
        printf("--------------------\n");
    } else {
        printf("La orden es NULL.\n");
    }
}
