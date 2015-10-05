#pragma once
#include "IBarrio.h"

class Barrio : public IBarrio
{
	private:
	Cadena _nombre;
	nat _cantidadCamaras;
	nat _promedioHurtos;
	Iterador<pCliente> _iterClientesDireccion;

	public:
	Barrio(Cadena nombre, nat cantidadCamaras, nat promedioHurtos, Iterador<pCliente> iterClientesDireccion)
	{
		_nombre = nombre;
		_cantidadCamaras = cantidadCamaras;
		_promedioHurtos = promedioHurtos;
		_iterClientesDireccion = iterClientesDireccion;
	}
	
	Cadena ObtenerNombreBarrio() const override;
	nat ObtenercantidadCamaras() const override;
	nat ObtenerpromedioHurtos() const override;
	Iterador<pCliente> ObtenerClientesPorDireccion() const override;
	bool operator==(const IBarrio& b) const override;
};
