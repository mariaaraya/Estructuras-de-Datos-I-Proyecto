#include "Marcador.h"

// Constructor
Marcador::Marcador(std::string nombre) : nombre(nombre)
{
}
// Destructor
Marcador::~Marcador() {  }

std::string Marcador::getNombre() const { return nombre; }
std::vector<std::string> Marcador::getEtiquetas() const { return etiquetas; }

void Marcador::setNombre(std::string nuevoNombre) { nombre = nuevoNombre; }

void Marcador::agregarEtiqueta(const std::string& etiqueta)
{
    if (std::find(etiquetas.begin(), etiquetas.end(), etiqueta) == etiquetas.end()) {
        etiquetas.push_back(etiqueta);
    }
}

void Marcador::eliminarEtiqueta(const std::string& etiqueta)
{
    auto it = std::remove(etiquetas.begin(), etiquetas.end(), etiqueta);
    if (it != etiquetas.end()) {
        etiquetas.erase(it, etiquetas.end());
    }
}


bool Marcador::tieneEtiqueta(const std::string&) const { return false; }

void Marcador::guardarMarcador(std::ofstream& handle)
{
    size_t nombreSize = nombre.size();
    handle.write(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
    handle.write(nombre.c_str(), nombreSize);

    // Guardar las etiquetas
    size_t etiquetasSize = etiquetas.size();
    handle.write(reinterpret_cast<char*>(&etiquetasSize), sizeof(etiquetasSize));
    for (const auto& etiqueta : etiquetas) {
        size_t etiquetaSize = etiqueta.size();
        handle.write(reinterpret_cast<char*>(&etiquetaSize), sizeof(etiquetaSize));
        handle.write(etiqueta.c_str(), etiquetaSize);
    }
}


void Marcador::leerMarcador(std::ifstream& handle) {


    size_t nombreSize;
    handle.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
    this->nombre.resize(nombreSize);
    handle.read(&this->nombre[0], nombreSize);

    // Leer las etiquetas
    size_t etiquetasSize;
    handle.read(reinterpret_cast<char*>(&etiquetasSize), sizeof(etiquetasSize));
    etiquetas.resize(etiquetasSize);
    for (auto& etiqueta : etiquetas) {
        size_t etiquetaSize;
        handle.read(reinterpret_cast<char*>(&etiquetaSize), sizeof(etiquetaSize));
        etiqueta.resize(etiquetaSize);
        handle.read(&etiqueta[0], etiquetaSize);
    }


    handle.close();
}

Marcador& Marcador::operator=(const Marcador& m)
{
    if (this != &m) {
        nombre = m.nombre;
        etiquetas = m.etiquetas; // Copiar etiquetas también
    }
    return *this;
}

bool Marcador::operator==(const Marcador& m) const
{
    return nombre == m.nombre && etiquetas == m.etiquetas;
}

std::ostream& operator<<(std::ostream& outp, const Marcador& m)
{
    outp << m.nombre << ": ";
    for (const auto& etiqueta : m.etiquetas) {
        outp << etiqueta << " ";
    }
    return outp;

}
