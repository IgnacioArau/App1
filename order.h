#ifndef ORDER_H
#define ORDER_H
//definimos que el máximo número de ventas que analizará el programa es de 1000 órdenes
#define MAX_ORDER 1000
#define INT_MAX 1000
//   Se define la estructura
typedef struct Order {
    int pizza_id;
    int order_id;
    char pizza_name_id[50];
    int quantity;
    char order_date[20];
    char order_time[8];
    float unit_price;
    float total_price;
    char pizza_size[2];
    char pizza_category[10];
    char pizza_ingredients[200];
    char pizza_name[100];
} Order;

//   Se definen las funciones
void pms(const Order orders[], int cantidad, char *masVendida);
void pls(const Order orders[], int cantidad, char *menosVendida);
void dms(const Order orders[], int cantidad);
void dls(const Order orders[], int cantidad);
void dmsp(const Order orders[], int cantidad);
void dlsp(const Order orders[], int cantidad);
void apo(Order orders[], int *cantidad);
void apd(Order orders[], int *cantidad);
void ims(const Order orders[], int cantidad);
void hp(const Order orders[], int cantidad);
void mostrarMenu();
#endif
