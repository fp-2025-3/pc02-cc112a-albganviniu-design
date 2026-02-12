#include <iostream>
#include <string>
using namespace std;

// Nodo
struct Proceso 
{
    int id;
    string nombre;
    float memoria;
    Proceso* sig;
};

// Lista
struct ListaProcesos 
{
    Proceso* cabeza;
};

// Inicializar lista vacía
void inicializar(ListaProcesos &lista) 
{
    lista.cabeza = nullptr;
}

// Insertar al inicio
void insertarInicio(ListaProcesos &lista, int id, string nombre, float memoria) 
{
    Proceso* nuevo = new Proceso{id, nombre, memoria, lista.cabeza};
    lista.cabeza = nuevo;
}

// Insertar al final
void insertarFinal(ListaProcesos &lista, int id, string nombre, float memoria) 
{
    Proceso* nuevo = new Proceso{id, nombre, memoria, nullptr};

    if (lista.cabeza == nullptr) 
    {
        lista.cabeza = nuevo;
        return;
    }

    Proceso* aux = lista.cabeza;
    while (aux->sig != nullptr)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;
}

// Mostrar
void mostrar(const ListaProcesos &lista) 
{
    Proceso* aux = lista.cabeza;

    while (aux != nullptr) 
    {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Memoria: " << aux->memoria << " MB\n";
        aux = aux->sig;
    }
}

// Buscar por ID
bool buscar(const ListaProcesos &lista, int id) 
{
    Proceso* aux = lista.cabeza;

    while (aux != nullptr) 
    {
        if (aux->id == id)
        {
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

// Eliminar por ID
bool eliminar(ListaProcesos &lista, int id) 
{
    if (lista.cabeza == nullptr) 
    {
        return false;
    }

    // eliminar cabeza
    if (lista.cabeza->id == id) 
    {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
        return true;
    }

    Proceso* ant = lista.cabeza;
    Proceso* act = lista.cabeza->sig;

    while (act != nullptr) 
    {
        if (act->id == id) 
        {
            ant->sig = act->sig;
            delete act;
            return true;
        }
        ant = act;
        act = act->sig;
    }

    return false; // no existe
}

// Contar procesos
int contar(const ListaProcesos &lista) 
{
    int c = 0;
    Proceso* aux = lista.cabeza;

    while (aux != nullptr) 
    {
        c++;
        aux = aux->sig;
    }
    return c;
}

// Insertar ordenado por memoria ascendente
void insertarOrdenado(ListaProcesos &lista, int id, string nombre, float memoria) 
{
    Proceso* nuevo = new Proceso{id, nombre, memoria, nullptr};

    if (lista.cabeza == nullptr || memoria < lista.cabeza->memoria) 
    {
        nuevo->sig = lista.cabeza;
        lista.cabeza = nuevo;
        return;
    }

    Proceso* aux = lista.cabeza;
    while (aux->sig != nullptr && aux->sig->memoria < memoria)
    {
        aux = aux->sig;
    }

    nuevo->sig = aux->sig;
    aux->sig = nuevo;
}

// Liberar memoria total
void liberar(ListaProcesos &lista) 
{
    while (lista.cabeza != nullptr) 
    {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
    }
}

int main() 
{
    ListaProcesos lista;
    inicializar(lista);

    // 3 al inicio
    insertarInicio(lista, 1, "Chrome", 200);
    insertarInicio(lista, 2, "VSCode", 150);
    insertarInicio(lista, 3, "Python", 180);

    // 2 al final
    insertarFinal(lista, 4, "Docker", 300);
    insertarFinal(lista, 5, "Node", 120);

    cout << "Procesos en lista:\n";
    mostrar(lista);

    cout << "\nTotal procesos: " << contar(lista) << endl;

    int idBuscar = 3;
    cout << "\nBuscar ID " << idBuscar << ": "
         << (buscar(lista, idBuscar) ? "Encontrado" : "No encontrado") << endl;

    cout << "\nEliminando ID 2...\n";
    eliminar(lista, 2);
    mostrar(lista);

    cout << "\nInsertar ordenado por memoria...\n";
    insertarOrdenado(lista, 6, "MySQL", 170);
    mostrar(lista);

    liberar(lista);
    return 0;
}
