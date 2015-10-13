#pragma once

template<class T>
class Cola abstract
{
	virtual ~Cola() {}
	virtual void Encolar(const T& elemento) abstract;
	virtual T DesEncolar() abstract;
	virtual bool EstaVacia() abstract;
};