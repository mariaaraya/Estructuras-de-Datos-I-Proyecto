#pragma once
#include "Libreria.h"
#include "Historial.h"

class Pestana
{
public:
	Pestana(bool);
	Pestana(bool, Historial*);
	~Pestana();

	Historial* getHistorial();
	void setHistorial(Historial*);
	bool getModoIncognito();
	void setModoIncognito(bool);
	//Metodo del historial
	void PnavegarAdelante();
	void PnavegarAtras();
	bool visitarPagina(Pagina*);
	//Metodo del marcadores
	void PagregarMarcador(Marcador*);
	void PagregarEtiqueta(std::string);

	friend std::ostream& operator<<(std::ostream& outp, const Pestana&);

private:
	bool  modoIncognito; // true es que si es modoIncognito
	Historial* historial;
};

// Archivos binarios 
//void guardarPestana(std::ofstream&);
//void leerPestana(std::ifstream&);