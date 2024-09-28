#include "pch.h"
#include "CppUnitTest.h"
#include "../Navegador Web/Marcador.cpp"
#include "../Navegador Web/Pagina.cpp"
#include "../Navegador Web/Historial.cpp"
#include "../Navegador Web/Pestana.cpp"
#include "../Navegador Web/ListaPestana.cpp"
#include "../Navegador Web/VectorPaginas.cpp"
#include "../Navegador Web/GestorArchivos.cpp"
#include "../Navegador Web/Configuracion.cpp"
#include "../Navegador Web/NavegadorWeb.cpp"
#include "../Navegador Web/ExcepcionFueraRango.cpp"
#include "../Navegador Web/ExcepcionCategoria.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(crearPestannaPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			Assert::IsNotNull(navegador.getPestanaLista());
			size_t cantidadAntes = navegador.getPestanaLista()->obtenerListaPestanas().size();
			navegador.crearPestana(false); //Crear una pestaña normal
			size_t cantidadDespues = navegador.getPestanaLista()->obtenerListaPestanas().size();
			Assert::AreEqual(cantidadAntes + 1, cantidadDespues); //Para confirmar que en verdad se ha creado una pestaña			
		}
		TEST_METHOD(visitarPaginaPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			navegador.crearPestana(false); 
			Pestana* pestañaActiva = navegador.getPestanaLista()->obtenerPestanaActiva();
			Pagina* paginaPrueba = new Pagina("Facebook", "https://www.facebook.com");
			pestañaActiva->visitarPagina(paginaPrueba); 
			Assert::IsNotNull(pestañaActiva->getPaginaActiva());
			Assert::AreEqual("https://www.facebook.com", pestañaActiva->getPaginaActiva()->getURL().c_str()); 
			Pagina* paginaInexistente = nullptr; 
			pestañaActiva->visitarPagina(paginaInexistente);
			Assert::IsNull(pestañaActiva->getPaginaActiva());
		}
		TEST_METHOD(agregarMarcadorPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			navegador.crearPestana(false);
			Pestana* pestañaActiva = navegador.getPestanaLista()->obtenerPestanaActiva();
			Assert::IsNotNull(pestañaActiva);
			Pagina* paginaPrueba = new Pagina("Facebook", "https://www.facebook.com");
			pestañaActiva->visitarPagina(paginaPrueba);
			Assert::IsNotNull(pestañaActiva->getPaginaActiva());
			Marcador* marcadorPrueba = new Marcador("FacebookBookmark");
			bool marcadorAgregado = navegador.agregarMarcador(marcadorPrueba);
			Assert::IsTrue(marcadorAgregado);
			std::string resultadoBusqueda = navegador.busquedaMarcador("FacebookBookmark");
			resultadoBusqueda.erase(resultadoBusqueda.find_last_not_of(" \n\r\t") + 1);
			size_t pos = resultadoBusqueda.find("\n");
			std::string urlExtraida;
			if (pos != std::string::npos)
			{
				urlExtraida = resultadoBusqueda.substr(pos + 1);
			}
			else
			{
				urlExtraida = resultadoBusqueda;
			}
			Assert::AreEqual(std::string("https://www.facebook.com"), urlExtraida);
		}
		TEST_METHOD(incognitoPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			navegador.crearPestana(true);
			// Verificar que la pestaña sea en modo incógnito
			Pestana* pestanaActiva = navegador.getPestanaLista()->obtenerPestanaActiva();
			Assert::IsNotNull(pestanaActiva);
			Assert::IsTrue(pestanaActiva->getModoIncognito());
		}
		TEST_METHOD(buscarMarcadorPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			navegador.crearPestana(false);
			Pestana* pestañaActiva = navegador.getPestanaLista()->obtenerPestanaActiva();
			Assert::IsNotNull(pestañaActiva);
			Pagina* paginaPrueba = new Pagina("Facebook", "https://www.facebook.com");
			pestañaActiva->visitarPagina(paginaPrueba);
			Assert::IsNotNull(pestañaActiva->getPaginaActiva());
			Assert::AreEqual("https://www.facebook.com", pestañaActiva->getPaginaActiva()->getURL().c_str());
			Marcador* marcador = new Marcador("FacebookBookmark");
			bool marcadorAgregado = navegador.agregarMarcador(marcador);
			Assert::IsTrue(marcadorAgregado);
			std::string resultado = navegador.busquedaMarcador("FacebookBookmark");
			Assert::IsTrue(resultado.find("https://www.facebook.com") != std::string::npos);
		}
		TEST_METHOD(configuracionPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			Configuracion* nuevaConfig = new Configuracion();
			nuevaConfig->setLimiteHistorial(10); 
			nuevaConfig->setTiempoLimpiar(30);
			navegador.actualizarConfiguracion(nuevaConfig);
			Configuracion* configActual = navegador.getConfiguracion(); 
			Assert::IsNotNull(configActual); 
			Assert::AreEqual(configActual->getLimiteHistorial(), 10); 
			Assert::AreEqual(configActual->getTiempoLimpiar(), 30); 
		}
		TEST_METHOD(guardarPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			navegador.crearPestana(false);
			navegador.visitarPagina("https://www.facebook.com");
			std::string nombreArchivo = "prueba2.bin";
			navegador.guardarSeccion(nombreArchivo);
			GestorArchivos gestorArchivos;
			Assert::IsTrue(gestorArchivos.verificarArchivo(nombreArchivo));
		}
		TEST_METHOD(cargarArchivoPrueba)
		{
			NavegadorWeb& navegador = NavegadorWeb::getNavegadorWeb();
			std::string nombreArchivo = "prueba2.bin";
			GestorArchivos gestorArchivos;
			Pestana* nuevaPestana = new Pestana(false); 
			Pagina* nuevaPagina = new Pagina("Facebook", "https://www.facebook.com");
			nuevaPestana->visitarPagina(nuevaPagina);
			navegador.getPestanaLista()->agregarPestana(nuevaPestana);
			navegador.guardarSeccion(nombreArchivo);
			Assert::IsTrue(gestorArchivos.verificarArchivo(nombreArchivo));
			navegador.cargarSeccion(nombreArchivo);
			Pestana* pestanaActiva = navegador.getPestanaLista()->obtenerPestanaActiva();
			Assert::IsNotNull(pestanaActiva);
			Pagina* paginaActiva = navegador.getPestanaLista()->obtenerPaginaActiva();
			Assert::IsNotNull(paginaActiva);
			std::string urlEsperada = "https://www.facebook.com";
			Assert::AreEqual(urlEsperada.c_str(), paginaActiva->getURL().c_str(),
				"La URL cargada no coincide con la esperada.");
		}
	};
}
