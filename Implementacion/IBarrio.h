#pragma once

#include "Puntero.h"
#include "Cadena.h"
#include "Iterador.h"
#include "ICliente.h"

class ICliente;
typedef Puntero<ICliente> pCliente;

class IBarrio abstract
{
public:
	virtual ~IBarrio(){}

	virtual Cadena ObtenerNombreBarrio() const abstract;
	virtual nat ObtenercantidadCamaras() const abstract;
	virtual nat ObtenerpromedioHurtos() const abstract;
	virtual Iterador<pCliente> ObtenerClientesPorDireccion() const abstract;

	virtual bool operator==(const IBarrio& b) const abstract;
};
typedef Puntero<IBarrio> pBarrio;