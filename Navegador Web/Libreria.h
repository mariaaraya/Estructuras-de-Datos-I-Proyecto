//#pragma once

#include <windows.h> 
//windows.h es un archivo cabecera espec�fico de Windows para la programaci�n en lenguaje C / C++ 
//que contiene las declaraciones de todas las funciones de la biblioteca Windows API, todas las macros 
//utilizadas por los programadores de aplicaciones para Windows, y todas las estructuras de datos utilizadas 
//en gran cantidad de funciones y subsistemas.
//https://es.wikipedia.org/w/index.php?title=Windows.h&oldid=155371387

#include <list>
//La plantilla list de C++ posee los m�todos necesarios para insertar y borrar elementos al inicio, 
//al final o en un punto espec�fico de la lista.
//https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Librer%C3%ADa_Est%C3%A1ndar_de_Plantillas/Listas

#include <vector>
//un vector es una colecci�n que implementa un array con tama�o din�mico
//(es decir, que se ajusta autom�ticamente en tama�o seg�n sea necesario).
//La clase std::vector en la biblioteca est�ndar de C++ proporciona una implementaci�n.
//A diferencia de los arrays tradicionales, los vectors permiten la adici�n y eliminaci�n de elementos.
//https://www.luisllamas.es/cpp-que-son-vector/

#include <sstream>
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>

#include <chrono> 
//C++ incluye soporte para dos tipos de manipulaci�n de tiempo:
//La biblioteca chrono, una colecci�n flexible de tipos que rastrean el tiempo con distintos grados de precisi�n(por ejemplo, std::chrono::time_point).
//Fecha y hora estilo C library(por ejemplo, std::time).
//https://runebook.dev/es/docs/cpp/chrono#google_vignette

#include <ctime>
//La biblioteca 'ctime' en C++ proporciona una funci�n llamada 'time()' que devuelve la fecha y la hora actuales.
//https://www.gyata.ai/es/c-plus-plus/c-time

#include <limits>
//El archivo de inclusi�n <limits.h> define los l�mites num�ricos para los tipos enteros
//https ://learn.microsoft.com/es-es/cpp/cpp/numerical-limits-cpp?view=msvc-170

#include <iomanip> // Para std::setw
//iomanip es una biblioteca de C++ que se utiliza para manipular la salida del programa.
//Permite la entrada y salida que se adaptan tanto para fines de visualizaci�n y programaci�n
//Iomanip tiene una serie de funciones de salida.Las funciones de "izquierda" y "derecha " justificar la salida en un lado elegido .
//http://ordenador.wingwit.com/Programacion/cc-programming/85226.html

#include <algorithm>  // Para std::transform
//Los algoritmos de la biblioteca est�ndar de C++ pueden funcionar en varias estructuras de datos.
//Las estructuras de datos en las que pueden operar incluyen no solo las clases de contenedor de la biblioteca est�ndar de C++, 
//como vector y list, sino tambi�n estructuras de datos definidas por el usuario y matrices de elementos, 
//siempre y cuando cumplan los requisitos de un algoritmo determinado.Los algoritmos de la biblioteca est�ndar de C++ 
//logran este nivel de generalidad al acceder a los elementos de un contenedor 
//indirectamente mediante iteradores y al recorrerlos.
//https://learn.microsoft.com/es-es/cpp/standard-library/algorithm?view=msvc-170