#pragma once
#include "Excepcion.h"
class ExcepcionFueraRango : public Excepcion {
public:
	ExcepcionFueraRango();
	virtual ~ExcepcionFueraRango();
	std::string toString() const;
};
