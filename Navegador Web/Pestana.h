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

	std::chrono::system_clock::time_point getFechaVisita() const;

	friend std::ostream& operator<<(std::ostream& outp, const Pestana&);

private:
	bool  modoIncognito; // true es que si es modoIncognito
	Historial* historial;
	std::chrono::system_clock::time_point fechaVisita;
};

// Archivos binarios 
//void guardarPestana(std::ofstream&);
//void leerPestana(std::ifstream&);