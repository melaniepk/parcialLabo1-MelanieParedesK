/*
 * Servicio.h
 *
 *  Created on: 13 may. 2021
 *      Author: mkale
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
#include "utn1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ID_SERV 20000
#define FALSE 1
#define TRUE 0


typedef struct
{
	int id;// (comienza en 20000, autoincremental)
	char descripcion[25];// (máximo 25 caracteres)
	float precio;
	int isEmpty;
}eServicio;

int agregarServicio(eServicio *lista, int tam,int indice, int idServicio,char *descripcion ,float precio);

int IncrementarId (int *proximoId);
int BuscarLibre(eServicio *lista, int tam);
int ImprimirServicios(eServicio *lista, int len);
int inicializarServicios(eServicio *lista, int tam);




#endif /* SERVICIO_H_ */
