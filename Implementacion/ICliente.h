#pragma once

#include "Puntero.h"
#include "Cadena.h"

class ICliente abstract
{
public:
	virtual ~ICliente(){}

	virtual nat ObtenerCiCliente() const abstract;
	virtual Cadena ObtenerNombreCliente() const abstract;
	virtual nat ObtenerFechaRegCliente() const abstract;
	virtual Cadena ObtenerNombreBarrio() const abstract;
	virtual Cadena ObtenerDireccion() const abstract;

	virtual bool operator==(const ICliente& c) const abstract;
};
typedef Puntero<ICliente> pCliente;