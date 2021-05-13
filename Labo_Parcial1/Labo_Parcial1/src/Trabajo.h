/*
 * Trabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: mkale
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "utn1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#define MARCA_LEN 26
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct
{
	int id;// (autoincremental)
	char marcaBicicleta[MARCA_LEN]; //(Cadena) Validar
	float rodadoBicicleta;
	int idServicio; //(debe existir) Validar
	eFecha fecha;// (Validar d�a, mes y a�o
	int isEmpty;

}eTrabajo;

int IncrementarIdT (int *proximoId);
int agregarTrabajo(eTrabajo *lista, int len,int id, int idServicio);
int BuscarLibreT(eTrabajo *lista, int tam);
eTrabajo PedirDatosTrabajo();
eFecha pedirFecha(char mensaje[]);
int ImprimirTrabajos(eTrabajo *lista, eServicio *listaServ,int tam, int tamServ);
int inicializarTrabajos(eTrabajo *list, int len);
int bajaTrabajo(eTrabajo *lista, int len,int id);
int ModificarTrabajo(eTrabajo *lista, int tam);







#endif /* TRABAJO_H_ */
