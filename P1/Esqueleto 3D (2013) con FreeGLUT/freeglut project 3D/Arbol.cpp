#include "Arbol.h"


Arbol::Arbol(tipo t) : ObjetoCompuesto()
{
	_t = t;
	
	creaArbol();
}


Arbol::~Arbol()
{
}


void Arbol::creaArbol() {

	PV3D v(0, 0, 0, 0);
	PV3D rot(1, 0, 0, 0);
	//color = new PV3D(1.0f, 0.0f, 1.0f, 0);									
	
	this->introduceObjeto(new Cilindro(0.45f, 0.35f, 4.0f, 30, 30));	//TRONCO	
	hijos[0]->setColor(0.545f, 0.271f, 0.075f);							//COLOR: MARR�N
	hijos[0]->matriz->rota(&rot, -90);

	switch (_t) {
	case ABETO:
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, 3.8f, 30, 30));	//UN CONO
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(0, 7, 0);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		break;
	case ROBLE:
		this->introduceObjeto(new Esfera(1.5f, 30, 30));				//UNA ESFERA
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(0, 5, 0);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		break;
	case PINO:
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, 3.8f, 30, 30));	//DOS CONOS
		this->introduceObjeto(new Cilindro(0.0f, 1.2f, 3.8f, 30, 30));
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		hijos[2]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(0, 7, 0);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		v.setPoints(0, 8, 0);
		hijos[2]->matriz->traslada(&v);
		hijos[2]->matriz->rota(&rot, 90);
		break;
	case ALAMO:
		this->introduceObjeto(new Esfera(1.5f, 30, 30));				//DOS ESFERAS
		this->introduceObjeto(new Esfera(1.2f, 30, 30));
		hijos[1]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		hijos[2]->setColor(0.000f, 0.392f, 0.000f);						//COLOR: VERDE OSCURO
		v.setPoints(-0.5, 5, 0.5);
		hijos[1]->matriz->traslada(&v);
		hijos[1]->matriz->rota(&rot, 90);
		v.setPoints(0.5, 5, -0.5);
		hijos[2]->matriz->traslada(&v);
		hijos[2]->matriz->rota(&rot, 90);
		break;

	}

	
}