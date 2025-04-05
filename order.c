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
//Encuentra la pizza más vendida según la cantidad
void pms(const Order *orders, int cantidad, char *masVendida) {
    int maxCantidad = -1;
    char yaContadas[cantidad][50];
    int yaContadasCount = 0;

    for (const Order *i = orders; i < orders + cantidad; i++) {
        int yaContada = 0;

        for (int k = 0; k < yaContadasCount; k++) {
            if (strcmp(i->pizza_name_id, yaContadas[k]) == 0) {
                yaContada = 1;
                break;
            }
        }
        if (yaContada)
            continue;

        int sumaCantidad = 0;
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(i->pizza_name_id, j->pizza_name_id) == 0) {
                sumaCantidad += j->quantity;
            }
        }

        if (sumaCantidad > maxCantidad) {
            maxCantidad = sumaCantidad;
            strcpy(masVendida, i->pizza_name_id);
        }

        strcpy(yaContadas[yaContadasCount++], i->pizza_name_id);
    }
}

void pls(const Order *orders, int cantidad, char *menosVendida) {
    int minCantidad = INT_MAX;
    char yaContadas[cantidad][50];
    int yaContadasCount = 0;

    for (const Order *i = orders; i < orders + cantidad; i++) {
        int yaContada = 0;

        for (int k = 0; k < yaContadasCount; k++) {
            if (strcmp(i->pizza_name_id, yaContadas[k]) == 0) {
                yaContada = 1;
                break;
            }
        }
        if (yaContada)
            continue;

        int sumaCantidad = 0;
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(i->pizza_name_id, j->pizza_name_id) == 0) {
                sumaCantidad += j->quantity;
            }
        }

        if (sumaCantidad < minCantidad) {
            minCantidad = sumaCantidad;
            strcpy(menosVendida, i->pizza_name_id);
        }

        strcpy(yaContadas[yaContadasCount++], i->pizza_name_id);
    }
}

// Función para obtener la fecha con más ventas en términos de dinero
void dms(const Order orders[], int cantidad) {
    float maxVentas = -FLT_MAX;
    char fechaMax[20];
    
    for (const Order *i = orders; i < orders + cantidad; i++) {
        float ventasDia = 0;
        
        // Sumamos todas las ventas por fecha
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(i->order_date, j->order_date) == 0) {
                ventasDia += j->total_price;
            }
        }
        
        if (ventasDia > maxVentas) {
            maxVentas = ventasDia;
            strcpy(fechaMax, i->order_date);
        }
    }
    
    printf("La fecha con más ventas en dinero es: %s, con un total de $%.2f\n", fechaMax, maxVentas);
}

// Función para obtener la fecha con menos ventas en términos de dinero
void dls(const Order orders[], int cantidad) {
    float minVentas = FLT_MAX;
    char fechaMin[20];
    
    for (const Order *i = orders; i < orders + cantidad; i++) {
        float ventasDia = 0;
        
        // Sumamos todas las ventas por fecha
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(i->order_date, j->order_date) == 0) {
                ventasDia += j->total_price;
            }
        }
        
        if (ventasDia < minVentas) {
            minVentas = ventasDia;
            strcpy(fechaMin, i->order_date);
        }
    }
    
    printf("La fecha con menos ventas en dinero es: %s, con un total de $%.2f\n", fechaMin, minVentas);
}

// Función para obtener la fecha con más ventas en términos de cantidad de pizzas
void dmsp(const Order orders[], int cantidad) {
    int maxCantidad = -1;
    char fechaMax[20];
    
    for (const Order *i = orders; i < orders + cantidad; i++) {
        int cantidadDia = 0;
        
        // Sumamos todas las cantidades de pizzas por fecha
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(i->order_date, j->order_date) == 0) {
                cantidadDia += j->quantity;
            }
        }
        
        if (cantidadDia > maxCantidad) {
            maxCantidad = cantidadDia;
            strcpy(fechaMax, i->order_date);
        }
    }
    
    printf("La fecha con más ventas en cantidad es: %s, con un total de %d pizzas\n", fechaMax, maxCantidad);
}

// Función para obtener la fecha con menos ventas en términos de cantidad de pizzas
void dlsp(const Order orders[], int cantidad) {
    int minCantidad = INT_MAX;
    char fechaMin[20];
    
    for (const Order *i = orders; i < orders + cantidad; i++) {
        int cantidadDia = 0;
        
        // Sumamos todas las cantidades de pizzas por fecha
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(i->order_date, j->order_date) == 0) {
                cantidadDia += j->quantity;
            }
        }
        
        if (cantidadDia < minCantidad) {
            minCantidad = cantidadDia;
            strcpy(fechaMin, i->order_date);
        }
    }
    
    printf("La fecha con menos ventas en cantidad es: %s, con un total de %d pizzas\n", fechaMin, minCantidad);
}

// Función para obtener el promedio de pizzas por orden
void apo(Order orders[], int *cantidad) {
    int totalPizzas = 0;
    
    for (Order *i = orders; i < orders + *cantidad; i++) {
        totalPizzas += i->quantity;
    }
    
    float promedio = (float)totalPizzas / *cantidad;
    printf("El promedio de pizzas por orden es: %.2f\n", promedio);
}

// Función para obtener el promedio de pizzas por día
void apd(Order orders[], int *cantidad) {
    int totalPizzas = 0;
    int totalDias = 0;
    char fechas[*cantidad][20];
    int fechaCount = 0;
    
    for (Order *i = orders; i < orders + *cantidad; i++) {
        int fechaEncontrada = 0;
        
        for (int j = 0; j < fechaCount; j++) {
            if (strcmp(i->order_date, fechas[j]) == 0) {
                fechaEncontrada = 1;
                break;
            }
        }
        
        if (!fechaEncontrada) {
            strcpy(fechas[fechaCount], i->order_date);
            fechaCount++;
        }
        
        totalPizzas += i->quantity;
    }
    
    float promedio = (float)totalPizzas / fechaCount;
    printf("El promedio de pizzas por día es: %.2f\n", promedio);
}

// Función para obtener el ingrediente más vendido
void ims(const Order orders[], int cantidad) {
    int maxCantidad = -1;
    char ingredienteMax[200];
    
    for (const Order *i = orders; i < orders + cantidad; i++) {
        int cantidadIngrediente = 0;
        
        // Contamos la cantidad de veces que se repite cada ingrediente
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strstr(j->pizza_ingredients, i->pizza_ingredients)) {
                cantidadIngrediente += j->quantity;
            }
        }
        
        if (cantidadIngrediente > maxCantidad) {
            maxCantidad = cantidadIngrediente;
            strcpy(ingredienteMax, i->pizza_ingredients);
        }
    }
    
    printf("El ingrediente más vendido es: %s, con un total de %d unidades\n", ingredienteMax, maxCantidad);
}

// Función para obtener la cantidad de pizzas vendidas por categoría
void hp(const Order orders[], int cantidad) {
    int categoriasCount = 0;
    char categorias[cantidad][10];
    
    for (const Order *i = orders; i < orders + cantidad; i++) {
        int categoriaEncontrada = 0;
        
        for (int j = 0; j < categoriasCount; j++) {
            if (strcmp(i->pizza_category, categorias[j]) == 0) {
                categoriaEncontrada = 1;
                break;
            }
        }
        
        if (!categoriaEncontrada) {
            strcpy(categorias[categoriasCount], i->pizza_category);
            categoriasCount++;
        }
    }
    
    for (int i = 0; i < categoriasCount; i++) {
        int cantidadVendida = 0;
        for (const Order *j = orders; j < orders + cantidad; j++) {
            if (strcmp(j->pizza_category, categorias[i]) == 0) {
                cantidadVendida += j->quantity;
            }
        }
        
        printf("Categoría %s: %d pizzas vendidas\n", categorias[i], cantidadVendida);
    }
}

// Función para mostrar el menú de funciones disponibles
void mostrarMenu() {
    printf("Opciones disponibles:\n");
    printf("1. pms - Pizza más vendida\n");
    printf("2. pls - Pizza menos vendida\n");
    printf("3. dms - Fecha con más ventas por dinero\n");
    printf("4. dls - Fecha con menos ventas por dinero\n");
    printf("5. dmsp - Fecha con más ventas por cantidad de pizzas\n");
    printf("6. dlsp - Fecha con menos ventas por cantidad de pizzas\n");
    printf("7. apo - Promedio de pizzas por orden\n");
    printf("8. apd - Promedio de pizzas por día\n");
    printf("9. ims - Ingrediente más vendido\n");
    printf("10. hp - Pizzas vendidas por categoría\n");
    printf("11. salir - Salir del programa\n");
}


