#include "PV3D.h"


PV3D::PV3D(GLfloat x, GLdouble y, GLfloat z, int pv)
{
	this->pv = pv;
	this->x = x;
	this->y = y;
	this->z = z;
}


PV3D::~PV3D()
{
}

PV3D* PV3D::clona(){

	return new PV3D(x, y, z, pv);
}


PV3D* PV3D::normaliza(GLfloat x, GLfloat y, GLfloat z){

	GLfloat modulo2 = productoEscalar(this);
	PV3D* p = new PV3D(x, y, z, 0);
	if (modulo2>0) {
		p->x = x / sqrt(modulo2);
		p->y = y / sqrt(modulo2);
		p->z = z / sqrt(modulo2);
	}
	return p;
}


GLfloat PV3D::productoEscalar(PV3D* v){
	
	return x*v->getX() + y*v->getY() + z*v->getZ();
}
PV3D* PV3D::productoVectorial(PV3D* v){

	PV3D * pVectorial = new PV3D(0, 0, 0, 0);
	pVectorial->x = y*v->getZ() - z*v->getY();
	pVectorial->y = z*v->getX() - x*v->getZ();
	pVectorial->z = x*v->getY() - y*v->getX();

	return pVectorial;
}
