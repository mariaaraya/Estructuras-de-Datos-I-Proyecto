#pragma once
#include "Libreria.h"

class Marcador
{
public:
	Marcador(std::string = "NOMBRE");
	virtual~Marcador();

	// Getters
	std::string getNombre() const;
    std::vector<std::string> getEtiquetas() const; //nuevo

	// Setters
	void setNombre(std::string);
	void agregarEtiqueta(const std::string&); //nuevos
	void eliminarEtiqueta(const std::string&);

	bool tieneEtiqueta(const std::string&) const;


	Marcador& operator=(const Marcador&);
	bool operator==(const Marcador&) const;
	friend std::ostream& operator<<(std::ostream& outp, const Marcador&);
private:
	std::string nombre;
	std::vector<std::string> etiquetas; //nuevo
};
// archivos binarios
//void guardarMarcador(std::ofstream&);
//void leerMarcador(std::ifstream&);