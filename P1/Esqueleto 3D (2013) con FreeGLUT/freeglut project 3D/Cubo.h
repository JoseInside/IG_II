#pragma once
#include "Objeto3D.h"
class Cubo: public Objeto3D
{
private:
	GLfloat _a;
public:
	Cubo(GLfloat a);
	~Cubo();

	void dibuja();
};

