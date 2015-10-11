#ifndef HASHIMP_CPP
#define HASHIMP_CPP
#include "HashImp.h"
#include "ListaEnlazada.h"

template <class Clave, class Valor>
HashImp<Clave, Valor>::HashImp(int const MAX_NUMBER, Puntero<FuncionHash<Clave>> funcion, Comparador<Valor> comp)
{
	_largo = Utilidades::ProximoPrimo(MAX_NUMBER);
	_funcionHash = funcion;
	_hash = Array<Puntero<Lista<Valor>>>(_largo,NULL);

	for (nat i = 0; i < _largo; i++)
		_hash[i] = new ListaEnlazada<Valor>(comp);
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
	nat bucket = _funcionHash->CodigoDeHash(c) % _largo;
	_hash[bucket] = nullptr;
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::EstaVacia() const
{
	bool vacia = true;
	for (nat i = 0; i < _largo; i++)
	{
		Puntero<Lista<Valor>> lista = _hash[i];
		if (lista != nullptr){
			vacia = (lista->Largo() == 0) && vacia;
		}
		else
		{
			vacia = true;
		}

			}
		
	return vacia;
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::EstaLlena() const
{
	bool llena = true;
	for (nat i = 0; i < _largo; i++)
	{
		Puntero<Lista<Valor>> lista = _hash[i];
		if (lista != nullptr){
		llena = (lista->Largo() != 0) && llena;
		}
		else
		{
			llena = false;
		}

	}
	return llena;
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::Pertenece(const Clave& c) const
{
	nat bucket = _funcionHash->CodigoDeHash(c) % _largo;
	Puntero<Lista<Valor>> lista = _hash[bucket];
	return lista !=nullptr && lista->Largo() != 0;
	
}

template <class Clave, class Valor>
bool HashImp<Clave, Valor>::Obtener(const Clave& c, Valor& v) const
{
	nat bucket = _funcionHash->CodigoDeHash(c) % _largo;
	Puntero<Lista<Valor>> lista = _hash[bucket];
	return lista->Existe(v);
}

template <class Clave, class Valor>
nat HashImp<Clave, Valor>::Largo() const
{
	return _largo;
}
#endif

