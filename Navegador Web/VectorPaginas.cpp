#include "VectorPaginas.h"

VectorPaginas::VectorPaginas()
{
	leerCVS();
}

VectorPaginas::~VectorPaginas()
{
	for (Pagina* pagina : paginas) {
		delete pagina;
	}
}

bool VectorPaginas::leerCVS()
{
	std::ifstream archivo("datos.csv");

	if (!archivo.is_open()) {
		return false;
	}
	else {
		std::string linea;
		getline(archivo, linea);
		while (std::getline(archivo, linea)) {
			std::stringstream ss(linea);
			std::string titulo, url, dominio;
			bool modoIncognito = false;
			if (std::getline(ss, titulo, ',') && std::getline(ss, url, ',')) {
				agregarPagina(new Pagina(titulo, url));
			}
		}
		return true;
	}

}


void VectorPaginas::agregarPagina(Pagina* nuevaPagina)
{
	paginas.push_back(nuevaPagina);
}

Pagina* VectorPaginas::buscarPagina(std::string titulo)
{
	for (const auto& pagina : paginas) {
		if (pagina->getURL() == titulo) {
			return pagina;
		}
	}
	return nullptr;
}



std::ostream& operator<<(std::ostream& outp, const VectorPaginas& vec)
{
	int contador = 0;
	for (const auto& pagina : vec.paginas) {
		outp << pagina->getTitulo() << " ";
		contador++;
		if (contador % 10 == 0) {  // Salta de línea cada 10 páginas
			outp << std::endl;
		}
	}
	return outp;
}

