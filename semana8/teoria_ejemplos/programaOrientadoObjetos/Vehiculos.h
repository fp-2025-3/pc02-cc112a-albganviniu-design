#ifndef VEHICULOS_H
#define VEHICULOS_H
#include <iostream>
#include <string>
using namespace std;

// definicion de la clase base (ABSTRACTA)
class Vehiculo
{
protected:
    // miembros de datos
    string placa;
    string marca;
    int anio;
    double precioVenta;

public:
    // Funciones miembro
    // Constructores
    Vehiculo(); // Constructor por defecto
    Vehiculo(string p, string m, int a, double pv);

    // Destructor
    virtual ~Vehiculo(); // virtual para polimorfismo

    // Getters (encapsulacion)
    string getPlaca() const;
    string getMarca() const;
    int getAnio() const;
    double getPrecioVenta() const;

    // Metodo virtual para polimorfismo
    virtual void mostrarInformacion() const;

    // Convertimos la clase base a una clase abstracta, definiendo un metodo virtual puro
    virtual double calcularPrecioFinal() const = 0; // método abstracto/virtual puro

    virtual void guardar(ofstream & out) const = 0;
    virtual void cargar(ifstream & in) const = 0;
};

class Automovil : public Vehiculo
{
private:
    int numeroPuertas;

public:
    // Funciones miembro
    // Constructores
    Automovil(); // Constructor por defecto
    Automovil(string p, string m, int a, double pv, int np);

    // Destructor
    ~Automovil();

    // Sobreescritura de metodo virtual
    void mostrarInformacion() const override;

    // Polimorfismo: precio final
    double calcularPrecioFinal() const override;

    void guardar(ofstream &out) const override;
    void cargar(ifstream &in) const override;
};

class Camion : public Vehiculo
{
private:
    double capacidad;

public:
    // Funciones miembro
    // Constructores
    Camion(); // Constructor por defecto
    Camion(string p, string m, int a, double pv, double cp);

    // Destructor
    ~Camion();

    // Sobreescritura de metodo virtual
    void mostrarInformacion() const override;

    // Polimorfismo: precio final
    double calcularPrecioFinal() const override;

    void guardar(ofstream &out) const override;
    void cargar(ifstream &in) const override;
};

class Motocicleta : public Vehiculo
{
private:
    double potencia;

public:
    // Funciones miembro
    // Constructores
    Motocicleta(); // Constructor por defecto
    Motocicleta(string p, string m, int a, double pv, double pt);

    // Destructor
    ~Motocicleta();

    // Sobreescritura de metodo virtual
    void mostrarInformacion() const override;

    // Polimorfismo: precio final
    double calcularPrecioFinal() const override;

    void guardar(ofstream &out) const override;
    void cargar(ifstream &in) const override;
};

#endif