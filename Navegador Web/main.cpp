#include "Clases.h"
#include "Libreria.h"

int main() {

    GestorArchivos arc;
    NavegadorWeb* navegador = new NavegadorWeb();

    //  Agregar algunas pestañas con páginas
    Historial* historial1 = new Historial();
    navegador->agregarPestana(false);
    navegador->visitarPagina("Twitter");
    navegador->visitarPagina("Yahoo");
    navegador->agregarMarcador(new Marcador("Hola"));
    navegador->agregarEtiqueta("sopa");
    navegador->agregarPestana(false);
    navegador->visitarPagina("Baidu");
    navegador->visitarPagina("Tumblr");
    navegador->agregarPestana(true);
    navegador->visitarPagina("Yahoo");
    navegador->visitarPagina("Tumblr");
    std::cout << "Navegador 1 ----------\n" << *navegador << std::endl;

    navegador->mostrarPestanaActiva();
    navegador->navegarArriba();
    navegador->mostrarPestanaActiva();
    std::cout << "Pagina Activa: \n" << *navegador->obtenerPaginaActiva();

    std::cout << "\n Historial: \n" << *navegador->obtenerPestanaActiva()->getHistorial();
    // Guardar el estado del navegador en un archivo
    std::string nombreArchivo = "navegador.bin";
    arc.Guardar(nombreArchivo, navegador);


    // Crear una nueva instancia de NavegadorWeb para leer los datos
    NavegadorWeb* navegadorLeido = new NavegadorWeb();
    arc.Leer(nombreArchivo, navegadorLeido);
    std::cout << "Navegador 2 ----------\n" << *navegadorLeido << std::endl;

    system("pause");
    return 0;
}

