#ifndef MASCOTA_H
#define MASCOTA_H
#include "cliente.h"
#include "burgos.h"
struct {
    int mascotaId;
    char mascotaNombre[20];
    int mascotaIdTipo;
    int mascotaIdColor;
    int mascotaEdad;
    int mascotaIdCliente;
}typedef eMascota;

int altaMascota(int*flagAlta,int*flagId,eMascota *mascotas,int length,eCliente*clientes);

int listarMascotas(int flagAlta,eMascota *mascotas,int length,eCliente*clientes);
int listarMascota(eMascota *mascotas,int index,eCliente*clientes);

int modificarMascota(int flagAlta,eMascota *mascotas,int length,eCliente*clientes);

int bajaMascota(int*flagAlta,eMascota*mascotas,int length,eCliente*clientes);

#endif
