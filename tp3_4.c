#include <stdio.h>
#include <stdlib.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct  {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct  {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos //El tamaño de este arreglo depende de la variable
                    // “CantidadProductosAPedir”
}typedef Cliente;

void cargar(Cliente *Cliente, int tama) {
    for (int i = 0; i < tama; i++) {
        (Cliente+i)->ClienteID = i;
        printf("Ingrese el nombre del cliente %d:\n", i);
        (Cliente+i)->NombreCliente = malloc(sizeof(char)*30);
        scanf("%s", (Cliente+i)->NombreCliente);
        (Cliente+i)->CantidadProductosAPedir = rand() % 5 + 1;
        (Cliente+i)->Productos = malloc(sizeof(Producto)*(Cliente+i)->CantidadProductosAPedir);

        for (int j = 0; j < (Cliente+i)->CantidadProductosAPedir; j++) {
            (Cliente+i)->Productos[j].ProductoID = j;
            (Cliente+i)->Productos[j].Cantidad = rand() % 10 +1;
            (Cliente+i)->Productos[j].TipoProducto = TiposProductos[rand()%5];
            (Cliente+i)->Productos[j].PrecioUnitario = rand()%100+10;
        }
    }
}

float prcProd(Producto prod){
    return(prod.Cantidad*prod.PrecioUnitario);
}

void mostrar(Cliente *cliente, int tama) {
    float precTotal=0,precProd;
    for (int i = 0; i < tama; i++) {
        printf("/////////////// CLIENTE %d ///////////////////\n",(cliente+i)->ClienteID);
        printf("Nombre: %s\n",(cliente+i)->NombreCliente);
        printf("Cant.Prod a pedir: %d\n",(cliente+i)->CantidadProductosAPedir);
        precTotal=0;

        for (int j = 0; j < (cliente+i)->CantidadProductosAPedir; j++) {
            printf("Producto %d:\n", j);
            printf("\tID: %d\n", (cliente+i)->Productos[j].ProductoID);
            printf("\tCantidad: %d\n", (cliente+i)->Productos[j].Cantidad);
            printf("\tTipo de producto: %s\n", (cliente+i)->Productos[j].TipoProducto);
            printf("\tPrecio unitario: $%.2f\n",(cliente+i)->Productos[j].PrecioUnitario);
            printf("\tPrecio: $%.2f\n",prcProd((cliente+i)->Productos[j]));
            precTotal = precTotal + prcProd((cliente+i)->Productos[j]);

        }
        printf("Total a pagar: $%.2f\n",precTotal);
        printf("//////////////////////////////////////////////////\n");
    }
}   


int main()
{
    int tama;
    Cliente *clientes;
    printf("ingrese la cantidad de cliente: \n");
    scanf("%d",&tama);
    clientes = malloc(sizeof(Cliente)*tama);
    cargar(clientes,tama);
    mostrar(clientes,tama);

   
    for (int i = 0; i < tama; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
    return 0;
}
