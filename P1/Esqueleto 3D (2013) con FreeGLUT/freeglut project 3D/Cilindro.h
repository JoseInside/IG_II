#pragma once
#include "ObjetoCuadrico.h"
class Cilindro: ObjetoCuadrico
{
private:
	GLfloat _rtop, _rbase, _h;
	GLUquadric* _c;
public:
	Cilindro(GLUquadric* c, GLfloat rtop, GLfloat rbase, GLfloat h);
	virtual~Cilindro();

	void dibuja();
};

