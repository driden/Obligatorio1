#include "CasoDePrueba.h"
#include "PruebasMock.h"

CasoDePrueba::CasoDePrueba(Puntero<ISistema> (*inicializar)(nat MAX_BARRIOS, nat MAX_CLIENTES))
{
	this->inicializar = inicializar;
}

Puntero<ISistema> CasoDePrueba::InicializarSistema(nat MAX_BARRIOS, nat MAX_CLIENTES)
{
	Puntero<ISistema> interfaz = inicializar(MAX_BARRIOS, MAX_CLIENTES);
	ignorarOK = false;
	return interfaz;
}

Array<pCliente> CasoDePrueba::InicializarCliente(Puntero<ISistema> interfaz, bool ignOk)
{
	Array<pBarrio> barrios = this->InicializarBarrio(interfaz, ignOk);

	ignorarOK = ignOk;

	Array<pCliente> clientes(11);
	// Orden creciente por nombre
	clientes[0] = new ClienteMock(5, "Edgardo", 20150523, "Prado", "Joaquin Suarez 1234");
	clientes[1] = new ClienteMock(4723, "Federica", 20150904, "Tres Ombues", "Juan Rosal 171");
	clientes[2] = new ClienteMock(47001281, "Horacio", 20150904, "Pocitos", "Sarmiento 1121");
	clientes[3] = new ClienteMock(333, "Jose", 20150520, "Prado", "Millan 4532");
	clientes[4] = new ClienteMock(47, "Juan", 20150904, "Centro", "Cuareim 1517");	
	clientes[5] = new ClienteMock(1048282, "Lucía", 20150523, "Prado", "Burgues 3921");
	clientes[6] = new ClienteMock(47112, "Maria", 20150904, "Sayago", "San Martin 157");
	clientes[7] = new ClienteMock(99999999, "Martín", 20150521, "Centro", "Mercedes 172");
	clientes[8] = new ClienteMock(470, "Pedro", 20150904, "Centro", "Andes 1417");
	clientes[9] = new ClienteMock(43749284, "Santiago", 20150523, "Buceo", "L A de Herrera 2183");
	clientes[10] = new ClienteMock(123432, "Tomas", 20150523, "Carrasco", "Arocena 1121");

	Cadena texto = "Se ingresa el Cliente '{0}'.";

	for(int i = clientes.Largo -1; i >= 0; i --){
		Verificar(interfaz ->IngresoCliente(clientes[i]->ObtenerCiCliente(), clientes[i]->ObtenerNombreCliente(), clientes[i]->ObtenerFechaRegCliente(), clientes[i]->ObtenerNombreBarrio(), clientes[i]->ObtenerDireccion()), OK, texto.DarFormato(clientes[i]->ObtenerNombreCliente()));
	}

	ignorarOK = false;

	return clientes;
}

Array<pBarrio> CasoDePrueba::InicializarBarrio(Puntero<ISistema> interfaz, bool ignOk)
{
	ignorarOK = ignOk;

	Array<pBarrio> barrios(10);
	// Orden creciente por nombre
	Array<pCliente> clientes(3);
	clientes[0]  = new ClienteMock(1048282, "Lucía", 20150523, "Prado", "Burgues 3921");
	clientes[1] = new ClienteMock(5, "Edgardo", 20150523, "Prado", "Joaquin Suarez 1234");
	clientes[2] = new ClienteMock(333, "Jose", 20150520, "Prado", "Millan 4532");

	barrios[0] = new BarrioMock("Buceo", 10, 20, Iterador<pCliente>());
	barrios[1] = new BarrioMock("Carrasco", 1, 200, Iterador<pCliente>());
	barrios[2] = new BarrioMock("Centro", 40, 45, Iterador<pCliente>());
	barrios[3] = new BarrioMock("Cerro", 10, 0, Iterador<pCliente>());
	barrios[4] = new BarrioMock("Cordon", 5, 40, Iterador<pCliente>());
	barrios[5] = new BarrioMock("Malvin", 50, 2, Iterador<pCliente>());
	barrios[6] = new BarrioMock("Pocitos", 20, 10, Iterador<pCliente>());
	barrios[7] = new BarrioMock("Prado", 60, 60, clientes.ObtenerIterador());
	barrios[8] = new BarrioMock("Sayago", 2, 10, Iterador<pCliente>());
	barrios[9] = new BarrioMock("Tres Ombues", 40, 20, Iterador<pCliente>());

	Cadena texto = "Se ingresa el barrio '{0}'.";

	for(int i = barrios.Largo - 1; i >= 0; i --){
		Verificar(interfaz->IngresoBarrio(barrios[i]->ObtenerNombreBarrio(), barrios[i]->ObtenercantidadCamaras(), barrios[i]->ObtenerpromedioHurtos()), OK, texto.DarFormato(barrios[i]->ObtenerNombreBarrio()));
	}

	ignorarOK = false;

	return barrios;
}

void CasoDePrueba::InicializarRecorrido(Puntero<ISistema> interfaz, bool ignOk)
{
	ignorarOK = true;

	interfaz ->IngresoConexion("Pocitos", "Cordon", 5, 10);
	interfaz ->IngresoConexion("Pocitos", "Cordon", 10, 5);
	interfaz ->IngresoConexion("Prado", "Sayago", 25, 30);
	interfaz ->IngresoConexion("Sayago", "Tres Ombues", 55, 60);
	interfaz ->IngresoConexion("Buceo", "Cordon", 50, 15);
	interfaz ->IngresoConexion("Cerro", "Sayago", 30, 10);
	interfaz ->IngresoConexion("Malvin", "Carrasco", 5, 5);
	interfaz ->IngresoConexion("Pocitos", "Malvin", 30, 25);
	interfaz ->IngresoConexion("Pocitos", "Malvin", 40, 5);
	interfaz ->IngresoConexion("Malvin", "Carrasco", 15, 1);
	interfaz ->IngresoConexion("Cerro", "Prado", 25, 50);
	interfaz ->IngresoConexion("Malvin", "Prado", 50, 100);
	interfaz ->IngresoConexion("Malvin", "Cordon", 30, 60);
	interfaz ->IngresoConexion("Cordon", "Tres Ombues", 35, 50);
	interfaz ->IngresoConexion("Sayago", "Pocitos", 15, 26);

	ignorarOK = false;
}

Cadena CasoDePrueba::GetNombre()const
{
	return "Casos de Prueba";
}

void CasoDePrueba::CorrerPruebaConcreta()
{
	PruebaOKIngresoBarrio();
	PruebaOKIngresoCliente();
	PruebaOKConsultaCliente();
	PruebaOKListadoBarrios();
	PruebaOKListadoClientes();
	PruebaOKIngresoConexion();
	PruebaOKCaminoMasRapido();
	PruebaOKBajaCliente();
	PruebaOKConsultaBarrio();
	PruebaOKBarrioConMasClientes();
	PruebaOKCaminoMenorDistancia();
	PruebaOKCableadoMinimo();

	PruebaERRORIngresoBarrio();
	PruebaERRORIngresoCliente();
	PruebaERRORConsultaCliente();
	PruebaERRORListadoBarrios();
	PruebaERRORListadoClientes();
	PruebaERRORIngresoConexion();
	PruebaERRORCaminoMasRapido();
	PruebaERRORBajaCliente();
	PruebaERRORConsultaBarrio();
	PruebaERRORBarrioConMasClientes();
	PruebaERRORCaminoMenorDistancia();
	PruebaERRORCableadoMinimo();
}

void CasoDePrueba::Verificar(TipoRetorno obtenido, TipoRetorno esperado, Cadena comentario)
{
	if (!ignorarOK || obtenido != esperado)
		Prueba::Verificar(obtenido, esperado, comentario);
}

template <class T>
void CasoDePrueba::Verificar(const T& obtenido, const T& esperado, Cadena comentario)
{
	Verificar(SonIguales(obtenido, esperado) ? OK : ERROR, OK, comentario.DarFormato(ObtenerTexto(obtenido), ObtenerTexto(esperado)));
}

template <class T>
void CasoDePrueba::VerificarConjuntos(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra)
{
	bool verificarCantidad = true;
	nat totalObtenidos = 0;
	T aux;
	foreach (T obtenido, obtenidos)
	{
		totalObtenidos++;
		if (Pertenece(obtenido, esperados, aux))
			Verificar(OK, OK, comentarioEncontrado);
		else
		{
			Verificar(ERROR, OK, comentarioSobra.DarFormato(ObtenerTexto(obtenido)));
			verificarCantidad = false;
		}
	}
	nat totalEsperados = 0;
	foreach (T esperado, esperados)
	{
		totalEsperados++;
		if (!Pertenece(esperado, obtenidos, aux))
		{
			Verificar(ERROR, OK, comentarioFalta.DarFormato(ObtenerTexto(esperado)));
			verificarCantidad = false;
		}
	}
	if (verificarCantidad && totalObtenidos != totalEsperados)
		Verificar(ERROR, OK, "Se verifica la cantidad de elementos de los conjuntos");
}

template <class T>
void CasoDePrueba::VerificarSecuencias(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra)
{
	esperados.Reiniciar();

	foreach (T obtenido, obtenidos)
	{
		if (esperados.HayElemento())
		{
			T esperado = *esperados;
			++esperados;
			Verificar(obtenido, esperado, comentarioEncontrado);
		}
		else
			Verificar(ERROR, OK, comentarioSobra.DarFormato(ObtenerTexto(obtenido)));
	}

	while (esperados.HayElemento())
	{
		T esperado = *esperados;
		++esperados;
		Verificar(ERROR, OK, comentarioFalta.DarFormato(ObtenerTexto(esperado)));
	}
}

template <class T>
bool CasoDePrueba::SonIguales(Iterador<T> obtenidos, Iterador<T> esperados) const
{
	obtenidos.Reiniciar();
	esperados.Reiniciar();
	while (obtenidos.HayElemento() && esperados.HayElemento())
	{
		if (!SonIguales(*obtenidos, *esperados))
			return false;
		++obtenidos;
		++esperados;
	}

	return esperados.HayElemento() == obtenidos.HayElemento();
}

template <class T>
Cadena CasoDePrueba::ObtenerTexto(Iterador<T> it) const
{
	Cadena sepVacio = "";
	Cadena sepGuion = "-";
	Cadena sep = sepVacio;
	Cadena retorno = sepVacio;
	foreach (auto t, it)
	{
		retorno += sep + ObtenerTexto(t);
		sep = sepGuion;
	}
	return retorno;
}

template <class T>
bool CasoDePrueba::Pertenece(const T& dato, Iterador<T> iterador, T& encontrado) const
{
	foreach (T dato2, iterador)
	{
		if (SonIguales(dato, dato2))
		{
			encontrado = dato2;
			return true;
		}
	}
	return false;
}

void CasoDePrueba::VerificarConsultaCliente(Tupla<TipoRetorno, pCliente> obtenido, Tupla<TipoRetorno, pCliente> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarListadoBarrios(Tupla<TipoRetorno, Iterador<pBarrio>> obtenido, Tupla<TipoRetorno, Iterador<pBarrio>> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		VerificarSecuencias(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarListadoClientes(Tupla<TipoRetorno, Iterador<pCliente>> obtenido, Tupla<TipoRetorno, Iterador<pCliente>> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		VerificarSecuencias(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarCaminoMasRapido(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarConsultaBarrio(Tupla<TipoRetorno, pBarrio> obtenido, Tupla<TipoRetorno, pBarrio> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarBarrioConMasClientes(Tupla<TipoRetorno, pBarrio> obtenido, Tupla<TipoRetorno, pBarrio> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarCaminoMenorDistancia(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2, esperado.Dato2, "Se obtuvo {0} y se esperaba {1}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

void CasoDePrueba::VerificarCableadoMinimo(Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> obtenido, Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> esperado, Cadena comentario)
{
	if (obtenido.Dato1 == OK && esperado.Dato1 == OK)
	{
		IniciarSeccion(comentario, esperado.Dato1);
		Verificar(obtenido.Dato2 == esperado.Dato2 ? OK : ERROR, OK, "Se verifica el dato 2");
		assert(false); //TODO Sacar el verificar que no corresponda (se verifica el orden, o igualdad de conjuntos)
		VerificarSecuencias(obtenido.Dato3, esperado.Dato3, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		VerificarConjuntos(obtenido.Dato3, esperado.Dato3, "Se obtuvo {0} y se esperaba {1}", "Se esperaba {0}", "No se esperaba {0}");
		CerrarSeccion();
	}
	else
		Verificar(obtenido.Dato1, esperado.Dato1, comentario);
}

bool CasoDePrueba::SonIguales(const pCliente& obtenido, const pCliente& esperado) const
{
	return obtenido->ObtenerCiCliente() == esperado->ObtenerCiCliente() && obtenido->ObtenerNombreCliente() == esperado->ObtenerNombreCliente() && obtenido->ObtenerFechaRegCliente() == esperado->ObtenerFechaRegCliente() && obtenido->ObtenerNombreBarrio() == esperado->ObtenerNombreBarrio() && obtenido->ObtenerDireccion() == esperado->ObtenerDireccion();
}

Cadena CasoDePrueba::ObtenerTexto(const pCliente& c) const
{
	return c->ObtenerNombreCliente();
}

bool CasoDePrueba::SonIguales(const pBarrio& obtenido, const pBarrio& esperado) const
{
	//TODO: Comprobar los clientes del barrio
	return obtenido->ObtenerNombreBarrio() == esperado->ObtenerNombreBarrio() && obtenido->ObtenercantidadCamaras() == esperado->ObtenercantidadCamaras() && obtenido->ObtenerpromedioHurtos() == esperado->ObtenerpromedioHurtos();
}

Cadena CasoDePrueba::ObtenerTexto(const pBarrio& b) const
{
	return b->ObtenerNombreBarrio();
}

bool CasoDePrueba::SonIguales(const pRecorrido& obtenido, const pRecorrido& esperado) const
{
	return obtenido->ObtenerNombreBarrioOrigen() == esperado->ObtenerNombreBarrioOrigen() && obtenido->ObtenerDistanciaTotalRecorrido() == esperado->ObtenerDistanciaTotalRecorrido() && obtenido->ObtenerTiempoTotalRecorrido() == esperado->ObtenerTiempoTotalRecorrido();
}

Cadena CasoDePrueba::ObtenerTexto(const pRecorrido& r) const
{
	return r->ObtenerNombreBarrioOrigen();
}

bool CasoDePrueba::SonIguales(const Tupla<Cadena, nat, nat>& obtenido, const Tupla<Cadena, nat, nat>& esperado) const
{
	return obtenido.Dato1 == esperado.Dato1 && obtenido.Dato2 == esperado.Dato2 && obtenido.Dato3 == esperado.Dato3;
}

Cadena CasoDePrueba::ObtenerTexto(const Tupla<Cadena, nat, nat>& t) const
{
	return t.Dato1;
}

bool CasoDePrueba::SonIguales(const Tupla<Cadena, Cadena, nat>& obtenido, const Tupla<Cadena, Cadena, nat>& esperado) const
{
	return obtenido.Dato1 == esperado.Dato1 && obtenido.Dato2 == esperado.Dato2 && obtenido.Dato3 == esperado.Dato3;
}

Cadena CasoDePrueba::ObtenerTexto(const Tupla<Cadena, Cadena, nat>& t) const
{
	return t.Dato1;
}

void CasoDePrueba::PruebaOKIngresoBarrio()
{
	IniciarSeccion("Ingreso Barrio");
	Puntero<ISistema> interfaz = InicializarSistema();

	Verificar(interfaz->IngresoBarrio("Centro",40, 5), OK, "Se ingresa el barrio Centro.");
	Verificar(interfaz->IngresoBarrio("Cordon",40, 5), OK, "Se ingresa el barrio Cordon.");
	Verificar(interfaz->IngresoBarrio("Pocitos",40, 5), OK, "Se ingresa el barrio Pocitos.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKIngresoCliente()
{
	IniciarSeccion("Ingreso Cliente");
	Puntero<ISistema> interfaz = InicializarSistema(100, 50);

	Verificar(interfaz->IngresoBarrio("Centro",40, 5), OK, "Se ingresa el barrio Centro.");
	Verificar(interfaz->IngresoBarrio("Prado",40, 5), OK, "Se ingresa el barrio Prado.");

	Verificar(interfaz->IngresoCliente(47272, "Juan", 20150904, "Centro", "Cuareim 1517"), OK, "Se ingresa el cliente Juan");
	Verificar(interfaz->IngresoCliente(33333333, "Jose", 20150520, "Prado", "Millan 4532"), OK, "Se ingresa el cliente José");
	Verificar(interfaz->IngresoCliente(99999999, "Martín", 20150521, "Centro", "Mercedes 172"), OK, "Se ingresa el cliente Martín");
	Verificar(interfaz->IngresoCliente(10101010, "Lucía", 20150523, "Prado", "Burgues 3921"), OK, "Se ingresa el cliente Lucía");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKConsultaCliente()
{
	IniciarSeccion("Consulta Cliente");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCliente> esperado;
	Tupla<TipoRetorno, pCliente> obtenido;

	Array<pCliente> clientes = this -> InicializarCliente(interfaz, true);

	obtenido = interfaz->ConsultaCliente(5);
	esperado = Tupla<TipoRetorno, pCliente>(OK, new ClienteMock(5, "Edgardo", 20150523, "Prado", "Joaquin Suarez 1234"));

	VerificarConsultaCliente(obtenido, esperado, "Se verifica a al cliente CI 5.");

	obtenido = interfaz->ConsultaCliente(47);
	esperado = Tupla<TipoRetorno, pCliente>(OK, new ClienteMock(47, "Juan", 20150904, "Centro", "Cuareim 1517"));

	VerificarConsultaCliente(obtenido, esperado, "Se verifica a al cliente CI 47.");

	obtenido = interfaz->ConsultaCliente(333);
	esperado = Tupla<TipoRetorno, pCliente>(OK, new ClienteMock(333, "Jose", 20150520, "Prado", "Millan 4532"));

	VerificarConsultaCliente(obtenido, esperado, "Se verifica a al cliente CI 333.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKListadoBarrios()
{
	IniciarSeccion("Listado Barrios");
	Puntero<ISistema> interfaz = InicializarSistema();
	
	Array<pBarrio> solucion = this->InicializarBarrio(interfaz, true);

	Tupla<TipoRetorno, Iterador<pBarrio>> esperado;
	Tupla<TipoRetorno, Iterador<pBarrio>> obtenido;

	obtenido = interfaz->ListadoBarrios();
	esperado = Tupla<TipoRetorno, Iterador<pBarrio>>(OK, solucion.ObtenerIterador());

	VerificarListadoBarrios(obtenido, esperado, "Se listan los barrios ordenados por nombre.");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKListadoClientes()
{
	IniciarSeccion("Listado Clientes");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, Iterador<pCliente>> esperado;
	Tupla<TipoRetorno, Iterador<pCliente>> obtenido;
	
	esperado = Tupla<TipoRetorno, Iterador<pCliente>>(OK, this->InicializarCliente(interfaz, true).ObtenerIterador());

	obtenido = interfaz->ListadoClientes();

	VerificarListadoClientes(obtenido, esperado, "Se listan los clientes ordenados alfabeticamente.");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKIngresoConexion()
{
	IniciarSeccion("Ingreso Conexion");
	Puntero<ISistema> interfaz = InicializarSistema();

	Verificar(interfaz->IngresoConexion("Prado","Sayago", 10, 6), OK, "Se ingresa conexion Prado-Sayago.");
	Verificar(interfaz->IngresoConexion("Pocitos","Cordon", 5, 10), OK, "Se ingresa conexion Pocitos-Cordon.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKCaminoMasRapido()
{
	IniciarSeccion("Camino Mas Rapido");
	Puntero<ISistema> interfaz = InicializarSistema();

	this -> InicializarBarrio(interfaz, true);
	this -> InicializarRecorrido(interfaz, true);

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;
	
	obtenido = interfaz->CaminoMasRapido("Horacio", "Santiago");
	Array<Tupla<Cadena, nat, nat>> recorrido(2);
	recorrido[0] = Tupla<Cadena, nat, nat>("Cordon", 10, 5);
	recorrido[1] = Tupla<Cadena, nat, nat>("Buceo", 50, 15);
	esperado = Tupla<TipoRetorno, pRecorrido>(OK, new RecorridoMock("Pocitos", recorrido.ObtenerIterador(), 60, 20));

	VerificarCaminoMasRapido(obtenido, esperado, "Se lista el camino mas rapido desde Horacio hasta Santiago.");

	obtenido = interfaz->CaminoMasRapido("Tomas", "Santiago");
	recorrido = Array<Tupla<Cadena, nat, nat>>(4);
	recorrido[0] = Tupla<Cadena, nat, nat>("Malvin", 15, 1);
	recorrido[1] = Tupla<Cadena, nat, nat>("Pocitos", 40, 5);
	recorrido[2] = Tupla<Cadena, nat, nat>("Cordon", 10, 5);
	recorrido[3] = Tupla<Cadena, nat, nat>("Buceo", 50, 15);

	esperado = Tupla<TipoRetorno, pRecorrido>(OK, new RecorridoMock("Pocitos", recorrido.ObtenerIterador(), 115, 26));

	VerificarCaminoMasRapido(obtenido, esperado, "Se lista el camino mas rapido desde Tomas hasta Santiago.");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKBajaCliente()
{
	IniciarSeccion("Baja Cliente");
	Puntero<ISistema> interfaz = InicializarSistema();
	this -> InicializarCliente(interfaz, true);

	Verificar(interfaz->BajaCliente(47), OK, "Se da de baja al cliente CI 47.");
	Verificar(interfaz->BajaCliente(333), OK, "Se da de baja al cliente CI 333.");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKConsultaBarrio()
{
	IniciarSeccion("Consulta Barrio");
	Puntero<ISistema> interfaz = InicializarSistema();

	Array<pBarrio> barrios = this->InicializarBarrio(interfaz, true);

	Tupla<TipoRetorno, pBarrio> esperado;
	Tupla<TipoRetorno, pBarrio> obtenido;

	obtenido = interfaz->ConsultaBarrio("Prado");
	esperado = Tupla<TipoRetorno, pBarrio>(OK, barrios[7]);

	VerificarConsultaBarrio(obtenido, esperado, "Se consulta el barrio Prado.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaOKBarrioConMasClientes()
{
	IniciarSeccion("Barrio Con Mas Clientes");
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pBarrio> esperado;
	Tupla<TipoRetorno, pBarrio> obtenido;

	Array<pBarrio> barrios = this -> InicializarBarrio(interfaz, true);

	obtenido = interfaz->BarrioConMasClientes();
	esperado = Tupla<TipoRetorno, pBarrio>(OK, barrios[3]); // Centro

	VerificarBarrioConMasClientes(obtenido, esperado, "Se consulta el barrio con mas clientes.");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKCaminoMenorDistancia()
{
	IniciarSeccion("Camino Menor Distancia");
	Puntero<ISistema> interfaz = InicializarSistema();

	this -> InicializarBarrio(interfaz, true);
	this -> InicializarRecorrido(interfaz, true);

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;
	
	obtenido = interfaz->CaminoMenorDistancia("Horacio", "Santiago");
	Array<Tupla<Cadena, nat, nat>> recorrido(2);
	recorrido[0] = Tupla<Cadena, nat, nat>("Cordon", 5, 10);
	recorrido[1] = Tupla<Cadena, nat, nat>("Buceo", 50, 15);
	esperado = Tupla<TipoRetorno, pRecorrido>(OK, new RecorridoMock("Pocitos", recorrido.ObtenerIterador(), 55, 25));

	VerificarCaminoMasRapido(obtenido, esperado, "Se lista el camino de menor distancia desde Horacio hasta Santiago.");

	obtenido = interfaz->CaminoMenorDistancia("Tomas", "Santiago");
	recorrido = Array<Tupla<Cadena, nat, nat>>(4);
	recorrido[0] = Tupla<Cadena, nat, nat>("Malvin", 5, 5);
	recorrido[1] = Tupla<Cadena, nat, nat>("Pocitos", 30, 25);
	recorrido[2] = Tupla<Cadena, nat, nat>("Cordon", 5, 10);
	recorrido[3] = Tupla<Cadena, nat, nat>("Buceo", 50, 15);

	esperado = Tupla<TipoRetorno, pRecorrido>(OK, new RecorridoMock("Pocitos", recorrido.ObtenerIterador(), 90, 55));

	VerificarCaminoMasRapido(obtenido, esperado, "Se lista el camino de menor distancia desde Tomas hasta Santiago.");
	
	CerrarSeccion();
}

void CasoDePrueba::PruebaOKCableadoMinimo()
{
	IniciarSeccion("Cableado Minimo");
	Puntero<ISistema> interfaz = InicializarSistema();

	this -> InicializarBarrio(interfaz, true);
	this -> InicializarRecorrido(interfaz, true);

	Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> esperado;
	Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> obtenido;

	/*
	obtenido = interfaz->CableadoMinimo();
	esperado = ...

	VerificarCableadoMinimo(obtenido, esperado, "Comentario");
	*/
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngresoBarrio()
{
	IniciarSeccion("Ingreso Barrio", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema(5);
	InicializarBarrio(interfaz, true);
	Verificar(interfaz->IngresoBarrio("Centro", 40, 450), ERROR, "ERROR: Ya existe el barrio de nombre Centro.");
	Verificar(interfaz->IngresoBarrio("Pocitos", 30, 10), ERROR, "ERROR: Ya existe el barrio de nombre Pocitos.");	
	Verificar(interfaz->IngresoBarrio("Bronx", 230,10), ERROR, "ERROR: Se sobrepasa la cantidad máxima de barrios.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngresoCliente()
{
	IniciarSeccion("Ingreso Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema(20,11);
	InicializarCliente(interfaz, true);

	Verificar(interfaz->IngresoCliente(5, "Gerardo", 20151203, "Centro", "18 de Julio 342"), ERROR, "ERROR: Ya existe el cliente con CI 5.");
	Verificar(interfaz->IngresoCliente(1331122, "Mario", 20151203, "Bronx", "5th Avenue 2031"), ERROR, "No existe el barrio con nombre Bronx.");
	Verificar(interfaz->IngresoCliente(1991122, "Ester", 20150701, "Centro", "Uruguay 1291"), ERROR, "ERROR: Se sobrepasa la cantidad máxima de clientes.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORConsultaCliente()
{
	IniciarSeccion("Consulta Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pCliente> esperado;
	Tupla<TipoRetorno, pCliente> obtenido;
	InicializarCliente(interfaz, true);

	obtenido = interfaz->ConsultaCliente(9999);
	esperado = Tupla<TipoRetorno, pCliente>(ERROR, nullptr);

	VerificarConsultaCliente(obtenido, esperado, "No existe el cliente con CI 9999.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORListadoBarrios()
{
	IniciarSeccion("Listado Barrios", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();
	Tupla<TipoRetorno, Iterador<pBarrio>> esperado;
	Tupla<TipoRetorno, Iterador<pBarrio>> obtenido;

	esperado = Tupla<TipoRetorno, Iterador<pBarrio>>(ERROR, nullptr);
	obtenido = interfaz->ListadoBarrios();

	VerificarListadoBarrios(obtenido, esperado, "No hay barrios ingresados en el sistema.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORListadoClientes()
{
	IniciarSeccion("Listado Clientes", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, Iterador<pCliente>> esperado;
	Tupla<TipoRetorno, Iterador<pCliente>> obtenido;

	esperado = Tupla<TipoRetorno, Iterador<pCliente>>(ERROR, nullptr);
	obtenido = interfaz->ListadoClientes();

	VerificarListadoClientes(obtenido, esperado, "No hay clientes ingresados en el sistema.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORIngresoConexion()
{
	IniciarSeccion("Ingreso Conexion", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();
	InicializarBarrio(interfaz, true);

	Verificar(interfaz->IngresoConexion("Prado","Bronx", 10, 6), ERROR, "No existe el barrio destino con nombre Bronx.");
	Verificar(interfaz->IngresoConexion("Bronx","Pocitos", 90, 10), ERROR, "No existe el barrio origen con nombre Bronx.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORCaminoMasRapido()
{
	IniciarSeccion("Camino Mas Rapido", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;

	InicializarCliente(interfaz, true);

	obtenido = interfaz->CaminoMasRapido("Horacio", "Santiago");
	esperado = Tupla<TipoRetorno, pRecorrido>(OK, nullptr);

	VerificarCaminoMasRapido(obtenido, esperado, "No existe camino entre Horacio hasta Santiago.");

	obtenido = interfaz->CaminoMasRapido("Tomas", "Santiago");
	esperado = Tupla<TipoRetorno, pRecorrido>(OK, nullptr);

	VerificarCaminoMasRapido(obtenido, esperado, "No existe camino entre Tomas hasta Santiago.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORBajaCliente()
{
	IniciarSeccion("Baja Cliente", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Verificar(interfaz->BajaCliente(44381239), ERROR, "No existe un cliente con CI 44381239.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORConsultaBarrio()
{
	IniciarSeccion("Consulta Barrio", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pBarrio> esperado;
	Tupla<TipoRetorno, pBarrio> obtenido;

	InicializarBarrio(interfaz, true);

	obtenido = interfaz->ConsultaBarrio("Soho");
	esperado = Tupla<TipoRetorno, pBarrio>(ERROR, nullptr);

	VerificarConsultaBarrio(obtenido, esperado, "No existe el barrio con nombre Soho.");

	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORBarrioConMasClientes()
{
	IniciarSeccion("Barrio Con Mas Clientes", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pBarrio> esperado;
	Tupla<TipoRetorno, pBarrio> obtenido;

	obtenido = interfaz->BarrioConMasClientes();
	esperado = Tupla<TipoRetorno, pBarrio>(ERROR, nullptr);

	VerificarBarrioConMasClientes(obtenido, esperado, "No hay barrios ingresados en el sistema.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORCaminoMenorDistancia()
{
	IniciarSeccion("Camino Menor Distancia", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, pRecorrido> esperado;
	Tupla<TipoRetorno, pRecorrido> obtenido;

	InicializarCliente(interfaz, true);

	obtenido = interfaz->CaminoMenorDistancia("Horacio", "Santiago");
	esperado = Tupla<TipoRetorno, pRecorrido>(OK, nullptr);

	VerificarCaminoMasRapido(obtenido, esperado, "No existe camino entre Horacio hasta Santiago.");

	obtenido = interfaz->CaminoMenorDistancia("Tomas", "Santiago");
	esperado = Tupla<TipoRetorno, pRecorrido>(OK, nullptr);

	VerificarCaminoMasRapido(obtenido, esperado, "No existe camino entre Tomas hasta Santiago.");
	CerrarSeccion();
}

void CasoDePrueba::PruebaERRORCableadoMinimo()
{
	IniciarSeccion("Cableado Minimo", ERROR);
	Puntero<ISistema> interfaz = InicializarSistema();

	Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> esperado;
	Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> obtenido;

	InicializarCliente(interfaz, true);
	obtenido = interfaz->CableadoMinimo();
	esperado = Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>>(ERROR, 0, nullptr);

	VerificarCableadoMinimo(obtenido, esperado, "Comentario");
	
	CerrarSeccion();
}
