#pragma once
#include <cmath>

typedef unsigned int nat;

class Utilidades
{
	public:
	static nat ProximoPrimo(const nat desde)
	{
		nat primo = 0;
		if (desde > 2)
		{
			bool encontre = false;
			//primer candidato a primo
			int candidato = desde + 1;

			while (!encontre)
			{
				//divido de 3 en adelante hasta raiz cuadrada del candidato.
				//si no le encuentro divisores es primo
				if (candidato % 2 == 0)
					candidato++;
				bool esPrimo = true;
				int hasta = ceil(sqrt(candidato));
				int i;
				for (i = 3; i <= hasta; i += 2)
				{
					if (candidato % i == 0)
					{
						esPrimo = false;
						break;
					}

				}
				if (esPrimo && i != 3)
				{
					primo = candidato;
					encontre = true;
				}
				else
				{
					candidato++;
				}
			}
		}
		else
		{
			primo = desde + 1;
		}
		return primo;
	}
};