#include "TAfin.h"


TAfin::TAfin()
{
	m = new GLfloat[16];
	for (int i = 0; i < 16; i++){
		m[i] = 0;
		m[0] = m[5] = m[10] = m[15] = 1;
	}
}


TAfin::~TAfin()
{
}
void TAfin::postmultiplica(GLfloat* m1){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	//Cargar m como matriz actual de modelado-vista
	glLoadMatrixf(m);
	//Post-multiplicar por m1
	glMultMatrixf(m1);
	//Dejar el resultado en m
	glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}
void TAfin::traslada(PV3D* v) {

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(v->getX(),v->getY(), v->getZ());
	GLfloat* m1 = new GLfloat[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	TAfin::postmultiplica(m1);
}
