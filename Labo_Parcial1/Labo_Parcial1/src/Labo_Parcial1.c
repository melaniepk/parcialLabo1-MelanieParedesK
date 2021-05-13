/*
 ============================================================================
 Name        : Labo_Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn1.h"
#include "Servicio.h"
#include "Trabajo.h"
#define TAM_SERV 4
#define TAM_TRABAJO 15

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	int idServElegido;
	int IdIncremental;
	int id = 0;
	int banderaDeCompletado=0;
	int retorno;

	eServicio arrayServicios[TAM_SERV];
	eTrabajo arrayTrabajos[TAM_TRABAJO];

	inicializarTrabajos(arrayTrabajos,TAM_TRABAJO);
	inicializarServicios(arrayServicios,TAM_SERV);


	agregarServicio(arrayServicios,4,0, 20000, "Limpieza",250);
	agregarServicio(arrayServicios,4,1, 20001, "Parche",300);
	agregarServicio(arrayServicios,4,2, 20002, "Centrado",400);
	agregarServicio(arrayServicios,4,3, 20003, "Cadena",350);

	do
	{
		if(utn_getNumero(&opcion,"Ingrese una opcion del men� entre las siguientes:\n"
				"1. ALTA TRABAJO\n2. MODIFICAR TRABAJO\n3. BAJA TRABAJO\n4. LISTAR TRABAJOS\n"
				"5. LISTAR SERVICIOS\n6. TOTAL en pesos por los servicios prestados\n","ERROR. Opcion no valida\n",1,6,10)==0)
		{
			switch(opcion)
			{
			case 1:
				IdIncremental = IncrementarIdT(&id);
				ImprimirServicios(arrayServicios,TAM_SERV);
				if(utn_getNumero(&idServElegido,"Ingrese el ID del servicio que desea contratar", "ERROR!", 20000,20003,10)==0)
				{
					agregarTrabajo(arrayTrabajos, TAM_TRABAJO, IdIncremental,idServElegido);
				}
				banderaDeCompletado = 1;
				break;
			case 2:
				if(banderaDeCompletado != 0)
				{

				}
				else
				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 3:
				if(banderaDeCompletado != 0)
				{
					ImprimirServicios(arrayServicios,TAM_SERV);
					retorno = ModificarTrabajo(arrayTrabajos, TAM_TRABAJO);
					if(retorno == -1)
					{
						printf("No se pudo modificar al trabajo o el ID no existe\n");
					}
					else
					{
						printf("Trabajo modificado\n");
					}
				}
				else

				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 4:
				if(banderaDeCompletado != 0)
				{
					ImprimirTrabajos(arrayTrabajos, arrayServicios,TAM_TRABAJO, TAM_SERV);
				}
				else
				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 5:
				if(banderaDeCompletado != 0)
				{
					ImprimirServicios(arrayServicios, TAM_SERV);
				}
				else
				{
					printf("Error! primero debe cargar trabajos");
				}
				break;
			case 6:
				break;
			}
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
