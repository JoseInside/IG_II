#include "Coche.h"


Coche::Coche()
{
	//Se añaden 7 elementos al objeto compuesto Coche
	//(1 chasis, 4 ruedas y 2 faros)
	//Por ejemplo, se añaden 4 ruedas,
	//compuestas por un cilindro y un disco
	for (int i = 0; i<4; i++)
		this->introduceObjeto(new Rueda());
	//Se sitúan los 7 elementos dentro del coche
	//Por ejemplo, las ruedas 1..4
	
	hijos[1]->rota(90, 1, 0, 0);
	
}


Coche::~Coche()
{
}
