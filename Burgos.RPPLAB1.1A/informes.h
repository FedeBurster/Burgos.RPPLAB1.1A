#ifndef INFORMES_H
#define INFORMES_H
#include "pagos.h"

int mostrarMascotasPorColor(eMascota*mascotas,eColor*colores,int length,eCliente*clientes);
int mostrarMascotasPorTipo(eMascota*mascotas,eTipo*tipos,int length,eCliente*clientes);
int informarMascotaMenorEdad(eMascota*mascotas,int length,eCliente*clientes);
int listarSeparadasTipo(eMascota*mascotas,int length,int flagAlta,eCliente*clientes);
int contarColorTipo(eColor*colores,eTipo*tipos,eMascota*mascotas,int length,int flagAlta);
int mostrarColorMasMascotas(eMascota*mascotas,eColor*colores,int length,int flagAlta);
int subMenuInformes();
int listarTrabajosPorMascota(eTrabajo*trabajos,int length,eMascota*mascotas, eServicio*servicios,int flagAlta,eCliente*clientes);
int mostrarImporteMascota(int flagAltaMascota,int flagAltaTrabajos,eMascota*mascotas,int length,eCliente*clientes,eTrabajo*trabajos);
int mostrarUnServicio(int flagAltaMascota,int flagAltaTrabajos,eMascota*mascotas,int length,eCliente*clientes,eTrabajo*trabajos,eServicio*servicios);
int mostrarServicioPorFecha(int flagAltaMascota,int flagAltaTrabajos,eMascota*mascotas,int length,eCliente*clientes,eTrabajo*trabajos,eServicio*servicios);
int mostrarTotalACobrar(ePagos*pagos,int length);
int mostrarClienteFiel(eCliente*clientes,ePagos*pagos,int length);
int servicioMasSolicitado(eTrabajo*trabajos,eServicio*servicios,int length);
int mostrarDeudaPorCliente(eCliente*clientes,ePagos*pagos,int length,eMascota*mascotas);
int mostrarMascotasPorCliente(eCliente*clientes,eMascota*mascotas,int length,int flagAlta);
int mostrarMascotasSeparadasColor(eMascota*mascotas,int length,int flagAlta,eCliente*clientes);
int mascotaMayorDeEdad(eMascota*mascotas,eCliente*clientes,int length,int flagAlta);

#endif
