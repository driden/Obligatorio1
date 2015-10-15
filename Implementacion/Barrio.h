#pragma once
#include "IBarrio.h"
#include "AVL.h"
#include "Cliente.h"
#include "AVLImp.h"

class Barrio : public IBarrio
{
	private:
	Cadena _nombre;
	nat _cantidadCamaras;
	nat _promedioHurtos;
	Iterador<pCliente> _iterClientesDireccion;
	Puntero<AVLImp<Cliente>> _avlClientes;
	public:
		Barrio(){}
	Barrio(Cadena nombre, nat cantidadCamaras, nat promedioHurtos)
	{
		_nombre = nombre;
		_cantidadCamaras = cantidadCamaras;
		_promedioHurtos = promedioHurtos;		
	}
	
	Cadena ObtenerNombreBarrio() const override;
	nat ObtenercantidadCamaras() const override;
	nat ObtenerpromedioHurtos() const override;
	Iterador<pCliente> ObtenerClientesPorDireccion() const override;
	bool operator==(const IBarrio& b) const override;
	Iterador<Cliente> IteradorClientesCI() const;
};
