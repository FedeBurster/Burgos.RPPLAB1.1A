
#ifndef CLIENTE_H
#define CLIENTE_H
struct {
    int clienteId;
    char clienteSexo;
    char clienteNombre[20];
}typedef eCliente;

int listarClientes(eCliente*clientes);
#endif
