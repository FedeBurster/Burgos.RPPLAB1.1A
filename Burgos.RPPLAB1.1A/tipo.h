struct{
    int tipoId;
    char tipoDescripcion[20];
}typedef eTipo;

#ifndef TIPO_H
#define TIPO_H

int listarTipos(eTipo *tipos,int length);

#endif
