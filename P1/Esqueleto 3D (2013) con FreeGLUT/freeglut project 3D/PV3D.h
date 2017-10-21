#pragma once
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <math.h>

class PV3D
{
public:
	PV3D(GLfloat x, GLfloat y, GLfloat z, int pv);
	~PV3D();

	PV3D* normaliza(GLfloat x, GLfloat y, GLfloat z);
	PV3D* clona();
	GLfloat productoEscalar(PV3D* v);
	PV3D* productoVectorial(PV3D* v);

	GLfloat getX(){ return x; }
	GLfloat getY(){ return y; }
	GLfloat getZ(){ return z; }
	
	void setPoints(GLfloat new_x, GLfloat new_y, GLfloat new_z);
	//bool esPunto() { return pv == 1; }
	//bool esVector() { return pv == 0; }

protected:

	GLfloat x, y, z;
	int pv;

};