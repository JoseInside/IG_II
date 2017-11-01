#include "Escena.h"
#include "Coche.h"
#include "Bosque.h"


Escena::Escena() : ObjetoCompuesto()
{
	//bosque = new Bosque();
	coche = new Coche();

	creaEscena();
}


Escena::~Escena()
{
}

void Escena::creaEscena() {

	this->introduceObjeto(coche);
	//this->introduceObjeto(bosque);
}

void Escena::movCoche(movType type) {
	
	PV3D v(1, 0, 0, 0);

	switch (type) {
	case FOWARD:
		hijos[0]->matriz->traslada(&v);
		break;
	case BACKWARDS:
		v.setPoints(-1, 0, 0);
		hijos[0]->matriz->traslada(&v);
		break;
	case LEFT:
		v.setPoints(0, 1, 0);
		hijos[0]->matriz->rota(&v, angRot);
		break;
	case RIGHT:
		v.setPoints(0, 1, 0);
		hijos[0]->matriz->rota(&v, -angRot);
		
		break;
	}
}