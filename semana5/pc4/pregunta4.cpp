#include <iostream>
using namespace std;

struct Item
{
    char* descripcion; // memoria dinamica
    int cantidad;
    double precioUnitario;
};

struct Pedido
{
    int numeroPedido;
    char* nombreCliente; // memoria dinámica
    Item* items;         // arreglo dinámico de items
    int cantidadItems;
};

Pedido* crearPedido(int numero, const char* cliente, int cantidadItems)
{

}

double calcularTotal(const Pedido* p)
{

}

Item* itemMasCaro(Pedido* p)
{

}

void liberarPedido(Pedido* p)
{
    
}

int main()
{

    return 0;
}