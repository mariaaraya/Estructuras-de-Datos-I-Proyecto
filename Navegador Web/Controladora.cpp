#include "Controladora.h"

Controladora::Controladora()
{
	navegador = new NavegadorWeb();
}

Controladora::~Controladora()
{
	delete navegador;
}

void Controladora::menuPrincipal()
{
    int opcion = 0;
    do {
        try{
            system("CLS");
            std::cout << "=== Menu del Navegador ===\n";
            std::cout << "1. Ir a un sitio web\n";
            std::cout << "2. Agregar marcador\n";
            std::cout << "3. Importar/Exportar\n";
            std::cout << "4. Ver marcadores\n";
            std::cout << "5. Busqueda/Filtros\n";
            std::cout << "6. Modo de navegacion privada\n";
            std::cout << "7. Nueva pestana\n";
            std::cout << "8. Configuracion\n";
            std::cout << "0. Salir\n";
            std::cout << "Seleccione una opcion: ";
            std::cin >> opcion;
       
            manejoOpcion(opcion);
            std::cin.get();
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    } while (opcion != 0);
}

void Controladora::manejoOpcion(int opcion)
{
    switch (opcion) {
    case 1: visitarSitio(); break;
    case 7: nuevaPestana(); break;
    case 0: std::cout << "\nSaliendo...\n"; break;
    default: 
        std::cout << "\nOpcion invalida. Intente de nuevo.\n"; 
        std::cin.get();
        std::cin.get();
        break;
    }
}

void Controladora::visitarSitio()
{
    std::string url;

    if (navegador->obtenerPestanaActiva() == nullptr) {
        std::cout << "\n";
        std::cout << "\t\t\t\t\tPrimero debe crear una nueva pestana\n";
        std::cin.get();
        std::cin.get();
        return;
    }
    
     std::cout << "\n";
     std::cout << "\t\t\t\t\tIngresar URL del sitio web: ";
     std::getline(std::cin, url);
     navegador->visitarPagina(url);
    
    std::cin.get();
    std::cin.get();
}

void Controladora::nuevaPestana()
{
    navegador->agregarPestana(false); //Significa que es una pestaña normal, es decir, no es modo incógnito
    std::cout << "\n";
    std::cout<<"\t\t\t\t\tSe ha creado una nueva pestana"; //pa probar
    std::cin.get();
    std::cin.get();
}
