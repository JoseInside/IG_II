#include "Coche.h"
#include "Rueda.h"
#include "Cubo.h"
#include "Cilindro.h"
Coche::Coche()
{	
	//Eje de rotación
	PV3D *ejeRot = new PV3D(1.0, 1.0, 1.0, 0);
	//Se añaden 7 elementos al objeto compuesto Coche
	//(1 chasis, 4 ruedas y 2 faros)
	//Por ejemplo, se añaden 4 ruedas,
	//compuestas por un cilindro y un disco
	
	//Se sitúan los 7 elementos dentro del coche
	//Por ejemplo, las ruedas 1..4



	hijos[1]->matriz->rota(ejeRot, 90.0f);
}


Coche::~Coche()
{
}

void Coche::creaCoche()
{
	//Primero creamos el chasis
	this->introduceObjeto(new Cubo(1));

	//Después añadimos las 4 ruedas
	for (int i = 0; i<4; i++)
		this->introduceObjeto(new Rueda());

	//Ahora los 2 faros
	for (int j = 0; j < 2; j++)
	{
		//Valores random, hay que ajustar
		this->introduceObjeto(new Cilindro(1, 1, 3, 30, 30)); 
	}
}