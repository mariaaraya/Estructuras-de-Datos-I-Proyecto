#define _CRTDBG_MAP_ALLOC 
//La definici�n del _CRTDBG_MAP_ALLOC s�mbolo hace que todas las instancias 
//de en new el c�digo se asignen correctamente a la versi�n de depuraci�n 
//de para registrar informaci�n de n�mero de l�nea y archivo de new origen.
//https://learn.microsoft.com/es-es/troubleshoot/developer/visualstudio/cpp/libraries/crtdbg-map-alloc-macro-not-work

#include <stdlib.h>
//Las funciones que pertenecen a stdlib.h pueden clasificarse en las 
//siguientes categor�as : conversi�n, memoria, control de procesos, ordenaci�n y b�squeda, matem�ticas.
//https://es.wikipedia.org/wiki/Stdlib.h

#include <crtdbg.h>
//es parte de la biblioteca de depuraci�n de Microsoft y se utiliza principalmente para ayudar en la detecci�n 
//de errores de memoria en programas que se ejecutan en entornos de Windows.
//Proporciona herramientas para rastrear la asignaci�n y liberaci�n de memoria din�mica, as� como para detectar fugas de memoria.
//Incluye macros �tiles como _CrtSetDbgFlag, que se pueden usar para establecer el modo de depuraci�n deseado.

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

