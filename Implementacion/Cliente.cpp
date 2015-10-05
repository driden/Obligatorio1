#pragma once
#include "Cliente.h"

nat Cliente::ObtenerCiCliente() const
{
	return _ci;
}
Cadena Cliente::ObtenerNombreCliente() const
{
	return _nombre;
}
nat Cliente::ObtenerFechaRegCliente() const
{
	return _fechaRegistro;
}
Cadena Cliente::ObtenerNombreBarrio() const
{
	return _nombreBarrio;
}
Cadena Cliente::ObtenerDireccion() const
{
	return _direccion;
}
bool Cliente::operator==(const ICliente& c) const 
{
	return this->_ci == c.ObtenerCiCliente();
}