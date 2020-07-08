#include "burgos.h"
#include <stdio.h>
#include <stdlib.h>

/** \brief muestra todos los clientes
 *
 * \param *clientes eCliente array de estructuras eCliente
 * \return 1
 *
 */
int listarClientes(eCliente*clientes)
{
    int i;
    printf("\n ID  SEXO NOMBRE");
    for(i=0;i<5;i++)
    {
        printf("\n%d  %c    %s",clientes[i].clienteId,clientes[i].clienteSexo,clientes[i].clienteNombre);
    }

    return 1;
}
