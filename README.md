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
    
> https://docs.microsoft.com/es-es/windows/win32/apiindex/windows-api-list?redirectedfrom=MSDN
    
 Una aplicación de consola de Windows puede tener varias interfaces ligeramente diferentes para el punto de entrada principal proporcionado por el programador. La diferencia entre estos es si el punto de entrada principal es el tradicional ****int main (int argc, char *argv[])*** o si es la versión específica de Windows ***int _tmain(int argc, _TCHAR* argv[])*** que proporciona caracteres amplios en los parámetros de la aplicación. Si genera un proyecto de aplicación de consola Windows Win32 con Visual Studio, la fuente generada será la versión específica de Windows.
    
### Ejemplo primer programa
    
``` c++
    #include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return MessageBox(NULL, "hello, world", "caption", 0);
}
 ```
    
    
>El WinMain es diferente de un estándar int main() utilizado con una aplicación de consola. Se utilizan más parámetros en la interfaz y, lo que es más importante, el punto de entrada principal para una aplicación de ventana utiliza una convención de llamada diferente del C/C++ estándar.

>El calificador APIENTRY indica la convención de llamada, que es el orden en que se insertan los argumentos en la pila † . De forma predeterminada, la convención de llamada es la convención estándar de C indicada por __cdecl. Sin embargo, Microsoft usa un tipo diferente de convención de llamadas, la convención PASCAL, para las funciones de la API de Windows, que se indica mediante el __stdcall calificador. APIENTRY es un nombre definido __stdcall en uno de los archivos de encabezado incluidos por windows.h
    
    
 Los siguientes argumentos WinMain son los siguientes:

hInst: el identificador de la instancia
hInstPrev: el identificador de instancia anterior. Ya no se usa.
cmdline: argumentos de la línea de comandos (consulte Pasar argumentos de WinMain (o wWinMain) a main normal )
 cmdshow: indica si se debe mostrar una ventana.
    
***Ejemplo***
    
``` c++
    BOOL WINAPI CopyFile(
  _In_ LPCTSTR lpExistingFileName,
  _In_ LPCTSTR lpNewFileName,
  _In_ BOOL    bFailIfExists
);
``` 
    
El tipo de datos para los dos parámetros de cadena se compone de varias partes:

LP = puntero largo
C = constante
T = CHAR
STR = cadena
    
## TCHAR
    
Ahora que TCHARsignifica? Esto depende de la plataforma elegida para la compilación del programa.
    
There core token, TCHAR is defined as:
    
 ``` c++
 #ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif
```
De nuevo, dependiendo de los indicadores de compilación, TCHAR es un carácter "estrecho" o "ancho" (2 bytes).
    
 Lo primero que se ve son las dos definiciones de macro UNICODEy _UNICODE. Estas macros hacen que nuestro programa comprenda cadenas de caracteres anchos ( wchar_t[n]), no cadenas angostas simples ( char[n]). Como resultado, todos los literales de cadena deben incluirse en una TEXT(macro. El tipo de carácter genérico para cadenas Win32 es TCHAR, cuya definición depende de si UNICODEestá definido o no. Se incluye un nuevo encabezado: <tchar.h>contiene la declaración de TCHAR.
    
    
Entonces, cuando se define UNICODE, CopyFilese define como CopyFileW, que utilizará matrices de caracteres de 2 bytes como su parámetro, que se espera que estén codificados en UTF-16.

Si UNICODE no está definido, CopyFilese define como el CopyFileAque usa matrices de caracteres de un solo byte que se espera que se codifiquen en la codificación ANSI predeterminada del usuario actual.

Hay dos macros similares: UNICODEhace que las API de Windows esperen cadenas anchas y _UNICODE(con un guión bajo al principio) que habilita funciones similares en la biblioteca de tiempo de ejecución de C.

Estas definiciones nos permiten escribir código que compila tanto en ANSI como en modo Unicode.
    
    
## Handle
    
 Un identificador es un tipo de datos que representa un objeto único. Son punteros, pero a estructuras de datos secretas mantenidas por el sistema operativo. Los detalles de estas estructuras no tienen por qué preocuparnos. Todo lo que un usuario debe hacer es simplemente crear/recuperar un identificador usando una llamada API y pasarlo a otras llamadas API que toman ese tipo de identificador. El único tipo de identificador que usamos fue el HWNDdevuelto por CreateWindowEx.
    
 ## Constants
   
In this example, we encounter a handful of constants, which are in all-caps and begin with a 2 or 3 letter prefix. (The Windows types are also in all-caps).
    
***Ejemplos:***
    
MB_ICONERROR: A flag used with MessageBox to display an error icon.
    
WS_EX_LEFT: The default extended window style. This causes the window to have left-aligned properties.
    
WS_OVERLAPPEDWINDOW: A window style indicating that the window should be a parent window with a title bar, size box, and others elements typical of top-level windows.
    
 ## Windows Types   
    
***Tipos Win32, que son alias para tipos integrados. Estos tipos están en mayúsculas. Los tipos de alias utilizados en este programa son:***
    
TCHAR: The generic character type. If UNICODE is defined, this is a wchar_t. Otheriwse, it is a char.
    
UINT: An unsigned integer. Used to represent the message identifier in window procedures, and other purposes.
    
WPARAM: In Win16, this was a WORD argument (hence the W prefix). With the introduction of Win32, however, this is now a UINT_PTR. This illustrates the point of these Windows aliases; they are there to protect programs from change.
    
LPARAM: This is a LONG argument (LONG_PTR in Win64).
    
PTSTR: The P means pointer. The T means generic character, and the STR means string. Thus, this is a pointer to a TCHAR string. Other string types include:
    
LPTSTR: Same as PTSTR
    
LPCTSTR: Means const TCHAR *
    
PCTSTR: Same as LPCTSTR
    
LPWSTR: Wide string (wchar_t *)
    
LPCWSTR: Means const wchar_t *
    
PWSTR: Same as LPWSTR
    
and much more As you can see, the Win32 types can be a hassle to understand, especially with so many synonymous types, which is an artifact of Win16.
LRESULT: This type is used to represent the return value of window procedures. It is usually a LONG (hence the L).
    
    
    
# Windows via C++ Libro

## Cambiar de tipo de proyecto de consola a escritorio    
    
Para compatibilidad con versiones anteriores, Windows de 64 bits puede ejecutar aplicaciones de 32 bits. 
    
### Error Handling 
    
Cuando se llama a una funcion y se tiene un error windows asigna un numero de 32 bits de error. La api que se usa para ver estos codigos es GetLastError().
Los codigos de error se encuentran definidos en una libreria que se llama WinError.h. Pero tambien cuanodo una funcion tiene exito genera un codigo como el de error
pero para success.
    
### Debugging mirar el ulitmo codigo de error
    
 While debugging, I find it extremely useful to monitor the thread's last error code. In Microsoft Visual Studio, Microsoft's
debugger supports a useful feature—you can configure the Watch window to always show you the thread's last error code
number and the text description of the error. This is done by selecting a row in the Watch window and typing $err,hr. 
    
    
## Chapter 2: Working with Characters and Strings

Primero fue las cademas de caracteres con terminacion nulla o cero "When we call
strlen, it returns the number of characters in a zero-terminated array of ANSI single-byte characters". Despues se crearon los 
Se crearon conjuntos de caracteres de doble byte (DBCS) que podian aceptar caracteres de uno o 2 bytes por ejemplo en el japones
FINALMENTE 
Se creo Unicode. UTF-16 codifica cada carácter como 2 bytes (o 16 bits). En este libro, cuando hablamos de Unicode,
siempre nos referimos a la codificación UTF-16 a menos que indiquemos lo contrario.    
    
>Note that the .NET Framework always encodes all characters and
strings using UTF-16, so using UTF-16 in your Windows application will improve performance and reduce memory
consumption if you need to pass characters or strings between native and managed code.
    
    
### C char
    
C language uses the char data type to represent an 8-bit ANSI character. By default, when
you declare a literal string in your source code, the C compiler turns the string's characters into an array of 8-bit char data
types:

``` c++
// An 8-bit character
char c = 'A';
// An array of 99 8-bit characters and an 8-bit terminating zero.
char szBuffer[100] = "A String";
    
```     
      
### wchar_t
    
 Microsoft define un tipo de datos integrado, wchar_t, que representa un carácter Unicode (UTF-16) de 16 bits.   
    
 Debido a que las versiones anteriores del compilador de Microsoft no ofrecían este tipo de datos incorporado, el compilador define este tipo de datos solo
cuando se especifica el modificador del compilador /Zc:wchar_t. ****De forma predeterminada, cuando crea un proyecto de C++ en Microsoft Visual Studio,
se especifica este modificador del compilador***. Recomendamos que siempre especifique este modificador del compilador, ya que es mejor trabajar con
Caracteres Unicode a través del tipo primitivo integrado entendido intrínsecamente por el compilador.   
    
    
# L "String"  Here is how you declare a Unicode character and string:  
    
 ```c++
   // An array up to 99 16-bit characters and a 16-bit terminating zero.
wchar_t szBuffer[100] = L"A String"; 
 
```
 Una L mayúscula antes de una cadena literal informa al compilador que la cadena debe compilarse como una cadena Unicode. Cuando el
el compilador coloca la cadena en la sección de datos del programa, codifica cada carácter usando UTF16, intercalando cero bytes
entre cada carácter ASCII(El sistema de ocho bits se conoce como ASCII extendido.) en este caso simple.
    
    
### CHAR y WCHAR
    
El equipo de Windows de Microsoft quiere definir sus propios tipos de datos para aislarse un poco del lenguaje C. Y entonces,
el archivo de encabezado de Windows, WinNT.h, define los siguientes tipos de datos:
    
 ```C++
 // Esto es lo que WINDOWS Define
    
typedef char CHAR; // An 8-bit character
typedef wchar_t WCHAR; // A 16-bit character
// Pointer to 8-bit character(s)
typedef CHAR *PCHAR;
typedef CHAR *PSTR;
typedef CONST CHAR *PCSTR
// Pointer to 16-bit character(s)
typedef WCHAR *PWCHAR    
typedef WCHAR *PWSTR;
typedef CONST WCHAR *PCWSTR;
    
```
   
### Header Annotations
    
El siguiente ejemplo muestra las anotaciones para la función GetModuleFileName . El parámetro hModule es un parámetro de entrada opcional. El parámetro lpFilename es un parámetro de salida; su tamaño en caracteres se especifica mediante el parámetro nSize y su longitud incluye el carácter de terminación nula . El parámetro nSize es un parámetro de entrada.
    
    
```C++
    DWORD
WINAPI
GetModuleFileName(
    __in_opt HMODULE hModule,
    __out_ecount_part(nSize, return + 1) LPTSTR lpFilename,
    __in DWORD nSize
    );
    
```
    
### Unicode and ANSI Functions in Windows
    
 Desde Windows NT, todas las versiones de Windows se construyen desde cero usando Unicode. 
> Es decir, todas las funciones básicas para
la creación de ventanas, la visualización de texto, la manipulación de cadenas, etc. requieren cadenas Unicode.
    
### APIS en Unicode ¿?
    
 Si llamas a alguno
función de Windows pasándole una cadena ANSI (una cadena de caracteres de 1 byte), la función primero convierte la cadena a Unicode
y luego pasa la cadena Unicode al sistema operativo.
    
***Entonces***
 
Si está esperando cadenas ANSI de vuelta de una función, el
El sistema convierte la cadena Unicode en una cadena ANSI antes de volver a su aplicación. Todas estas conversiones ocurren
invisible para ti. Por supuesto, hay una sobrecarga de tiempo y memoria involucrada para que el sistema lleve a cabo todas estas secuencias.
conversiones.
 
    
### CreateWindowExA  vs CreateWindowExA y todas las apis tienen 2 versiones
    
 
CreateWindowExW es la versión que acepta cadenas Unicode. La W mayúscula al final del nombre de la función representa
por ancho. Los caracteres Unicode tienen 16 bits de ancho, por lo que con frecuencia se denominan caracteres anchos. La A mayúscula en el
final de CreateWindowExA indica que la función acepta cadenas de caracteres ANSI.
Pero generalmente solo incluimos una llamada a CreateWindowEx en nuestro código y no llamamos directamente a CreateWindowExW o
CreateWindowExA. En WinUser.h, CreateWindowEx es en realidad una macro definida como   
    
```C++
 //But usually we just include a call to CreateWindowEx in our code and don't directly call either CreateWindowExW or
//   CreateWindowExA. In WinUser.h, CreateWindowEx is actually a macro defined as
    
#ifdef UNICODE
#define CreateWindowEx CreateWindowExW
#else
#define CreateWindowEx CreateWindowExA
#endif
    
```
## Cuando crea un nuevo proyecto con Visual Studio, define UNICODE de forma predeterminada.  
    
#  Unicode and ANSI Functions in the C Run-Time Library
    
An example of a C run-time function that returns the length of an ANSI string is strlen, and an example of an equivalent
C run-time function that returns the length of a Unicode string is wcslen.
   
## UNICODE
    The plain versions without the underscore affect the character set the Windows header files treat as default. So if you define UNICODE, then GetWindowText will map to GetWindowTextW instead of GetWindowTextA, for example. Similarly, the TEXT macro will map to L"..." instead of "...".    
    
## _UNICODE 
    
    The versions with the underscore affect the character set the C runtime header files treat as default. So if you define _UNICODE, then _tcslen will map to wcslen instead of strlen, for example. Similarly, the _TEXT macro will map to L"..." instead of "...".
    
## TEXT
    
    The plain versions without the underscore affect the character set the Windows header files treat as default. So if you define UNICODE, then GetWindowText will map to GetWindowTextW instead of GetWindowTextA, for example. Similarly, the TEXT macro will map to L”…” instead of “…”.
    
## _TEXT y TEXT
    
The versions with the underscore affect the character set the C runtime header files treat as default. So if you define _UNICODE, then _tcslen will map to wcslen instead of strlen, for example. Similarly, the _TEXT macro will map to L”…” instead of “…”.

What about _T? Okay, I don’t know about that one. Maybe it was just to save somebody some typing.  
    
## StrSafe.h file e _s (for secure) suffix or StringCch
    
>https://docs.microsoft.com/en-us/windows/win32/menurc/strsafe-ovw
    
    funciones seguras para manejo de cadenas.
    
## Windows internally does everything with Unicode characters and strings, so when you pass an ANSI character or
string, Windows must allocate memory and convert the ANSI character or string to its Unicode equivalent.
    
## _countof vs sizeof(arr)
    
    El primero te da la medida en elementos o caracteres de un string. Y sizeof te da el tamaño pero en bytes.
    
>There is also a set of functions that have "Cb" in their name, such as
StringCbCat(Ex), StringCbCopy(Ex), and StringCbPrintf(Ex). These functions expect that the size argument
is in count of bytes instead of count of characters. You'll typically use the sizeof operator to get this value.    
    
```
    sizeof(arr) = 40 bytes
_countof(arr) = 20 elements
    
```    

# Chapter 3: Kernel Objects
    
## What Is a Kernel Object?

Each kernel object is simply a memory block allocated by the
kernel and is accessible only by the kernel. This memory block is a data structure whose members maintain information
about the object
    
## User Objects 
 
USER objects get their name from the fact that they represent user interface elements like desktops, windows, menus, cursors, icons, and accelerator tables (menu keyboard shortcuts).

A basic limitation imposed by the window manager is that no process can create more than 10,000 USER objects.
    
    
One fundamental limitation on the number of USER objects comes from the fact that their identifiers were 16-bit values in the first versions of Windows, which were 16-bit. When 32-bit support was added in later versions, USER identifiers had to remain restricted to 16-bit values so that 16-bit processes could interact with windows and other USER objects created by 32-bit processes. Thus, 65,535 (2^16) is the limit on the total number of USER objects that can be created on a session.
    
for historical reasons, windows must have even-numbered identifiers, so there can be a maximum of 32,768 windows per session.    
    
User interface objects support only one handle per object. Processes cannot inherit or duplicate handles to user objects. Processes in one session cannot reference a user handle in another session.
    
## Graphics Device Interface (GDI) 
    
 es uno de los tres componentes o subsistemas de la interfaz de usuario de Microsoft Windows. Trabaja junto con el núcleo y la API de Windows.

Esta interfaz de programación de aplicaciones se encarga del control gráfico de los dispositivos de salida, como los monitores o las impresoras.
    
    
## Identificador de instancia único ( hInstanceExe)
    
A cada archivo ejecutable o DLL cargado en el espacio de direcciones de un proceso se le asigna un identificador de instancia único. tu ejecutable
la instancia del archivo se pasa como el primer parámetro de (w) WinMain, hInstanceExe. El valor del identificador generalmente se necesita para las llamadas.
    
```    
HICON LoadIcon(
 HINSTANCE hInstance,
 PCTSTR pszIcon);
```
### NOTA HMODULEs and HINSTANCEs

The Platform SDK documentation states that some functions require a parameter of the type HMODULE. An example is the
GetModuleFileName function, which is shown here:
 
As it turns out, HMODULEs and HINSTANCEs are exactly the same thing. If the documentation for a function indicates
that an HMODULE is required, you can pass an HINSTANCE, and vice versa.     
    
    
```     
DWORD GetModuleFileName(
 HMODULE hInstModule,
 PTSTR pszPath,
 DWORD cchPath);
 ``` 
    
El valor real del parámetro hInstanceExe de (w)WinMain es la dirección de memoria base donde el sistema cargó el
la imagen del archivo ejecutable en el espacio de direcciones del proceso. Por ejemplo, si el sistema abre el archivo ejecutable y carga su
contenido en la dirección 0x00400000, (w) el parámetro hInstanceExe de WinMain tiene un valor de 0x00400000.
     
La dirección base donde se carga la imagen de un archivo ejecutable está determinada por el enlazador. Diferentes enlazadores pueden usar diferentes
direcciones base predeterminadas.
    
    
### HMODULE GetModuleHandle(PCTSTR pszModule);
    
 Cuando llama a esta función, pasa una cadena terminada en cero que especifica el nombre de un archivo ejecutable o DLL cargado
en el espacio de direcciones del proceso de llamada. Si el sistema encuentra el archivo ejecutable o DLL especificado, GetModuleHandle
devuelve la dirección base donde se carga ese archivo ejecutable o DLL. El sistema devuelve NULL si no puede encontrar el
expediente. También puede llamar a GetModuleHandle, pasando NULL para el parámetro pszModule; GetModuleHandle devuelve el
llamando a la dirección base del archivo ejecutable. 
    
    
## A Process' Environment Variables
    
Each process has an associated environment block. An environment block is a block of memory allocated within the
process address space that contains a set of strings that look like this: Tiene por ejemplo %APPDATA%
    
    
## Usando GetCurrentDirectory
    
 Note
The MAX_PATH constant defined in WinDef.h as 260 is the maximum number of characters for a directory name or a
filename. So it is safe to pass a buffer of MAX_PATH elements of the TCHAR type when you call
GetCurrentDirectory.
A Process' Current Direct
    
    
## The CreateProcess Function
    
 Crea un nuevo proceso y su subproceso principal. El nuevo proceso se ejecuta en el contexto de seguridad del proceso de llamada.
      
    
    
 Ejemplo
    
```   
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    TCHAR szCommandLine[] = TEXT("NOTEPAD");
    CreateProcess(NULL, szCommandLine, NULL, NULL,FALSE, 0, NULL, NULL, &si, &pi);    
```
    
    
### pszApplicationName and pszCommandLine
    
The pszApplicationName and pszCommandLine parameters specify the name of the executable file the new process
will use and the command-line string that will be passed to the new process, respectively. Let's talk about the
pszCommandLine parameter first. ***eL VALOR De szCommandLine si no se tiene la extencion se pone .exe por default***

    
La ruta donde windows busca el programa primero comieza desde el directirio actual despues revisa los del sistema y finalmente las variables de entorno. 
incluso se puede poner la ruta completa lo cual genera que no se busque en otra carpeta.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
