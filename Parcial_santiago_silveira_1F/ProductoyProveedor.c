#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProductoyProveedor.h"
#include "ComprobarYLimites.h"

void hardCode(proveedor empresas[])
{
    empresas[0].idProveedor =1;
    strcpy(empresas[0].descripcionProveedor, "Ford");

    empresas[1].idProveedor = 2;
    strcpy(empresas[1].descripcionProveedor, "Renault");

    empresas[2].idProveedor = 3;
    strcpy(empresas[2].descripcionProveedor, "Fiat");

    empresas[3].idProveedor = 4;
    strcpy(empresas[3].descripcionProveedor, "Mercedez");

    empresas[4].idProveedor = 5;
    strcpy(empresas[4].descripcionProveedor, "Subaru");
}

void menu()
{
    printf("1- Agregar producto\n");
    printf("2- Modificar producto\n");
    printf("3- Borrar producto\n");
    printf("4- Informar\n");
    printf("5- Listar productos\n\n");
    printf("6- Salir\n");
}

void inicializar(eProducto lista[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].estado = 0;
    }
}

void agregarProducto(eProducto lista[], int cantidad)
{
    int i;
    printf("\n");
    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 0)
        {
            strcpy(lista[i].descripcion,getString("Ingrese descripsion: ","Error no se ingreso dentro de los limites",1,50,1));
            lista[i].codigo=getInt("\nIngrese codigo: ","Error.",1,1,0);
            lista[i].idProveedor=getInt("\nIngrese codigo del proveedor(0-4): ","Error.",0,4,1);
            lista[i].importe=getFloat("\nIngrese importe: ","Error.",1,1,0);
            lista[i].cantidad=getInt("\nIngrese cantidad: ","Error.",0,200,1);
            lista[i].estado = 1;
            break;
        }
    }
}

void modificarProducto(eProducto lista[])
{
    char seguir = 's';
    int i,p,opcion,indice;
    printf("\nLos productos disponibles a modificar son: ");
    for(i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            printf("\nCodigo: %d\t Descripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
        }
    }
    p=lista[i].codigo=getInt("\nIngrese el codigo del producto a modificar: ","Error.",1,1,0);

    for(i=0;i<20;i++)
    {
        indice = -1;
        if(lista[i].codigo == p)
        {
            indice = i;
            break;
        }
    }
    printf("\n");
    if(indice != -1)
    {
        while(seguir=='s')//---------------------------------------------------------------------------
        {
            printf("1- Codigo del producto: %d\n",lista[indice].codigo);
            //printf("2- Descripcion del producto: %s\n",lista[indice].descripcion);
            printf("2- Importe del producto: %.2f\n",lista[indice].importe);
            printf("3- Cantidad del producto: %d\n\n",lista[indice].cantidad);
            printf("4- Terminar de modificar.\n");

            scanf("%d",&opcion);


            switch(opcion)
            {
                case 1://CODIGO
                    lista[i].codigo=getInt("\nIngrese el nuevo codigo del producto: ","Error.",1,1,0);
                    break;
                case 2://IMPORTE
                    lista[i].importe=getFloat("\nIngrese el nuevo importe del producto: ","Error.",1,1,0);
                    break;
                case 3://CANTIDAD
                    lista[i].cantidad=getInt("\nIngrese la nueva cantidad del producto: ","Error.",0,200,1);
                    break;
                case 4://TERMINAR
                    seguir = 'n';
                    break;
            }
        }
        printf("\nModificacion finalizada.\n");
    }
    else
    {
        printf("\nError no hay un producto con este codigo.\n");
    }
}

void borrarProducto(eProducto lista[])
{
    int indice,p,i;
    printf("\nLos productos disponibles a borrar son: ");
    for(i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            printf("\nCodigo: %d\t Descripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
        }
    }
    p=lista[i].codigo=getInt("\nIngrese el codigo del producto a borrar: ","Error.",1,1,0);

    for(i=0;i<20;i++)
    {
        indice = -1;
        if(lista[i].codigo == p)
        {
            indice = i;
            break;
        }
    }

    if(indice != -1)
    {
        printf("\nEsta seguro que quiere borrar el producto?<s/n> ");
        char respuesta;
        do
        {
            scanf("%c",&respuesta);

        }while(respuesta != 's' && respuesta != 'n');
        if(respuesta == 's')
        {
            printf("El producto fue eliminado.\n");
            lista[indice].estado = 0;
        }
        else
        {
            printf("El producto no fue eliminado.\n");
        }
    }
    else
    {
        printf("\nError no hay un producto con este codigo");
    }
}

void listarProductos(eProducto lista[], eProducto aux)
{
    int i,j,opcion;
    char seguir = 's';
    while(seguir=='s')
        {
            printf("1- Ordenar por importe\n");
            printf("2- Ordenar por descripcion\n");
            printf("5- No ordenar.\n");

            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    for(i=0;i<20;i++)
                    {
                        if(lista[i].estado == 1)
                        {
                            for(j=i+1;j<20;j++)
                                {
                                if(lista[j].estado == 1)
                                {
                                    if(lista[i].importe<lista[j].importe)
                                    {
                                        aux=lista[i];
                                        lista[i]=lista[j];
                                        lista[j]=aux;
                                    }
                                }
                            }
                        }
                    }
                    printf("\nLos productos son: ");
                    for(i=0;i<20;i++)
                    {
                        if(lista[i].estado == 1)
                        {
                            printf("\nCodigo: %d\t Descripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
                        }
                    }
                    break;
                case 2:
                    {
                        if(lista[i].estado == 1)
                        {
                            for(j=i+1;j<20;j++)
                                {
                                if(lista[j].estado == 1)
                                {
                                    if(strcmp(lista[j].descripcion,lista[i].descripcion)<0)
                                    {
                                        aux=lista[i];
                                        lista[i]=lista[j];
                                        lista[j]=aux;
                                    }
                                }
                            }
                        }
                    }
                    printf("\nLos productos son: ");
                    for(i=0;i<20;i++)
                    {
                        if(lista[i].estado == 1)
                        {
                            printf("\nCodigo: %d\t Descripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
                        }
                    }
                    break;
                case 5://TERMINAR
                    seguir = 'n';
                    break;
        }
    }
}

void mostrarLista(eProducto lista[],int cantidad)
{
    int i,contador;
    float suma,promedio;
    printf("\nLos productos que superan las 10 unidades en stock son: \n");
    for(i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].cantidad > 10)
            {
                printf("\nCodigo: %d\tCodigo del proveedor: %d\tDescripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].idProveedor,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
            }
        }
    }
    printf("\nLos productos que no superan las 10 unidades en stock son: \n");
    for(i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].cantidad <= 10)
            {
                printf("\nCodigo: %d\tCodigo del proveedor: %d\tDescripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].idProveedor,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
            }
        }
    }
    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 1)
        {
            suma = suma + lista[i].importe;
            contador++;
        }
    }
    promedio = suma / contador;
    printf("\nLos productos que superan el importe promedio son: \n");
    for(i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].importe > promedio)
            {
                printf("\nCodigo: %d\tCodigo del proveedor: %d\tDescripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].idProveedor,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
            }
        }
    }
    printf("\nLos productos que no superan el importe promedio son: \n");
    for(i=0;i<20;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].importe < promedio)
            {
                printf("\nCodigo: %d\tCodigo del proveedor: %d\tDescripcion: %s\t Cantidad: %d\t Importe: %2.f\n",lista[i].codigo,lista[i].idProveedor,lista[i].descripcion,lista[i].cantidad,lista[i].importe);
            }
        }
    }
}

void informar(eProducto lista[],int cantidad)
{
    int i,contador,contadorExtra,contadorMenor,stockMenor,stockMayor;
    float suma,promedio;
    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 1)
        {
            suma = suma + lista[i].importe;
            contador++;
        }
    }
    promedio = suma / contador;
    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].importe > promedio)
            {
                contadorExtra++;
            }
            if(lista[i].importe < promedio)
            {
                contadorMenor++;
            }
            if(lista[i].cantidad <= 10)
            {
                stockMenor++;
            }
            if(lista[i].cantidad > 10)
            {
                stockMayor++;
            }
        }
    }
    printf("\nTotal: %.2f\nPromedio: %.2f\nCantidad de productos que superan el importe promedio: %d\n",suma,promedio,contadorExtra);
    printf("Cantidad de productos que no superan el importe promedio: %d\nCantidad de productos que no superan las 10 unidades en stock: %d\n",contadorMenor,stockMenor);
    printf("Cantidad de productos que si superan las 10 unidades en stock: %d\n",stockMayor);
}


//ITEM EXTRA: LISTAR PROVEEDORES CON SUS PRODUCTOS
//LISTAR LOS PRODUCTOS Y SUS PROVEEDORES

