#pragma once
#include "Objeto3D.h"
class Cubo: public Objeto3D
{

public:
	//Pasamos el tama�o del cubo como par�metro para construirlo
	Cubo(GLfloat tam);
	~Cubo();

	void dibuja();

private:
	GLfloat _tam;
};

