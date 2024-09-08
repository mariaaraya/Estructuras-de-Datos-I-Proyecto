#include "Clases.h"


int main() {

    NavegadorWeb navegador;

    //  Agregar algunas pestañas con páginas
    Historial* historial1 = new Historial();
    navegador.agregarPestana(false);
    navegador.visitarPagina("Twitter");
    navegador.visitarPagina("Yahoo");
    navegador.agregarPestana(false);
    navegador.visitarPagina("Baidu");
    navegador.visitarPagina("Tumblr");
    std::cout << "Navegador 1 ----------\n" << navegador << std::endl;

    // Guardar el estado del navegador en un archivo
    std::string nombreArchivo = "navegador.dat";
    navegador.guardarNavegadorWeb(nombreArchivo);

    // Crear una nueva instancia de NavegadorWeb para leer los datos
    NavegadorWeb navegadorLeido;
    navegadorLeido.leerNavegadorWeb(nombreArchivo);

    std::cout << "Navegador 2 ----------\n" << navegadorLeido << std::endl;

    return 0;
}

