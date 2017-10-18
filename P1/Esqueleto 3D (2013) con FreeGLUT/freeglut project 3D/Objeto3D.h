#pragma once

#include "TAfin.h"
class Objeto3D
{
private:
	//color
protected:
	TAfin* matriz;
public:
	Objeto3D();
	~Objeto3D();

	virtual void dibuja() = 0;
};

