#include "Personaje.h"
#include <iostream>
#include <windows.h>

using namespace std;

// CONSTRUCTOR CON PARAMETROS
Personaje::Personaje(string pName, int pHP, int pBasicAttack, int pPosX, int pPosY) {
	name = pName;
	hp = pHP;
	basicAttack = pBasicAttack;
	posX = pPosX;
	posY = pPosY;
}

// CONSTRUCTOR SIN PARAMETROS
Personaje::Personaje() {

}

// GETTERS
string Personaje::getName() {
	return name;
}
int Personaje::getHP() {
	return hp;
}
int Personaje::getBasicAttack() {
	return basicAttack;
}
int Personaje::getPosX() {
	return posX;
}
int Personaje::getPosY() {
	return posY;
}

// SETTERS
void Personaje::setName(string pName) {
	name = pName;
}
void Personaje::setHP(int pHP) {
	hp = pHP;
}
void Personaje::setBasicAttack(int pBasicAttack) {
	basicAttack = pBasicAttack;
}
void Personaje::setPosX(int pPosX) {
	posX = pPosX;
}
void Personaje::setPosY(int pPosY) {
	posY = pPosY;
}