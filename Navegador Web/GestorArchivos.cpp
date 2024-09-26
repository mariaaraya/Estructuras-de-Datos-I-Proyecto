#include "GestorArchivos.h"
#include "NavegadorWeb.h"

void GestorArchivos::Guardar(const std::string nombreArchivo, ListaPestana* n) {
    std::ofstream handle(nombreArchivo, std::ios::binary);

    if (!handle.is_open()) {
        throw std::runtime_error("Error al abrir el archivo '" + nombreArchivo + "'");
    }

    size_t numPestanas = 0;
    for (const auto& pestana : n->obtenerListaPestanas()) {
        if (!pestana->getModoIncognito()) {
            ++numPestanas;
        }
    }

    handle.write(reinterpret_cast<char*>(&numPestanas), sizeof(numPestanas));
    if (!handle) {
        throw std::runtime_error("Error al escribir el numero de pestañas en el archivo.");
    }

    for (const auto& pestana : n->obtenerListaPestanas()) {
        if (!pestana->getModoIncognito()) {
            bool modoIncognito = pestana->getModoIncognito();
            handle.write(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito));
            if (!handle) {
                std::cerr << "Error al escribir el modo incognito en el archivo." << std::endl;
            }

            bool hasHistorial = (pestana->getHistorial() != nullptr);
            handle.write(reinterpret_cast<char*>(&hasHistorial), sizeof(hasHistorial));
            if (!handle) {
                throw std::runtime_error("Error al escribir el modo incognito en el archivo.");
            }

            if (hasHistorial) {
                const auto& listaP = pestana->getHistorial()->obtenerListaPaginas();
                size_t numPaginas = listaP.size();
                handle.write(reinterpret_cast<char*>(&numPaginas), sizeof(numPaginas));
                if (!handle) {
                    throw std::runtime_error("Error al escribir el numero de páginas en el archivo");
                }

                for (const auto& pagina : listaP) {
                    std::string titulo = pagina->getTitulo();
                    size_t tituloSize = titulo.size();
                    handle.write(reinterpret_cast<char*>(&tituloSize), sizeof(tituloSize));
                    handle.write(titulo.c_str(), tituloSize);
                    if (!handle) {
                        std::cerr << "Error al escribir el titulo en el archivo." << std::endl;
                    }

                    std::string URL = pagina->getURL();
                    size_t URLSize = URL.size();
                    handle.write(reinterpret_cast<char*>(&URLSize), sizeof(URLSize));
                    handle.write(URL.c_str(), URLSize);
                    if (!handle) {
                        throw std::runtime_error("Error al escribir la URL en el archivo.");
                    }

                    const auto& marcador = pagina->getMarcador();
                    bool hasMarcador = (marcador != nullptr);
                    handle.write(reinterpret_cast<char*>(&hasMarcador), sizeof(hasMarcador));
                    if (!handle) {
                        throw std::runtime_error("Error al escribir el numero de marcadores en el archivo.");
                    }

                    if (hasMarcador) {
                        std::string nombre = marcador->getNombre();
                        size_t nombreSize = nombre.size();
                        handle.write(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
                        handle.write(nombre.c_str(), nombreSize);
                        if (!handle) {
                            throw std::runtime_error("Error al escribir el nombre del marcador en el archivo.");
                        }

                        const auto& etiquetas = marcador->getEtiquetas();
                        size_t etiquetasSize = etiquetas.size();
                        handle.write(reinterpret_cast<char*>(&etiquetasSize), sizeof(etiquetasSize));
                        if (!handle) {
                            throw std::runtime_error("Error al escribir el tamano de las etiquetas en el archivo.");
                        }

                        for (const auto& etiqueta : etiquetas) {
                            size_t etiquetaSize = etiqueta.size();
                            handle.write(reinterpret_cast<char*>(&etiquetaSize), sizeof(etiquetaSize));
                            handle.write(etiqueta.c_str(), etiquetaSize);
                            if (!handle) {
                                throw std::runtime_error("Error al escribir la etiqueta en el archivo.");
                            }
                        }
                    }
                }
            }
        }
    }

    handle.close();
}

bool GestorArchivos::verificarArchivo(const std::string nombreArchivo)
{
    std::ifstream handle(nombreArchivo, std::ios::binary);
    if (!handle.is_open()) {
        return false;
    }
    handle.close();
    return true;
}


ListaPestana* GestorArchivos::Leer(const std::string nombreArchivo)
{
    std::ifstream handle(nombreArchivo, std::ios::binary);

    if (!handle.is_open()) {
        throw std::runtime_error("Error al abrir el archivo '" + nombreArchivo + "'");
    }

    // Crear una nueva lista de pestañas
    ListaPestana* listaPestanas = new ListaPestana();

    // Leer número de pestañas
    size_t numPestanas;
    handle.read(reinterpret_cast<char*>(&numPestanas), sizeof(numPestanas));

    if (!handle) {
        throw std::runtime_error("Error al leer el número de pestañas.");
    }

    // Leer cada pestaña
    for (size_t i = 0; i < numPestanas; ++i) {
        bool modoIncognito;
        handle.read(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito));

        if (!handle) {
            throw std::runtime_error("Error al leer el modo incógnito de la pestaña.");
        }

        // Crear una nueva pestaña
        Pestana* pestana = new Pestana(modoIncognito);

        bool hasHistorial;
        handle.read(reinterpret_cast<char*>(&hasHistorial), sizeof(hasHistorial));

        if (hasHistorial) {
            Historial* historial = new Historial();
            pestana->setHistorial(historial);

            // Leer el historial
            size_t numPaginas;
            handle.read(reinterpret_cast<char*>(&numPaginas), sizeof(numPaginas));

            if (!handle) {
                throw std::runtime_error("Error al leer el número de páginas en el historial.");
            }

            for (size_t j = 0; j < numPaginas; ++j) {
                Pagina* pagina = new Pagina();

                // Leer título
                size_t tituloSize;
                handle.read(reinterpret_cast<char*>(&tituloSize), sizeof(tituloSize));
                if (!handle) {
                    throw std::runtime_error("Error al leer el tamaño del título de la página.");
                }

                std::string titulo(tituloSize, '\0');
                handle.read(&titulo[0], tituloSize);
                pagina->setTitulo(titulo);

                // Leer URL
                size_t URLSize;
                handle.read(reinterpret_cast<char*>(&URLSize), sizeof(URLSize));
                if (!handle) {
                    throw std::runtime_error("Error al leer el tamaño de la URL de la página.");
                }

                std::string URL(URLSize, '\0');
                handle.read(&URL[0], URLSize);
                pagina->setURL(URL);

                // Leer marcador
                bool hasMarcador;
                handle.read(reinterpret_cast<char*>(&hasMarcador), sizeof(hasMarcador));
                if (!handle) {
                    throw std::runtime_error("Error al leer el indicador de marcador.");
                }

                if (hasMarcador) {
                    Marcador* marcador = new Marcador();
                    pagina->setMarcador(marcador);

                    // Leer nombre del marcador
                    size_t nombreSize;
                    handle.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
                    if (!handle) {
                        throw std::runtime_error("Error al leer el tamaño del nombre del marcador.");
                    }

                    std::string nombre(nombreSize, '\0');
                    handle.read(&nombre[0], nombreSize);
                    marcador->setNombre(nombre);

                    // Leer etiquetas
                    size_t etiquetasSize;
                    handle.read(reinterpret_cast<char*>(&etiquetasSize), sizeof(etiquetasSize));
                    if (!handle) {
                        throw std::runtime_error("Error al leer el tamaño de las etiquetas.");
                    }

                    for (size_t k = 0; k < etiquetasSize; ++k) {
                        size_t etiquetaSize;
                        handle.read(reinterpret_cast<char*>(&etiquetaSize), sizeof(etiquetaSize));
                        if (!handle) {
                            throw std::runtime_error("Error al leer el tamaño de la etiqueta.");
                        }

                        std::string etiqueta(etiquetaSize, '\0');
                        handle.read(&etiqueta[0], etiquetaSize);
                        marcador->agregarEtiqueta(etiqueta);
                    }
                }

                historial->agregarPagina(pagina); // Agregar página al historial
            }
        }

        listaPestanas->agregarPestana(pestana); // Agregar la pestaña a la lista
    }

    handle.close();

    return listaPestanas; // Retornar la lista de pestañas
}