#ifndef METRICS_H
#define METRICS_H

#include "order.h"

char* calculate_metric(const char *metric_name, struct order *orders, int size);
char* pizza_mas_vendida(struct order *orders, int size);
char* pizza_menos_vendida(struct order *orders, int size);
char* fecha_mas_ventas_dinero(struct order *orders, int size);
char* fecha_menos_ventas_dinero(struct order *orders, int size);
char* fecha_mas_ventas_pizzas(struct order *orders, int size);
char* fecha_menos_ventas_pizzas(struct order *orders, int size);
char* promedio_pizzas_por_orden(struct order *orders, int size);
char* promedio_pizzas_por_dia(struct order *orders, int size);
char* ingrediente_mas_vendido(struct order *orders, int size);
char* pizzas_por_categoria(struct order *orders, int size);

#endif // METRICS_H
