#pragma once
#include "Objeto3D.h"
class ObjetoCompuesto: public Objeto3D {

protected:
	int numHijos;
public:
	ObjetoCompuesto();
	~ObjetoCompuesto();

	Objeto3D** hijos;
	void dibuja();
	void introduceObjeto(Objeto3D* objeto);
};

