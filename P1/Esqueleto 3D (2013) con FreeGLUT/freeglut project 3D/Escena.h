#pragma once
#include "ObjetoCompuesto.h"
#include "Objeto3D.h"

class Escena : public ObjetoCompuesto
{

public:
	enum movType {FOWARD, BACKWARDS, LEFT, RIGHT};
	
	Escena();
	~Escena();

	void movCoche(movType type);

protected:
	Objeto3D *coche, *bosque;
	const GLfloat angRot = 20.0f;
	void creaEscena();

};

