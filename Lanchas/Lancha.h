#pragma once
#include <iostream>

using namespace std;

class Lancha {

	private:

		string name;
		double speed;
		int distancia;
		bool nitro;

	public:

		//constructor
		Lancha(string pName, double pSpeed, int pDistancia, bool pNitro);

		//getters
		string getName();
		double getSpeed();
		int getDistancia();
		bool getNitro();

		//setters
		void setName(string pName);
		void setSpeed(double pSpeed);
		void setDistancia(int pDistancia);
		void setNitro(bool pNitro);

		//Métodos propios
		void printLancha(int pColor);

};