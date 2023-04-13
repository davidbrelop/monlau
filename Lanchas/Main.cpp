#include "Lancha.h"
#include <iostream>
#include <Windows.h>

using namespace std;

void presentacion(string& firstPlayerName) {
    cout << "BIENVENIDO A TODO GAS, LA MEJOR CARRERA DE LANCHAS ACUATICAS DE LA HISTORIA" << endl;
    cout << endl;
    cout << "Introduce el nombre del jugador: ";
    cin >> firstPlayerName;
    cout << endl;
    
}

void elegirDificultad(string& modo) {
    while (modo != "1" && modo != "2" && modo != "3") {
        cout << "Elige el modo de juego:" << endl;
        cout << "[1] Facil" << endl;
        cout << "[2] Normal" << endl;
        cout << "[3] Dificil" << endl;
        cin >> modo;
        if (modo != "1" && modo != "2" && modo != "3") {
            cout << "Por favor, vuelve a elegir una opcion disponible." << endl;
            cout << endl;
        }
    }
    cout << endl;
}

void cuentaAtras() {
    cout << "LA CARRERA COMIENZA EN..." << endl;
    Sleep(1000);
    cout << "3" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << endl;
}

void printarTurno(int turno, Lancha lancha) {
    if (lancha.getName() == "CPU") {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    }
    cout << "TURNO " << turno << " DE: " << lancha.getName() << endl;
    cout << "------------";
    for (int i = 0; i < lancha.getName().length(); i++) {
        cout << "-";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << endl;
    cout << endl;
}

void tirarDado(int& numDado, string modo, Lancha lancha) {
    if (lancha.getName() == "CPU") {    // Solo entra en el caso de que sea la CPU quien tira el dado
        if(modo == "1") {
            numDado = 1 + rand() % 3;   // Modo facil: en el dado va a salir un numero del 1 al 3
        }
        else if (modo == "2") {
            numDado = 1 + rand() % 6;   // Modo normal: en el dado va a salir un numero del 1 al 6
        }
        else {
            numDado = 4 + rand() % 3;   // Modo dificil: en el dado va a salir un numero del 4 al 6
        }
    }
    else {    // Solo entra en el caso de que sea el jugador quien tira el dado
        numDado = 1 + rand() % 6;
    }
}

bool quieresNitro() {
    string eleccion = "0";
    while (eleccion != "1" && eleccion != "2") {
        cout << "Quieres utilizar el nitro en este turno?" << endl;
        cout << "[1] Si" << endl;
        cout << "[2] No" << endl;
        cin >> eleccion;
        if (eleccion != "1" && eleccion != "2") {
            cout << "Por favor, vuelve a elegir una opcion disponible." << endl;
        }
        cout << endl;
    }
    if (eleccion == "1") {
        return true;
    }
    else {
        return false;
    }
}

void intentarNitro(int& numDado, Lancha& lancha) {
    numDado = rand() % 2;
    switch (numDado) {
    case 0:
        cout << "El nitro no ha funcionado correctamente." << endl;
        cout << "La velocidad TOTAL se va a reducir a la mitad." << endl;
        lancha.setSpeed(lancha.getSpeed() / 2);
        break;
    case 1:
        cout << "La velocidad TOTAL se va a multiplicar por dos." << endl;
        lancha.setSpeed(lancha.getSpeed() * 2);
        break;
    }
    lancha.setNitro(false);
}

void resumenTurno(int turno, Lancha playerLancha, Lancha computerLancha, int colorJugador, int colorComputer) {
    cout << "RESUMEN DEL TURNO " << turno << "" << endl;
    cout << "-------------------" << endl;
    cout << endl;
    playerLancha.printLancha(colorJugador);
    cout << endl;
    computerLancha.printLancha(colorComputer);
    cout << endl;
}

void determinarGanador(Lancha playerLancha, Lancha computerLancha) {
    if (playerLancha.getDistancia() > computerLancha.getDistancia()) {
        cout << "FELICIDADES, HAS GANADO! " << endl;
    }
    else if (playerLancha.getDistancia() < computerLancha.getDistancia()) {
        cout << "HAS PERDIDO..." << endl;
    }
    else {
        cout << "LA PARTIDA HA TERMINADO EN EMPATE." << endl;
    }
}

int main() {

    //Variables del programa
    const int MAX_TURNOS = 5;
    const int GREEN = 2;
    const int RED = 4;
    string playerName;
    string computerName = "CPU";
    string dificultad;
    int numDado;

    //Inicio del juego
    srand(time(NULL));
    presentacion(playerName);
    elegirDificultad(dificultad);
    cuentaAtras();

    //Creacion de lanchas
    Lancha playerLancha(playerName, 0, 0, true);
    Lancha computerLancha(computerName, 0, 0, true);

    for (int turno = 1; turno <= MAX_TURNOS; turno++) {
        
        //Turno del primer jugador
        printarTurno(turno, playerLancha);
        tirarDado(numDado, dificultad, playerLancha);
        cout << "Has sacado un " << numDado << "." << endl;
        cout << endl;
        playerLancha.setSpeed(playerLancha.getSpeed() + numDado);
        if (playerLancha.getNitro()) {
            Sleep(3000);
            if (quieresNitro()) {
                intentarNitro(numDado, playerLancha);
                cout << endl;
            }
        }
        playerLancha.setDistancia(playerLancha.getDistancia() + playerLancha.getSpeed() * 100);
        Sleep(3000);

        //Turno de la CPU
        printarTurno(turno, computerLancha);
        tirarDado(numDado, dificultad, computerLancha);
        cout << "La " << computerLancha.getName() << " ha sacado un " << numDado << "." << endl;
        cout << endl;
        computerLancha.setSpeed(computerLancha.getSpeed() + numDado);
        if (computerLancha.getNitro()) {
            if ((turno < MAX_TURNOS && (playerLancha.getDistancia() - (computerLancha.getDistancia() + computerLancha.getSpeed() * 100) >= 500)) || (turno == MAX_TURNOS && (playerLancha.getDistancia() - (computerLancha.getDistancia() + computerLancha.getSpeed() * 100) >= 0))) {
                Sleep(3000);
                cout << "La " << computerLancha.getName() << " ha decidido utilizar el nitro en este turno." << endl;
                cout << endl;
                Sleep(3000);
                intentarNitro(numDado, computerLancha);
                cout << endl;
            }
        }
        computerLancha.setDistancia(computerLancha.getDistancia() + computerLancha.getSpeed() * 100);
        Sleep(3000);

        //Mostrar por pantalla la distancia de cada lancha
        resumenTurno(turno, playerLancha, computerLancha, GREEN, RED);
        cout << endl;
        Sleep(7000);
    }

    //Mostrar por pantalla el ganador de la partida
    determinarGanador(playerLancha, computerLancha);
}