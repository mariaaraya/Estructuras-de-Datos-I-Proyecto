#include "ListaPestana.h"

ListaPestana::ListaPestana() :PestanaActiva(listaP.end()) {}

ListaPestana::~ListaPestana()
{
    for (auto pestana : listaP) {
        delete pestana;
    }
    listaP.clear();
}

bool ListaPestana::agregarPestana(bool modoIn)
{
    listaP.push_back(new Pestana(modoIn));
    PestanaActiva = --listaP.end();
    return true;
}
/*Para archivos*/
void ListaPestana::agregarPestana(Pestana* p)
{
    listaP.push_back(p);
    PestanaActiva = --listaP.end();
}

Pagina* ListaPestana::obtenerPaginaActiva()
{
    if (!listaP.empty() && PestanaActiva != listaP.end()) {
        return (*PestanaActiva)->getHistorial()->obtenerPaginaActiva();
    }
    return nullptr;
}

Pestana* ListaPestana::obtenerPestanaActiva()
{
    if (!listaP.empty() && PestanaActiva != listaP.end()) {
        return *PestanaActiva;
    }
    return nullptr;
}

void ListaPestana::mostrarPestanaActiva()
{
    if (!listaP.empty() && PestanaActiva != listaP.end()) {
        std::cout << **PestanaActiva << std::endl;
    }
    else {
        std::cout << "No hay pestaña activa." << std::endl;
    }
}

bool ListaPestana::navegarArriba()
{
    if (PestanaActiva != listaP.begin()) {
        --PestanaActiva;
        return true;
    }
    else {
        return false;
    }
}

bool ListaPestana::navegarAbajo()
{
    if (PestanaActiva != listaP.end() && std::next(PestanaActiva) != listaP.end()) {
        ++PestanaActiva;
        return true;
    }
    else {
        return false;
    }
}

const std::list<Pestana*>& ListaPestana::obtenerListaPestanas() const
{
    return listaP;
}

std::ostream& operator<<(std::ostream& outp, const ListaPestana& n)
{
    for (const auto& pestana : n.listaP) {
        if (pestana->getModoIncognito() == false) {
            outp << *pestana << std::endl;
        }
    }
    return outp;
}

/*=============Pagina=============*/

void ListaPestana::visitarPagina(Pagina* p)
{ 
    (*PestanaActiva)->visitarPagina(p);
}

bool ListaPestana::navegarAtrasP()
{
    return (*PestanaActiva)->PnavegarAtras();
}

bool ListaPestana::navegarAdelanteP()
{
    return  (*PestanaActiva)->PnavegarAdelante();
}

void ListaPestana::mostarPagina()
{
    (*PestanaActiva)->mostarPagina();
}


bool ListaPestana::agregarMarcador(Marcador* marcador)
{
    if (PestanaActiva!= listaP.end()) {
        return (*PestanaActiva)->PagregarMarcador(marcador);
    }
    return false;
}

bool  ListaPestana::agregarEtiqueta(std::string etiqueta)
{
   return (*PestanaActiva)->PagregarEtiqueta(etiqueta);
}

std::string ListaPestana::buscarPaginas(const std::string& critero) const
{
    return (*PestanaActiva)->PbuscarPaginas(critero);
}

void ListaPestana::aplicarPoliticasHistorial(int limite, int tie)
{
    (*PestanaActiva)->PaplicarPoliticasHistorial(limite , tie);
}


