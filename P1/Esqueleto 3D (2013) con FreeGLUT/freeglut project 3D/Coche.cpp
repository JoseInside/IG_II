#include "Coche.h"
#include "Rueda.h"
#include "Cubo.h"
#include "Cilindro.h"


Coche::Coche()
{

	creaCoche();
	
	//PV3D v(0, 5.5, 0, 0);
	//hijos[0]->matriz->traslada(&v);

	PV3D v1(0, 1.5, 0, 0);
	PV3D rot(0, 1, 0, 0);
	
	//CHASIS
	hijos[0]->matriz->traslada(&v1);

	//RUEDAS
	v1.setPoints(0.8, 0.5, 1.4);
	hijos[1]->matriz->traslada(&v1);
	hijos[1]->matriz->rota(&rot, 180);

	v1.setPoints(0.8, 0.5, -1.4);
	hijos[2]->matriz->traslada(&v1);

	v1.setPoints(-0.8, 0.5, 1.4);
	hijos[3]->matriz->traslada(&v1);
	hijos[3]->matriz->rota(&rot, 180);

	v1.setPoints(-0.8, 0.5, -1.4);
	hijos[4]->matriz->traslada(&v1);

	//FAROS
	v1.setPoints(1.0, 1.5, -0.6);
	hijos[5]->matriz->traslada(&v1);
	hijos[5]->matriz->rota(&rot, 90);
	
	v1.setPoints(1.0, 1.5, 0.6);
	hijos[6]->matriz->traslada(&v1);
	hijos[6]->matriz->rota(&rot, 90);
}



	/*
	//Eje de rotación
	PV3D *ejeRot = new PV3D(1.0, 1.0, 1.0, 0);
	//Se añaden 7 elementos al objeto compuesto Coche
	//(1 chasis, 4 ruedas y 2 faros)
	//Por ejemplo, se añaden 4 ruedas,
	//compuestas por un cilindro y un disco
	
	//Se sitúan los 7 elementos dentro del coche
	//Por ejemplo, las ruedas 1..4

	//hijos[1]->matriz->rota(ejeRot, 90.0f);
	creaCoche();
	*/



Coche::~Coche()
{
}

void Coche::creaCoche()
{
	//Primero creamos el chasis
	this->introduceObjeto(new Cubo(2));
	hijos[0]->setColor(1.000f, 0.000f, 1.000f);
	//Después añadimos las 4 ruedas
	for (int i = 0; i < 4; i++)
		this->introduceObjeto(new Rueda());

	//Ahora los 2 faros
	for (int j = 0; j < 2; j++)
	{
		//Valores random, hay que ajustar
		this->introduceObjeto(new Cilindro(0.25f, 0.25f, 0.4f, 30, 30));
	}
	hijos[5]->setColor(0.000f, 1.000f, 0.000f);
	hijos[6]->setColor(0.000f, 1.000f, 0.000f);
}