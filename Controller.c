#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Deposito.h"
#include "Parser.h"
#include "utn.h"

int validIndiceProducto(ArrayList* pArray, Deposito* pElement)
{
    int auxProducto;
    int i;
    int pProducto;
    int retorno=-1;
    if(pArray!=NULL && pElement!=NULL)
    {
        Deposito* aux;
        Deposito_getProducto(pElement,&pProducto);
        for(i=0;i<al_len(pArray);i++)
        {
            aux = al_get(pArray,i);
            Deposito_getProducto(aux,&auxProducto);
            if(auxProducto==pProducto)
            {
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}

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
    int retorno = -1;
    int origen = getInt("Ingrese deposito origen:  < 0 | 1>");
    int destino = getInt("Ingrese deposito destino:  < 0 | 1>");
    Deposito* aux;
    if(origen == destino)
    {
        printf("ERROR!\n");
        return -1;
    }
    else
    {
        producto = getInt("Ingrese numero producto\n");
        if(!origen)
        {
            aux = pProducto(dep0,producto);
            if(aux!=NULL)
            {
                indice = al_indexOf(dep0,aux);
                al_add(dep1,al_pop(dep0,indice));
                if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                    retorno = 0;
            }
            else
                printf("PRODUCTO NO ENCONTRADO, ERROR!\n");
        }
        else if(origen==1)
        {
            aux = pProducto(dep1,producto);
            if(aux!=NULL)
            {
                indice = al_indexOf(dep1,aux);
                al_add(dep0,al_pop(dep1,indice));
                if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                    retorno = 0;
            }
            else
                printf("PRODUCTO NO ENCONTRADO, ERROR!\n");
        }
    }
    return retorno;
}

int Deposito_DescontarStock(ArrayList* dep0, ArrayList* dep1)
{
    int producto=0;
    int cantidadActual=0;
    int cantidadDescontar=0;
    int retorno=-1;
    Deposito* auxDep0;
    Deposito* auxDep1;
    if(dep0!=NULL && dep1!=NULL)
    {
        producto = getInt("Ingrese codigo de producto: \n");
        cantidadDescontar = getInt("Ingrese cantidad a descontar: \n");
        auxDep0 = pProducto(dep0,producto);
        auxDep1 = pProducto(dep1,producto);
            if(auxDep0!=NULL)
            {
                Deposito_getCantidad(auxDep0,&cantidadActual);
                if(cantidadActual==cantidadDescontar)
                {
                    al_remove(dep1,al_indexOf(dep0,auxDep0));
                    if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                        retorno = 0;
                }
                else if(cantidadActual>cantidadDescontar)
                {
                    cantidadActual=cantidadActual-cantidadDescontar;
                    Deposito_setCantidad(auxDep0,cantidadActual);
                    if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                        retorno = 0;
                }
                else
                {
                    printf("CANTIDAD DE STOCK ACTUAL: %d --- CANTIDAD A DESCONTAR: %d \n",cantidadActual,cantidadDescontar);
                }
                //indice = al_indexOf(dep0,aux);
                //al_get(dep0,indice);
            }
            else if(auxDep1!=NULL)
            {
                Deposito_getCantidad(auxDep1,&cantidadActual);
                if(cantidadActual==cantidadDescontar)
                {
                    al_remove(dep1,al_indexOf(dep1,auxDep1));
                    if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                        retorno = 0;
                }
                else if(cantidadActual>cantidadDescontar)
                {
                    cantidadActual=cantidadActual-cantidadDescontar;
                    Deposito_setCantidad(auxDep1,cantidadActual);
                    if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                        retorno = 0;
                }
                else
                {
                    printf("CANTIDAD DE STOCK ACTUAL: %d --- CANTIDAD A DESCONTAR: %d \n",cantidadActual,cantidadDescontar);
                }
            }
            else
            {
                printf("PRODUCTO NO ENCONTRADO EN NINGUN DEPOSITO\n");
            }
    }
    return retorno;
}

int Deposito_AgregarStock(ArrayList* dep0, ArrayList* dep1)
{
    int producto=0;
    int cantidadActual=0;
    int cantidadAgregar=0;
    int retorno=-1;
    Deposito* auxDep0;
    Deposito* auxDep1;
    if(dep0!=NULL && dep1!=NULL)
    {
        producto = getInt("Ingrese codigo de producto: \n");
        cantidadAgregar = getInt("Ingrese cantidad a agregar: \n");
        auxDep0 = pProducto(dep0,producto);
        auxDep1 = pProducto(dep1,producto);
            if(auxDep0!=NULL)
            {
                Deposito_getCantidad(auxDep0,&cantidadActual);
                if(cantidadAgregar>0)
                {
                    cantidadActual=cantidadActual+cantidadAgregar;
                    Deposito_setCantidad(auxDep0,cantidadActual);
                    if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                        retorno = 0;
                }
                else
                    printf("ERROR!! CANTIDAD DE STOCK ACTUAL: %d --- CANTIDAD A AGREGAR: %d \n",cantidadActual,cantidadAgregar);
                //indice = al_indexOf(dep0,aux);
                //al_get(dep0,indice);
            }
            else if(auxDep1!=NULL)
            {
                Deposito_getCantidad(auxDep1,&cantidadActual);
                if(cantidadAgregar>0)
                {
                    cantidadActual=cantidadActual+cantidadAgregar;
                    Deposito_setCantidad(auxDep1,cantidadActual);
                    if(!guardar_Deposito("dep1.csv",dep1) && !guardar_Deposito("dep0.csv",dep0))
                        retorno = 0;
                }
                else
                    printf("CANTIDAD DE STOCK ACTUAL: %d --- CANTIDAD A DESCONTAR: %d \n",cantidadActual,cantidadAgregar);
            }
            else
            {
                printf("PRODUCTO NO ENCONTRADO EN NINGUN DEPOSITO\n");
            }
    }
    return retorno;
}
