#ifndef SISTEMA_H
#define SISTEMA_H

#include "ISistema.h"

class Sistema : public ISistema
{
public:
	Sistema(nat MAX_BARRIOS, nat MAX_CLIENTES);

	// Tipo 1
	TipoRetorno IngresoBarrio(Cadena nombreBarrio, nat cantidadCamaras, nat promedioHurtos) override;
	TipoRetorno IngresoCliente(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Cadena nombreBarrio, Cadena direccion) override;
	Tupla<TipoRetorno, pCliente> ConsultaCliente(nat ciCliente) override;
	Tupla<TipoRetorno, Iterador<pBarrio>> ListadoBarrios() override;
	Tupla<TipoRetorno, Iterador<pCliente>> ListadoClientes() override;
	TipoRetorno IngresoConexion(Cadena nombreBarrioOrigen, Cadena nombreBarrioDestino, nat distancia, nat tiempo) override;
	Tupla<TipoRetorno, pRecorrido> CaminoMasRapido(Cadena nombreClienteOrigen, Cadena nombreClienteDestino) override;

	// Tipo 2
	TipoRetorno BajaCliente(nat ciCliente) override;
	Tupla<TipoRetorno, pBarrio> ConsultaBarrio(Cadena nombreBarrio) override;
	Tupla<TipoRetorno, pBarrio> BarrioConMasClientes() override;
	Tupla<TipoRetorno, pRecorrido> CaminoMenorDistancia(Cadena nombreBarrioOrigen, Cadena nombreBarrioDestino) override;
	Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> CableadoMinimo() override;

private:
};

#endif
