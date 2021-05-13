/*
 * Trabajo.c
 *
 *  Created on: 13 may. 2021
 *      Author: mkale
 */
#include "utn1.h"
#include "Trabajo.h"
#include "Servicio.h"
#define FALSE 1
#define TRUE 0

int inicializarTrabajos(eTrabajo *list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;
			retorno = 0;
		}
	}

	return retorno;
}


eTrabajo PedirDatosTrabajo()
{
    eTrabajo miTrabajo;

	utn_getString(miTrabajo.marcaBicicleta ,MARCA_LEN, "\nIngrese la marca de la bicicleta", "\nError!. ", 10);
	utn_getNumeroFlotante(&miTrabajo.rodadoBicicleta,"Ingrese el rodado de la bicicleta:\n","Error al ingresar el rodado.\n",1,50,10);
    miTrabajo.fecha = pedirFecha("Ingrese fecha");


    return miTrabajo;

}

int BuscarLibreT(eTrabajo *lista, int tam)
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

int IncrementarIdT (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	return nuevoId;
}

int agregarTrabajo(eTrabajo *lista, int len,int id, int idServicio)
{

	int i;
	int retorno = -1;

	if(lista != NULL && len > 0)
	{
		i = BuscarLibreT(lista, len);
		if (i != -1)
		{
			lista[i] = PedirDatosTrabajo();
			lista[i].id = id;
			lista[i].idServicio = idServicio;
			lista[i].isEmpty = FALSE;

			retorno = 0;
		}

	}
	return retorno;
}


eFecha pedirFecha(char mensaje[])
{
	eFecha miFecha;
	utn_getNumero(&miFecha.dia,"Ingrese dia", "ERROR! no existe ese dia",1,31,5);
	utn_getNumero(&miFecha.mes,"Ingrese mes", "ERROR! no existe ese mes",1,12,5);
	utn_getNumero(&miFecha.dia,"Ingrese anio", "ERROR! no existe ese año",2020,2100,5);

	return miFecha;
}



int ImprimirTrabajos(eTrabajo *lista, eServicio *listaServ,int tam, int tamServ)
{

	int retorno = -1;
	int i;
	int j;
	if(lista != NULL && tam > 0 && listaServ != NULL && tamServ >=0)
	{

		for(i=0;i<tam;i++)
		{

			for(j=0;j<tamServ;j++)
			{

				if(lista[i].isEmpty == FALSE &&  listaServ[i].isEmpty == FALSE &&lista[i].idServicio == listaServ[j].id)
				{
					printf("  ID del trabajo    Marca       Rodado      Id del servicio        Fecha\n ");

					printf(" %d           %s         %.2f          %d          %d/%d/%d \n ", lista[i].id,
															   lista[i].marcaBicicleta,
															   lista[i].rodadoBicicleta,
															   listaServ[j].id,
															   lista[i].fecha.dia,
															   lista[i].fecha.mes,
															   lista[i].fecha.anio);
				}
				retorno = 0;

			}


		}
	}
	return retorno;
}
