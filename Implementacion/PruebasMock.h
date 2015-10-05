#pragma once

#include "ICliente.h"
#include "IBarrio.h"
#include "IRecorrido.h"

class ClienteMock : public ICliente
{
public:
	ClienteMock(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Cadena nombreBarrio, Cadena direccion);

	nat ObtenerCiCliente() const override;
	Cadena ObtenerNombreCliente() const override;
	nat ObtenerFechaRegCliente() const override;
	Cadena ObtenerNombreBarrio() const override;
	Cadena ObtenerDireccion() const override;

	bool operator==(const ICliente& c) const override;

private:
	nat m_CiCliente;
	Cadena m_NombreCliente;
	nat m_FechaRegCliente;
	Cadena m_NombreBarrio;
	Cadena m_direccion;
};

class BarrioMock : public IBarrio
{
public:
	BarrioMock(Cadena nombreBarrio, nat cantidadCamaras, nat promedioHurtos, Iterador<pCliente> clientesPorDireccion);

	Cadena ObtenerNombreBarrio() const override;
	nat ObtenercantidadCamaras() const override;
	nat ObtenerpromedioHurtos() const override;
	Iterador<pCliente> ObtenerClientesPorDireccion() const override;

	bool operator==(const IBarrio& b) const override;

private:
	Cadena m_NombreBarrio;
	nat m_cantidadCamaras;
	nat m_promedioHurtos;
	Iterador<pCliente> m_ClientesPorDireccion;
};

class RecorridoMock : public IRecorrido
{
public:
	RecorridoMock(Cadena nombreBarrioOrigen, Iterador<Tupla<Cadena, nat, nat>> traslados, nat distanciaTotalRecorrido, nat tiempoTotalRecorrido);

	Cadena ObtenerNombreBarrioOrigen() const override;
	Iterador<Tupla<Cadena, nat, nat>> ObtenerTraslados() const override;
	nat ObtenerDistanciaTotalRecorrido() const override;
	nat ObtenerTiempoTotalRecorrido() const override;

	bool operator==(const IRecorrido& r) const override;

private:
	Cadena m_NombreBarrioOrigen;
	Iterador<Tupla<Cadena, nat, nat>> m_Traslados;
	nat m_DistanciaTotalRecorrido;
	nat m_TiempoTotalRecorrido;
};
