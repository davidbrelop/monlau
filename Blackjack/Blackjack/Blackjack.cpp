// Blackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
#include <windows.h>

using namespace std;

//Variable global
bool baraja[4][13];

void presentacion(string& name){
    cout << "===========================================================================" << endl;
    cout << "=                       Bienvenido a BLACK JACK MONLAU                    =" << endl;
    cout << "===========================================================================" << endl;
    cout << endl;
    cout << "Por favor, introduce tu nombre: ";
    cin >> name;
    cout << endl;
}

void inicializarArray(){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            baraja[i][j] = true;
        }
    }
}

void sacarCarta(int& points, string name){
    bool cartaSeleccionada = false;
    int valor, palo, carta;
    string tipoCarta, tipoPalo;
    while (!cartaSeleccionada) {
        palo = rand() % 4;
        carta = rand() % 13;
        if (baraja[palo][carta]) {
            cartaSeleccionada = true;
            baraja[palo][carta] = false;
            if (carta == 0) {
                if (name == "Croupier") {   //Se ejecuta si el Croupier saca un AS
                    if (points+11 <= 21) {
                        valor = 11;
                    }
                    else {
                        valor = 1;
                    }
                }
                else {  //Se ejecuta si el Jugador saca un AS
                    cout << "La proxima carta es un AS. Quieres darle un valor de 1 o de 11? ";
                    cin >> valor;
                    while (valor != 1 && valor != 11) {
                        cout << "El valor debe ser 1 o 11. Por favor, introduce un valor correcto: ";
                        cin >> valor;
                    }
                }
            }
            else if(carta >= 10) {
                valor = 10;
            }
            else {
                valor = carta + 1;
            }
        }
    }
    points = points + valor;
    switch (carta) {
    case 0:
        tipoCarta = "un 1";
        break;
    case 1:
        tipoCarta = "un 2";
        break;
    case 2:
        tipoCarta = "un 3";
        break;
    case 3:
        tipoCarta = "un 4";
        break;
    case 4:
        tipoCarta = "un 5";
        break;
    case 5:
        tipoCarta = "un 6";
        break;
    case 6:
        tipoCarta = "un 7";
        break;
    case 7:
        tipoCarta = "un 8";
        break;
    case 8:
        tipoCarta = "un 9";
        break;
    case 9:
        tipoCarta = "un 10";
        break;
    case 10:
        tipoCarta = "una J";
        break;
    case 11:
        tipoCarta = "una Q";
        break;
    case 12:
        tipoCarta = "una K";
        break;
    }
    switch(palo) {
        case 0:
            tipoPalo = "picas";
            break;
        case 1:
            tipoPalo = "diamantes";
            break;
        case 2:
            tipoPalo = "treboles";
            break;
        case 3:
            tipoPalo = "corazones";
            break;
    }
    if (name == "Croupier") {
        cout << "El " << name;
    }
    else {
        cout << name;
    }
    cout << " ha sacado " << tipoCarta << " de " << tipoPalo << " y tiene un total de " << points << " PUNTOS." << endl;
}

bool quieresCarta() {
    int eleccion = 0;
    while (eleccion != 1 && eleccion != 2) {
        cout << endl;
        cout << "Quieres pedir otra carta?" << endl;
        cout << "1.- Si" << endl;
        cout << "2.- No" << endl;
        cin >> eleccion;
        if (eleccion != 1 && eleccion != 2) {
            cout << "Por favor, elije una opcion valida." << endl;
        }
    }
    cout << endl;
    switch (eleccion) {
        case 1:
            return true;
            break;
        case 2:
            return false;
            break;
    }
}

bool comprobarPuntuacion(int points) {
    if (points >= 21) {
        return true;
    }
    else {
        return false;
    }
}

void determinarGanador(int pointsPlayer, int pointsCroupier) {
    if (pointsPlayer == pointsCroupier) {
        cout << "EMPATE!";
    }
    else if ((pointsPlayer > pointsCroupier || pointsCroupier > 21) && pointsPlayer <= 21) {
        cout << "HAS GANADO!";
    }
    else {
        cout << "HAS PERDIDO!";
    }
}

int main() {
    //Variable general
    bool gameOver = false;

    //Variables del jugador
    string namePlayer;
    int pointsPlayer = 0;
    bool rendicionPlayer = false;

    //Variables del croupier
    string nameCroupier = "Croupier";
    int pointsCroupier = 0;
    bool rendicionCroupier = false;
    
    srand(time(NULL));
    presentacion(namePlayer);
    inicializarArray();
    //Sacamos dos cartas para el jugador
    Sleep(1000);
    sacarCarta(pointsPlayer, namePlayer);
    Sleep(2500);
    sacarCarta(pointsPlayer, namePlayer);
    cout << endl;
    Sleep(2500);
    //Comprobamos si el jugador ya ha alcanzado 21 puntos
    rendicionPlayer = comprobarPuntuacion(pointsPlayer);
    //Sacamos una carta para el Croupier
    sacarCarta(pointsCroupier, nameCroupier);
    Sleep(2500);
    //Turno del jugador
    cout << endl;
    if (!rendicionPlayer) {
        cout << "TURNO DEL JUGADOR" << endl;
        cout << "-----------------" << endl;
    }
    while(!rendicionPlayer) {
        if (quieresCarta()) {
            Sleep(1000);
            sacarCarta(pointsPlayer, namePlayer);
            Sleep(2500);
            rendicionPlayer = comprobarPuntuacion(pointsPlayer);
            if (pointsPlayer > 21) {
                cout << endl;
                cout << "Has superado los 21 puntos." << endl;
                cout << endl;
                gameOver = true;
                Sleep(2500);
            }
        }
        else {
            rendicionPlayer = true;
        }
    }
    //Turno del Croupier
    if (!gameOver && pointsCroupier <= pointsPlayer) {
        cout << "TURNO DEL CROUPIER" << endl;
        cout << "------------------" << endl;
        cout << endl;
        while (!rendicionCroupier && pointsCroupier <= pointsPlayer) {
            Sleep(1000);
            sacarCarta(pointsCroupier, nameCroupier);
            Sleep(2500);
            rendicionCroupier = comprobarPuntuacion(pointsCroupier);
        }
        cout << endl;
        if (pointsCroupier > 21) {
            cout << "El " << nameCroupier << " ha superado los 21 puntos." << endl;
            cout << endl;
            gameOver = true;
            Sleep(2500);
        }
        else if (pointsCroupier > pointsPlayer) {
            cout << "El " << nameCroupier << " ha superado tus puntos." << endl;
            cout << endl;
            gameOver = true;
            Sleep(2500);
        }
    }
    //Determinamos el ganador de la partida
    determinarGanador(pointsPlayer, pointsCroupier);
    cout << endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln