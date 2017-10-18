#pragma once
#include "ObjetoCompuesto.h"
#include "ObjetoCuadrico.h"
#include "Esfera.h"
#include "Cilindro.h"

class Arbol: public ObjetoCompuesto
{
public:
	enum tipo { ABETO, ROBLE, PINO, ALAMO };

	Arbol(tipo t);
	~Arbol();

	void dibuja();

private:
	tipo _t;
};

