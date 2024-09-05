#include "Pagina.h"

Pagina::Pagina(std::string titulo, std::string url, bool modoIncognito)
    : titulo(titulo), URL(url), modoIncognito(modoIncognito) {}

// Destructor
Pagina::~Pagina() {}

// Getters
std::string Pagina::getTitulo() const { return titulo; }
std::string Pagina::getURL() const { return URL; }
bool Pagina::getModoIncognito() const { return modoIncognito; }

// Setters
void Pagina::setTitulo(std::string nuevoTitulo) { titulo = nuevoTitulo; }
void Pagina::setURL(std::string nuevaURL) { URL = nuevaURL; }
void Pagina::setModoIncognito(bool nuevoModoIncognito) { modoIncognito = nuevoModoIncognito; }

Pagina& Pagina::operator=(const Pagina& p)
{
    if (this != &p) {
        this->titulo = p.titulo;
        this->URL = p.URL;
        this->modoIncognito = p.modoIncognito;
    }
    return *this;
}
bool Pagina::operator==(const Pagina& p)
{
    return (this->titulo == p.titulo && this->URL == p.URL && this->modoIncognito == p.modoIncognito);
}

std::ostream& operator<<(std::ostream& outp, const Pagina& p)
{
    outp << p.getTitulo() << "\n" << p.getURL();
    return outp;
}

// Inicialización de los atributos estáticos
std::list<Pagina*> Pagina::listaP;
std::list<Pagina*>::iterator Pagina::PaginaActiva = Pagina::listaP.end();

// Nuevos Métodos estáticos para manejo de lista de páginas
bool Pagina::agregarPagina(Pagina* p) {
    listaP.push_back(p);
    if (listaP.size() == 1) {
        PaginaActiva = listaP.begin();
    }
    return true;
}

void Pagina::cambiarPagina(Pagina* p) {
    auto iter = std::find(listaP.begin(), listaP.end(), p);
    if (iter != listaP.end()) {
        PaginaActiva = iter;
    }
}

Pagina* Pagina::obtenerPaginaActiva() {
    return (PaginaActiva != listaP.end()) ? *PaginaActiva : nullptr;
}

void Pagina::navegarAtras() {
    if (PaginaActiva != listaP.begin()) {
        --PaginaActiva;
    }
}

void Pagina::navegarAdelante() {
    if (PaginaActiva != listaP.end() && std::next(PaginaActiva) != listaP.end()) {
        ++PaginaActiva;
    }
}

void Pagina::mostrarPaginas(std::ostream& outp) {
    for (const auto& pagina : listaP) {
        outp << *pagina << std::endl;
    }
}
