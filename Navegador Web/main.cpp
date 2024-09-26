#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
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

    system("pause");
    return 0;
}

