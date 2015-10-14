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
		~Cliente(){}
		Cliente(){}
		Cliente(nat ci, nat fechaRegistro, Cadena nombre, Cadena nombreBarrio, Cadena direccion)
		{
			_ci = ci;
			_fechaRegistro = fechaRegistro;
			_nombre = nombre;
			_nombreBarrio = nombreBarrio;
			_direccion = direccion;
		}
	nat ObtenerCiCliente() const override;
	Cadena ObtenerNombreCliente() const override;
	nat ObtenerFechaRegCliente() const override;
	Cadena ObtenerNombreBarrio() const override;
	Cadena ObtenerDireccion() const override;

	bool operator==(const ICliente& c) const override;
};