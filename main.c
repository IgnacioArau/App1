#include "order.h"
#include "metrics.h"

int main(int argc, char *argv[]) {
    
    Order orders[100];
    int cantidad = 0;
    upload_order(orders, &cantidad);

    int opcion = 0;

    
  // mostrar el menú
    while (opcion != 11) {
        mostrarMenu();
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);  

        if (opcion == 1) {
            pms(orders, cantidad);
        } else if (opcion == 2) {
            pls(orders, cantidad);
        } else if (opcion == 3) {
            dms(orders, cantidad);
        } else if (opcion == 4) {
            dls(orders, cantidad);
        } else if (opcion == 5) {
            dmsp(orders, cantidad);
        } else if (opcion == 6) {
            dlsp(orders, cantidad);
        } else if (opcion == 7) {
            apo(orders, &cantidad);
        } else if (opcion == 8) {
            apd(orders, &cantidad);
        } else if (opcion == 9) {
            ims(orders, cantidad);
        } else if (opcion == 10) {
            hp(orders, cantidad);
        } else if (opcion == 11) {
            printf("Saliendo del programa...\n");
        } else {
            printf("Opción no válida, por favor ingresa una opción válida.\n");
        }
    }

    return 0;
}
}
