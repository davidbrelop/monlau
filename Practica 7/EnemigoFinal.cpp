#include "EnemigoFinal.h"
#include <iostream>

using namespace std;

// CONSTRUCTOR
EnemigoFinal::EnemigoFinal(string pName, int pHP, int pBasicAttack, int pPosX, int pPosY, int pFireAttack, int pFrozenAttack)
	: Personaje(pName, pHP, pBasicAttack, pPosX, pPosY) {
		fireAttack = pFireAttack;
		frozenAttack = pFrozenAttack;
}

// GETTERS
int EnemigoFinal::getFireAttack() {
	return fireAttack;
}
int EnemigoFinal::getFrozenAttack() {
	return frozenAttack;
}

// SETTERS
void EnemigoFinal::setFireAttack(int pFireAttack) {
	fireAttack = pFireAttack;
}
void EnemigoFinal::setFrozenAttack(int pFrozenAttack) {
	frozenAttack = pFrozenAttack;
}

//MÉTODOS PROPIOS