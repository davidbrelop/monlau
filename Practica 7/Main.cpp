#include "Personaje.h"
#include "EnemigoFinal.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

using namespace std;

#define LENGTH 9
#define HEIGHT 3
#define NUMERO_ENEMIGOS 5
#define VACIO 0
#define HEROE 1
#define ENEMIGO 2
#define ENEMIGO_FINAL 3
#define VENDAS 4

int tablero[LENGTH][HEIGHT];
Personaje arrayEnemigos[NUMERO_ENEMIGOS];

void presentacion(string& playerName) {
    cout << "BIENVENIDO AL JUEGO DE 'STRANGER THINGS'" << endl;
    cout << "DEBES LLEGAR HASTA LA META Y DERROTAR AL ENEMIGO FINAL PARA SALVAR EL MUNDO" << endl;
    cout << endl;
    cout << "Introduce tu nombre: ";
    cin >> playerName;
    cout << endl;
}

void imprimirTablero() {
    cout << "+---+---+---+---+---+---+---+---+---+" << endl;
    for (int y = 0; y < HEIGHT; y++) {
        cout << "| ";
        for (int x = 0; x < LENGTH; x++) {
            if (tablero[x][y] == HEROE) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "X";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << " | ";
            }
            else if (tablero[x][y] == ENEMIGO) {
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                //cout << "X";
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << " ";
                cout << " | ";
            }
            else if (tablero[x][y] == ENEMIGO_FINAL) {
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                //cout << "X";
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << " ";
                cout << " | ";
            }
            else if (tablero[x][y] == VENDAS) {
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                //cout << "X";
                //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << " ";
                cout << " | ";
            }
            else {
                cout << " " << " | ";
            }
        }
        cout << endl << "+---+---+---+---+---+---+---+---+---+" << endl;
    }
}

void moverJugador(Personaje& heroe, bool& hayObjetoEnCasilla, int& tipoObjetoEncontrado, bool& haHabidoMovimiento) {
    haHabidoMovimiento = false;
    char tecla = _getch();
    switch (tecla) {
    case 72: // Flecha hacia arriba
        if (heroe.getPosY() > 0) {
            if (tablero[heroe.getPosX()][heroe.getPosY() - 1] == ENEMIGO){
                tipoObjetoEncontrado = ENEMIGO;
                hayObjetoEnCasilla = true;
            
            }
            else if (tablero[heroe.getPosX()][heroe.getPosY() - 1] == ENEMIGO_FINAL) {
                tipoObjetoEncontrado = ENEMIGO_FINAL;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX()][heroe.getPosY() - 1] == VENDAS) {
                tipoObjetoEncontrado = VENDAS;
                hayObjetoEnCasilla = true;

            }
            tablero[heroe.getPosX()][heroe.getPosY()] = VACIO;
            heroe.setPosY(heroe.getPosY() - 1);
            tablero[heroe.getPosX()][heroe.getPosY()] = HEROE;
            haHabidoMovimiento = true;
        }
        break;
        
    case 80: // Flecha hacia abajo
        if (heroe.getPosY() < HEIGHT - 1) {
            if (tablero[heroe.getPosX()][heroe.getPosY() + 1] == ENEMIGO) {
                tipoObjetoEncontrado = ENEMIGO;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX()][heroe.getPosY() + 1] == ENEMIGO_FINAL) {
                tipoObjetoEncontrado = ENEMIGO_FINAL;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX()][heroe.getPosY() + 1] == VENDAS) {
                tipoObjetoEncontrado = VENDAS;
                hayObjetoEnCasilla = true;

            }
            tablero[heroe.getPosX()][heroe.getPosY()] = VACIO;
            heroe.setPosY(heroe.getPosY() + 1);
            tablero[heroe.getPosX()][heroe.getPosY()] = HEROE;
            haHabidoMovimiento = true;
        }
        break;

    case 75: // Flecha hacia la izquierda
        if (heroe.getPosX() > 0) {
            if (tablero[heroe.getPosX() - 1][heroe.getPosY()] == ENEMIGO) {
                tipoObjetoEncontrado = ENEMIGO;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX() - 1][heroe.getPosY()] == ENEMIGO_FINAL) {
                tipoObjetoEncontrado = ENEMIGO_FINAL;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX() - 1][heroe.getPosY()] == VENDAS) {
                tipoObjetoEncontrado = VENDAS;
                hayObjetoEnCasilla = true;

            }
            tablero[heroe.getPosX()][heroe.getPosY()] = VACIO;
            heroe.setPosX(heroe.getPosX() - 1);
            tablero[heroe.getPosX()][heroe.getPosY()] = HEROE;
            haHabidoMovimiento = true;
        }
        break;

    case 77: // Flecha hacia la derecha
        if (heroe.getPosX() < LENGTH - 1) {
            if (tablero[heroe.getPosX() + 1][heroe.getPosY()] == ENEMIGO) {
                tipoObjetoEncontrado = ENEMIGO;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX() + 1][heroe.getPosY()] == ENEMIGO_FINAL) {
                tipoObjetoEncontrado = ENEMIGO_FINAL;
                hayObjetoEnCasilla = true;

            }
            else if (tablero[heroe.getPosX() + 1][heroe.getPosY()] == VENDAS) {
                tipoObjetoEncontrado = VENDAS;
                hayObjetoEnCasilla = true;

            }
            tablero[heroe.getPosX()][heroe.getPosY()] = VACIO;
            heroe.setPosX(heroe.getPosX() + 1);
            tablero[heroe.getPosX()][heroe.getPosY()] = HEROE;
            haHabidoMovimiento = true;
        }
        break;
    }
}

void batalla(Personaje& heroe, Personaje& enemigo, int& enemigosDerrotados, bool& hayObjetoEnCasilla) {
    cout << endl << "Te has encontrado con un " << arrayEnemigos[enemigosDerrotados].getName() << ". Preparate para la batalla!" << endl;
    PlaySound(TEXT("aparicion_enemigos.wav"), NULL, SND_SYNC);
    while (heroe.getHP() > 0 && enemigo.getHP() > 0) {
        cout << endl;
        cout << "Pulsa INTRO para atacar..." << endl;
        char tecla;
        do {
            tecla = _getch(); // Tecla de ENTER
        } while (tecla != 13);
        enemigo.setHP(enemigo.getHP() - heroe.getBasicAttack());
        cout << endl;
        cout << "Le has quitado " << heroe.getBasicAttack() << " puntos de vida." << endl;
        PlaySound(TEXT("espada.wav"), NULL, SND_ASYNC);
        Sleep(3000);
        if (enemigo.getHP() > 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "SU VIDA RESTANTE: " << enemigo.getHP() << " puntos" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            Sleep(3000);
            heroe.setHP(heroe.getHP() - enemigo.getBasicAttack());
            cout << endl;
            cout << "El " << enemigo.getName() << " te ha contratacado y te ha quitado " << enemigo.getBasicAttack() << " puntos de vida." << endl;
            PlaySound(TEXT("ouch.wav"), NULL, SND_ASYNC);
            Sleep(3000);
            if (heroe.getHP() > 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "TU VIDA RESTANTE: " << heroe.getHP() << " puntos" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else {
                heroe.setHP(0);
                cout << endl << "El " << enemigo.getName() << " te ha derrotado." << endl << endl;
            }
        }
        else {
            enemigo.setHP(0);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "SU VIDA RESTANTE: " << enemigo.getHP() << " puntos" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            Sleep(3000);
            cout << endl << "Has derrotado a este " << enemigo.getName() << "... Puedes seguir con tu camino!" << endl << endl;
            PlaySound(TEXT("dead_notification.wav"), NULL, SND_ASYNC);
            hayObjetoEnCasilla = false;
            enemigosDerrotados++;
        }
        Sleep(3000);
    }
}

void batalla(Personaje& heroe, EnemigoFinal& finalBoss) {
    cout << endl << "Te has encontrado con " << finalBoss.getName() << ". Preparate para tu batalla final!" << endl;
    PlaySound(TEXT("aparicion_enemigos.wav"), NULL, SND_SYNC);
    while (heroe.getHP() > 0 && finalBoss.getHP() > 0) {
        cout << endl;
        cout << "Pulsa INTRO para atacar..." << endl;
        char tecla;
        do {
            tecla = _getch(); // Tecla de ENTER
        } while (tecla != 13);
        finalBoss.setHP(finalBoss.getHP() - heroe.getBasicAttack());
        cout << endl;
        cout << "Le has quitado " << heroe.getBasicAttack() << " puntos de vida." << endl;
        PlaySound(TEXT("espada.wav"), NULL, SND_ASYNC);
        Sleep(3000);
        if (finalBoss.getHP() > 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "SU VIDA RESTANTE: " << finalBoss.getHP() << " puntos" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            Sleep(3000);
            int ataque;
            string tipoAtaque;
            switch (1 + rand() % 5) {
                case 1:
                case 2:
                case 3:
                    ataque = finalBoss.getBasicAttack();
                    break;
                case 4:
                    ataque = finalBoss.getFireAttack();
                    tipoAtaque = "fuego";
                    break;
                case 5:
                    ataque = finalBoss.getFrozenAttack();
                    tipoAtaque = "hielo";
                    break;
            }
            heroe.setHP(heroe.getHP() - ataque);
            cout << endl;
            if (tipoAtaque == "fuego") {
                cout << finalBoss.getName() << " te ha lanzado una bola de fuego y te ha quitado " << ataque << " puntos de vida." << endl;
            }
            else if (tipoAtaque == "hielo") {
                cout << finalBoss.getName() << " te ha congelado y te ha quitado " << ataque << " puntos de vida." << endl;
            }
            else {
                cout << finalBoss.getName() << " te ha contratacado y te ha quitado " << ataque << " puntos de vida." << endl;
            }
            PlaySound(TEXT("ouch.wav"), NULL, SND_ASYNC);
            Sleep(3000);
            if (heroe.getHP() > 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                cout << "TU VIDA RESTANTE: " << heroe.getHP() << " puntos" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else {
                heroe.setHP(0);
                cout << endl << finalBoss.getName() << " te ha derrotado." << endl << endl;
            }
        }
        else {
            finalBoss.setHP(0);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "SU VIDA RESTANTE: " << finalBoss.getHP() << " puntos" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            Sleep(3000);
            cout << endl << "Has derrotado a " << finalBoss.getName() << "..." << endl << endl;
            PlaySound(TEXT("dead_notification.wav"), NULL, SND_ASYNC);
        }
        Sleep(3000);
    }
}

void recogerVendas(Personaje& heroe, bool& hayObjetoEnCasilla) {
    cout << endl << "FELICIDADES! Te has encontrado unas vendas para curarte. Tu salud aumenta 50 puntos de vida." << endl;
    PlaySound(TEXT("aparicion_enemigos.wav"), NULL, SND_SYNC);
    heroe.setHP(heroe.getHP() + 50);
    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "TU VIDA RESTANTE: " << heroe.getHP() << " puntos" << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    hayObjetoEnCasilla = false;
    Sleep(3000);
}

int main() {
    
    //Variables del programa
    string playerName;
    bool haHabidoMovimiento;
    bool hayObjetoEnCasilla = false;
    int tipoObjetoEncontrado;
    int enemigosDerrotados = 0;
    
    //Inicio de la partida
    srand(time(NULL));
    presentacion(playerName);

    //Posicionamento del heroe
    int posXH = 0;
    int posYH = rand() % HEIGHT;
    Personaje heroe = Personaje(playerName, 1000, 150, posXH, posYH);
    tablero[posXH][posYH] = HEROE;
    
    //Posicionamento de los enemigos
    for (int i = 0; i < NUMERO_ENEMIGOS; i++) {
        int posXE;
        int posYE;
        bool espacioOcupado;
        do {
            posXE = 1 + rand() % (LENGTH - 2);
            posYE = rand() % HEIGHT;
            if (tablero[posXE][posYE] != 0) {
                espacioOcupado = true;
            }
            else {
                espacioOcupado = false;
            }
        } while (espacioOcupado);
        arrayEnemigos[i] = Personaje("Demogorgon", 400, 50, posXE, posYE);
        tablero[posXE][posYE] = ENEMIGO;
    }

    //Posicionamento del enemigo final
    int posXEF = LENGTH - 1;
    int posYEF = rand() % HEIGHT;
    EnemigoFinal finalBoss = EnemigoFinal("Vecna", 800, 100, posXEF, posYEF, 200, 300);
    tablero[posXEF][posYEF] = ENEMIGO_FINAL;

    //Posicionamento de las vendas
    for (int i = 0; i < 2; i++) {
        int posXV;
        int posYV;
        bool espacioOcupado;
        do {
            posXV = 1 + rand() % (LENGTH - 2);
            posYV = rand() % HEIGHT;
            if (tablero[posXV][posYV] != 0) {
                espacioOcupado = true;
            }
            else {
                espacioOcupado = false;
            }
        } while (espacioOcupado);
        tablero[posXV][posYV] = VENDAS;
    }
 
    //Desarrollo de la partida
    while (heroe.getHP() > 0 && finalBoss.getHP() > 0) {
        imprimirTablero();
        cout << endl << "Utiliza las flechas para moverte por el tablero:" << endl << endl;
        while (!hayObjetoEnCasilla) {
            moverJugador(heroe, hayObjetoEnCasilla, tipoObjetoEncontrado, haHabidoMovimiento);
            if (haHabidoMovimiento) {
                imprimirTablero();
                if (!hayObjetoEnCasilla) {
                    cout << endl << "Utiliza las flechas para moverte por el tablero:" << endl << endl;
                }
            }
        }
        if (hayObjetoEnCasilla) {
            if (tipoObjetoEncontrado == ENEMIGO) {
                batalla(heroe, arrayEnemigos[enemigosDerrotados], enemigosDerrotados, hayObjetoEnCasilla);
            }
            else if (tipoObjetoEncontrado == ENEMIGO_FINAL) {
                batalla(heroe, finalBoss);
            }
            else if (tipoObjetoEncontrado == VENDAS) {
                recogerVendas(heroe, hayObjetoEnCasilla);
            }
        }
    }

    //Final de la partida
    if (heroe.getHP() <= 0) {
        cout << "HAS PERDIDO..." << endl;
        PlaySound(TEXT("game_over.wav"), NULL, SND_SYNC);
    }
    else if (finalBoss.getHP() <= 0) {
        cout << "FELICIDADES, HAS GANADO!" << endl;
        PlaySound(TEXT("congratulations.wav"), NULL, SND_SYNC);
    }
}