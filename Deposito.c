#include "Deposito.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

Deposito* Deposito_new()
{
    Deposito* this;
    this=malloc(sizeof(Deposito));
    return this;
}

void Deposito_delete(Deposito* this)
{
    free(this);
}

Deposito* Deposito_newConParametros(int producto,char* descripcion,int cantidad)
{
    Deposito* this;
    this=Deposito_new();

    if(
    !Deposito_setProducto(this,producto)&&
    !Deposito_setDescripcion(this,descripcion)&&
    !Deposito_setCantidad(this,cantidad))
        return this;

    Deposito_delete(this);
    return NULL;
}

Deposito* Deposito_newConParametrosStr(char* productoStr,char* descripcionStr,char* cantidadStr)
{
    Deposito* this;
    this=Deposito_new();
    int cantidad;
    int producto;
    if(esNumerico(productoStr)&& esNumerico(productoStr))
    {
        cantidad = atoi(cantidadStr);
        producto = atoi(productoStr);
    }

    if(
    !Deposito_setProducto(this,producto)&&
    !Deposito_setDescripcion(this,descripcionStr)&&
    !Deposito_setCantidad(this,cantidad))
        return this;

    Deposito_delete(this);
    return NULL;
}

int Deposito_setProducto(Deposito* this,int producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->producto=producto;
        retorno=0;
    }
    return retorno;
}

int Deposito_getProducto(Deposito* this,int* producto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *producto=this->producto;
        retorno=0;
    }
    return retorno;
}

int Deposito_setDescripcion(Deposito* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(this->descripcion,descripcion);
        retorno=0;
    }
    return retorno;
}

int Deposito_getDescripcion(Deposito* this,char* descripcion)
{
    int retorno=-1;
    if(this!=NULL && descripcion!=NULL)
    {
        strcpy(descripcion,this->descripcion);
        retorno=0;
    }
    return retorno;
}

int Deposito_setCantidad(Deposito* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Deposito_getCantidad(Deposito* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

