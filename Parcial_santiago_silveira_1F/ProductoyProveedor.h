#ifndef PRODUCTOYPROVEEDOR_H_INCLUDED
#define PRODUCTOYPROVEEDOR_H_INCLUDED

typedef struct {
    int idProveedor;
    char descripcionProveedor[51];
}proveedor;

/** \brief
 *
 * \param empresas[] proveedor Establece el nombre de los proveedores junto a sus ids
 * \return void
 *
 */
void hardCode(proveedor empresas[]);

typedef struct
{
    int codigo;
    int idProveedor;
    int cantidad;
    int estado;
    char descripcion[51];
    float importe;
}eProducto;

/** \brief
 * menu() imprime el menu en pantalla
 * \return void
 *
 */
void menu();

/** \brief
 * inicializar()
 * \param lista[] eProducto Inicializa los estados de cada ficha de producto
 * \param cantidad int Cantidad de fichas productos disponible para listar
 * \return void
 *
 */
void inicializar(eProducto lista[], int cantidad);

/** \brief
 * inicializar()
 * \param lista[] eProducto Busca una ficha libre y la rellena con las caracteristicas del producto
 * \param cantidad int Cantidad de fichas productos disponible para listar
 * \return void
 *
 */
void agregarProducto(eProducto lista[], int cantidad);

/** \brief
 * modificarProducto()
 * \param lista[] eProducto Permite modificar cualquier caracterisca de un producto ingresando su codigo
 * \return void
 *
 */
void modificarProducto(eProducto lista[]);

/** \brief
 * borrarProducto()
 * \param lista[] eProducto Elimina la ficha del producto seleccionado por su codigo
 * \return void
 *
 */
void borrarProducto(eProducto lista[]);

/** \brief
 * listarProductos()
 * \param lista[] eProducto Lista las fichas de productos y las muestra segun ciertas condiciones
 * \param aux eProducto Utiliza un auxiliar para hacer el ordenamiento
 * \return void
 *
 */
void listarProductos(eProducto lista[],eProducto aux);

/** \brief
 *  mostrarLista()
 * \param lista[] eProducto Muestra productos que cumplen con ciertas condiciones
 * \param cantidad int Cantidad de fichas productos disponible para listar
 * \return void
 *
 */
void mostrarLista(eProducto lista[], int cantidad);

/** \brief
 *  informar()
 * \param lista[] eProducto Informa del estado de ciertos productos listados
 * \param cantidad int Cantidad de fichas productos disponible para listar
 * \return void
 *
 */
void informar(eProducto lista[],int cantidad);

#endif // FUNCIONES_H_INCLUDED

