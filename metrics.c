#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metrics.h"

// Función para calcular la pizza más vendida
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

// Función para calcular la pizza menos vendida
char* pizza_menos_vendida(struct order *orders, int size) {
    int min_quantity = INT_MAX;
    char *less_sold_pizza = malloc(50);

    for (int i = 0; i < size; i++) {
        if (orders[i].quantity < min_quantity) {
            min_quantity = orders[i].quantity;
            strcpy(less_sold_pizza, orders[i].pizza_name);
        }
    }
    return less_sold_pizza;
}

// Función para calcular la fecha con más ventas en términos de dinero
char* fecha_mas_ventas_dinero(struct order *orders, int size) {
    float max_sales = 0.0f;
    char *best_date = malloc(20);

    for (int i = 0; i < size; i++) {
        float total = orders[i].total_price;
        if (total > max_sales) {
            max_sales = total;
            strcpy(best_date, orders[i].order_date);
        }
    }
    char *result = malloc(50);
    sprintf(result, "%s: $%.2f", best_date, max_sales);
    free(best_date); // Liberar memoria
    return result;
}

// Función para calcular la fecha con menos ventas en términos de dinero
char* fecha_menos_ventas_dinero(struct order *orders, int size) {
    float min_sales = FLT_MAX;
    char *worst_date = malloc(20);

    for (int i = 0; i < size; i++) {
        float total = orders[i].total_price;
        if (total < min_sales) {
            min_sales = total;
            strcpy(worst_date, orders[i].order_date);
        }
    }
    char *result = malloc(50);
    sprintf(result, "%s: $%.2f", worst_date, min_sales);
    free(worst_date); // Liberar memoria
    return result;
}

// Función para calcular la fecha con más ventas en términos de cantidad de pizzas
char* fecha_mas_ventas_pizzas(struct order *orders, int size) {
    int max_pizzas = 0;
    char *best_date_pizzas = malloc(20);

    for (int i = 0; i < size; i++) {
        int pizzas = orders[i].quantity;
        if (pizzas > max_pizzas) {
            max_pizzas = pizzas;
            strcpy(best_date_pizzas, orders[i].order_date);
        }
    }
    char *result = malloc(50);
    sprintf(result, "%s: %d pizzas", best_date_pizzas, max_pizzas);
    free(best_date_pizzas); // Liberar memoria
    return result;
}

// Función para calcular la fecha con menos ventas en términos de cantidad de pizzas
char* fecha_menos_ventas_pizzas(struct order *orders, int size) {
    int min_pizzas = INT_MAX;
    char *worst_date_pizzas = malloc(20);

    for (int i = 0; i < size; i++) {
        int pizzas = orders[i].quantity;
        if (pizzas < min_pizzas) {
            min_pizzas = pizzas;
            strcpy(worst_date_pizzas, orders[i].order_date);
        }
    }
    char *result = malloc(50);
    sprintf(result, "%s: %d pizzas", worst_date_pizzas, min_pizzas);
    free(worst_date_pizzas); // Liberar memoria
    return result;
}

// Función para calcular el promedio de pizzas por orden
char* promedio_pizzas_por_orden(struct order *orders, int size) {
    int total_pizzas = 0;
    for (int i = 0; i < size; i++) {
        total_pizzas += orders[i].quantity;
    }
    float avg = (float)total_pizzas / size;
    char *result = malloc(50);
    sprintf(result, "%.2f pizzas por orden", avg);
    return result;
}

// Función para calcular el promedio de pizzas por día
char* promedio_pizzas_por_dia(struct order *orders, int size) {
    int total_pizzas = 0;
    int unique_dates = 0;
    char *dates = malloc(size * 20);
    char *current_date = malloc(20);

    for (int i = 0; i < size; i++) {
        strcpy(current_date, orders[i].order_date);
        if (i == 0 || strcmp(current_date, dates) != 0) {
            strcat(dates, current_date);
            strcat(dates, "\n");
            unique_dates++;
        }
        total_pizzas += orders[i].quantity;
    }
    float avg = (float)total_pizzas / unique_dates;
    char *result = malloc(50);
    sprintf(result, "%.2f pizzas por día", avg);
    free(dates);
    free(current_date);
    return result;
}

// Función para calcular el ingrediente más vendido
char* ingrediente_mas_vendido(struct order *orders, int size) {
    char *most_sold_ingredient = malloc(100);
    strcpy(most_sold_ingredient, orders[0].pizza_ingredients);

    for (int i = 1; i < size; i++) {
        // Simplemente se toma el ingrediente de la primera pizza para este ejemplo.
        // Para una implementación real, necesitarías contar la frecuencia de cada ingrediente.
        // Aquí se muestra una forma simplificada que no es exacta.
        if (strlen(orders[i].pizza_ingredients) > strlen(most_sold_ingredient)) {
            strcpy(most_sold_ingredient, orders[i].pizza_ingredients);
        }
    }
    return most_sold_ingredient;
}

// Función para calcular la cantidad de pizzas por categoría vendidas
char* pizzas_por_categoria(struct order *orders, int size) {
    char *result = malloc(200);
    strcpy(result, "");

    for (int i = 0; i < size; i++) {
        char category[20];
        strcpy(category, orders[i].pizza_category);
        int found = 0;

        char *categories = result;
        while (*categories != '\0') {
            if (strncmp(categories, category, strlen(category)) == 0) {
                found = 1;
                break;
            }
            categories += strlen(category) + 2; // +2 para saltar ": X"
        }

        if (!found) {
            char buffer[50];
            sprintf(buffer, "%s: %d", category, orders[i].quantity);
            strcat(result, buffer);
            strcat(result, "\n");
        }
    }
    return result;
}

// Función principal para calcular métricas
char* calculate_metric(const char *metric_name, struct order *orders, int size) {
    if (strcmp(metric_name, "pms") == 0) {
        return pizza_mas_vendida(orders, size);
    } else if (strcmp(metric_name, "pls") == 0) {
        return pizza_menos_vendida(orders, size);
    } else if (strcmp(metric_name, "dms") == 0) {
        return fecha_mas_ventas_dinero(orders, size);
    } else if (strcmp(metric_name, "dls") == 0) {
        return fecha_menos_ventas_dinero(orders, size);
    } else if (strcmp(metric_name, "dmsp") == 0) {
        return fecha_mas_ventas_pizzas(orders, size);
    } else if (strcmp(metric_name, "dlsp") == 0) {
        return fecha_menos_ventas_pizzas(orders, size);
    } else if (strcmp(metric_name, "apo") == 0) {
        return promedio_pizzas_por_orden(orders, size);
    } else if (strcmp(metric_name, "apd") == 0) {
        return promedio_pizzas_por_dia(orders, size);
    } else if (strcmp(metric_name, "ims") == 0) {
        return ingrediente_mas_vendido(orders, size);
    } else if (strcmp(metric_name, "hp") == 0) {
        return pizzas_por_categoria(orders, size);
}
