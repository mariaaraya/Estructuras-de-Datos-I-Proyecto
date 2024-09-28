#include "Controler.h"

Controler::Controler()
{
	navegador = &NavegadorWeb::getNavegadorWeb();
	opcion = 0;
}

Controler::Controler(NavegadorWeb* na)
{
	navegador = na;
	opcion = 0;
}

Controler::~Controler()
{
	if (navegador) delete navegador;
}

void Controler::controlPrincipal()
{
	MenuPrincipal::bienvenida();
	NuevaPestana(); // Se crea una pestaña apenas se ingresa el sistema
	system("pause");
	system("cls");
	do {
		navegador->Mostrar();
		opcion = MenuPrincipal::menuPrincipal();
		system("pause");
		system("cls");
		try {
			switch (opcion) {
			case 1:
				Vistar();
				system("cls");
				break;
			case 2:
				NuevaPestana();
				system("cls");
				break;
			case 3:
				EliminarPestana();
				system("cls");
				break;
			case 4:
				MMarcador();
				system("cls");
				break;
			case 5:
				ModoIncognito();
				system("cls");
				break;
			case 6:
				FiltroyBusqueda();
				system("cls");
				break;
			case 7:
				CConfiguracion();
				system("cls");
				break;
			case 8:
				Archivos();
				system("cls");
				break;
			case 72: // Flechas
			case 80:
			case 75:
			case 77:
				Navegar();
				break;
			case 9:
				Finalizar();
				system("cls");
				break;
			default:
				throw new ExcepcionFueraRango();
				break;
			}
		}
		catch (Excepcion* e) {
			MenuPrincipal::excepcion(e);
			system("pause");
			system("cls");
			delete e;
		}
		catch (...) {
			MenuPrincipal::error();
			system("pause");
			system("cls");
		}
	} while (opcion != 9);
}

/* Case 1*/
void Controler::Vistar()
{
	std::string url = MenuPrincipal::URl();
	bool aux = navegador->visitarPagina(url);
	if (aux == false) {
		system("cls");
		MenuPrincipal::pagina404();
	}
	system("pause");
}

/* Case 2*/
void Controler::NuevaPestana()
{
	navegador->crearPestana(false);
}

void Controler::EliminarPestana()
{
	navegador->EliminarPestana();
}


void Controler::MMarcador()
{
	Marcador* marcadoraux = MenuPrincipal::marcador();
	bool aux = navegador->agregarMarcador(marcadoraux);
	if (aux == false) {
		system("cls");
		throw new ExcepcionCategoria();
	}
	system("pause");
}

void Controler::ModoIncognito()
{
	navegador->crearPestana(true);
}

void Controler::FiltroyBusqueda()
{
	do {
		opcion = MenuPrincipal::menuFiltroyBusqueda();
		system("pause");
		system("cls");
		try {
			switch (opcion) {
			case 1:
				Filtro();
				system("cls");
				break;
			case 2:
				Busqueda();
				system("cls");
				break;
			case 3:
				break;
			default:
				throw new ExcepcionFueraRango();
				break;
			}
		}
		catch (Excepcion* e)
		{
			MenuPrincipal::excepcion(e);
			system("pause");
			system("cls");
			delete e;
		}
		catch (...) {
			MenuPrincipal::error();
			system("pause");
			system("cls");
		}
	} while (opcion != 3);
}



void Controler::Filtro()
{
	std::string filtro = MenuPrincipal::nombreFiltro();
	navegador->Filtro(filtro);
}
void Controler::Busqueda()
{
	std::string marcador = MenuPrincipal::nombreMarcador();
     std::cout<<navegador->busquedaMarcador(marcador);
	system("pause");
	system("cls");
}


void Controler::CConfiguracion()
{
	Configuracion* configuracion = MenuPrincipal::crearConfiguracion();
	navegador->actualizarConfiguracion(configuracion);
	system("pause");
	system("cls");
}


void Controler::Archivos()
{
	do {
		opcion = MenuPrincipal::menuArchivo();
		system("pause");
		system("cls");
		try {
			switch (opcion) {
			case 1:
				Archivos1();
				system("cls");
				break;
			case 2:
				Archivos2();
				system("cls");
				break;
			case 3:
				break;
			default:
				throw new ExcepcionFueraRango();
				break;
			}
		}
		catch (Excepcion* e)
		{
			MenuPrincipal::excepcion(e);
			system("pause");
			system("cls");
			delete e;
		}
		catch (...) {
			MenuPrincipal::error();
			system("pause");
			system("cls");
		}
	} while (opcion != 3);
}

void Controler::Archivos1()
{
		std::string archivo = MenuPrincipal::nombreArchivo();
		navegador->guardarSeccion(archivo); // Captura posibles excepciones aquí
}

void Controler::Archivos2()
{
	std::string archivo = MenuPrincipal::nombreArchivoLeer();
	navegador->cargarSeccion(archivo);
	system("pause");
	system("cls");
}

/*---Navegar---*/
void Controler::Navegar()
{
	navegador->navegar(opcion);
}

/* Case Teclas*/

/*--Finalizar--*/
void Controler::Finalizar()
{
	MenuPrincipal::salir();
	system("pause");
}
