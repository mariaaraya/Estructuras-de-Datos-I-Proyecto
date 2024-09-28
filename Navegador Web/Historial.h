#pragma once
#include "Libreria.h"
#include "Pagina.h"

class Historial
{
public:
    Historial();
    virtual~Historial();
    bool agregarPagina(Pagina* p);
    void cambiarPagina(Pagina* p);
    Pagina* obtenerPaginaActiva();
    void mostrarPaginaActiva();
    bool navegarAtras();
    bool navegarAdelante();
    const std::list<Pagina*>& obtenerListaPaginas() const;
    bool eliminarPaginaFrente();
    void Filtro(std::string);
    friend std::ostream& operator<<(std::ostream&, const Historial&);
    //Metodo del marcadores
    bool agregarMarcador(Marcador*);
    bool agregarEtiqueta(std::string);
    std::string buscarPaginas(const std::string&) const;
    //Metodos de Configuracion
    void aplicarPoliticasHistorial(int, int);
private:
    std::list<Pagina*> listaP;
    std::list<Pagina*>::iterator PaginaActiva;
};

