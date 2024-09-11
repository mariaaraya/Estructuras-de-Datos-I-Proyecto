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
    void navegarAtras();
    void navegarAdelante();
    const std::list<Pagina*>& obtenerListaPaginas() const;
    //Metodo del marcadores
    void agregarMarcador(Marcador*);
    void agregarEtiqueta(std::string);
    friend std::ostream& operator<<(std::ostream&, const Historial&);
private:
    // Atributos estáticos para la lista de páginas y navegación
    std::list<Pagina*> listaP;
    std::list<Pagina*>::iterator PaginaActiva;
};

//// Archivos binarios 
   //void guardarHistorial(std::ofstream&);
   //void leerHistorial(std::ifstream&);