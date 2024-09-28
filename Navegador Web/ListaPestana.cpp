#include "ListaPestana.h"

ListaPestana::ListaPestana() :PestanaActiva(listaP.end()) {}

ListaPestana::~ListaPestana()
{
    for (auto pestana : listaP) {
        delete pestana;
    }
    listaP.clear();
}

bool ListaPestana::agregarPestana(bool modoIn)
{
    listaP.push_back(new Pestana(modoIn));
    PestanaActiva = --listaP.end();
    return true;
}
/*Para archivos*/
void ListaPestana::agregarPestana(Pestana* p)
{
    listaP.push_back(p);
    PestanaActiva = --listaP.end();
}

Pagina* ListaPestana::obtenerPaginaActiva()
{
    if (!listaP.empty() && PestanaActiva != listaP.end()) {
        return (*PestanaActiva)->getHistorial()->obtenerPaginaActiva();
    }
    return nullptr;
}

Pestana* ListaPestana::obtenerPestanaActiva()
{
    if (!listaP.empty() && PestanaActiva != listaP.end()) {
        return *PestanaActiva;
    }
    return nullptr;
}

void ListaPestana::mostrarPestanaActiva()
{
    // Secuencia ANSI para color azul (para sistemas compatibles).
    const std::string azul = "\033[34m";
    const std::string reset = "\033[0m";

    int indice = 1;  // Contador para indicar el n�mero de la pesta�a.

    // Iterar por todas las pesta�as.
    for (auto it = listaP.begin(); it != listaP.end(); ++it, ++indice) {
        std::string formatoInicio = "<", formatoFin = ">";
        std::string color = ""; // Por defecto, sin color.

        // Si la pesta�a est� en modo inc�gnito, agregar el color azul.
        if ((*it)->getModoIncognito()) {
            color = azul;
        }

        // Si esta es la pesta�a activa, cambiamos el formato a `<< >>`.
        if (it == PestanaActiva) {
            formatoInicio = "<<";
            formatoFin = ">>";
        }

        // Mostrar el �ndice de la pesta�a con el formato y color adecuado.
        std::cout << color << formatoInicio << "Pestana " << indice << formatoFin << reset << " ";
    }
    std::cout << std::endl;  // Para asegurar que las pesta�as se imprimen en la misma l�nea.
}

bool ListaPestana::navegarArriba()
{
    if (PestanaActiva != listaP.begin()) {
        --PestanaActiva;
        return true;
    }
    else {
        return false;
    }
}

bool ListaPestana::navegarAbajo()
{
    if (PestanaActiva != std::prev(listaP.end())) {
        ++PestanaActiva;
        return true;
    }
    else {
        return false;
    }
}

bool ListaPestana::EliminarPestana()
{
    if (listaP.empty() || PestanaActiva == listaP.end()) {
        return false;
    }

    auto it = PestanaActiva;

    // Si hay m�s de una pesta�a
    if (listaP.size() > 1) {
        // Si no es la primera pesta�a, mover la pesta�a activa a la anterior
        if (it != listaP.begin()) {
            PestanaActiva = std::prev(it);
        }
        else {
            // Si es la primera pesta�a, mover la pesta�a activa a la siguiente
            PestanaActiva = std::next(it);
        }
    }
    else {
        // Si solo hay una pesta�a, la lista quedar� vac�a
        PestanaActiva = listaP.end();
    }

    delete* it;
    listaP.erase(it);
    if (listaP.empty()) {
        agregarPestana(false); // Puedes ajustar el par�metro seg�n sea necesario
    }
    return true;
}

const std::list<Pestana*>& ListaPestana::obtenerListaPestanas() const
{
    return listaP;
}

std::ostream& operator<<(std::ostream& outp, const ListaPestana& n)
{
    for (const auto& pestana : n.listaP) {
        if (pestana->getModoIncognito() == false) {
            outp << *pestana << std::endl;
        }
    }
    return outp;
}

/*=============Pagina=============*/

void ListaPestana::visitarPagina(Pagina* p)
{ 
    (*PestanaActiva)->visitarPagina(p);
}

bool ListaPestana::navegarAtrasP()
{
    return (*PestanaActiva)->PnavegarAtras();
}

bool ListaPestana::navegarAdelanteP()
{
    return  (*PestanaActiva)->PnavegarAdelante();
}

void ListaPestana::mostarPagina()
{
    (*PestanaActiva)->mostarPagina();
}

void ListaPestana::PMostrar()
{
    std::cout << "==========================================================================================\n";
    std::cout << "                                      Navegador Web         \n";
    std::cout << "==========================================================================================\n";
    mostrarPestanaActiva();
    std::cout << "------------------------------------------------------------------------------------------\n";
    mostarPagina(); 
    std::cout << "==========================================================================================\n\n";
}


bool ListaPestana::agregarMarcador(Marcador* marcador)
{
    if (PestanaActiva!= listaP.end()) {
        return (*PestanaActiva)->PagregarMarcador(marcador);
    }
    return false;
}

bool  ListaPestana::agregarEtiqueta(std::string etiqueta)
{
   return (*PestanaActiva)->PagregarEtiqueta(etiqueta);
}

std::string ListaPestana::buscarPaginas(const std::string& critero) const
{
    return (*PestanaActiva)->PbuscarPaginas(critero);
}

void ListaPestana::aplicarPoliticasHistorial(int limite, int tie)
{
    (*PestanaActiva)->PaplicarPoliticasHistorial(limite , tie);
}


