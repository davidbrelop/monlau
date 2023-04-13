#include "Lancha.h"
#include <iostream>
#include <windows.h>

using namespace std;

//constructor
Lancha::Lancha(string pName, double pSpeed, int pDistancia, bool pNitro) {
	name = pName;
	speed = pSpeed;
	distancia = pDistancia;
	nitro = pNitro;
}

//getters
string Lancha::getName() {
	return name;
}
double Lancha::getSpeed() {
	return speed;
}
int Lancha::getDistancia() {
	return distancia;
}
bool Lancha::getNitro() {
	return nitro;
}

//setters
void Lancha::setName(string pName) {
	name = pName;
}
void Lancha::setSpeed(double pSpeed) {
	speed = pSpeed;
}
void Lancha::setDistancia(int pDistancia) {
	distancia = pDistancia;
}
void Lancha::setNitro(bool pNitro) {
	nitro = pNitro;
}

//Métodos propios
void Lancha::printLancha(int pColor) { //2 es verde y 4 es rojo
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), pColor);
	for (int i = 1; i <= getDistancia()/100; i++) {
		cout << " ";
	}
	cout << "   _   " << endl;
	for (int i = 1; i <= getDistancia()/100; i++) {
		cout << ".";
	}
	cout << "__/ \\__" << endl;
	for (int i = 1; i <= getDistancia()/100; i++) {
		cout << ".";
	}
	cout << "\\_____/" << "     " << getDistancia() << " metros" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}