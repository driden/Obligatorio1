#ifndef ISISTEMA_H
#define ISISTEMA_H

#include "Cadena.h"
#include "Iterador.h"
#include "Puntero.h"
#include "TipoRetorno.h"
#include "Tupla.h"
#include "ICliente.h"
#include "IBarrio.h"
#include "IRecorrido.h"

class ISistema abstract
{
public:
	virtual ~ISistema(){}

	// Tipo 1
	virtual TipoRetorno IngresoBarrio(Cadena nombreBarrio, nat cantidadCamaras, nat promedioHurtos) abstract;
	virtual TipoRetorno IngresoCliente(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Cadena nombreBarrio, Cadena direccion) abstract;
	virtual Tupla<TipoRetorno, pCliente> ConsultaCliente(nat ciCliente) abstract;
	virtual Tupla<TipoRetorno, Iterador<pBarrio>> ListadoBarrios() abstract;
	virtual Tupla<TipoRetorno, Iterador<pCliente>> ListadoClientes() abstract;
	virtual TipoRetorno IngresoConexion(Cadena nombreBarrioOrigen, Cadena nombreBarrioDestino, nat distancia, nat tiempo) abstract;
	virtual Tupla<TipoRetorno, pRecorrido> CaminoMasRapido(Cadena nombreClienteOrigen, Cadena nombreClienteDestino) abstract;

	// Tipo 2
	virtual TipoRetorno BajaCliente(nat ciCliente) abstract;
	virtual Tupla<TipoRetorno, pBarrio> ConsultaBarrio(Cadena nombreBarrio) abstract;
	virtual Tupla<TipoRetorno, pBarrio> BarrioConMasClientes() abstract;
	virtual Tupla<TipoRetorno, pRecorrido> CaminoMenorDistancia(Cadena nombreBarrioOrigen, Cadena nombreBarrioDestino) abstract;
	virtual Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> CableadoMinimo() abstract;
};

#endif
