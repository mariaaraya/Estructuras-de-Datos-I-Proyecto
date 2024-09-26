#pragma once

#include "Excepcion.h"
class ExcepcionCategoria : public Excepcion
{
public:
	ExcepcionCategoria();
	virtual ~ExcepcionCategoria();
	virtual std::string toString() const;
};

