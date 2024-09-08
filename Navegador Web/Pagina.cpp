#include "Pagina.h"

Pagina::Pagina(std::string titulo1, std::string url)
    : titulo(titulo1), URL(url), marcador(nullptr) {}

Pagina::Pagina(std::string titulo1, std::string url, Marcador* marca)
    : titulo(titulo1), URL(url), marcador(marca) {}

Pagina::Pagina(const Pagina& otra) : titulo(otra.titulo), URL(otra.URL) {
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
std::string Pagina::getTitulo() const { return titulo; }
std::string Pagina::getURL() const { return URL; }
Marcador* Pagina::getMarcador() { return marcador; }

// Setters
void Pagina::setTitulo(std::string nuevoTitulo) { titulo = nuevoTitulo; }
void Pagina::setURL(std::string nuevaURL) { URL = nuevaURL; }

void Pagina::setMarcador(Marcador* nuevoMarcador)
{
    if (marcador) delete marcador;
    marcador = nuevoMarcador;
}

void Pagina::agregarEtiqueta(std::string tag)
{
    marcador->agregarEtiqueta(tag);
}

void Pagina::guardarPagina(std::ofstream& handle)
{

    // Guardar el título
    size_t tituloSize = titulo.size();
    handle.write(reinterpret_cast<char*>(&tituloSize), sizeof(tituloSize));
    handle.write(titulo.c_str(), tituloSize);

    // Guardar la URL
    size_t URLSize = URL.size();
    handle.write(reinterpret_cast<char*>(&URLSize), sizeof(URLSize));
    handle.write(URL.c_str(), URLSize);

    // Guardar el marcador si existe
    bool hasMarcador = (marcador != nullptr);
    handle.write(reinterpret_cast<char*>(&hasMarcador), sizeof(hasMarcador));
    if (hasMarcador) {
        marcador->guardarMarcador(handle);
    }
}

void Pagina::leerPagina(std::ifstream& handle)
{
    // Leer el título
    size_t tituloSize;
    handle.read(reinterpret_cast<char*>(&tituloSize), sizeof(tituloSize));
    titulo.resize(tituloSize);
    handle.read(&titulo[0], tituloSize);

    // Leer la URL
    size_t URLSize;
    handle.read(reinterpret_cast<char*>(&URLSize), sizeof(URLSize));
    URL.resize(URLSize);
    handle.read(&URL[0], URLSize);

    // Leer el marcador si existe
    bool hasMarcador;
    handle.read(reinterpret_cast<char*>(&hasMarcador), sizeof(hasMarcador));
    if (hasMarcador) {
        if (marcador == nullptr) {
            marcador = new Marcador();
        }
        marcador->leerMarcador(handle);
    }
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
