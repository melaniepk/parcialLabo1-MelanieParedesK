/*
 * Servicio.c
 *
 *  Created on: 13 may. 2021
 *      Author: mkale
 */
#include "Servicio.h"
/*
int BuscarLibre(eServicio *lista, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty== TRUE)
        {
            index = i;
            break;
        }
    }
    return index;
}
*/
/*
eServicio PedirDatosServicio()
{
    eServicio miServicio;

		utn_getString(miServicio.descripcion ,sizeof(miServicio.descripcion ), "\nIngrese el apellido del empleado", "\nError!. ", 10);
		utn_getNumeroFlotante(&miServicio.precio,"Ingrese el salario del empleado:\n","Error al ingresar salario.\n",100,999999,10);
		utn_getNumero(&miServicio.id,"Ingrese el sector del empleado: \n","Sector no registrado\n",1,100,10);



    return miServicio;

}*/
/*
int IncrementarId (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	 return nuevoId;
}
*/
int agregarServicio(eServicio *lista, int tam,int indice, int idServicio,char *descripcion ,float precio)
{

	int retorno = -1;
	eServicio bufferServicio;

	if(lista != NULL && tam > 0 && indice >=0  && descripcion != NULL)
	{

		strncpy(bufferServicio.descripcion, descripcion, sizeof(bufferServicio.descripcion));
		bufferServicio.id = idServicio;
		bufferServicio.precio = precio;
		bufferServicio.isEmpty = FALSE;
		lista[indice] = bufferServicio;

			retorno = 0;


	}
	return retorno;
}

int ImprimirServicios(eServicio *lista, int len)
{

	int retorno = -1;
	int i;
	if(lista != NULL && len > 0)
	{
			   printf("  ID     Descripcion      Precio\n ");

		for(i=0;i<len;i++)
		{
			if(lista[i].isEmpty != TRUE)
			{
				retorno = 0;

				printf(" %d      %s         %.2f\n ", lista[i].id,
														   lista[i].descripcion,
														   lista[i].precio);
			}

		}
	}
	return retorno;
}

int inicializarServicios(eServicio *lista, int tam)
{
	int retorno = -1;
	int i;
	if(lista != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			lista[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}


