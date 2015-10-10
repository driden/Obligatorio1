#ifndef HASHIMP_CPP
#define HASHIMP_CPP
#include "HashImp.h"
#include "ListaEnlazada.h"

template <class Clave, class Valor>
HashImp<Clave, Valor>::HashImp(int const MAX_NUMBER, Puntero<FuncionHash<Clave>> funcion, Comparador<Valor> comp)
{
	_largo = Utilidades::ProximoPrimo(MAX_NUMBER);
	_funcionHash = funcion;
	_hash = Array<Puntero<Lista<Valor>>>(_largo,new ListaEnlazada<Valor>(comp));
}

template <class Clave, class Valor>
void HashImp<Clave, Valor>::Agregar(const Clave& c, const Valor& v)
{
	nat bucket = _funcionHash->CodigoDeHash(c) % _largo;
	//insertar en la lista (con repeticiones)
	Puntero<Lista<Valor>> lista = _hash[bucket];
	lista->Insertar(v);
}

template <class Clave, class Valor>
void HashImp<Clave, Valor>::Borrar(const Clave& c)
{
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::EstaVacia() const
{
	return true;
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::EstaLlena() const
{
	return true;
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::Pertenece(const Clave& c) const
{
	return true;
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::Obtener(const Clave& c, Valor& v) const
{
	return true;
}

template <class Clave, class Valor>
nat HashImp<Clave, Valor>::Largo() const
{
	return _largo;
}
#endif

