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
	glutSolidCube(_tam);
	glPopMatrix();
}