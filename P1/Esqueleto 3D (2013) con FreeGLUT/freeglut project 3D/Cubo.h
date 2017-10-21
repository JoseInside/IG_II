#pragma once
#include "Malla.h"
#include "ObjetoCuadrico.h"
class Cubo: public Malla
{

public:
	//Pasamos el tamaño del cubo como parámetro para construirlo
	Cubo(GLfloat tam);
	~Cubo();

	void dibuja();

private:
	GLfloat _tam;
};

