#pragma once
#include "Arbol.h"

class Bosque : public ObjetoCompuesto
{
public:
	Bosque();
	~Bosque();

protected:

	int randX, randZ;
	void creaBosque();
	Arbol* arbolGenerico;
};

