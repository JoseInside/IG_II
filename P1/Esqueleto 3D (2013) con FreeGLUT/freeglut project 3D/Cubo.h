#pragma once
#include "Objeto3D.h"
class Cubo: public Objeto3D
{

public:
	//Pasamos el tamaño del cubo como parámetro para construirlo
	Cubo(GLfloat tam);
	~Cubo();

	void dibuja();

private:
	GLfloat _tam;
};

