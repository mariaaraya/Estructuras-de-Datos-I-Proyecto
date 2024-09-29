#pragma once
#include "Libreria.h"

class Excepcion {
public:
	Excepcion() =default;
	virtual ~Excepcion() = default;
	virtual std::string toString() const = 0;
};

//Detectar errores : Identifica fallos en tiempo de ejecuci�n sin necesidad de comprobaciones exhaustivas.
//Mantener la claridad del c�digo : Separa la l�gica del programa del manejo de errores.
//Mejorar la robustez : Evita la propagaci�n de errores y facilita la recuperaci�n.
//Facilitar la depuraci�n : Simplifica la identificaci�n y correcci�n de errores.
/*Referencia: https://oregoom.com/cpp/excepciones/#google_vignette*/