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
	PaginaActiva = std::prev(listaP.end());
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

const std::list<Pagina*>& Historial::obtenerListaPaginas() const
{
	return listaP;
}

void Historial::agregarMarcador(Marcador* marcador)
{
	(*PaginaActiva)->setMarcador(marcador);
}

void Historial::agregarEtiqueta(std::string etiqueta)
{
	(*PaginaActiva)->agregarEtiqueta(etiqueta);
}



std::ostream& operator<<(std::ostream& outp, const Historial& h)
{
	for (const auto& pagina : h.listaP) {
		outp << *pagina << std::endl;
	}
	return outp;
}

//void Historial::guardarHistorial(std::ofstream& handle)
//{
//	// Guardar el n�mero de p�ginas
//	size_t numPaginas = listaP.size();
//	handle.write(reinterpret_cast<char*>(&numPaginas), sizeof(numPaginas));
//
//	// Guardar cada p�gina
//	for (const auto& pagina : listaP) {
//		pagina->guardarPagina(handle);
//	}
//}
//
//void Historial::leerHistorial(std::ifstream& handle)
//{
//	size_t numPaginas;
//	handle.read(reinterpret_cast<char*>(&numPaginas), sizeof(numPaginas));
//
//	for (size_t i = 0; i < numPaginas; ++i) {
//		Pagina* pagina = new Pagina();
//		pagina->leerPagina(handle);
//		listaP.push_back(pagina);
//	}
//}
Pagina* Historial::buscarP�ginas(const std::string& criterio) { //puede ser por t�tulo o URL
	for (Pagina* pagina : listaP) {
		if (pagina->getTitulo() == criterio || pagina->getURL() == criterio) {
			return pagina;
		}
	}
	return nullptr;
}

//Era eliminar una pagina o todas????
bool Historial::eliminarP�ginas(const std::string& criterio) { //puede ser por t�tulo o URL
	for (auto it = listaP.begin(); it != listaP.end(); ++it) {
		if ((*it)->getTitulo() == criterio || (*it)->getURL() == criterio) {
			delete* it;  // Elimina la p�gina de la memoria
			listaP.erase(it);  // Elimina la p�gina de la lista
			return true;  // P�gina eliminada con �xito
		}
	}
	return false;
}