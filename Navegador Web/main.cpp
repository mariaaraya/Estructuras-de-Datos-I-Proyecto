#define _CRTDBG_MAP_ALLOC 
//La definición del _CRTDBG_MAP_ALLOC símbolo hace que todas las instancias 
//de en new el código se asignen correctamente a la versión de depuración 
//de para registrar información de número de línea y archivo de new origen.
//https://learn.microsoft.com/es-es/troubleshoot/developer/visualstudio/cpp/libraries/crtdbg-map-alloc-macro-not-work

#include <stdlib.h>
//Las funciones que pertenecen a stdlib.h pueden clasificarse en las 
//siguientes categorías : conversión, memoria, control de procesos, ordenación y búsqueda, matemáticas.
//https://es.wikipedia.org/wiki/Stdlib.h

#include <crtdbg.h>
//es parte de la biblioteca de depuración de Microsoft y se utiliza principalmente para ayudar en la detección 
//de errores de memoria en programas que se ejecutan en entornos de Windows.
//Proporciona herramientas para rastrear la asignación y liberación de memoria dinámica, así como para detectar fugas de memoria.
//Incluye macros útiles como _CrtSetDbgFlag, que se pueden usar para establecer el modo de depuración deseado.

//Repositorio en GitHub: https://github.com/mariaaraya/Estructuras-de-Datos-I-Proyecto/tree/rama1

#include "Clases.h"
#include "Libreria.h"
#include "MenuPrincipal.h"
#include "Controler.h"
using namespace std;

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Controler* c = new Controler();
    c->controlPrincipal();
    delete c;

    _CrtDumpMemoryLeaks(); // cuando se depura nos dice si hay memory leaks

    return 0;
}

