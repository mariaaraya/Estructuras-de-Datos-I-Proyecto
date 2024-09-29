#include "Pagina.h"


Pagina::Pagina(std::string titulo1, std::string url)
    : titulo(titulo1), URL(url), marcador(nullptr), filtro(true), fechaVisita(std::chrono::system_clock::now()) {
    std::time_t fechaVisitaTimeT = std::chrono::system_clock::to_time_t(fechaVisita);
    std::tm tm;
    localtime_s(&tm, &fechaVisitaTimeT);

}

Pagina::Pagina(std::string titulo1, std::string url, Marcador* marca) 
    : titulo(titulo1), URL(url), marcador(marca), filtro(true) , fechaVisita(std::chrono::system_clock::now()) {
    std::time_t fechaVisitaTimeT = std::chrono::system_clock::to_time_t(fechaVisita);
    std::tm tm;
    localtime_s(&tm, &fechaVisitaTimeT);
}

Pagina::Pagina(const Pagina& otra) : titulo(otra.titulo), URL(otra.URL) , filtro(otra.filtro) {
    fechaVisita = std::chrono::system_clock::now();
    std::time_t fechaVisitaTimeT = std::chrono::system_clock::to_time_t(fechaVisita);
    std::tm tm;
    localtime_s(&tm, &fechaVisitaTimeT);
    if (otra.marcador) {
        marcador = new Marcador(*otra.marcador); // Copia profunda del marcador
    }
    else {
        marcador = nullptr;
    }
}

// Destructor
Pagina::~Pagina() {
    if (marcador) delete marcador;
}

// Getters
std::string Pagina::getTitulo() const { return this->titulo; }
std::string Pagina::getURL() const { return URL; }
Marcador* Pagina::getMarcador() { return marcador; }
bool Pagina::getFiltro(){return filtro;}
// Setters
void Pagina::setTitulo(std::string nuevoTitulo) { titulo = nuevoTitulo; }
void Pagina::setURL(std::string nuevaURL) { URL = nuevaURL; }

void Pagina::setMarcador(Marcador* nuevoMarcador)
{
    if (marcador) delete marcador;
    marcador = nuevoMarcador;
}

void Pagina::setFiltro(bool fil){filtro = fil;}


bool Pagina::agregarEtiqueta(std::string tag)
{
    if (marcador) {
        marcador->agregarEtiqueta(tag);
        return true;
    }
    return false;
}

std::chrono::system_clock::time_point Pagina::getFechaVisita() const
{
    return fechaVisita;
}


Pagina& Pagina::operator=(const Pagina& p)
{
    if (this != &p) {
        this->titulo = p.titulo;
        this->URL = p.URL;
        if (this->marcador != nullptr) { delete this->marcador; }
        if (p.marcador != nullptr) {
            this->marcador = new Marcador(*p.marcador);
        }
        else { this->marcador = nullptr; }

    }
    return *this;
}
bool Pagina::operator==(const Pagina& p)
{
    return (this->titulo == p.titulo && this->URL == p.URL && *this->marcador == *p.marcador);
}

std::ostream& operator<<(std::ostream& outp, const Pagina& p)
{
    outp << p.getTitulo() << "\n" << p.getURL();
    return outp;
}
