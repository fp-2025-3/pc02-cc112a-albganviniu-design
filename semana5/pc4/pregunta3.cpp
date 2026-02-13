#include <iostream>
using namespace std;

struct Producto
{
    int codigo;
    char* nombre;   // cadena dinamica
    double precio;
    int stock;
};

Producto crearProducto(int codigo, const char* nombre, double precio, int stock)
{
    char* nombre = new char[1];
}

Producto* crearInventario(int n)
{

}

Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado)
{

}

void liberarInventario(Producto* inventario, int n)
{

}

int main()
{

    return 0;
}