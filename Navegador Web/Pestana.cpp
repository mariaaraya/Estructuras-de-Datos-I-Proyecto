#include "Pestana.h"

Pestana::Pestana(bool modo) :modoIncognito(modo), historial(new Historial) {}

Pestana::Pestana(bool modo, Historial* historial)
	:modoIncognito(modo), historial(historial) {}

Pestana::~Pestana() {
	delete historial;
}

Historial* Pestana::getHistorial() { return historial; }
void Pestana::setHistorial(Historial* historial) { this->historial = historial; }
bool Pestana::getModoIncognito() { return modoIncognito; }
void Pestana::setModoIncognito(bool modo) { modoIncognito = modo; }
void Pestana::PnavegarAdelante()
{
	historial->navegarAdelante();
}

void Pestana::PnavegarAtras()
{
	historial->navegarAtras();
}

bool Pestana::visitarPagina(Pagina* aux)
{
	historial->agregarPagina(aux);
	return true;
}

void Pestana::PagregarMarcador(Marcador* marcador)
{
	historial->agregarMarcador(marcador);
}

void Pestana::PagregarEtiqueta(std::string etiqueta)
{
	historial->agregarEtiqueta(etiqueta);
}

void Pestana::guardarPestana(std::ofstream& handle)
{ 
	// Guardar el modo incognito
	handle.write(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito));

	// Guardar el historial
	bool hasHistorial = (historial != nullptr);
	handle.write(reinterpret_cast<char*>(&hasHistorial), sizeof(hasHistorial));
	if (hasHistorial) {
		historial->guardarHistorial(handle);
	}
}

void Pestana::leerPestana(std::ifstream& handle)
{ 
	// Leer el modo incognito
	handle.read(reinterpret_cast<char*>(&modoIncognito), sizeof(modoIncognito));

	// Leer el historial
	bool hasHistorial;
	handle.read(reinterpret_cast<char*>(&hasHistorial), sizeof(hasHistorial));
	if (hasHistorial) {
		if (historial == nullptr) {
			historial = new Historial();
		}
		historial->leerHistorial(handle);
	}
}


std::ostream& operator<<(std::ostream& outp, const Pestana& pestana)
{
	outp << *pestana.historial << std::endl;
	return outp;
}
