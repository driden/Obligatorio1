#include "PruebasMock.h"

ClienteMock::ClienteMock(nat ciCliente, Cadena nombreCliente, nat fechaRegCliente, Cadena nombreBarrio, Cadena direccion)
{
	m_CiCliente = ciCliente;
	m_NombreCliente = nombreCliente;
	assert(fechaRegCliente >= 20000101);
	m_FechaRegCliente = fechaRegCliente;
	m_NombreBarrio = nombreBarrio;
	m_direccion = direccion;
}

nat ClienteMock::ObtenerCiCliente() const
{
	return m_CiCliente;
}

Cadena ClienteMock::ObtenerNombreCliente() const
{
	return m_NombreCliente;
}

nat ClienteMock::ObtenerFechaRegCliente() const
{
	return m_FechaRegCliente;
}

Cadena ClienteMock::ObtenerNombreBarrio() const
{
	return m_NombreBarrio;
}

Cadena ClienteMock::ObtenerDireccion() const
{
	return m_direccion;
}

bool ClienteMock::operator==(const ICliente& c) const
{
	return this == &c;
}

BarrioMock::BarrioMock(Cadena nombreBarrio, nat cantidadCamaras, nat promedioHurtos, Iterador<pCliente> clientesPorDireccion)
{
	m_NombreBarrio = nombreBarrio;
	m_cantidadCamaras = cantidadCamaras;
	m_promedioHurtos = promedioHurtos;
	m_ClientesPorDireccion = clientesPorDireccion;
}

Cadena BarrioMock::ObtenerNombreBarrio() const
{
	return m_NombreBarrio;
}

nat BarrioMock::ObtenercantidadCamaras() const
{
	return m_cantidadCamaras;
}

nat BarrioMock::ObtenerpromedioHurtos() const
{
	return m_promedioHurtos;
}

Iterador<pCliente> BarrioMock::ObtenerClientesPorDireccion() const
{
	return m_ClientesPorDireccion;
}

bool BarrioMock::operator==(const IBarrio& b) const
{
	return this == &b;
}

RecorridoMock::RecorridoMock(Cadena nombreBarrioOrigen, Iterador<Tupla<Cadena, nat, nat>> traslados, nat distanciaTotalRecorrido, nat tiempoTotalRecorrido)
{
	m_NombreBarrioOrigen = nombreBarrioOrigen;
	m_Traslados = traslados;
	m_DistanciaTotalRecorrido = distanciaTotalRecorrido;
	m_TiempoTotalRecorrido = tiempoTotalRecorrido;
}

Cadena RecorridoMock::ObtenerNombreBarrioOrigen() const
{
	return m_NombreBarrioOrigen;
}

Iterador<Tupla<Cadena, nat, nat>> RecorridoMock::ObtenerTraslados() const
{
	return m_Traslados;
}

nat RecorridoMock::ObtenerDistanciaTotalRecorrido() const
{
	return m_DistanciaTotalRecorrido;
}

nat RecorridoMock::ObtenerTiempoTotalRecorrido() const
{
	return m_TiempoTotalRecorrido;
}

bool RecorridoMock::operator==(const IRecorrido& r) const
{
	return this == &r;
}
