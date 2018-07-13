/***
* 1- Cargar depositos: Se deberan leer ambos archiuos y generar dos Arraylist con los datos.
* 2- Listar productos de deposito: Se le pedira al usuario el numero de deposito (1 o 2) y se imprimira la lista de productos en dicho deposito.
* 3- Mover productos a deposito: Se le pedira al usuario que ingrese el numero de deposito origen y luego el numero de deposito destino. Luego se le pedira al usuario que ingrese el
* codigo del producto a mover(debera existir en el deposito origen). Los productos deberan borrarse del deposito origen y agregarse al deposito destino.
* (Esta operacion se hace sobre la cantidad total de los productos, no puede quedar el mismo codigo de producto en ambos depositos).
* 4- Descontar productos de deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Se le pedira al usuario que ingrese
* la cantidad de productos a descontar y dicha cantidad se restara a la cantidad actual de productos de ese tipo en el deposito correspondiente,
* si es que existe esa cantidad disponible.
* 5- Agregar productos a deposito: Se ingresara el codigo del producto, se debera detectar en que deposito se encuentra. Luego se le pedira al usuario que ingrese
* la camntidad de productos a sumar y dicha cantidad se sumara a la cantidad actual de productos de ese tipo en el deposito correspondiente.
* 6- Salir.
*
* NOTA: Cada vez que se haga una modificacion sobre un deposito, la misma se debe reflejarse en el archivo csv correspondiente a dicho deposito
* El cambio no puede realizarse solo en el ArrayList.
***/

#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"
#include "ArrayList.h"
#include "view.h"
#include "Deposito.h"
#include "utn.h"
void* pProducto(ArrayList* pArray,int numProduc)
{
    Deposito* aux;
    int i,producto;
    if(pArray!=NULL)
    {
        for(i=0;i<al_len(pArray);i++)
        {
            aux= al_get(pArray,i);
            Deposito_getProducto(aux,&producto);
            if(producto==numProduc)
            {
                return aux;
                break;
            }
        }
    }
    return NULL;
}
int Deposito_migrar(ArrayList* dep0, ArrayList* dep1)
{
    int indice;
    int producto;
    int origen = getInt("Ingrese deposito  < 0 | 1>");
    int destino = getInt("Ingrese deposito < 0 | 1>");
    Deposito* aux=NULL;
    if(origen == destino)
    {
        printf("ERROR!");
        return -1;
    }
    else
    {
        producto = getInt("Ingrese numero producto\n");
        if(!origen)
        {
            aux = pProducto(dep0,producto);
            indice = al_indexOf(dep0,aux);
            al_add(dep1,al_pop(dep0,indice));

        }

        else if(origen==1)
        {
            aux = pProducto(dep1,producto);
            indice = al_indexOf(dep1,aux);
            al_add(dep0,al_pop(dep1,indice));
        }
    }
    return 0;
}
int main()
{
    ArrayList* dep0=al_newArrayList();
    ArrayList* dep1=al_newArrayList();
    parser_Deposito("dep0.csv",dep0);
    parser_Deposito("dep1.csv",dep1);
    Deposito_migrar(dep0,dep1);
    printf_Productos(dep0,dep1);
    printf_Productos(dep0,dep1);
    return 0;
}
