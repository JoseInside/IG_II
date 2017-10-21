#pragma once
#include "TAfin.h"

class Objeto3D
{
public:
	Objeto3D();
	~Objeto3D();

	virtual void dibuja() = 0;

	void setColor(GLfloat x, GLfloat y, GLfloat z);
	TAfin* matriz;

protected:
	
	PV3D* color;
	
};

