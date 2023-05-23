#pragma once
#include "Personaje.h"
#include <iostream>

using namespace std;

class EnemigoFinal : public Personaje {

private:

	int fireAttack;
	int frozenAttack;

public:

	// CONSTRUCTOR
	EnemigoFinal(string pName, int pHP, int pBasicAttack, int pPosX, int pPosY, int pFireAttack, int pFrozenAttack);

	// GETTERS
	int getFireAttack();
	int getFrozenAttack();

	// SETTERS
	void setFireAttack(int pFireAttack);
	void setFrozenAttack(int pFrozenAttack);

};