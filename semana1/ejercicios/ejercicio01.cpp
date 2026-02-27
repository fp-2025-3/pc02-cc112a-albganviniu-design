#include <iostream>
using namespace std;

// Prototipos o firma de funciones
int potenciaIterativa(int a, int n);
int potenciaRecursiva(int a, int n);
int potenciaRapida(int a, int n);



int main(){
   

    cout << potenciaIterativa(2, -3);
    cout << potenciaRecursiva(2,30);


     return 0;
}


/*
a = 2, n = 0
a = 2, n = 5
a = 2, n = 30
a = 2, n = -3
*/


// Implementaciones de las funciones
int potenciaIterativa(int a, int n) {
    int resultado = 1;
    for (int i = 0; i < n; ++i) {
        resultado *= a; 
    }

    return resultado;
}


int potenciaRecursiva(int a, int n) {
    // Caso base:
    if (n == 0)
        return 1;

    //Caso recursivo:
    return a * potenciaRecursiva(a, n-1);
}


int potenciaRapida(int a, int n) {
     // Caso base:
    if (n == 0)
        return 1;

    if (n % 2 == 0) {
        int res = potenciaRapida(a, n/2);
        return res * res;
    }

    return a * potenciaRapida(a, n - 1);
}
