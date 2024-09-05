#pragma once
#include <string>
#include <iostream>

class Marcador
{
public:
	Marcador(std::string = "NOMBRE");
	virtual~Marcador();
	// Getters
	std::string getNombre() const;
	// Setters
	void setNombre(std::string);
	Marcador& operator=(const Marcador&);
	bool operator==(const Marcador&);
	friend std::ostream& operator<<(std::ostream& outp, const Marcador&);
private:
	std::string nombre;
};