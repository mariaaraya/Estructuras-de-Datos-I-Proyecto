#include "Configuracion.h"

Configuracion::Configuracion() : limiteHistorial(100), tiempoLimpiar(100)
{
}

Configuracion::~Configuracion()
{
}

int Configuracion::getLimiteHistorial()
{
    return limiteHistorial;
}

void Configuracion::setLimiteHistorial(int limite)
{
    limiteHistorial = limite;
}

int Configuracion::getTiempoLimpiar()
{
    return tiempoLimpiar;
}

void Configuracion::setTiempoLimpiar(int tiempo)
{
    tiempoLimpiar = tiempo;  // Esto convertiría minutos a segundos
}
