#include "Vehiculos.h"
#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;

int main()
{
    Vehiculo *lista[MAX]; // arreglo de punteros (polimorfismo)
    int contador = 0;
    int opcion;

    do
    {
        cout << "\n===== SISTEMA DE VEHICULOS =====\n";
        cout << "1. Registrar vehiculo\n";
        cout << "2. Mostrar vehiculos\n";
        cout << "3. Guardar en archivo binario\n";
        cout << "4. Leer archivo binario\n";
        cout << "5. Salir\n";
        cout << "Seleccione opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int tipo;
            string placa, marca;
            int anio;
            double precio;

            cout << "\n1. Automovil\n2. Camion\n3. Motocicleta\n";
            cout << "Tipo: ";
            cin >> tipo;

            cout << "Placa: ";
            cin >> placa;
            cout << "Marca: ";
            cin >> marca;
            cout << "Año: ";
            cin >> anio;
            cout << "Precio base: ";
            cin >> precio;

            if (tipo == 1)
            {
                int puertas;
                cout << "Numero de puertas: ";
                cin >> puertas;
                lista[contador++] = new Automovil(placa, marca, anio, precio, puertas);
            }
            else if (tipo == 2)
            {
                double capacidad;
                cout << "Capacidad (ton): ";
                cin >> capacidad;
                lista[contador++] = new Camion(placa, marca, anio, precio, capacidad);
            }
            else if (tipo == 3)
            {
                double potencia;
                cout << "Potencia (HP): ";
                cin >> potencia;
                lista[contador++] = new Motocicleta(placa, marca, anio, precio, potencia);
            }

            break;
        }

        case 2:
        {
            cout << "\n===== LISTA DE VEHICULOS =====\n";
            for (int i = 0; i < contador; i++)
            {
                cout << "\nVehiculo " << i + 1 << endl;
                lista[i]->mostrarInformacion(); // POLIMORFISMO
            }
            break;
        }

        case 3:
        {
            ofstream archivo("vehiculos.dat", ios::binary);

            if (!archivo)
            {
                cout << "Error al abrir archivo.\n";
                break;
            }

            archivo.write((char *)&contador, sizeof(contador));

            for (int i = 0; i < contador; i++)
            {
                if (dynamic_cast<Automovil *>(lista[i]))
                {
                    int tipo = 1;
                    archivo.write((char *)&tipo, sizeof(tipo));
                }
                else if (dynamic_cast<Camion *>(lista[i]))
                {
                    int tipo = 2;
                    archivo.write((char *)&tipo, sizeof(tipo));
                }
                else if (dynamic_cast<Motocicleta *>(lista[i]))
                {
                    int tipo = 3;
                    archivo.write((char *)&tipo, sizeof(tipo));
                }

                // Guardamos datos comunes
                string placa = lista[i]->getPlaca();
                string marca = lista[i]->getMarca();
                int anio = lista[i]->getAnio();
                double precio = lista[i]->getPrecioVenta();

                int len;

                len = placa.size();
                archivo.write((char *)&len, sizeof(len));
                archivo.write(placa.c_str(), len);

                len = marca.size();
                archivo.write((char *)&len, sizeof(len));
                archivo.write(marca.c_str(), len);

                archivo.write((char *)&anio, sizeof(anio));
                archivo.write((char *)&precio, sizeof(precio));
            }

            archivo.close();
            cout << "Datos guardados correctamente.\n";
            break;
        }

        case 4:
        {
            ifstream archivo("vehiculos.dat", ios::binary);

            if (!archivo)
            {
                cout << "No existe archivo.\n";
                break;
            }

            // Liberar memoria previa
            for (int i = 0; i < contador; i++)
                delete lista[i];

            contador = 0;

            archivo.read((char *)&contador, sizeof(contador));

            for (int i = 0; i < contador; i++)
            {
                int tipo;
                archivo.read((char *)&tipo, sizeof(tipo));

                int len;
                string placa, marca;
                int anio;
                double precio;

                archivo.read((char *)&len, sizeof(len));
                placa.resize(len);
                archivo.read(&placa[0], len);

                archivo.read((char *)&len, sizeof(len));
                marca.resize(len);
                archivo.read(&marca[0], len);

                archivo.read((char *)&anio, sizeof(anio));
                archivo.read((char *)&precio, sizeof(precio));

                if (tipo == 1)
                    lista[i] = new Automovil(placa, marca, anio, precio, 0);
                else if (tipo == 2)
                    lista[i] = new Camion(placa, marca, anio, precio, 0);
                else if (tipo == 3)
                    lista[i] = new Motocicleta(placa, marca, anio, precio, 0);
            }

            archivo.close();
            cout << "Datos cargados correctamente.\n";
            break;
        }

        case 5:
            cout << "Saliendo...\n";
            break;
        }

    } while (opcion != 5);

    // Liberar memoria final
    for (int i = 0; i < contador; i++)
    {
        delete lista[i];
    }

    return 0;
}