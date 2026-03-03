#include "Vehiculos.h"
#include <iostream>
#include <iomanip>
using namespace std;

Vehiculo::Vehiculo() // Constructor por defecto
{
    cout << "Llamando al constructor por defecto" << endl;
} // Constructor por defecto

Vehiculo::Vehiculo(string p, string m, int a, double pv) : placa(p), marca(m), anio(a), precioVenta(pv) 
{
    cout << "Llamando al constructor de parametro" << endl;
}

Vehiculo::~Vehiculo()
{
    cout << "Destruyendo Vehiculo" << endl;
}

// Getters
string Vehiculo::getPlaca() const
{ 
    return placa;
}

string Vehiculo::getMarca() const
{
    return marca;
}

int Vehiculo::getAnio() const
{
    return anio;
}

double Vehiculo::getPrecioVenta() const
{
    return precioVenta;
}

void Vehiculo::mostrarInformacion() const
{
    cout << "Placa: " << placa << endl;
    cout << "Marca: " << marca << endl;
    cout << "Anio: " << anio << endl;
    cout << fixed << setprecision(2);
    cout << "Precio base: $" << precioVenta << endl;
}

// Automovil
Automovil::Automovil() {} // Constructor por defecto

Automovil::Automovil(string p, string m, int a, double pv, int np) : Vehiculo(p, m, a, pv), numeroPuertas(np) {}

Automovil::~Automovil()
{
    cout << "Destruyendo Automovil" << endl;
}

void Automovil::mostrarInformacion() const
{
    Vehiculo::mostrarInformacion();
    cout << "Numero de puertas: " << numeroPuertas << endl;
    cout << "Precio final: $" << calcularPrecioFinal() << endl;
}

double Automovil::calcularPrecioFinal() const
{
    return getPrecioVenta() * 1.05; // precio base + 5%
}

// Camion
Camion::Camion() {} // Constructor por defecto

Camion::Camion(string p, string m, int a, double pv, double cp) : Vehiculo(p, m, a, pv), capacidad(cp) {}

Camion::~Camion()
{
    cout << "Destruyendo Camion" << endl;
}

void Camion::mostrarInformacion() const
{
    Vehiculo::mostrarInformacion();
    cout << "Capacidad: " << capacidad << " toneladas" << endl;
    cout << "Precio final: $" << calcularPrecioFinal() << endl;
}

double Camion::calcularPrecioFinal() const
{
    return getPrecioVenta() * 1.12; // precio base + 12%
}

// Motocicleta
Motocicleta::Motocicleta() {} // Constructor por defecto

Motocicleta::Motocicleta(string p, string m, int a, double pv, double pt) : Vehiculo(p, m, a, pv), potencia(pt) {}

Motocicleta::~Motocicleta()
{
    cout << "Destruyendo Motocicleta" << endl;
}

void Motocicleta::mostrarInformacion() const
{
    Vehiculo::mostrarInformacion();
    cout << "Potencia: " << potencia << " HP" << endl;
    cout << "Precio final: $" << calcularPrecioFinal() << endl;
}

double Motocicleta::calcularPrecioFinal() const
{
    return getPrecioVenta() * 1.03; // precio base + 3%
}