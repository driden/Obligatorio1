#pragma once

#include "Barrio.h"
#include "AVLIteracion.h"

Cadena Barrio::ObtenerNombreBarrio() const
{
	return _nombre;
}
nat Barrio::ObtenercantidadCamaras() const
{
	return _cantidadCamaras;
}
nat Barrio::ObtenerpromedioHurtos() const
{
	return _promedioHurtos;
}
Iterador<pCliente> Barrio::ObtenerClientesPorDireccion() const
{
	return _iterClientesDireccion;
}
bool Barrio::operator==(const IBarrio& b) const
{
	return this->_nombre == b.ObtenerNombreBarrio();
}

Iterador<Cliente> Barrio::IteradorClientesCI() const
{
	return new AVLIteracion<Cliente>(_avlClientes);
}