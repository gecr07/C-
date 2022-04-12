# C++
Programacion en general de C++ 


# printf

## Some C++ data types, their format specifiers, and their most common bit widths are as follows:

>Int ("%d"): 32 Bit integer

>Long ("%ld"): 64 bit integer

>Char ("%c"): Character type

>Float ("%f"): 32 bit real value

>Double ("%lf"): 64 bit real value

### Ejemplo 

```
char ch = 'd';
double d = 234.432;
printf("%c %lf", ch, d);
```


# scanf

Se usan las mismas para que se usen con estas dos funciones

### Ejemplo 

``` c++
char ch;
double d;
scanf("%c %lf", &ch, &d);

```

### Ejemplo 2
```
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a,x;
    long b;
    long long c;
    char d;
    float e;
    double f;
    x = scanf("%d %ld %lld %c %f %lf", &a, &b, &c, &d, &e, &f);
    printf("%d\n", a);
    printf("%ld\n", b);
    printf("%lld\n", c);
    printf("%c\n", d);
    printf("%f\n", e);
    printf("%lf\n", f);
    return 0;
}
```
## _CRT_SECURE_NO_WARNINGS

Para poder usar funciones antiguas vete a Proyecto > Propiedades del Proyecto > C++ > Presprocesador > Definiciones del Prepocedaor y pon _CRT_SECURE_NO_WARNINGS
//#pragma warning(suppress : 4996) tambien quita warnings


## Constantes 

como es un prototipo de funcion no necesita los nombres de las variables y si compila ademas recuerda recibe un const string para que no pueda modificar
nada del string que le pasaron porlomnos no la funcion no modifica nada.
```
string ltrim(const string &);

```

# This means that we have three rules in C++:

Rule One: The names of parameters in function prototypes are ignored.

Rule Two: A function implementation doesn't have to pick the same names for its parameters as its prototype.

Rule Three: Parameters don't even need to have names at all.

By combining these three rules together, you sometimes see things like this:

```
int myFunction(int, double); // Prototype gives no names to arguments

int myFunction(int a, double b) {
    // .. use parameters a and b ... //
}
```
## std::stoi

Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.

## Arrays

Arreglos variables de tamaño.
```
int n = 10;
double a[n]; // Legal in g++ (with extensions), illegal in proper C++
```
Usa esto en c++ visual studio
```
int n = 10;
double* a = new double[n]; // Don't forget to delete [] a; when you're done!

```
***para usarlo usa***

```
cout << *(var+j) << " "; // asi de des referencia los punteros
```

## C++ 11 Arrays 

Para usar esto utiliza #include <array> tiene algunas ventajas y utiliza el relativamente nuevo c++ 11 sintaxis no se como decirlo. Su principal ventaja std::array is a container that encapsulates fixed size arrays.

> array<object_type, arr_size> arr_name;


# WinAPI
    
    WinAPI (también conocido como Win32; oficialmente llamado Microsoft Windows API) es una interfaz de programación de aplicaciones escrita en C por Microsoft para permitir el acceso a las funciones de Windows. Los componentes principales de WinAPI son:

WinBase: Las funciones del kernel, CreateFile, CreateProcess, etc.
WinUser: las funciones GUI, CreateWindow, RegisterClass, etc.
WinGDI: Las funciones gráficas, Ellipse, SelectObject, etc.
Controles comunes: controles estándar, vistas de lista, controles deslizantes, etc.
    
    >https://docs.microsoft.com/es-es/windows/win32/apiindex/windows-api-list?redirectedfrom=MSDN
    
 Una aplicación de consola de Windows puede tener varias interfaces ligeramente diferentes para el punto de entrada principal proporcionado por el programador. La diferencia entre estos es si el punto de entrada principal es el tradicional ****int main (int argc, char *argv[])*** o si es la versión específica de Windows ***int _tmain(int argc, _TCHAR* argv[])*** que proporciona caracteres amplios en los parámetros de la aplicación. Si genera un proyecto de aplicación de consola Windows Win32 con Visual Studio, la fuente generada será la versión específica de Windows.
    
    ### Ejemplo primer programa
    
    ```
    #include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return MessageBox(NULL, "hello, world", "caption", 0);
}
 ```
    
>El WinMain es diferente de un estándar int main() utilizado con una aplicación de consola. Se utilizan más parámetros en la interfaz y, lo que es más importante, el punto de entrada principal para una aplicación de ventana utiliza una convención de llamada diferente del C/C++ estándar.

>El calificador APIENTRY indica la convención de llamada, que es el orden en que se insertan los argumentos en la pila † . De forma predeterminada, la convención de llamada es la convención estándar de C indicada por __cdecl. Sin embargo, Microsoft usa un tipo diferente de convención de llamadas, la convención PASCAL, para las funciones de la API de Windows, que se indica mediante el __stdcall calificador. APIENTRY es un nombre definido __stdcall en uno de los archivos de encabezado incluidos por windows.h
    
    
 Los siguientes argumentos WinMain son los siguientes:

-hInst: el identificador de la instancia
-hInstPrev: el identificador de instancia anterior. Ya no se usa.
-cmdline: argumentos de la línea de comandos (consulte Pasar argumentos de WinMain (o wWinMain) a main normal )
- cmdshow: indica si se debe mostrar una ventana.
    
    
    
