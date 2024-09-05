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