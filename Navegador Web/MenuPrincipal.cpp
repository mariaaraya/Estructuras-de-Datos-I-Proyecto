#define NOMINMAX // Evita conflictos con la macro max
#include "MenuPrincipal.h"
#include <conio.h>
#include <iostream>

/*--------------Principal--------------*/
int MenuPrincipal::menuPrincipal()
{
    int opcion = 0;
    std::cout << "\n--------------- M E N U ------------------\n";
    std::cout << "[1] Ir al sitio web\n";
    std::cout << "[2] Nueva pestana\n";
    std::cout << "[3] Marcadores\n";
    std::cout << "[4] Modo incognito\n";
    std::cout << "[5] Busqueda\n";
    std::cout << "[6] Configuracion\n";
    std::cout << "[7] Importacion y exportacion\n";
    std::cout << "[8] Salir\n";
    std::cout << "Ingrese la ocpion: ";
    while (true) {
        int tecla = _getch(); // Captura la tecla presionada
        if (tecla >= '1' && tecla <= '8') { // Verifica si la tecla es un n�mero v�lido
            opcion = tecla - '0'; // Convierte el car�cter a n�mero
            break;
        }
        else if (tecla == 0 || tecla == 224) { // Detecta si es una tecla especial
            tecla = _getch(); // Captura el segundo car�cter
            switch (tecla) {
            case 72: // Flecha arriba
            case 80: // Flecha abajo
            case 75: // Flecha izquierda
            case 77: // Flecha derecha
                return tecla;
            default:
                break;
            }
        }
        else {
            std::cout << "Opcion no valida. Por favor, ingrese un numero entre 1 y 8.\n";
        }
    }
    std::cout << opcion << std::endl;
    return opcion;
}

std::string MenuPrincipal::URl()
{
    std::string url = "" ;
    std::cout << "Ingrese el URL:";
    std::cin >> url;
    std::cout<<"\n";
    return url;
}

void MenuPrincipal::pagina404()
{
    std::string border(50, '*'); // L�nea de asteriscos para el borde
    std::string message = "404 - Not Found";
    std::cout << "\n" << border << "\n";
    std::cout << std::setw(30) << std::right << message << "\n";
    std::cout << border << "\n";
    std::cout << "Lo sentimos, la pagina que buscas no existe.\n";
    std::cout << "Por favor, verifica la URL e intenta nuevamente.\n";
    std::cout << border << "\n";
}


std::string MenuPrincipal::nombreMarcador()
{
    std::string marcador = "";
    std::cout << "Ingrese el nombre del marcador:";
    std::cin >> marcador;
    std::cout << "\n";
    return marcador;

}

Marcador* MenuPrincipal::marcador()
{
    std::string marcador = "";
    int etiqueta = 0;
    std::string etiqueta2 = "";
    std::cout << "Ingrese el nombre del marcador:";
    std::cin >> marcador;
    std::cout<<"\n";
    Marcador* aux = new Marcador(marcador);
    std::cout << "Dijite la cantidad de etiquetas que quiere:";
    std::cin >> etiqueta;
    std::cout<<"\n";
   // comprobarint(etiqueta);
    for (int i = 0; i < etiqueta; i++) {
     std::cout << "Ingrese el nombre de la etiqueta:";
     std::cin >> etiqueta2;
     std::cout<<"\n";
     aux->agregarEtiqueta(etiqueta2);
     etiqueta2 = "";
    }
    return aux;
}

/*---Configuracion---*/

Configuracion* MenuPrincipal::crearConfiguracion()
{
    Configuracion* aux = new Configuracion();
    int limite;
    int tiempo;
    std::cout << "Dijite el maximo de pagina que desea vistar: ";
    std::cin >> limite;
    std::cout << "\n";
    comprobarint(limite);
    std::cout << "Dijite el maximo del tiempo que desea que una pagina este activa: ";
    std::cin >> tiempo;
    std::cout << "\n";
    comprobarint(tiempo);
    aux->setLimiteHistorial(limite);
    aux->setTiempoLimpiar(tiempo);
    return aux;
}


/*---Archivos---*/
int MenuPrincipal::menuArchivo()
{
    int opcion = 0;
    std::cout << "[1] Guardar Seccion\n";
    std::cout << "[2] Continuar Seccion\n";
    std::cout << "[3] Salir\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;
    std::cout << "\n";
    if (std::cin.fail() || opcion <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return opcion;
}


std::string MenuPrincipal::nombreArchivo()
{
    std::string archivo = "";
    std::cout << "Ingrese un nombre para guardar la seccion: ";
    std::cin >> archivo;
    std::cout << "\n";
    return archivo;
}

std::string MenuPrincipal::nombreArchivoLeer()
{
    std::string archivo = "";
    std::cout << "Ingrese un nombre para continuar con la seccion: ";
    std::cin >> archivo;
    std::cout << "\n";
    return archivo;
}



/*--------------Comprobacion--------------*/



void MenuPrincipal::comprobarint(int& entero)
{
    if (std::cin.fail() || entero <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw new ExcepcionFueraRango();
    }
}







/*--------------Excepcion--------------*/


void MenuPrincipal::excepcion(Excepcion* e)
{ 
    std::cout << e->toString() << '\n';
}


void MenuPrincipal::error()
{
    std::cout << "ERROR DESCONOCIDO.\n";
}





/*--------------Salida--------------*/
void MenuPrincipal::bienvenida()
{
    std::cout << "\n----> Bienvenidos al Navegador Web de EDD <----\n";
    std::cout<<std::endl<< "Para navegar entre pestannas use las flechas de Arriba y Abajo" << std::endl;
    std::cout << "Por ejemplo: Primera pestanna almacena las primera paginas" << std::endl;
    std::cout << "La segunda pestanna almacena las otra paginas, y para navegar a esta apreta la tecla de Abajo" << std::endl;
    std::cout << "Asi continuamente puede navegar entre las pestannas del navegador web :)" << std::endl;
    std::cout << std::endl << "Esperamos que su experiencia sea grata, que lo disfrute!" << std::endl<<std::endl;

}

void MenuPrincipal::salir()
{
	std::cout << "---------------------> C R E A D O R E S <---------------------\n\n";
	std::cout << " Kendra Artavia Caballero.\n";
    std::cout << " Alexia Alvarado Alfaro.\n";
    std::cout << " Maria Aroyo Campos.\n";
	std::cout << "\n----------> G R A C I A S   P O R   U T I L I Z A R <----------\n";

}


