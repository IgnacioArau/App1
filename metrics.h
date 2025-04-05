#ifndef METRICS_H
#define METRICS_H

#include "order.h"

char* calculate_metric(const char *metric_name, struct order *orders, int size);
char* pizza_mas_vendida(struct order *orders, int size);

#endif // METRICS_H

