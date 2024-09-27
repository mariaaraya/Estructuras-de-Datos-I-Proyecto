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
	Pagina* getPaginaActiva();
	friend std::ostream& operator<<(std::ostream& outp, const Pestana&);
	//Metodo del historial
	bool PnavegarAdelante();
	bool PnavegarAtras();
	bool visitarPagina(Pagina*);
	void mostarPagina();
	//Metodo del marcadores
	bool PagregarMarcador(Marcador*);
	bool PagregarEtiqueta(std::string);
	std::string PbuscarPaginas(const std::string&) const;
	//Configuracion
	void PaplicarPoliticasHistorial(int, int);


private:
	bool  modoIncognito; // true es que si es modoIncognito
	Historial* historial;
	std::chrono::system_clock::time_point fechaVisita;
};
