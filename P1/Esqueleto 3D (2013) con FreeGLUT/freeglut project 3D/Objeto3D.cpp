#include "Objeto3D.h"


Objeto3D::Objeto3D()
{
	matriz = new TAfin();
}


Objeto3D::~Objeto3D()
{
}

void Objeto3D::setColor(GLfloat x, GLfloat y, GLfloat z) {
	
	color = new PV3D(x, y, z, 0);
}