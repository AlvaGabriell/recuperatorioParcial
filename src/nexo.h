/*
 * nexo.h
 *
 *  Created on: 6 dic. 2022
 *      Author: Usuario
 */
#include "utn.h"
#include "vehiculo.h"
#include "tipo.h"
#include "fecha.h"
#include "servicio.h"

#ifndef NEXO_H_
#define NEXO_H_



#endif /* NEXO_H_ */
eVehiculo NEXO_pedirDatoEmpleado(int id, eTipo tipos[],int tamT);
int NEXO_altaEmpleados(eVehiculo empleados[],int tam,int id,eTipo tipos [], int tamT);
void NEXO_mostrarEmpleado(eVehiculo empleado, eTipo tipos[],int tamT );
int NEXO_mostrarEmpleados(eVehiculo empleados[],int tam,eTipo tipos[],int tamT);
eVehiculo NEXO_buscarUnoPorId(eVehiculo empleados[],int tam,int id);
int NEXO_buscarPosicionPorId(eVehiculo empleados[],int tam,int id);
eServicio NEXO_pedirDatoHoja(int id, eVehiculo vehiculos[],int tamVehi,eTipo tipos[],int tamTipo);
int NEXO_darDebajaEmpleado(eVehiculo empleados[],int tam,eTipo tipos[],int tamT);
int NEXO_modificarVehi(eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamTipo, int id,eServicio servicios[], int tamServicio);
int nexo_imprimirTipos(eVehiculo listaVehiculo[], int tam, eTipo tipos[],int tamT);
int nexo_informes(eVehiculo listaVehiculo[], int tam, eTipo tipos[],int tamT,eServicio servicios[],int tamS);
int nexo_imprimirPorFechaSeleccion(eServicio servicios[], int tamS);
int nexo_imprimirAcumPorFecha(eServicio servicios[], int tamS);
int nexo_imprimirPorIdAuto(eServicio servicios[], int tamS,eVehiculo vehiculos[],int tamV,eTipo tipos[],int tamT);
