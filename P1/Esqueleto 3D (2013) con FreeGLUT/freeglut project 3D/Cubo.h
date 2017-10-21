#pragma once
#include "Malla.h"
#include "ObjetoCuadrico.h"
class Cubo: public Malla
{

public:
	//Pasamos el tama�o del cubo como par�metro para construirlo
	Cubo(GLfloat tam);
	~Cubo();

	void dibuja();

private:
	GLfloat _tam;
};

