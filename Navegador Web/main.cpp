#include "Libreria.h"
#include "Historial.h"
#include "Marcador.h"
#include "VectorMarcador.h"
#include "Pagina.h"
#include "Pestana.h"

int main() {
    //Crear pestañas
    Pestana* pestana1 = new Pestana();
    // Crear marcadores
    Marcador marcador1("Google");
    marcador1.agregarEtiqueta("Busqueda");
    marcador1.agregarEtiqueta("Tecnologia");

    Marcador marcador2("YouTube");
    marcador2.agregarEtiqueta("Videos");
    marcador2.agregarEtiqueta("Entretenimiento");

    // Mostrar marcadores
    std::cout << "Marcadores creados:\n";
    std::cout << marcador1 << std::endl;
    std::cout << marcador2 << std::endl;

    // Crear un vector de marcadores y agregar marcadores a él
    VectorMarcador vectorMarcadores;
    vectorMarcadores.agregarMarcador(new Marcador(marcador1));
    vectorMarcadores.agregarMarcador(new Marcador(marcador2));

    // Mostrar el vector de marcadores
    std::cout << "\nVector de Marcadores:\n";
    std::cout << vectorMarcadores << std::endl;

    // Buscar un marcador
    Marcador marcadorBusqueda("Google");
    Marcador* encontrado = vectorMarcadores.buscarMarcador(&marcadorBusqueda);
    if (encontrado) {
        std::cout << "Marcador encontrado: " << *encontrado << std::endl;
    }
    else {
        std::cout << "Marcador no encontrado.\n";
    }

    // Eliminar un marcador
    vectorMarcadores.eliminarMarcador(encontrado);
    std::cout << "\nVector de Marcadores después de eliminar 'Google':\n";
    std::cout << vectorMarcadores << std::endl;

    // Crear páginas
    Pagina pagina1("Wikipedia", "https://www.wikipedia.org", false);
    Pagina pagina2("GitHub", "https://www.github.com", true);

    // Mostrar páginas
    std::cout << "\nPaginas creadas:\n";
    std::cout << pagina1 << std::endl;
    std::cout << pagina2 << std::endl;

    // Utilizar los métodos estáticos de la clase Pagina
    Pagina::agregarPagina(new Pagina(pagina1));
    Pagina::agregarPagina(new Pagina(pagina2));
    Pagina::mostrarPaginas(std::cout);

    // Crear un historial de páginas
    Historial historial;
    historial.agregarPagina(new Pagina("StackOverflow", "https://stackoverflow.com", false));
    historial.agregarPagina(new Pagina("Reddit", "https://www.reddit.com", false));

    // Mostrar historial
    std::cout << "\nHistorial de pestanas:\n";
    std::cout << historial << std::endl;

    // Eliminar una pestaña del historial
    historial.eliminarPagina(0);
    std::cout << "\nHistorial de pestanas despues de eliminar la primera:\n";
    std::cout << historial << std::endl;

	return 0;
}