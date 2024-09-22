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
/*Para archivos*/
void NavegadorWeb::agregarPestana(Pestana* p)
{
    listaP.push_back(p);
    PestanaActiva = --listaP.end();
}

Pagina* NavegadorWeb::obtenerPaginaActiva()
{
    if (PestanaActiva != listaP.end()) {
        return (*PestanaActiva)->getHistorial()->obtenerPaginaActiva();
    }
    return nullptr;
}

Pestana* NavegadorWeb::obtenerPestanaActiva()
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

const std::list<Pestana*>& NavegadorWeb::obtenerListaPestanas() const
{
    return listaP;
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

bool NavegadorWeb::eliminarPagina(const std::string& criterio)
{
    if (PestanaActiva != listaP.end()) {
        return (*PestanaActiva)->getHistorial()->eliminarPáginas(criterio);
    }
    return false;
}

Pagina* NavegadorWeb::buscarPagina(const std::string& criterio)
{
    if (PestanaActiva != listaP.end()) {
        return (*PestanaActiva)->getHistorial()->buscarPáginas(criterio);
    }
    return nullptr;
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



//void NavegadorWeb::guardarNavegadorWeb(std::string& nombreArchivo) {
//    // Abrir el archivo en modo binario y agregar datos al final
//    std::ofstream handle(nombreArchivo, std::ios::binary | std::ios::trunc);
//
//    if (!handle.is_open()) {
//        std::cerr << "Error al abrir el archivo '" << nombreArchivo << "'\n";
//        return;
//    }
//
//    size_t numPestanas = 0;
//    for (const auto& pestana : listaP) {
//        if (!pestana->getModoIncognito()) {
//            ++numPestanas;
//        }
//    }
//    // Guardar el número de pestañas que no están en modo incógnito
//    handle.write(reinterpret_cast<char*>(&numPestanas), sizeof(numPestanas));
//
//    for (const auto& pestana : listaP) {
//        if (!pestana->getModoIncognito()) {
//            pestana->guardarPestana(handle);
//        }
//    }
//
//    handle.close();
//}
//
//// Implementación de leerNavegadorWeb
//void NavegadorWeb::leerNavegadorWeb(std::string& nombreArchivo) {
//    std::ifstream handle(nombreArchivo, std::ios::binary);
//
//    if (!handle.is_open()) {
//        std::cout << "Error al abrir el archivo '" << nombreArchivo << "'";
//        exit(EXIT_FAILURE);
//    }
//    //leer numero pestañas
//    size_t numPestanas;
//    handle.read(reinterpret_cast<char*>(&numPestanas), sizeof(numPestanas));
//    //leer cada pestaña
//    for (size_t i = 0; i < numPestanas; ++i) {
//        Pestana* pestana = new Pestana(false); // Inicializa con un valor por defecto
//        pestana->leerPestana(handle);
//        listaP.push_back(pestana);
//    }
//
//    handle.close();
//}
