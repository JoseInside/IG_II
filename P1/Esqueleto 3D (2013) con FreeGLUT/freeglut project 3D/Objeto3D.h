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
	bool isActive() { return active; };
	void changeActive() { active = !active; };
protected:
	bool active;
	PV3D* color;
	
};

