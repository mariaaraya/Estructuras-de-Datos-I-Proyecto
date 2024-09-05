#include "Marcador.h"

// Constructor
Marcador::Marcador(std::string nombre) : nombre(nombre)
{
}
// Destructor
Marcador::~Marcador() {  }
std::string Marcador::getNombre() const { return nombre; }
// Setters

void Marcador::setNombre(std::string nuevoNombre) { nombre = nuevoNombre; }

Marcador& Marcador::operator=(const Marcador& m)
{
    if (this != &m) {
        nombre = m.nombre;


    }
    return *this;
}

bool Marcador::operator==(const Marcador& m)
{
    if (nombre != m.nombre) return false;

}

std::ostream& operator<<(std::ostream& outp, const Marcador& m)
{
    outp << m.nombre << ":";
    return outp;
}
