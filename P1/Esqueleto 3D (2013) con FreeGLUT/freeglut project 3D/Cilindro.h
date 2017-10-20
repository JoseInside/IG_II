#pragma once
#include "ObjetoCuadrico.h"
class Cilindro: public ObjetoCuadrico
{

public:
	Cilindro(GLfloat rtop, GLfloat rbase, GLfloat h, GLfloat sli, GLfloat sta);
	virtual~Cilindro();

	void dibuja();

protected:
	GLfloat _rtop, _rbase, _h, _sli, _sta;
};

