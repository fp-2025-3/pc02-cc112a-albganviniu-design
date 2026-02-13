#include <iostream>
#include <cmath>
using namespace std;

struct Polinomio
{
    int grado;
    float *coef;
};

// Mostrar
void mostrarPolinomio(const Polinomio &p)
{
    for (int i = 0; i <= p.grado; i++)
    {
        if (p.grado - i == 0)
        {
            cout << p.coef[i]; // término independiente
        }
        else
        {
            cout << p.coef[i] << "x^" << p.grado - i;
        }

        if (i != p.grado)
            cout << " + ";
    }
    cout << endl;
}

// Suma
Polinomio sumar(const Polinomio &a, const Polinomio &b)
{
    Polinomio r;
    r.grado = max(a.grado, b.grado);
    r.coef = new float[r.grado + 1];

    for (int i = 0; i <= r.grado; i++)
    {
        r.coef[i] = 0;
    }

    for (int i = 0; i <= a.grado; i++)
    {
        r.coef[r.grado - a.grado + i] += a.coef[i];
    }

    for (int i = 0; i <= b.grado; i++)
    {
        r.coef[r.grado - b.grado + i] += b.coef[i];
    }
    return r;
}

// Producto
Polinomio multiplicar(const Polinomio &a, const Polinomio &b)
{
    Polinomio r;
    r.grado = a.grado + b.grado;
    r.coef = new float[r.grado + 1];

    for (int i = 0; i <= r.grado; i++)
    {
        r.coef[i] = 0;
    }

    for (int i = 0; i <= a.grado; i++)
    {
        for (int j = 0; j <= b.grado; j++)
        {
            r.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return r;
}

// Liberar memoria
void liberar(Polinomio &p)
{
    delete[] p.coef;
    p.coef = nullptr;
}

int main()
{
    Polinomio p1;
    Polinomio p2;
    Polinomio p3;

    p1.grado = 2;
    p1.coef[0] = 1;
    p1.coef[1] = 0;
    p1.coef[2] = 3;

    p2.grado = 1;
    p2.coef[0] = -4;
    p2.coef[1] = 5;

    p3.grado = 2;
    p3.coef[0] = 3;
    p3.coef[1] = 0;
    p3.coef[2] = 1;

    cout << "Polinomio 1: ";
    mostrarPolinomio(p1);

    cout << endl;

    cout << "polinomio 2: ";
    mostrarPolinomio(p2);

    cout << endl;

    cout << "polinomio 3: ";
    mostrarPolinomio(p3);

    Polinomio suma1 = sumar(p1, p2);
    Polinomio suma2 = sumar(suma1, p3);
    cout << "La suma de los tres polinomios es: ";
    mostrarPolinomio(suma2);

    Polinomio prod1 = multiplicar(p1, p2);
    Polinomio prod2 = multiplicar(prod1, p3);
    cout << "El producto de los tres polinomios es: ";
    mostrarPolinomio(prod2);

    // liberar memoria
    liberar(p1);
    liberar(p2);
    liberar(p3);
    liberar(suma1);
    liberar(suma2);
    liberar(prod1);
    liberar(prod2);

    return 0;
}