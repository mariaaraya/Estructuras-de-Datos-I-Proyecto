#include "Historial.h"

Historial::Historial() : PaginaActiva(listaP.end()) {}

Historial::~Historial()
{
	for (auto pagina : listaP) {
		delete pagina;
	}
	listaP.clear();
}

bool Historial::agregarPagina(Pagina* p)
{
	listaP.push_back(p);
	if (listaP.size() == 1) {
		PaginaActiva = listaP.begin();
	}
	return true;
}

void Historial::cambiarPagina(Pagina* p)
{
	auto iter = std::find(listaP.begin(), listaP.end(), p);
	if (iter != listaP.end()) {
		PaginaActiva = iter;
	}

}

Pagina* Historial::obtenerPaginaActiva()
{
	if (PaginaActiva != listaP.end()) {
		return *PaginaActiva;
	}
	return nullptr;
}

void Historial::mostrarPaginaActiva()
{
	std::cout << **PaginaActiva << std::endl;
}

void Historial::navegarAtras()
{
	if (PaginaActiva != listaP.begin()) {
		--PaginaActiva;
	}
}

void Historial::navegarAdelante()
{
	if (PaginaActiva != listaP.end() && std::next(PaginaActiva) != listaP.end()) {
		++PaginaActiva;
	}
}

void Historial::agregarMarcador(Marcador* marcador)
{
	(*PaginaActiva)->setMarcador(marcador);
}

void Historial::agregarEtiqueta(std::string etiqueta)
{
	(*PaginaActiva)->agregarEtiqueta(etiqueta);
}

void Historial::guardarHistorial(std::ofstream& handle)
{
	// Guardar el número de páginas
	size_t numPaginas = listaP.size();
	handle.write(reinterpret_cast<char*>(&numPaginas), sizeof(numPaginas));

	// Guardar cada página
	for (const auto& pagina : listaP) {
		pagina->guardarPagina(handle);
	}
}

void Historial::leerHistorial(std::ifstream& handle)
{
	size_t numPaginas;
	handle.read(reinterpret_cast<char*>(&numPaginas), sizeof(numPaginas));

	for (size_t i = 0; i < numPaginas; ++i) {
		Pagina* pagina = new Pagina();
		pagina->leerPagina(handle);
		listaP.push_back(pagina);
	}
}

std::ostream& operator<<(std::ostream& outp, const Historial& h)
{
	for (const auto& pagina : h.listaP) {
		outp << *pagina << std::endl;
	}
	return outp;
}
