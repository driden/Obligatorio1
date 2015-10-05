#pragma once
#include  "ICliente.h"

class Cliente : public ICliente
{
	private:
	nat _ci;
	Cadena _nombre;
	nat _fechaRegistro;
	Cadena _nombreBarrio;
	Cadena _direccion;

	public:
	nat ObtenerCiCliente() const override;
	Cadena ObtenerNombreCliente() const override;
	nat ObtenerFechaRegCliente() const override;
	Cadena ObtenerNombreBarrio() const override;
	Cadena ObtenerDireccion() const override;

	bool operator==(const ICliente& c) const override;
};