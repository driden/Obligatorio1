#pragma once

#include "Puntero.h"
#include "Cadena.h"
#include "Iterador.h"
#include "Tupla.h"

class IRecorrido abstract
{
public:
	virtual ~IRecorrido(){}

	virtual Cadena ObtenerNombreBarrioOrigen() const abstract;
	virtual Iterador<Tupla<Cadena, nat, nat>> ObtenerTraslados() const abstract;
	virtual nat ObtenerDistanciaTotalRecorrido() const abstract;
	virtual nat ObtenerTiempoTotalRecorrido() const abstract;

	virtual bool operator==(const IRecorrido& r) const abstract;
};
typedef Puntero<IRecorrido> pRecorrido;