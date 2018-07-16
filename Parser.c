#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Deposito.h"
#include "Controller.h"


/** \brief  Parser
 * \param   char* fileName is path file
 * \param   ArrayList* listaEmpleados
 * \return  Return [1]
 */
int parser_Deposito(char* fileName, ArrayList* pArray)
{
    Deposito* aux;
    char producto[50];
    char descripcion[50];
    char cantidad[50];
    int cantidadLeida;
    /*int canTest = 0;
    char desTest[50];
    int proTest = 0;*/
    FILE* fp;
    fp = fopen(fileName,"r");
    if(fp!=NULL)
    {
        fscanf(fp,"%[^,],%[^,],%[^\n]\n",producto,descripcion,cantidad);
        while(!feof(fp))
        {
            cantidadLeida = fscanf(fp,"%[^,],%[^,],%[^\n]\n",producto,descripcion,cantidad);
            if(cantidadLeida==3)
            {
                aux = Deposito_newConParametrosStr(producto,descripcion,cantidad);
                if(aux!=NULL && validIndiceProducto(pArray,aux))
                {
                    al_add(pArray,aux);
                //Deposito_getCantidad(aux,&canTest);
                //Deposito_getDescripcion(aux,desTest);
                //Deposito_getProducto(aux,&proTest);
                //printf("%d      %s      %d\n",proTest,desTest,canTest);
                }
            }
        }
    }
    fclose(fp);

    return 1; // OK
}
