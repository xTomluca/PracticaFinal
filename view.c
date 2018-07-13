#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Deposito.h"
#include "view.h"
#include "utn.h"
void printf_ImprimirProducto(void* p)
{
    if(p!=NULL)
    {
        Deposito* aux = p;
        int cantidad;
        int producto;
        char descripcion[50];
        Deposito_getCantidad(aux,&cantidad);
        Deposito_getDescripcion(aux,descripcion);
        Deposito_getProducto(aux,&producto);
        printf("    %d  -   %s  -  %d\n",producto,descripcion,cantidad);
    }
}
void printf_Productos(ArrayList* dep0, ArrayList* dep1)
{
    int opcion;
    if(dep0!=NULL && dep1 !=NULL)
    {
        opcion = getInt("DEPOSITO A LISTAR <0 | 1>\n");
        if(!opcion)
            al_map(dep0,printf_ImprimirProducto);
        else if(opcion==1)
            al_map(dep1,printf_ImprimirProducto);
        else
            printf("OPCION INCORRECTA!\n");
    }
}

