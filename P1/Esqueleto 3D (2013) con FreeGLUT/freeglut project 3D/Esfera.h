#pragma once
#include "ObjetoCuadrico.h"
class Esfera : public ObjetoCuadrico
{
private:
	GLUquadric* _e;
	GLfloat _r;
public:
	Esfera(GLUquadric* e, GLfloat r);
	~Esfera();

	void dibuja();
};

