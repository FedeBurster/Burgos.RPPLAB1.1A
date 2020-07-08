#ifndef BURGOS_H
#define BURGOS_H

#include "tipo.h"
#include "color.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "fecha.h"
#include "informes.h"
#include "cliente.h"
#include "pagos.h"

int mainMenu();
int hardcodeoTiposColoresServicio(eTipo *tipos,eColor *colores,eServicio *servicios);
int inicializarArrays(ePagos*pagos,eTrabajo*trabajos,eMascota*mascotas,int length);
int validateString(char* message, char* messageError, int maxLengthString, char* auxString);
int validarStringIdColor(char stringInt[]);
int validarStringInt(char stringInt[]);

int hardCodeoEjemplos(eCliente*clientes,eMascota*mascotas,eTrabajo*trabajos,int*flagAltaMascotas,int*flagAltaTrabajos,ePagos*pagos);

int getInt(char message[], char messageError[], int limiteMin, int limiteMax);

#endif
