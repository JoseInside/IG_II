#pragma once
#include "Objeto3D.h"
class ObjetoCompuesto: public Objeto3D {

protected:
	Objeto3D** hijos;
	int numHijos;
public:
	ObjetoCompuesto();
	~ObjetoCompuesto();

	void dibuja();
	void introduceObjeto(Objeto3D* objeto);
};

