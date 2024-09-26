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
	NuevaPestana(); // Se crea una pestaña apenas se ingrea el sistema
	system("pause");
	system("cls");
	do {
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
				MMarcador();
				system("cls");
				break;
			case 4:
				ModoIncognito();
				system("cls");
				break;
			case 5:
				Busqueda();
				system("cls");
				break;
			case 6:
				CConfiguracion();
				system("cls");
				break;
			case 7:
				Archivos();
				system("cls");
				break;
			case 72: // Flechas
			case 80:
			case 75:
			case 77:
				Navegar();
			case 8:
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
		}
		catch (...) {
			MenuPrincipal::error();
			system("pause");
			system("cls");
		}
	} while (opcion != 8);
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
	navegador->crearPestana(true);
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
/* Case 4*/
void Controler::ModoIncognito()
{
	navegador->crearPestana(true);
}
/* Case 5*/
void Controler::Busqueda()
{
	std::string marcador = MenuPrincipal::nombreMarcador();
     std::cout<<navegador->busquedaMarcador(marcador);
	system("pause");
	system("cls");
}

/* Case 6*/
void Controler::CConfiguracion()
{
	Configuracion* configuracion = MenuPrincipal::crearConfiguracion();
	navegador->actualizarConfiguracion(configuracion);
	system("pause");
	system("cls");
}
/* Case 7*/

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
	navegador->guardarSeccion(archivo);
	system("pause");
	system("cls");
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
}
