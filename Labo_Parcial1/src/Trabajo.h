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
#define MARCA_LEN 25
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
	eFecha fecha;// (Validar día, mes y año
	int isEmpty;

}eTrabajo;

int IncrementarIdT (int *proximoId);
int agregarTrabajo(eTrabajo *lista, int len,int id, int idServicio);
int BuscarLibreT(eTrabajo *lista, int tam);
eTrabajo PedirDatosTrabajo();
eFecha pedirFecha(char mensaje[]);
int ImprimirTrabajos(eTrabajo *lista, eServicio *listaServ,int tam, int tamServ);
int inicializarTrabajos(eTrabajo *list, int len);






#endif /* TRABAJO_H_ */
