#include "Cubo.h"


Cubo::Cubo(GLfloat tam) : Malla()
{
	_tam = tam;
}


Cubo::~Cubo()
{
}
void Cubo::dibuja(){
	
	glPushMatrix();
	glMultMatrixf(this->matriz->getM());
	glColor3f(this->color->getX(), this->color->getY(), this->color->getZ());
	glutSolidCube(_tam);
	glPopMatrix();
}