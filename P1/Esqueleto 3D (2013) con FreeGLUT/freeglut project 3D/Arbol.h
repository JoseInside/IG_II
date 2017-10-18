#pragma once
#include "ObjetoCompuesto.h"
class Arbol
{
public:
	Arbol();
	~Arbol();

	enum tipo { ABETO, ROBLE, PINO, ALAMO };
	void dibuja(enum tipo);
};

