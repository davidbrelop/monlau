#pragma once
#include <iostream>

using namespace std;

class Personaje {

private:

	string name;
	int hp;
	int basicAttack;
	int posX;
	int posY;

public:

	// CONSTRUCTOR CON PARAMETROS
	Personaje(string pName, int pHP, int pBasicAttack, int pPosX, int pPosY);
	
	// CONSTRUCTOR SIN PARAMETROS
	Personaje();

	// GETTERS
	string getName();
	int getHP();
	int getBasicAttack();
	int getPosX();
	int getPosY();

	// SETTERS
	void setName(string pName);
	void setHP(int pHP);
	void setBasicAttack(int pAttack);
	void setPosX(int pPosX);
	void setPosY(int pPosY);

	// MÉTODOS PROPIOS
	void printLancha(int pColor);

};