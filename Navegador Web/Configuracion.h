#pragma once
#include "Libreria.h"

class Configuracion
{
public:
	Configuracion();
	~Configuracion();

	int getLimiteHistorial();
	void setLimiteHistorial(int);
	int getTiempoLimpiar();
	void setTiempoLimpiar(int);

private:
	int limiteHistorial;
	int tiempoLimpiar;
};

