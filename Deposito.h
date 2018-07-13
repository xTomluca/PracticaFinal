#ifndef DEPOSITO_H_INCLUDED
#define DEPOSITO_H_INCLUDED
typedef struct
{
    int producto;
    char descripcion[128];
    int cantidad;
}Deposito;

Deposito* Deposito_new();
void Deposito_delete();
Deposito* Deposito_newConParametros(int producto,char* descripcion,int cantidad);
Deposito* Deposito_newConParametrosStr(char* productoStr,char* descripcionStr,char* cantidadStr);

int Deposito_setProducto(Deposito* this,int producto);
int Deposito_getProducto(Deposito* this,int* producto);

int Deposito_setDescripcion(Deposito* this,char* descripcion);
int Deposito_getDescripcion(Deposito* this,char* descripcion);

int Deposito_setCantidad(Deposito* this,int cantidad);
int Deposito_getCantidad(Deposito* this,int* cantidad);

#endif // DEPOSITO_H_INCLUDED
