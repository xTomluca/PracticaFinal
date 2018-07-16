#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Deposito.h"
#include "view.h"
#include "utn.h"
#include "Controller.h"
#include "Parser.h"
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
void printf_MenuPrincipal(ArrayList* dep0, ArrayList* dep1)
{
    int opcion=0;
    char seguir = 's';
    do
    {
        printf("MENU DE OPCIONES: \n");
        printf("1) CARGAR DEPOSITOS \n");
        printf("2) LISTAR DEPOSITO \n");
        printf("3) MIGRAR PRODUCTO \n");
        printf("4) DESCONTAR STOCK \n");
        printf("5) AGREGAR STOCK \n");
        printf("6) SALIR \n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
            case 1:
                parser_Deposito("dep0.csv",dep0);
                parser_Deposito("dep1.csv",dep1);
                break;
            case 2:
                printf_Productos(dep0,dep1);
                break;
            case 3:
                Deposito_migrar(dep0,dep1);
                break;
            case 4:
                Deposito_DescontarStock(dep0,dep1);
                break;
            case 5:
                Deposito_AgregarStock(dep0,dep1);
                break;
            case 6:
                seguir = 'n';
                break;

        }
    }
    while(seguir!='n');
}

