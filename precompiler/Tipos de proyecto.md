#Información general de la programación para Windows en C++


https://docs.microsoft.com/es-es/cpp/windows/overview-of-windows-programming-in-cpp?view=msvc-170


## Aplicaciones de línea de comandos (consola) USAMOS ESTA

Las aplicaciones de consola de C++ se ejecutan desde la línea de comandos en una ventana de consola y solo pueden mostrar la salida de texto. 


## Aplicaciones cliente de escritorio nativas


Una aplicación cliente de escritorio nativa es una aplicación con ventanas de C o C++ que usa las API nativas de Windows C originales o las API del modelo de objetos componentes (COM) para acceder al sistema operativo. Esas API se escriben principalmente en C. Hay más de una manera de crear una aplicación 
de escritorio nativa: puede programar mediante las API win32 directamente, mediante un bucle de mensajes de estilo C que procesa eventos del sistema operativo. O bien, puede programar mediante Microsoft Foundation Classes (MFC), una biblioteca de C++ ligeramente orientada a objetos que encapsula Win32. Ninguno de los enfoques se considera "moderno" en comparación con Plataforma universal de Windows (UWP), pero ambos siguen siendo totalmente compatibles y tienen millones de líneas de código que se ejecutan en el mundo en la actualidad. Una aplicación Win32 que se ejecuta en una ventana requiere que el desarrollador trabaje explícitamente con Windows mensajes dentro de una Windows de procedimiento. A pesar del nombre, una aplicación Win32 se puede compilar como un binario de 32 bits (x86) o de 64 bits (x64). En el IDE Visual Studio, los términos x86 y Win32 son sinónimos.

Para empezar a trabajar con la programación Windows C++, consulte Introducción con Win32 y C++. Después de comprender Win32, será más fácil 
obtener información sobre las aplicaciones de escritorio MFC. Para obtener un ejemplo de una aplicación de escritorio de C++ tradicional que usa gráficos 
sofisticados, vea Hilo: Developing C++ Applications for Windows.


## Windows SDK

Para escribir un Windows en C o C++, debe instalar el Kit de desarrollo de software (SDK) de Microsoft Windows o Microsoft Visual Studio. El SDK Windows contiene los encabezados y bibliotecas necesarios para compilar y vincular la aplicación. El SDK Windows también contiene herramientas de línea de comandos para compilar Windows, incluidos el compilador Visual C++ y el vinculador. Aunque puede compilar y compilar Windows con las herramientas de línea de comandos, se recomienda usar Microsoft Visual Studio.

El SDK Windows admite el desarrollo de aplicaciones de 32 y 64 bits. Las WINDOWS están diseñadas para que el mismo código se pueda compilar para 32 o 64 bits sin cambios.

## Windows convenciones de codificación (notaciones húngaros)

 ### Typedefs
 
Los Windows encabezados contienen una gran cantidad de definiciones de tipo. Muchos de ellos se definen en el archivo de encabezado WinDef.h. Estos son algunos de los que encontrará con frecuencia.
 
 <table>
<thead>
<tr>
<th>Tipo de datos</th>
<th>Size</th>
<th>¿Firmado?</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>BYTE</strong></td>
<td>8 bits</td>
<td>Sin signo</td>
</tr>
<tr>
<td><strong>DWORD</strong></td>
<td>32 bits</td>
<td>Sin signo</td>
</tr>
<tr>
<td><strong>INT32</strong></td>
<td>32 bits</td>
<td>Firmado</td>
</tr>
<tr>
<td><strong>INT64</strong></td>
<td>64 bits</td>
<td>Firmado</td>
</tr>
<tr>
<td><strong>LONG</strong></td>
<td>32 bits</td>
<td>Firmado</td>
</tr>
<tr>
<td><strong>LONGLONG</strong></td>
<td>64 bits</td>
<td>Firmado</td>
</tr>
<tr>
<td><strong>UINT32</strong></td>
<td>32 bits</td>
<td>Sin signo</td>
</tr>
<tr>
<td><strong>UINT64</strong></td>
<td>64 bits</td>
<td>Sin signo</td>
</tr>
<tr>
<td><strong>ULONG</strong></td>
<td>32 bits</td>
<td>Sin signo</td>
</tr>
<tr>
<td><strong>ULONGLONG</strong></td>
<td>64 bits</td>
<td>Sin signo</td>
</tr>
<tr>
<td><strong>WORD</strong></td>
<td>16 bits</td>
<td>Sin signo</td>
</tr>
</tbody>
</table>

Los tipos enumerados aquí tienen un tamaño fijo y los tamaños son los mismos en aplicaciones de 32 y 64 bits. Por ejemplo, el tipo DWORD siempre tiene 32 bits de ancho.. Osea se usan en windows para tener un standar y que no varien un DWORD siempre sera 4 bytes.


### Tipos de puntero

Windows define muchos tipos de datos del formato puntero a X. Normalmente tienen el prefijo P- o LP- en el nombre. Por ejemplo, LPRECT es un puntero a un RECT, donde RECT es una estructura que describe un rectángulo. Las siguientes declaraciones de variable son equivalentes.

```
RECT*  rect;  // Pointer to a RECT structure.
LPRECT rect;  // The same
PRECT  rect;  // Also the same.

```

En arquitecturas de 16 bits (Windows de 16 bits) hay dos tipos de punteros, P para "puntero" y LP significa "puntero largo". Se necesitaban punteros largos (también denominados punteros lejanos) para abordar los intervalos de memoria fuera del segmento actual. ****El prefijo LP se ha conservado para facilitar el puerto de código de 16 bits a un código de 32 Windows. Hoy en día no hay ninguna distinción y estos tipos de puntero son todos equivalentes. Evite usar estos prefijos; o si debe usar uno, use P.***

## Tipos de precisión de puntero (OTRAS que varian dependiendo si se trabaja con 64 o 32)

Los siguientes tipos de datos siempre son el tamaño de un puntero, es decir, 32 bits de ancho en aplicaciones de 32 bits y 64 bits de ancho en aplicaciones de 64 bits. El tamaño se determina en tiempo de compilación. Cuando una aplicación de 32 bits se ejecuta en archivos de 64 Windows, estos tipos de datos siguen teniendo 4 bytes de ancho. (Una aplicación de 64 bits no se puede ejecutar en aplicaciones de 32 Windows, por lo que no se produce la situación inversa).

```

    DWORD _ PTR
    INT _ PTR
    LONG _ PTR
    ULONG _ PTR
    UINT _ PTR
```

Estos tipos se usan en situaciones en las que ***un entero se puede convertir en un puntero.*** También se usan para definir variables para aritmética de puntero y para definir contadores de bucle que recorren en iteración el intervalo completo de bytes en búferes de memoria. Por lo general, aparecen en lugares en los que un valor de 32 bits existente se expandió a 64 bits en conjuntos de 64 Windows.


### Notation (Notation) de Origen húngaro


La notación húngaro es la práctica de agregar prefijos a los nombres de variables para proporcionar información adicional sobre la variable. (El inventor de la notación, Charles Simonyi, era húngaro, de ahí su nombre).

En su forma original, la notación húngaro proporciona información semántica sobre una variable, que le informa del uso previsto. Por ejemplo, significa un índice, cb significa un tamaño en bytes ("recuento de bytes") y rw y col mean row y column numbers. Estos prefijos están diseñados para evitar el uso accidental de una variable en el contexto incorrecto. Por ejemplo, si vio la expresión , sabrá que se está agregando un número de fila a un tamaño, lo que es casi seguro rwPosition + cbTable un error en el código.


## Trabajo con cadenas

Windows admite de forma nativa cadenas Unicode para elementos de interfaz de usuario, nombres de archivo, etc. Unicode es la codificación de caracteres preferida, ya que admite todos los idiomas y conjuntos de caracteres.


Windows representa caracteres Unicode mediante la codificación UTF-16, en la que cada carácter se codifica como uno o dos valores de 16 bits. Los caracteres UTF-16 se denominan caracteres anchos , para distinguirlos de los caracteres ANSI de 8 bits. 

El Visual C++ admite el tipo de datos integrado wchart_ para caracteres anchos. El archivo de encabezado WinNT.h también define la definición de tipo siguiente.

### L"String"

Verá ambas versiones en código de ejemplo de MSDN. Para declarar un literal de caracteres anchos o un literal de cadena de caracteres anchos, coloque L delante del literal.

```
wchar_t a = L'a';
wchar_t *str = L"hello";
```

Algunos ejemplos de definiciones de cadenas 

<table>
<thead>
<tr>
<th>Definición de tipo</th>
<th>Definición</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>CHAR</strong></td>
<td><code>char</code></td>
</tr>
<tr>
<td><strong>PSTR</strong> o <strong>LPSTR</strong></td>
<td><code>char*</code></td>
</tr>
<tr>
<td><strong>PCSTR</strong> o <strong>LPCSTR</strong></td>
<td><code>const char*</code></td>
</tr>
<tr>
<td><strong>PWSTR</strong> o <strong>LPWSTR</strong></td>
<td><code>wchar_t*</code></td>
</tr>
<tr>
<td><strong>PCWSTR</strong> o <strong>LPCWSTR</strong></td>
<td><code>const wchar_t*</code></td>
</tr>
</tbody>
</table>


## Funciones Unicode y ANSI

Cuando Microsoft introdujo la compatibilidad con Unicode para Windows, se facilitaba la transición proporcionando dos conjuntos paralelos de API, uno para cadenas ANSI y otro para cadenas Unicode. Por ejemplo, hay dos funciones para establecer el texto de la barra de título de una ventana:

    SetWindowTextA toma una cadena ANSI.
    SetWindowTextW toma una cadena Unicode.

Internamente, la versión ANSI traduce la cadena a Unicode. Los encabezados Windows también definen una macro que se resuelve en la versión Unicode cuando se define el símbolo de preprocesador UNICODE o la versión ANSI en caso contrario.
Fuente:https://docs.microsoft.com/es-es/windows/win32/LearnWin32/working-with-strings

## TCHAR

Cuando las aplicaciones necesitaban admitir Windows NT, así como Windows 95, Windows 98 y Windows Me, resultaba útil compilar el mismo código para cadenas ANSI o Unicode, en función de la plataforma de destino. Para ello, el SDK Windows proporciona macros que asignan cadenas a Unicode o ANSI, en función de la plataforma.

<table>
<thead>
<tr>
<th>Macro</th>
<th>Unicode</th>
<th>ANSI</th>
</tr>
</thead>
<tbody>
<tr>
<td>TCHAR</td>
<td><code>wchar_t</code></td>
<td><code>char</code></td>
</tr>
<tr>
<td>TEXT(&quot;x&quot;)</td>
<td><code>L&quot;x&quot;</code></td>
<td><code>&quot;x&quot;</code></td>
</tr>
</tbody>
</table>

Por ejemplo, el código siguiente:
C++

```
SetWindowText(TEXT("My Application"));
```

se resuelve en uno de los siguientes elementos:

```
SetWindowTextW(L"My Application"); // Unicode function with wide-character string.

SetWindowTextA("My Application");  // ANSI function.
```
Las macros TEXT y TCHAR son menos útiles hoy en día, ya que todas las aplicaciones deben usar Unicode. Sin embargo, es posible que los vea en código anterior y en algunos de los ejemplos de código de MSDN.

***Tenga cuidado: algunos encabezados usan el símbolo de preprocesador UNICODEy otros usan _UNICODE con un prefijo de subrayado. Defina siempre ambos símbolos. Visual C++ establece ambos de forma predeterminada al crear un proyecto.***


## _lprintf 

Se encuentra en Tchar.h  y es para trabajar con caracteres Unicode 
FUENTE:https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l?view=msvc-170
