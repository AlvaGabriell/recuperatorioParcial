/*
 * servicio.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Usuario
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_
typedef struct
{
	int idHoja;
	int vehiculoId;
	char descipcion[50];
	int precioServicio;
	eFecha fecha;
	int isEmpty;
}eServicio;

#endif /* SERVICIO_H_ */
int SERVI_inicializarArray(eServicio empleados[], int tam);
int SERVI_buscarArrayLibre(eServicio empleados[],int tam);
eServicio SERVI_pedirDatoHoja(int id);
int SERVI_altaEmpleados(eServicio empleados[],int tam,int id);
void SERVI_mostrarEmpleado(eServicio empleado);
int SERVI_mostrarEmpleados(eServicio empleados[],int tam);
eServicio SERVI_buscarUnoPorId(eServicio empleados[],int tam,int id);
int SERVI_buscarPosicionPorId(eServicio empleados[],int tam,int id);
