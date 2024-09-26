#include "ExcepcionFueraRango.h"

ExcepcionFueraRango::ExcepcionFueraRango() : Excepcion() {}

ExcepcionFueraRango::~ExcepcionFueraRango() {}

std::string ExcepcionFueraRango::toString() const {
	return "ERROR: el dato digitado esta fuera de rango.\n";
}

