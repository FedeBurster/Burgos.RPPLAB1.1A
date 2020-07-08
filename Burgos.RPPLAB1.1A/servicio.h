#ifndef SERVICIO_H
#define SERVICIO_H
struct {
    int servicioId;
    char servicioDescripcion[25];
    float servicioPrecio;
}typedef eServicio;

int listarServicios(eServicio *servicios);
#endif
