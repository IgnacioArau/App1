#include "order.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de funcion para prevenir el mensaje de declaracion implicita
void free_order(Order* order);

Order* create_order_from_csv(const char* csv_line) {
    Order* new_order = (Order*)malloc(sizeof(Order));
    if (new_order == NULL) {
        perror("Error al asignar memoria para la orden de pizza");
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
                new_order->pizza_id = atoi(token);
                break;
            case 1:
                new_order->order_id = atoi(token);
                break;
            case 2:
                strncpy(new_order->pizza_name_id, token, sizeof(new_order->pizza_name_id) - 1);
                new_order->pizza_name_id[sizeof(new_order->pizza_name_id) - 1] = '\0';
                break;
            case 3:
                new_order->quantity = atoi(token);
                break;
            case 4:
                strncpy(new_order->order_date, token, sizeof(new_order->order_date) - 1);
                new_order->order_date[sizeof(new_order->order_date) - 1] = '\0';
                break;
            case 5:
                strncpy(new_order->order_time, token, sizeof(new_order->order_time) - 1);
                new_order->order_time[sizeof(new_order->order_time) - 1] = '\0';
                break;
            case 6:
                new_order->unit_price = strtof(token, NULL);
                break;
            case 7:
                new_order->total_price = strtof(token, NULL);
                break;
            case 8:
                strncpy(new_order->pizza_size, token, sizeof(new_order->pizza_size) - 1);
                new_order->pizza_size[sizeof(new_order->pizza_size) - 1] = '\0';
                break;
            case 9:
                strncpy(new_order->pizza_category, token, sizeof(new_order->pizza_category) - 1);
                new_order->pizza_category[sizeof(new_order->pizza_category) - 1] = '\0';
                break;
            case 10:
                strncpy(new_order->pizza_ingredients, token, sizeof(new_order->pizza_ingredients) - 1);
                new_order->pizza_ingredients[sizeof(new_order->pizza_ingredients) - 1] = '\0';
                break;
            case 11:
                strncpy(new_order->pizza_name, token, sizeof(new_order->pizza_name) - 1);
                new_order->pizza_name[sizeof(new_order->pizza_name) - 1] = '\0';
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

void free_order(Order* order) {
    if (order != NULL) {
        free(order);
    }
}

void print_order(const Order* order) {
    if (order != NULL) {
        printf("Pizza ID: %d\n", order->pizza_id);
        printf("Orden ID: %d\n", order->order_id);
        printf("Pizza Name ID: %s\n", order->pizza_name_id);
        printf("Cantidad: %d\n", order->quantity);
        printf("Fecha Orden: %s\n", order->order_date);
        printf("Tiempo Orden: %s\n", order->order_time);
        printf("Precio Unidad: %.2f\n", order->unit_price);
        printf("Precio Total: %.2f\n", order->total_price);
        printf("Tamaño Pizza: %s\n", order->pizza_size);
        printf("Categoría Pizza: %s\n", order->pizza_category);
        printf("Ingredientes Pizza: %s\n", order->pizza_ingredients);
        printf("Nombre Pizza: %s\n", order->pizza_name);
        printf("-------------------------\n");
    } else {
        printf("La orden es NULL.\n");
    }
}

// Implementacion de funciones ya declaradas en order.h
void pms(const Order orders[], int cantidad, char moda[]) {
    int maxFrecuencia = 0;

    for (int i = 0; i < cantidad; i++) {
        int frecuencia = 0;

        for (int j = 0; j < cantidad; j++) {
            if (strcmp(orders[i].pizza_name_id, orders[j].pizza_name_id) == 0) {
                frecuencia++;
            }
        }

        if (frecuencia > maxFrecuencia) {
            maxFrecuencia = frecuencia;
            strcpy(moda, orders[i].pizza_name_id);
        }
    }
}

void pls(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función pls no implementada aún\n");
}

void dms(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función dms no implementada aún\n");
}

void dls(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función dls no implementada aún\n");
}

void dmsp(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función dmsp no implementada aún\n");
}

void dlsp(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función dlsp no implementada aún\n");
}

void apo(Order orders[], int *cantidad) {
    // Implementación pendiente
    printf("Función apo no implementada aún\n");
}

void apd(Order orders[], int *cantidad) {
    // Implementación pendiente
    printf("Función apd no implementada aún\n");
}

void ims(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función ims no implementada aún\n");
}

void hp(const Order orders[], int cantidad) {
    // Implementación pendiente
    printf("Función hp no implementada aún\n");
}

void upload_order(Order orders[], int *cantidad) {
    // Implementación pendiente
    printf("Función upload_order no implementada aún\n");
}

void mostrarMenu() {
    printf("\n===== MENÚ PRINCIPAL =====\n");
    printf("1. PMS - Pizzas más vendidas\n");
    printf("2. PLS - Pizzas menos vendidas\n");
    printf("3. DMS - Fechas con más ventass\n");
    printf("4. DLS - Fechas con menos ventas\n");
    printf("5. DMSP - Fechas con más ventas en términos de cantidad\n");
    printf("6. DLSP - Fechas con menos ventas en términos de cantidad de pizzas\n");
    printf("7. APO - Promedio de pizzas por ordenes\n");
    printf("8. APD - Promedio de pizzas por día\n");
    printf("9. IMS - Ingredientes más vendidos\n");
    printf("10. HP - Cantidad de pizzas por categoría vendidas\n");
    printf("11. Subir Orders\n");
    printf("0. Salir\n");
    printf("Ingrese su opción: ");
}


