#include "Bosque.h"


Bosque::Bosque() : ObjetoCompuesto()
{
	creaBosque();
	
}


Bosque::~Bosque()
{
}


void Bosque::creaBosque() {

	for (int i = 0; i < 4; ++i) {
		int randX = rand() % 21 - 10;	// rango -10, 10
		int randZ = rand() % 21 - 10;	// rango -10, 10
		PV3D* newPos = new PV3D(randX, 0, randZ, 0);

		//bool encontrado = false;
		int cont = 0;

		/*while (cont < numHijos) {
			if (hijos[cont]->matriz->getM() == newPos->matriz->getM()) { //FALTA ESTO
				//buscar rango de nuevo
				randX = rand() % 21 - 10;	// rango -10, 10
				randZ = rand() % 21 - 10;	// rango -10, 10
				newPos->setPoints(randX, 0, randZ);
				cont = 0;
			}
			else {
				cont++;
			}
		}*/

		int prob = rand() % 4;
		Arbol::tipo tipo;
		GLfloat _h, _tam;
		_h = rand() % 5 + 2;	//ALTURA DEL TRONCO 
		_tam = rand() % 5 + 1;	//TAMAÑO DE LA COPA 
		switch (prob) {
		case 1:
			tipo = Arbol::ABETO;
			break;
		case 2:
			tipo = Arbol::ROBLE;
			break;
		case 3:
			tipo = Arbol::PINO;
			break;
		case 4:
			tipo = Arbol::ALAMO;
			break;
		}
		//probabilidad 0.25 type arbol
		arbolGenerico = new Arbol(tipo, newPos, _h, _tam);
		this->introduceObjeto(arbolGenerico);
	}
}