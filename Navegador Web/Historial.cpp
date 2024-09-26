#define _CRT_SECURE_NO_WARNINGS
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
    if (PaginaActiva != listaP.end()) {
        std::cout << **PaginaActiva << std::endl;
    }
    else
        std::cout << "" << std::endl;
}

bool Historial::navegarAtras()
{
    if (PaginaActiva != listaP.begin()) {
        --PaginaActiva;
        return true;
    }
    return false;
}

bool Historial::navegarAdelante()
{

    if (PaginaActiva != listaP.end() && PaginaActiva != std::prev(listaP.end())) {
        ++PaginaActiva;
        return true;
    }
    return false;
}

const std::list<Pagina*>& Historial::obtenerListaPaginas() const
{
    return listaP;
}

bool Historial::eliminarPaginaFrente()
{
	if (!listaP.empty()) {
		if (PaginaActiva == listaP.begin()) {
			// Mover la página activa a la siguiente página antes de eliminar la actual
			PaginaActiva = std::next(listaP.begin());
		}
		Pagina* pagina = listaP.front();
		listaP.pop_front();
		delete pagina;
		// Si la lista está vacía después de eliminar, ajustar PaginaActiva
		if (listaP.empty()) {
			PaginaActiva = listaP.end();
		}
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& outp, const Historial& h)
{
	for (const auto& pagina : h.listaP) {
		outp << *pagina << std::endl;
	}
	return outp;
}



/*==========================================*/
bool Historial::agregarMarcador(Marcador* marcador)
{
    if (PaginaActiva != listaP.end()) {
        (*PaginaActiva)->setMarcador(marcador);
        return true;
    }
    return false;
}


bool Historial::agregarEtiqueta(std::string etiqueta)
{
    if (PaginaActiva != listaP.end()) {
        return (*PaginaActiva)->agregarEtiqueta(etiqueta);
    }
    return false;
}



std::string Historial::buscarPaginas(const std::string& nombreMarcador) const
{
    std::ostringstream oss;
    bool found = false;
    for (const auto& pagina : listaP) {
        if (pagina->getMarcador() && pagina->getMarcador()->getNombre() == nombreMarcador) {
            oss << *pagina << std::endl;
            found = true;

        }
    }
    return found ? oss.str() : "No se encontraron páginas con el marcador especificado.";
}


/*+++++++++++++++++++++Configuracion+++++++++++++++++++++++++++++++++++*/
void Historial::aplicarPoliticasHistorial(int limiteHistorial, int TiempoLimpiar)
{
    while (listaP.size() > limiteHistorial) {
        eliminarPaginaFrente();
      
    }
    auto ahora = std::chrono::system_clock::now();
    auto tiempoLimpiar = std::chrono::hours(TiempoLimpiar * 24);

    for (auto it = listaP.begin(); it != listaP.end();) {
        auto fechaVisita = (*it)->getFechaVisita();
        auto tiempoVisita = std::chrono::duration_cast<std::chrono::hours>(ahora - fechaVisita);

        std::time_t fechaVisitaTimeT = std::chrono::system_clock::to_time_t(fechaVisita);
        std::tm* tm = std::localtime(&fechaVisitaTimeT);

        if (tiempoVisita > tiempoLimpiar) {
            if (PaginaActiva == it) {
                PaginaActiva = std::next(it);
            
            }
            it = listaP.erase(it);
          
        }
        else {
            ++it;
        }
    }
}