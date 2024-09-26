#pragma once
#include "Libreria.h"

class Excepcion {
public:
	Excepcion() =default;
	virtual ~Excepcion() = default;
	virtual std::string toString() const = 0;
};
