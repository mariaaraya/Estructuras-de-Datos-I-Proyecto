#pragma once
#include "Libreria.h"

class Excepcion {
public:
	Excepcion() =default;
	virtual ~Excepcion() = default;
	virtual std::string toString() const = 0;
};

//Detectar errores : Identifica fallos en tiempo de ejecución sin necesidad de comprobaciones exhaustivas.
//Mantener la claridad del código : Separa la lógica del programa del manejo de errores.
//Mejorar la robustez : Evita la propagación de errores y facilita la recuperación.
//Facilitar la depuración : Simplifica la identificación y corrección de errores.
/*Referencia: https://oregoom.com/cpp/excepciones/#google_vignette*/