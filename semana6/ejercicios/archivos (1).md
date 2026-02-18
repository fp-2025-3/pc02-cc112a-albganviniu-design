# Laboratorio 6: Archivos en C++

## Ejercicio 1 

Una pequeña tienda desea registrar las ventas diarias de la semana. Implementar un programa que solicite al usuario el monto de ventas de cada día y los almacene en un archivo llamado `ventas.txt`

Cada valor debe almacenarse en una línea diferente.

Luego de registrar los 7 montos, el programa debe calcular:

* Total de ventas.

* Promedio semanal.

* Día con mayor venta.

* Día con menor venta.

Finalmente, debe escribir al final del mismo archivo:

**Ejemplo de salida esperada en el archivo**
```txt
1200
980
1500
870
1100
1320
1010
-------------------------
RESUMEN
Total: 7980
Promedio: 1140
Mayor venta: 1500
Menor venta: 870
```


## Ejercicio 2

Implementar un programa que lea datos numéricos almacenados en un archivo de texto `notas.txt`

```txt
15
18
12
09
20
14
16
11
``` 
a continuación:

* Procese la información desde el archivo.

* Genere un reporte estadístico en un nuevo archivo `reporte.txt`. Dicho archivo debe contener:

    * Cantidad total de estudiantes.

    * Promedio general.

    * Nota más alta.

    * Nota más baja.

    * Cantidad de estudiantes aprobados (nota ≥ 10).

    * Cantidad de estudiantes desaprobados (nota < 10).

**Formato de salida del archivo reporte.txt**

```txt
REPORTE GENERAL
------------------------
Total estudiantes: X
Promedio: X
Mayor nota: X
Menor nota: X
Aprobados: X
Desaprobados: X
```




## Ejercicio 3

Se desea implementar un sistema de gestión de productos para un almacén.

Cada producto tendrá la siguiente estructura:

```cpp
struct Producto {
    int id;                  // Identificador único
    char nombre[30];         // Nombre del producto
    double precio;           // Precio unitario
    int stock;               // Cantidad disponible
    bool activo;             // true = activo, false = eliminado lógicamente
};
```

El archivo debe llamarse `inventario.dat` y debe ser manejado exclusivamente en modo binario.

El programa debe implementar las siguientes funciones:

a) 

```cpp
void registrarProducto(const char* nombreArchivo);
```
* Agrega un nuevo producto al final del archivo.

* No debe permitir IDs repetidos.

* Debe validar que:
    
    * Precio > 0
    
    * Stock >= 0


b) 

```cpp
void mostrarProductos(const char* nombreArchivo);
```

* Muestra todos los productos activos.

* Debe indicar también la posición física del registro dentro del archivo.



c)
```cpp
int buscarProductoPorID(const char* nombreArchivo, int idBuscado);
```

* Debe devolver la posición del registro dentro del archivo.

* Si no existe, retornar -1.

* Debe detener la búsqueda apenas lo encuentre.


d)
```cpp
void modificarPrecio(const char* nombreArchivo, int id, double nuevoPrecio);
```

* Debe usar acceso aleatorio.

* No puede reescribir todo el archivo.

* Debe posicionarse exactamente sobre el registro a modificar.



e)
```cpp
void eliminarProducto(const char* nombreArchivo, int id);

```

* No debe borrar físicamente el registro.

* Solo debe cambiar el campo activo a false.

* Debe usar acceso aleatorio.


e)

```cpp
double calcularValorInventario(const char* nombreArchivo);
```
* Debe calcular: Total = $\sum(precio×stock)$.
Solo considerando productos activos.


El programa debe tener un menú interactivo:


1. Registrar producto
2. Mostrar productos
3. Buscar producto
4. Modificar precio
5. Eliminar producto
6. Calcular valor total
0. Salir



