#include "burgos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/** \brief
 *
 * \param *flagAlta int direccion de memoria a bandera alta
 * \param *flagId int direccion de memoria a la bandera id
 * \param *mascotas eMascota array de estructuras eMascota
 * \param length int longitud de array
 * \param *clientes eCliente array de estructuras eCliente
 * \return 1 si el alta completa con exito, 0 de lo contrario
 *
 */
int altaMascota(int *flagAlta,int*flagId,eMascota *mascotas,int length,eCliente*clientes)
{
    int i,flag=0,auxInt,j;
    char auxString[20];
    for(i=0;i<length;i++)
    {
        if(mascotas[i].mascotaId==-1)
        {
            ////NOMBRE MASCOTA
            validateString("\nIngrese el nombre: ","\n\nEl nombre debe estar compuesto unicamente de caracteres alfabeticos.\nVuelva a ingresar el nombre: ",20,mascotas[i].mascotaNombre);
            ///////TIPO MASCOTA
            printf("\n1)Ave\n2)Perro\n3)Gato\n4)Roedor\n5)Pez\nIngrese el tipo de su mascota: ");
            scanf("%s",auxString);
            fflush(stdin);
            if(validarStringIdColor(auxString)==0)
            {
                do{
                    printf("\n1)Ave\n2)Perro\n3)Gato\n4)Roedor\n5)Pez\nVuelva ingresar el tipo de su mascota: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                }while(validarStringIdColor(auxString)==0);
            }
            mascotas[i].mascotaIdTipo=atoi(auxString)+999;
            /////COLOR MASCOTA
            printf("\n1)Negro\n2)Blanco\n3)Gris\n4)Rojo\n5)Azul\nIngrese el color de su mascota: ");
            scanf("%s",auxString);
            fflush(stdin);
            if(validarStringIdColor(auxString)==0)
            {
                do{
                    printf("\n1)Negro\n2)Blanco\n3)Gris\n4)Rojo\n5)Azul\nVuelva a ingresar el color de su mascota: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                }while(validarStringIdColor(auxString)==0);
            }
            mascotas[i].mascotaIdColor=atoi(auxString)+4999;
            /////EDAD MASCOTA
            printf("\nIngrese la edad de su mascota: ");
            scanf("%s",auxString);
            fflush(stdin);
            if(validarStringInt(auxString)==0)
            {
                do{
                    printf("\nVuelva a ingresar la edad de su mascota: ");
                    scanf("%s",auxString);
                    fflush(stdin);
                }while(validarStringInt(auxString)==0);
            }
            mascotas[i].mascotaEdad=atoi(auxString);
            /////////////ID CLIENTE
            do{
                listarClientes(clientes);
                printf("\nIngrese ID del cliente: ");
                scanf("%d",&auxInt);
                fflush(stdin);
                for(j=0;j<5;j++)
                {
                    if(clientes[j].clienteId==auxInt)
                    {
                        flag=1;
                    }
                }
                if(flag==0)
                {
                    printf("\nError, cliente inexistente\n");
                }
            }while(flag==0);
            mascotas[i].mascotaIdCliente=auxInt;
            ////ID MASCOTA
            *flagAlta=*flagAlta+1;
            *flagId=*flagId+1;
            mascotas[i].mascotaId=*flagId;
            printf("\nSe asigno el ID %d",mascotas[i].mascotaId);
            printf("\nAlta terminado correctamente\n");
            system("pause");
            return 1;
        }
    }
    return 0;
}
/** \brief muestra todos los datos del array eMascota
 *
 * \param flagAlta int bandera alta
 * \param *mascotas eMascota array de estructuras eMascota
 * \param length int longitud de array
 * \param *clientes eCliente array de estructuras eCliente
 * \return 1
 *
 */
int listarMascotas(int flagAlta,eMascota *mascotas,int length,eCliente*clientes)
{
    int i;
    if(flagAlta==0)
    {
        printf("\nSe debe dar de alta al menos una mascota para acceder a esta opcion\n");
        system("pause");
        return 0;
    }
    printf("\nID               NOMBRE   TIPO  COLOR EDAD DUENIO");
    for(i=0;i<length;i++)
    {
        if(mascotas[i].mascotaId!=-1)
        {
            listarMascota(mascotas,i,clientes);
        }
    }
    printf("\n");
    return 1;
}

/** \brief muestra una estructura eMascota
 *
 * \param *mascotas eMascota array de estructuras eMascota
 * \param index int indice
 * \param *clientes eCliente array de estructuras eCliente
 * \return 1
 *
 */
int listarMascota(eMascota *mascotas,int index,eCliente*clientes)
{
    int i;
    printf("\n%2d %20s ",mascotas[index].mascotaId,mascotas[index].mascotaNombre);
    if(mascotas[index].mascotaIdTipo==1000)
    {
        printf("   Ave ");
    }
    if(mascotas[index].mascotaIdTipo==1001)
    {
        printf(" Perro ");
    }
    if(mascotas[index].mascotaIdTipo==1002)
    {
        printf("  Gato ");
    }
    if(mascotas[index].mascotaIdTipo==1003)
    {
        printf("Roedor ");
    }
    if(mascotas[index].mascotaIdTipo==1004)
    {
        printf("   Pez ");
    }

    if(mascotas[index].mascotaIdColor==5000)
    {
        printf(" Negro ");
    }
    if(mascotas[index].mascotaIdColor==5001)
    {
        printf(" Blanco");
    }
    if(mascotas[index].mascotaIdColor==5002)
    {
        printf("  Gris ");
    }
    if(mascotas[index].mascotaIdColor==5003)
    {
        printf("  Rojo ");
    }
    if(mascotas[index].mascotaIdColor==5004)
    {
        printf("  Azul ");
    }
    printf("%3d",mascotas[index].mascotaEdad);
    for(i=0;i<5;i++)
    {
        if(mascotas[index].mascotaIdCliente==clientes[i].clienteId && clientes[i].clienteId!=-1)
        {
            printf("  %s",clientes[i].clienteNombre);
        }
    }
    return 1;
}

/** \brief permite modificar tipo y edad de una mascota
 *
 * \param flagAlta int bandera alta
 * \param *mascotas eMascota array de estructuras eMascota
 * \param *clientes eCliente array de estructuras eCliente
 * \return 1 si los cambios se completan con exito, 0 de lo contrario
 *
 */
int modificarMascota(int flagAlta,eMascota *mascotas,int length,eCliente*clientes)
{
    int i,auxInt;
    char auxString[20];
    listarMascotas(flagAlta,mascotas,length,clientes);
    if(flagAlta==0)
    {
        return 0;
    }
    printf("\nIngrese el ID de la mascota que desea modificar: ");
    scanf("%d",&auxInt);
    fflush(stdin);
    for(i=0;i<length;i++)
    {
        if(auxInt==mascotas[i].mascotaId && auxInt!=-1)
        {
            system("cls");
            printf("ID               NOMBRE   TIPO  COLOR EDAD DUENIO");
            listarMascota(mascotas,i,clientes);
            printf("\n\n1)Modificar tipo\n2)Modificar edad\nIngrese el campo que desea modificar: ");
            scanf("%d",&auxInt);
            if(auxInt==1)
            {
                printf("\n1)Ave\n2)Perro\n3)Gato\n4)Roedor\n5)Pez\nIngrese el nuevo tipo de su mascota: ");
                scanf("%s",auxString);
                fflush(stdin);
                if(validarStringIdColor(auxString)==0)
                {
                    do{
                        printf("\n1)Ave\n2)Perro\n3)Gato\n4)Roedor\n5)Pez\nVuelva ingresar el tipo de su mascota: ");
                        scanf("%s",auxString);
                        fflush(stdin);
                    }while(validarStringIdColor(auxString)==0);
                }
                mascotas[i].mascotaIdTipo=atoi(auxString)+999;
                printf("\nLos cambios se realizaron con exito.\n");
                system("pause");
                return 1;
            }
            if(auxInt==2)
            {
                printf("\nIngrese la edad de su mascota: ");
                scanf("%s",auxString);
                fflush(stdin);
                if(validarStringInt(auxString)==0)
                {
                    do{
                        printf("\nVuelva a ingresar la edad de su mascota: ");
                        scanf("%s",auxString);
                        fflush(stdin);
                    }while(validarStringInt(auxString)==0);
                }
                mascotas[i].mascotaEdad=atoi(auxString);
                printf("\nLos cambios se realizaron con exito.\n");
                system("pause");
                return 1;
            }
        }
    }
    printf("\nEl ID ingresado no corresponde\n");
    system("pause");
    return 0;
}

/** \brief da de baja una estructura mascota
 *
 * \param *flagAlta int direccion de memoria a bandera alta
 * \param *mascotas eMascota array de estructuras eMascota
 * \param length int longitud del array
 * \param *clientes eCliente array de estructuras eCliente
 * \return 1 si se baja con exito, 0 de lo contrario
 *
 */
int bajaMascota(int*flagAlta,eMascota*mascotas,int length,eCliente*clientes)
{
    listarMascotas(*flagAlta,mascotas,length,clientes);
    if(flagAlta==0)
    {
        return 0;
    }
    int i,auxInt;
    printf("\nIngrese el ID de la mascota que desea dar de baja: ");
    scanf("%d",&auxInt);
    fflush(stdin);
    for(i=0;i<length;i++)
    {
        if(auxInt==mascotas[i].mascotaId && auxInt!=-1)
        {
            system("cls");
            printf("ID               NOMBRE   TIPO  COLOR EDAD DUEÑO");
            listarMascota(mascotas,i,clientes);
            mascotas[i].mascotaId=-1;
            *flagAlta=*flagAlta-1;
            printf("\n\nLa mascota fue dada de baja con exito\n");
            system("pause");
            return 1;
        }
    }
    printf("\nEl ID ingresado no corresponde\n");
    system("pause");
    return 0;
}
