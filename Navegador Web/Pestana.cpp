#include "Pestana.h"

Pestana::Pestana(Historial* historial):historial(historial){}

Pestana::~Pestana() {delete historial;}

Historial* Pestana::getHistorial() {return historial;}

void Pestana::setHistorial(Historial* historial) {this->historial = historial;}

void Pestana::irAdelante()
{
	//Falta implementar
}

void Pestana::irAtras()
{
	//Falta implementar
}

void Pestana::visitarPagina(std::string url)
{
	//Falta implementar
}

void Pestana::mostrarHistorial(std::ostream& outp) const
{
	if (historial) {
		historial->mostrarHistorial(outp);
	}
}
