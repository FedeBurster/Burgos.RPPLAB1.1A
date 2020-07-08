#include <stdio.h>
#include <stdlib.h>
#include "burgos.h"
#define ARRAY_LENGTH 50
int main()
{
    eMascota mascotas[ARRAY_LENGTH];
    eTrabajo trabajos[ARRAY_LENGTH];
    eCliente clientes[5];
    ePagos pagos[ARRAY_LENGTH];
    int flagMascotasId=11,flagTrabajoId=10010,flagTrabajoAlta=0,opcion,flagMascotasAlta=0,opcionDos,flagPagoId=450050;
    eTipo tipos[5];
    eColor colores[5];
    eServicio servicios[3];

    inicializarArrays(pagos,trabajos,mascotas,ARRAY_LENGTH);
    hardcodeoTiposColoresServicio(tipos,colores,servicios);
    hardCodeoEjemplos(clientes,mascotas,trabajos,&flagMascotasAlta,&flagTrabajoAlta,pagos);

    do{
        switch(opcion=mainMenu())
        {
            case 1:
                altaMascota(&flagMascotasAlta,&flagMascotasId,mascotas,ARRAY_LENGTH,clientes);
                break;
            case 2:
                modificarMascota(flagMascotasAlta,mascotas,ARRAY_LENGTH,clientes);
                break;
            case 3:
                bajaMascota(&flagMascotasAlta,mascotas,ARRAY_LENGTH,clientes);
                break;
            case 4:
                listarMascotas(flagMascotasAlta,mascotas,ARRAY_LENGTH,clientes);
                system("pause");
                break;
            case 5:
                listarTipos(tipos,5);
                system("pause");
                break;
            case 6:
                listarColores(colores,5);
                system("pause");
                break;
            case 7:
                listarServicios(servicios);
                system("pause");
                break;
            case 8:
                altaTrabajo(flagMascotasAlta,&flagTrabajoAlta,&flagTrabajoId,mascotas,servicios,trabajos,ARRAY_LENGTH,clientes,pagos,&flagPagoId);
                break;
            case 9:
                listarTrabajos(trabajos,ARRAY_LENGTH,mascotas,servicios);
                system("pause");
                break;
            case 10:
                switch(opcionDos=subMenuInformes())
                {
                    case 1:
                        mostrarMascotasPorColor(mascotas,colores,ARRAY_LENGTH,clientes);
                        break;
                    case 2:
                        mostrarMascotasPorTipo(mascotas,tipos,ARRAY_LENGTH,clientes);
                        break;
                    case 3:
                        informarMascotaMenorEdad(mascotas,ARRAY_LENGTH,clientes);
                        break;
                    case 4:
                        listarSeparadasTipo(mascotas,ARRAY_LENGTH,flagMascotasAlta,clientes);
                        break;
                    case 5:
                        contarColorTipo(colores,tipos,mascotas,ARRAY_LENGTH,flagMascotasAlta);
                        break;
                    case 6:
                        mostrarColorMasMascotas(mascotas,colores,ARRAY_LENGTH,flagMascotasAlta);
                        break;
                    case 7:
                        listarTrabajosPorMascota(trabajos,ARRAY_LENGTH,mascotas,servicios,flagMascotasAlta,clientes);
                        break;
                    case 8:
                        mostrarImporteMascota(flagMascotasAlta,flagTrabajoAlta,mascotas,ARRAY_LENGTH,clientes,trabajos);
                        break;
                    case 9:
                        mostrarUnServicio(flagMascotasAlta,flagTrabajoAlta,mascotas,ARRAY_LENGTH,clientes,trabajos,servicios);
                        break;
                    case 10:
                        mostrarServicioPorFecha(flagMascotasAlta,flagTrabajoAlta,mascotas,ARRAY_LENGTH,clientes,trabajos,servicios);
                        break;
                    case 11:
                        mostrarTotalACobrar(pagos,ARRAY_LENGTH);
                        break;
                    case 12:
                        mostrarDeudaPorCliente(clientes,pagos,ARRAY_LENGTH,mascotas);
                        break;
                    case 13:
                        mostrarClienteFiel(clientes,pagos,ARRAY_LENGTH);
                        break;
                    case 14:
                        servicioMasSolicitado(trabajos,servicios,ARRAY_LENGTH);
                        break;
                    case 15:
                        mostrarMascotasPorCliente(clientes,mascotas,ARRAY_LENGTH,flagMascotasAlta);
                        break;
                    case 16:
                        mostrarMascotasSeparadasColor(mascotas,ARRAY_LENGTH,flagMascotasAlta,clientes);
                        break;
                    case 17:
                        mascotaMayorDeEdad(mascotas,clientes,ARRAY_LENGTH,flagMascotasAlta);
                        break;
                }
                break;
        }
    }while(opcion!=0);
    return 0;
}
