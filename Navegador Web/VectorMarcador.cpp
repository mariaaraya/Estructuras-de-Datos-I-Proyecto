#include "VectorMarcador.h"

VectorMarcador::VectorMarcador()
{

}

VectorMarcador::~VectorMarcador()
{
	for (auto marcador : vecmarcador) {
		delete marcador;
	}
	vecmarcador.clear();
}

bool VectorMarcador::agregarMarcador(Marcador* m)
{
	vecmarcador.push_back(m);
	return true;
}

Marcador* VectorMarcador::buscarMarcador(Marcador* m)
{
	if (!m) return nullptr;
	for (auto marcador : vecmarcador) {
		if (*marcador == *m) {
			return marcador;
		}
	}
	return nullptr;
}

std::ostream& operator<<(std::ostream& outp, const VectorMarcador& vec)
{
	for (const auto& marcador : vec.vecmarcador) {
		outp << *marcador << std::endl;
	}
	return outp;
}
