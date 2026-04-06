#include <stdio.h>
#include <string.h>

int main()
{
    int id = 0;
    char nombre[50] = "";
    int stock = 0;
    float precio = 0;
    float ganancias = 0;

    int opc = 0, opc2 = 0;
    int aux;
    int cantidad;
    float descuento;
    int len;

    do{
        printf("\n··············MENU················\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Informacion del producto\n");
        printf("5. Mostrar ganancias\n");
        printf("6. Salir\n");

        do{
            printf("Seleccione una opcion: ");
            aux = scanf("%d",&opc);

            if(aux != 1 || opc < 1 || opc > 6){
                printf("Opcion invalida, intente otra vez\n");
                while(getchar()!='\n'); // limpiar entrada
            }

        }while(aux != 1 || opc < 1 || opc > 6);

        switch(opc){

            case 1:
                printf("Ingrese ID del producto: ");
                scanf("%d",&id);

                printf("Ingrese nombre del producto: ");
                getchar();
                fgets(nombre,50,stdin);
                len = strlen(nombre) - 1;
                nombre[len] = '\0';

                printf("Ingrese stock inicial: ");
                scanf("%d",&stock);

                printf("Ingrese precio: ");
                scanf("%f",&precio);

                printf("Producto registrado correctamente\n");
                break;

            case 2:
                if(stock <= 0){
                    printf("No hay stock disponible\n");
                }else{
                    printf("Ingrese cantidad a vender: ");
                    scanf("%d",&cantidad);

                    if(cantidad > stock){
                        printf("No hay suficiente stock\n");
                    }else{
                        printf("Ingrese descuento (0 a 100): ");
                        scanf("%f",&descuento);

                        float subtotal = cantidad * precio;
                        float total = subtotal - (subtotal * descuento / 100);

                        stock = stock - cantidad;
                        ganancias = ganancias + total;

                        printf("Venta realizada\n");
                        printf("Total a pagar: %.2f\n", total);
                        printf("Stock restante: %d\n", stock);
                    }
                }
                break;

            case 3:
                printf("Ingrese cantidad a agregar: ");
                scanf("%d",&cantidad);

                stock = stock + cantidad;
                printf("Stock actualizado: %d\n", stock);
                break;

            case 4:
                printf("\n--- DATOS DEL PRODUCTO ---\n");
                printf("ID: %d\n", id);
                printf("Nombre: %s\n", nombre);
                printf("Stock: %d\n", stock);
                printf("Precio: %.2f\n", precio);
                break;

            case 5:
                printf("Ganancias totales: %.2f\n", ganancias);
                break;

            case 6:
                printf("Saliendo del sistema...\n");
                break;
        }

        if(opc != 6){
            printf("\nDesea continuar? 1.Si / 2.No: ");
            scanf("%d",&opc2);
        }

    }while(opc != 6 && opc2 == 1);

    return 0;
}
