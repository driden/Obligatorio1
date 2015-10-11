#pragma once

typedef unsigned int nat;

template <class T>
class ColaPrioridad abstract
{
	public:
	virtual ~ColaPrioridad() {}

	virtual void Insertar(const T &x, const nat p) abstract;

	virtual Puntero<T> BorrarMin() abstract;

	virtual nat Tamanio() abstract;

	virtual bool EstaVacia() abstract;

};