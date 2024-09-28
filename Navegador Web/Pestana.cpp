#include "Pestana.h"

Pestana::Pestana(bool modo) :modoIncognito(modo), historial(new Historial), fechaVisita(std::chrono::system_clock::now()) {}

Pestana::Pestana(bool modo, Historial* historial)
	:modoIncognito(modo), historial(historial), fechaVisita(std::chrono::system_clock::now()) {}

Pestana::~Pestana() {
	delete historial;
}

Historial* Pestana::getHistorial() { return historial; }
void Pestana::setHistorial(Historial* historial) { this->historial = historial; }
bool Pestana::getModoIncognito() { return modoIncognito; }
void Pestana::setModoIncognito(bool modo) { modoIncognito = modo; }

Pagina* Pestana::getPaginaActiva()
{
	return historial->obtenerPaginaActiva();
}

bool Pestana::PnavegarAdelante()
{
	return historial->navegarAdelante();
}

bool Pestana::PnavegarAtras()
{
	return  historial->navegarAtras();
}

bool Pestana::visitarPagina(Pagina* aux)
{
	return historial->agregarPagina(aux);
}

void Pestana::mostarPagina()
{
	historial->mostrarPaginaActiva();
}

void Pestana::Filtro(std::string filtro)
{
	historial->Filtro(filtro);
}


std::ostream& operator<<(std::ostream& outp, const Pestana& pestana)
{
	outp << *pestana.historial << std::endl;
	return outp;
}

/*----------*/

/*------------------------Marcador------------------------*/


bool Pestana::PagregarMarcador(Marcador* marcador)
{
	return historial->agregarMarcador(marcador);
}

bool Pestana::PagregarEtiqueta(std::string etiqueta)
{
	return historial->agregarEtiqueta(etiqueta);
}

std::string Pestana::PbuscarPaginas(const std::string& marcador) const
{
	return historial->buscarPaginas(marcador);
}


/*-------------------Configuracion------------------------*/


void Pestana::PaplicarPoliticasHistorial(int limite, int tie)
{
	historial->aplicarPoliticasHistorial(limite, tie);
}

