#include <stdio.h>
#include <stdlib.h>
#include "ProductoyProveedor.h"
#include "ComprobarYLimites.h"

int main()
{
    char seguir = 's';
    int opcion;
    int cantidad=20;
    proveedor empresas[5];
    eProducto lista[20],aux;
    inicializar(lista,20);

    while(seguir=='s')
    {
        menu();

        opcion=getInt("","",1,6,1);

        switch(opcion)
        {
            case 1://AGREGAR
                agregarProducto(lista,cantidad);
                break;
            case 2://MODIFICAR
                modificarProducto(lista);
                break;
            case 3://BORRAR
                borrarProducto(lista);
                break;
            case 4://INFORMAR
                informar(lista,cantidad);
                break;
            case 5://LISTAR
                listarProductos(lista,aux);
                mostrarLista(lista,cantidad);
                break;
            case 6://SALIR
                seguir = 'n';
                break;
        }
    }
    return 0;
}
