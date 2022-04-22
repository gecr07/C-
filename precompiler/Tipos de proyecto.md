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

