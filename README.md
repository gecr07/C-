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

