/*
 * tipo.h
 *
 *  Created on: 7 dic. 2022
 *      Author: Usuario
 */

#ifndef TIPO_H_
#define TIPO_H_
typedef struct
{
	int idTipo;
	char descripcion[50];
}eTipo;

#endif /* TIPO_H_ */
void TIPO_mostrarEmpleado(eTipo empleado);
int TIPO_mostrarEmpleados(eTipo empleados[],int tam);
eTipo TIPO_buscarSecPorId(eTipo listaSec[],int tamSec,int id);
