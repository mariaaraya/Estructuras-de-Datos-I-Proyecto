#include "ExcepcionCategoria.h"

ExcepcionCategoria::ExcepcionCategoria() :Excepcion() {}

ExcepcionCategoria::~ExcepcionCategoria()
{
}

std::string ExcepcionCategoria::toString() const
{
	return  "Pagina no activa o Pestana no activa\n";;
}
