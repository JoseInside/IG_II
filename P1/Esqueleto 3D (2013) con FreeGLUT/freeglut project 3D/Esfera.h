#pragma once
#include "ObjetoCuadrico.h"
class Esfera : public ObjetoCuadrico
{

public:
	Esfera(GLfloat r, GLfloat sli, GLfloat sta);
	~Esfera();

	void dibuja();

protected:

	GLfloat _r, _sli, _sta;
};

