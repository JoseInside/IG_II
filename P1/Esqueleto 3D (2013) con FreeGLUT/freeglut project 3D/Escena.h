#pragma once
#include "ObjetoCompuesto.h"
#include "Objeto3D.h"

class Escena : public ObjetoCompuesto
{

public:
	enum movType {FOWARD, BACKWARDS, LEFT, RIGHT};
	Objeto3D* getCoche();

	Escena();
	~Escena();

	void movCoche(movType type);
	void controlJuego();
	//bool getCollision() { return collision; };
	//bool isEndGame() { return gameOver; };
protected:
	//Bosque *bosque;
	Objeto3D *coche;
	int numArboles;
	const GLfloat angRot = 20.0f;
	bool collision, gameOver;

	void creaEscena();
	void creaBosque();

};

