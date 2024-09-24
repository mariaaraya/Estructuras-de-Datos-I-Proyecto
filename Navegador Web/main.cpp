#include "Clases.h"
#include "Libreria.h"

int main() {

    GestorArchivos arc;
    NavegadorWeb* navegador = new NavegadorWeb();


    // Configurar el historial del navegador
    int limiteHistorial = 3;  // L�mite de 3 entradas en el historial
    int tiempoLimpiar = 1;    // Tiempo para limpiar entradas viejas en d�as (1 d�a de antig�edad)
    navegador->configurarHistorial(limiteHistorial, tiempoLimpiar);

    //  Agregar algunas pesta�as con p�ginas
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
    std::cout << "Pagina Activa: \n" << *navegador->obtenerPaginaActiva() << std::endl;

    std::string paginaBuscar = "Yahoo";
    Pagina* paginaEncontrada = navegador->buscarPagina(paginaBuscar);
    if (paginaEncontrada) {
        std::cout << "Pagina encontrada: " << *paginaEncontrada << std::endl;
    }
    else {
        std::cout << "Pagina no encontrada" << std::endl;
    }

    std::string paginaEliminar = "Tumblr";
    bool eliminada = navegador->eliminarPagina(paginaEliminar);
    if (eliminada) {
        std::cout << "Pagina " << paginaEliminar << " eliminada con exito" << std::endl;
    }
    else {
        std::cout << "Pagina " << paginaEliminar << " no eliminada" << std::endl;
    }


    std::cout << "\n Historial antes de aplicar politicas: \n"
        << *navegador->obtenerPestanaActiva()->getHistorial();

    // Aplicar pol�ticas
    navegador->aplicarPoliticasHistorial();

    std::cout << "\n Historial despu�s de aplicar politicas: \n"
        << *navegador->obtenerPestanaActiva()->getHistorial();

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

