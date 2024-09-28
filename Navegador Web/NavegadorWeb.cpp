#include "NavegadorWeb.h"

NavegadorWeb* NavegadorWeb::navegadorWeb = nullptr;

NavegadorWeb::NavegadorWeb() {
	this->csvpaginas = new VectorPaginas;
	this->archivos = new GestorArchivos;
	this->configuracion = new Configuracion;
	this->pestanaLista = new ListaPestana;
}

NavegadorWeb::~NavegadorWeb()
{
	if (csvpaginas) delete csvpaginas;
	if (archivos) delete archivos;
	if (configuracion) delete configuracion;
	if (pestanaLista) delete pestanaLista;
}

NavegadorWeb& NavegadorWeb::getNavegadorWeb()
{
	if (navegadorWeb == nullptr) {
		navegadorWeb = new NavegadorWeb();
	}
	return *navegadorWeb;
}

ListaPestana* NavegadorWeb::getPestanaLista()
{
	return pestanaLista;
}

Configuracion* NavegadorWeb::getConfiguracion()
{
	return configuracion;
}

/*=========================Historial de navegación=========================*/

/*Metado para realizar la navegacion entre las paginas
77= para adelente (Pagina)
75= para atras (Pagina)
72= para arriba (Pestana)
80= para abajo  (Pestana)*/
bool NavegadorWeb::navegar(int flecha)
{
	if (flecha == 77) {
		return pestanaLista->navegarAdelanteP();
	}
	else if (flecha == 75) {
		return pestanaLista->navegarAtrasP();
	}
	else if (flecha == 72) {
		return pestanaLista->navegarArriba();
	}
	else if (flecha == 80) {
		return pestanaLista->navegarAbajo();
	}
	else
		return false;
}
/*===========================================================================*/

/*=========================Administrador de pestañas=========================*/

/*1-Creacion de paginas y pestañas*/
/*Primero busca la pagina en el csv si no esta  retorna  falso para que despues
dar el error 404 – Not Found(MenuPrincal) */

bool NavegadorWeb::visitarPagina(std::string url)
{
	Pagina* aux = csvpaginas->buscarPagina(url);
	if (aux) {
		Pagina* copiaAux = new Pagina(*aux);
		pestanaLista->visitarPagina(copiaAux);
		//pestanaLista->aplicarPoliticasHistorial(configuracion->getLimiteHistorial() , configuracion->getTiempoLimpiar());
		return true;
	}
	return false;
}

void NavegadorWeb::crearPestana(bool modo)
{
	pestanaLista->agregarPestana(modo);
}

void NavegadorWeb::Mostrar()
{
	pestanaLista->aplicarPoliticasHistorial(configuracion->getLimiteHistorial(), configuracion->getTiempoLimpiar());
	pestanaLista->PMostrar();
}


/*===================== Configuracion ================================*/
//actualiza las configuraciones	del usuario, el maximo de paginas y tiempo establecido
void NavegadorWeb::actualizarConfiguracion(Configuracion* confi)
{
	if (configuracion) delete configuracion;
	configuracion = confi;
}
bool NavegadorWeb::EliminarPestana()
{
	return pestanaLista->EliminarPestana();
}
void NavegadorWeb::Filtro(std::string filtro)
{
	pestanaLista->Filtro(filtro);
}
/*===========================================================================*/

/*=========================Sistema de marcadores=========================*/

/* Cada pagina solo puede tener un marcador si la persona 
crea un nueva marcadeor para a la misca pagian se elimina el viejo 
para poner el nuevo*/
bool NavegadorWeb::agregarMarcador(Marcador* marcador)
{
	return pestanaLista->agregarMarcador(marcador);
}

/*Mostrar las paginas de la pestana activa que poseen el marcador con el 
nombre solicitado */
std::string NavegadorWeb::busquedaMarcador(const std::string& marcador) const
{
	return pestanaLista->buscarPaginas(marcador);
}


/*===========================================================================*/


/*=========================Búsqueda y filtrado de historial=========================*/

/*Guarda el naveador que estanso usando*/
void NavegadorWeb::guardarSeccion(const std::string nombreArchivo)
{
	archivos->Guardar(nombreArchivo, pestanaLista);
}
/*Carga el navegadro anteriormente guardado*/
void NavegadorWeb::cargarSeccion(const std::string nombreArchivo)
{
		delete pestanaLista;
		pestanaLista = archivos->Leer(nombreArchivo);
	
}



/*===========================================================================*/


