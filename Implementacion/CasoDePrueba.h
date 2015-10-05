#pragma once

#include "ISistema.h"
#include "Prueba.h"

class CasoDePrueba : public Prueba
{
public:
	CasoDePrueba(Puntero<ISistema> (*inicializar)(nat MAX_BARRIOS, nat MAX_CLIENTES));

protected:
	void CorrerPruebaConcreta() override;
	Cadena GetNombre() const override;

private:
	Puntero<ISistema> (*inicializar)(nat MAX_BARRIOS, nat MAX_CLIENTES);
	Puntero<ISistema> InicializarSistema(nat MAX_BARRIOS = 20, nat MAX_CLIENTES = 20);
	Array<pCliente> InicializarCliente(Puntero<ISistema> interfaz, bool ignOk = false);
	Array<pBarrio> InicializarBarrio(Puntero<ISistema> interfaz, bool ignOk = false);
	void InicializarRecorrido(Puntero<ISistema> interfaz, bool ignOk = false);

	bool ignorarOK;
	void Verificar(TipoRetorno obtenido, TipoRetorno esperado, Cadena comentario);
	template <class T>
	void Verificar(const T& obtenido, const T& esperado, Cadena comentario);
	template <class T>
	void VerificarConjuntos(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra);
	template <class T>
	void VerificarSecuencias(Iterador<T> obtenidos, Iterador<T> esperados, Cadena comentarioEncontrado, Cadena comentarioFalta, Cadena comentarioSobra);
	template <class T>
	bool SonIguales(Iterador<T> obtenidos, Iterador<T> esperados) const;
	template <class T>
	Cadena ObtenerTexto(Iterador<T> it) const;
	template <class T>
	bool Pertenece(const T& dato, Iterador<T> iterador, T& encontrado) const;
	void VerificarConsultaCliente(Tupla<TipoRetorno, pCliente> obtenido, Tupla<TipoRetorno, pCliente> esperado, Cadena comentario);
	void VerificarListadoBarrios(Tupla<TipoRetorno, Iterador<pBarrio>> obtenido, Tupla<TipoRetorno, Iterador<pBarrio>> esperado, Cadena comentario);
	void VerificarListadoClientes(Tupla<TipoRetorno, Iterador<pCliente>> obtenido, Tupla<TipoRetorno, Iterador<pCliente>> esperado, Cadena comentario);
	void VerificarCaminoMasRapido(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario);
	void VerificarConsultaBarrio(Tupla<TipoRetorno, pBarrio> obtenido, Tupla<TipoRetorno, pBarrio> esperado, Cadena comentario);
	void VerificarBarrioConMasClientes(Tupla<TipoRetorno, pBarrio> obtenido, Tupla<TipoRetorno, pBarrio> esperado, Cadena comentario);
	void VerificarCaminoMenorDistancia(Tupla<TipoRetorno, pRecorrido> obtenido, Tupla<TipoRetorno, pRecorrido> esperado, Cadena comentario);
	void VerificarCableadoMinimo(Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> obtenido, Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> esperado, Cadena comentario);
	bool SonIguales(const pCliente& obtenido, const pCliente& esperado) const;
	Cadena ObtenerTexto(const pCliente& c) const;
	bool SonIguales(const pBarrio& obtenido, const pBarrio& esperado) const;
	Cadena ObtenerTexto(const pBarrio& b) const;
	bool SonIguales(const pRecorrido& obtenido, const pRecorrido& esperado) const;
	Cadena ObtenerTexto(const pRecorrido& r) const;
	bool SonIguales(const Tupla<Cadena, nat, nat>& obtenido, const Tupla<Cadena, nat, nat>& esperado) const;
	Cadena ObtenerTexto(const Tupla<Cadena, nat, nat>& t) const;
	bool SonIguales(const Tupla<Cadena, Cadena, nat>& obtenido, const Tupla<Cadena, Cadena, nat>& esperado) const;
	Cadena ObtenerTexto(const Tupla<Cadena, Cadena, nat>& t) const;

	void PruebaOKIngresoBarrio();
	void PruebaOKIngresoCliente();
	void PruebaOKConsultaCliente();
	void PruebaOKListadoBarrios();
	void PruebaOKListadoClientes();
	void PruebaOKIngresoConexion();
	void PruebaOKCaminoMasRapido();
	void PruebaOKBajaCliente();
	void PruebaOKConsultaBarrio();
	void PruebaOKBarrioConMasClientes();
	void PruebaOKCaminoMenorDistancia();
	void PruebaOKCableadoMinimo();

	void PruebaERRORIngresoBarrio();
	void PruebaERRORIngresoCliente();
	void PruebaERRORConsultaCliente();
	void PruebaERRORListadoBarrios();
	void PruebaERRORListadoClientes();
	void PruebaERRORIngresoConexion();
	void PruebaERRORCaminoMasRapido();
	void PruebaERRORBajaCliente();
	void PruebaERRORConsultaBarrio();
	void PruebaERRORBarrioConMasClientes();
	void PruebaERRORCaminoMenorDistancia();
	void PruebaERRORCableadoMinimo();
};