#include <iostream>
#include <fstream>  // para manejar archivos
using namespace std;

struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};

// [P1][P2][P3].....[Pn]

int buscarProductoID(const char* nombreArchivo, int IDbuscar)
{
    // Como vamos a buscar un producto en un archivo binario instanciamos la clase ifstream
    ifstream archivo(nombreArchivo, ios::binary);

    if(!archivo)
    {
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }

    Producto p;

    int posicion = 0;

    while (archivo.read((char*)&p, sizeof(Producto)))
    {
        if (p.id == IDbuscar)
        {
            archivo.close();
            return posicion;
        }
        posicion++;
    }

    archivo.close();
    return -1;
}

// a) Funcion para registrar un producto
void registrarProducto(const char* nombreArchivo)
{
    Producto p; // en C struct Producto p;

    cout << "Infrese ID: ";
    cin >> p.id;

    // No debe permitir IDs repetidos
    if (buscarProductoID(nombreArchivo, p.id) != -1)
    {
        cerr << "ERROR, el ID ya existe" << endl;
        return;
    }

    cin.ignore(); // limpiar el buffer
    cout << "Ingrese el nombre: ";
    cin.getline(p.nombre, 30);

    cout << "Ingrese el precio: ";
    cin >> p.precio;

    if (p.precio <= 0)
    {
        cout << "Precio invalido" << endl;
        return;
    }
    
    cout << "Ingrese stock: ";
    cin >> p.stock;

    if (p.stock < 0)
    {
        cout << "Stock invalido" << endl;
        return;
    }

    p.activo = true;

    // USAMOS ARCHIVOS ARCHIVOS

    // Paso 1: instanciar un objeto de la clase ofstream y activar el modo binario
    ofstream archivo(nombreArchivo, ios::binary);

    if (!archivo)
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    // Paso 2: Escribir el archivo binario
    archivo.write((char*)&p, sizeof(Producto)); // archivo.write(reinterpret_cast<char*>(&p), sizeof(Producto))

    archivo.close();

    cout << "Producto registrado correctamente" << endl;
}

int main()
{
    

    return 0;
}