#include "Sistema.h"

Sistema::Sistema(nat MAX_BARRIOS, nat MAX_CLIENTES)
{
}

// Tipo 1

TipoRetorno Sistema::IngresoBarrio(Cadena nombreBarrio, nat cantidadCamaras, nat promedioHurtos)
{
	return NO_IMPLEMENTADA;
}

TipoRetorno Sistema::IngresoCliente(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Cadena nombreBarrio, Cadena direccion)
{
	return NO_IMPLEMENTADA;
}

Tupla<TipoRetorno, pCliente> Sistema::ConsultaCliente(nat ciCliente)
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, Iterador<pBarrio>> Sistema::ListadoBarrios()
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, Iterador<pCliente>> Sistema::ListadoClientes()
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

TipoRetorno Sistema::IngresoConexion(Cadena nombreBarrioOrigen, Cadena nombreBarrioDestino, nat distancia, nat tiempo)
{
	return NO_IMPLEMENTADA;
}

Tupla<TipoRetorno, pRecorrido> Sistema::CaminoMasRapido(Cadena nombreClienteOrigen, Cadena nombreClienteDestino)
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

// Tipo 2

TipoRetorno Sistema::BajaCliente(nat ciCliente)
{
	return NO_IMPLEMENTADA;
}

Tupla<TipoRetorno, pBarrio> Sistema::ConsultaBarrio(Cadena nombreBarrio)
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, pBarrio> Sistema::BarrioConMasClientes()
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, pRecorrido> Sistema::CaminoMenorDistancia(Cadena nombreBarrioOrigen, Cadena nombreBarrioDestino)
{
	return TUPLA(NO_IMPLEMENTADA, nullptr);
}

Tupla<TipoRetorno, nat, Iterador<Tupla<Cadena, Cadena, nat>>> Sistema::CableadoMinimo()
{
	return TUPLA(NO_IMPLEMENTADA, 0, nullptr);
}
