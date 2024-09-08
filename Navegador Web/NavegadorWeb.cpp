#include "NavegadorWeb.h"

NavegadorWeb::NavegadorWeb() :PestanaActiva(listaP.end()), paginas(new VectorPaginas()) {}

NavegadorWeb::~NavegadorWeb()
{
    for (auto pestana : listaP) {
        delete pestana;
    }
    listaP.clear();

    delete paginas;
}

bool NavegadorWeb::agregarPestana(bool modoIn)
{
    listaP.push_back(new Pestana(modoIn));
    PestanaActiva = --listaP.end();
    return true;
}

Pestana* NavegadorWeb::obtenerPaginaActiva()
{
    if (PestanaActiva != listaP.end()) {
        return *PestanaActiva;
    }
    return nullptr;
}

void NavegadorWeb::mostrarPestanaActiva()
{
    std::cout << **PestanaActiva << std::endl;
}

void NavegadorWeb::navegarArriba()
{
    if (PestanaActiva != listaP.begin()) {
        --PestanaActiva;
    }
}

void NavegadorWeb::navegarAbajo()
{
    if (PestanaActiva != listaP.end() && std::next(PestanaActiva) != listaP.end()) {
        ++PestanaActiva;
    }
}

void NavegadorWeb::agregarMarcador(Marcador* marcador)
{
    (*PestanaActiva)->PagregarMarcador(marcador);
}

void NavegadorWeb::agregarEtiqueta(std::string etiqueta)
{
    (*PestanaActiva)->PagregarEtiqueta(etiqueta);
}

void NavegadorWeb::PnavegarAdelante()
{
    (*PestanaActiva)->PnavegarAdelante();
}

void NavegadorWeb::PnavegarAtras()
{
    (*PestanaActiva)->PnavegarAtras();
}
//Primero busca la pagina en el csv si no esta  retorna  falso para que
// despues dar el error 404 – Not Found ( todavia no realizado) 
bool NavegadorWeb::visitarPagina(std::string p)
{
    Pagina* aux = paginas->buscarPagina(p);
    if (aux) {
        Pagina* copiaAux = new Pagina(*aux);
        return (*PestanaActiva)->visitarPagina(copiaAux);
    }
    return false;
}

void NavegadorWeb::guardarNavegadorWeb(std::string& nombreArchivo) {
    std::ofstream handle;

    // Abrir el archivo en modo binario y agregar datos al final
    handle.open(nombreArchivo, std::ios::binary | std::ios::app);

    if (!handle.is_open()) {
        std::cout << "Error al abrir el archivo '" << nombreArchivo << "'";
        exit(EXIT_FAILURE);
    }
    size_t numPestanas = 0;
    for (const auto& pestana : listaP) {
        if (!pestana->getModoIncognito()) {
            ++numPestanas;
        }
    }

    // Guardar el número de pestañas que no están en modo incógnito
    handle.write(reinterpret_cast<char*>(&numPestanas), sizeof(numPestanas));

    // Guardar cada pestaña que no está en modo incógnito
    for (const auto& pestana : listaP) {
        if (!pestana->getModoIncognito()) {
            pestana->guardarPestana(handle);
        }
    }

    handle.close();
}

// Implementación de leerNavegadorWeb
void NavegadorWeb::leerNavegadorWeb(std::string& nombreArchivo) {
    std::ifstream handle;

    // Abrir el archivo en modo binario
    handle.open(nombreArchivo, std::ios::binary);

    if (!handle.is_open()) {
        std::cout << "Error al abrir el archivo '" << nombreArchivo << "'";
        exit(EXIT_FAILURE);
    }

    // Leer el número de pestañas
    size_t numPestanas;
    handle.read(reinterpret_cast<char*>(&numPestanas), sizeof(numPestanas));

    // Leer cada pestaña
    for (size_t i = 0; i < numPestanas; ++i) {
        Pestana* pestana = new Pestana(false); // Inicializa con un valor por defecto
        pestana->leerPestana(handle);
        listaP.push_back(pestana);
    }

    handle.close();
}

std::ostream& operator<<(std::ostream& outp, const NavegadorWeb& n)
{
    for (const auto& pestana : n.listaP) {
        if (pestana->getModoIncognito() == false) {
            outp << *pestana << std::endl;
        }
    }
    return outp;
}
