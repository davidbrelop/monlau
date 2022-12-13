// Videojuego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

//Atributos del primer enemigo
int firstEnemyHP = 1000;
int firstEnemyDamage;
string firstEnemyName = "Freezer";
bool firstEnemyIsAlive = true;

//Atributos del segundo enemigo
int secondEnemyHP = 1000;
int secondEnemyDamage;
string secondEnemyName = "Bills";
bool secondEnemyIsAlive = true;

//Atributos de nuestro héroe
string heroName;
int heroDamage;
int kickDamage = 200;
int swordDamage = 500;
int kamehamehaDamage = 1000;
int maxKamehamehaUses = 1;
int heroHP = 2000;
bool heroIsAlive = true;

//Variable donde guardaremos temporalmente a qué enemigo atacar y qué ataque usar
int selectEnemy;
int selectAtaque;
bool selectEnemyOK = false;
bool selectAtaqueOK = false;

int main() {
    
    cout << "Los enemigos " << firstEnemyName << " y " << secondEnemyName << " acaban de aparecer en la Tierra. Cada uno tiene " << firstEnemyHP << " puntos de vida.\n";
    PlaySound(TEXT("aparicion_enemigos.wav"), NULL, SND_SYNC);
    cout << "Inserta el nombre del heroe que los va a derrotar: ";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << ".\n";

    while (heroIsAlive && (firstEnemyIsAlive || secondEnemyIsAlive)){
        srand(time(NULL));
        firstEnemyDamage = 1 + rand() % 1000;
        secondEnemyDamage = 1 + rand() % 1000;
        cout << "Quieres atacar a " << firstEnemyName << " [1] o a " << secondEnemyName << " [2]? ";
        cin >> selectEnemy;
        switch (selectEnemy) {
        case 1: //Se ejecuta solo si atacamos al primer enemigo
            if(!firstEnemyIsAlive){
                cout << "No puedes atacar a " << firstEnemyName << " porque ha muerto. Vuelve a elegir otra vez:\n";
            }
            else{
                while (!selectAtaqueOK){ //Se ejecuta hasta que el usuario elige un ataque que exista
                    cout << "Que ataque quieres hacerle a " << firstEnemyName << "? [1] Patada [2] Golpe de Espada [3] Kamehameha ";
                    cin >> selectAtaque;
                    if (selectAtaque == 1 || selectAtaque == 2 || selectAtaque == 3){
                        selectAtaqueOK = true;
                        if (selectAtaque == 3){
                            if (maxKamehamehaUses > 0){
                                selectAtaqueOK = true;
                            }
                            else {
                                cout << "No puedes utilizar Kamehameha porque ya has superado el limite de veces que se puede utilizar. Elige otro ataque.\n";
                                selectAtaqueOK = false;
                            }
                        }
                    }
                    else {
                        cout << "Este ataque no existe. Vuelve a elegir otra vez:\n";
                    }
                }
                selectAtaqueOK = false;
                switch (selectAtaque) {
                case 1: //Se ejecuta solo si elegimos Patada
                    firstEnemyHP = firstEnemyHP - kickDamage;
                    PlaySound(TEXT("kick.wav"), NULL, SND_SYNC);
                    if (firstEnemyHP <= 0) {
                        firstEnemyHP = 0;
                        firstEnemyIsAlive = false;
                        cout << "Has derrotado a " << firstEnemyName << ".\n";
                        PlaySound(TEXT("dead_notification.wav"), NULL, SND_SYNC);
                    }
                    else {
                        cout << "A " << firstEnemyName << " le queda(n) " << firstEnemyHP << " punto(s) de vida.\n";
                    }
                    if (firstEnemyIsAlive) {
                        heroHP = heroHP - firstEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                    if (secondEnemyIsAlive && heroIsAlive) {
                        heroHP = heroHP - secondEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                break;
                case 2: //Se ejecuta solo si elegimos Golpe de Espada
                    firstEnemyHP = firstEnemyHP - swordDamage;
                    PlaySound(TEXT("espada.wav"), NULL, SND_SYNC);
                    if (firstEnemyHP <= 0) {
                        firstEnemyHP = 0;
                        firstEnemyIsAlive = false;
                        cout << "Has derrotado a " << firstEnemyName << ".\n";
                        PlaySound(TEXT("dead_notification.wav"), NULL, SND_SYNC);
                    }
                    else {
                        cout << "A " << firstEnemyName << " le queda(n) " << firstEnemyHP << " punto(s) de vida.\n";
                    }
                    if (firstEnemyIsAlive) {
                        heroHP = heroHP - firstEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                    if (secondEnemyIsAlive && heroIsAlive) {
                        heroHP = heroHP - secondEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                break;
                case 3: //Se ejecuta solo si elegimos Kamehameha
                    firstEnemyHP = firstEnemyHP - kamehamehaDamage;
                    PlaySound(TEXT("kamehameha.wav"), NULL, SND_SYNC);
                    maxKamehamehaUses--;
                    if (firstEnemyHP <= 0) {
                        firstEnemyHP = 0;
                        firstEnemyIsAlive = false;
                        cout << "Has derrotado a " << firstEnemyName << ".\n";
                        PlaySound(TEXT("dead_notification.wav"), NULL, SND_SYNC);
                    }
                    else {
                        cout << "A " << firstEnemyName << " le queda(n) " << firstEnemyHP << " punto(s) de vida.\n";
                    }
                    if (firstEnemyIsAlive) {
                        heroHP = heroHP - firstEnemyDamage;
                        if (heroHP <= 0) {
                                heroHP = 0;
                                heroIsAlive = false;
                                cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                    if (secondEnemyIsAlive && heroIsAlive) {
                        heroHP = heroHP - secondEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                break;
                }
            }
        break;
        case 2: //Se ejecuta solo si atacamos al segundo enemigo
            if (!secondEnemyIsAlive){
                cout << "No puedes atacar a " << secondEnemyName << " porque ha muerto. Vuelve a elegir otra vez:\n";
            }
            else{
                while (!selectAtaqueOK) { //Se ejecuta hasta que el usuario elige un ataque que exista
                    cout << "Que ataque quieres hacerle a " << secondEnemyName << "? [1] Patada [2] Golpe de Espada [3] Kamehameha ";
                    cin >> selectAtaque;
                    if (selectAtaque == 1 || selectAtaque == 2 || selectAtaque == 3) {
                        selectAtaqueOK = true;
                        if (selectAtaque == 3) {
                            if (maxKamehamehaUses > 0) {
                                selectAtaqueOK = true;
                            }
                            else {
                                cout << "No puedes utilizar Kamehameha porque ya has superado el limite de veces que se puede utilizar. Elige otro ataque:\n";
                                selectAtaqueOK = false;
                            }
                        }
                    }
                    else {
                        cout << "Este ataque no existe. Vuelve a elegir otra vez:\n";
                    }
                }
                selectAtaqueOK = false;
                switch (selectAtaque) {
                case 1: //Se ejecuta solo si elegimos Patada
                    secondEnemyHP = secondEnemyHP - kickDamage;
                    PlaySound(TEXT("kick.wav"), NULL, SND_SYNC);
                    if (secondEnemyHP <= 0) {
                        secondEnemyHP = 0;
                        secondEnemyIsAlive = false;
                        cout << "Has derrotado a " << secondEnemyName << ".\n";
                        PlaySound(TEXT("dead_notification.wav"), NULL, SND_SYNC);
                    }
                    else {
                        cout << "A " << secondEnemyName << " le queda(n) " << secondEnemyHP << " punto(s) de vida.\n";
                    }
                    if (secondEnemyIsAlive) {
                        heroHP = heroHP - secondEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                    if (firstEnemyIsAlive && heroIsAlive) {
                        heroHP = heroHP - firstEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                break;
                case 2: //Se ejecuta solo si elegimos Golpe de Espada
                    secondEnemyHP = secondEnemyHP - swordDamage;
                    PlaySound(TEXT("espada.wav"), NULL, SND_SYNC);
                    if (secondEnemyHP <= 0) {
                        secondEnemyHP = 0;
                        secondEnemyIsAlive = false;
                        cout << "Has derrotado a " << secondEnemyName << ".\n";
                        PlaySound(TEXT("dead_notification.wav"), NULL, SND_SYNC);
                    }
                    else {
                        cout << "A " << secondEnemyName << " le queda(n) " << secondEnemyHP << " punto(s) de vida.\n";
                    }
                    if (secondEnemyIsAlive) {
                        heroHP = heroHP - secondEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                    if (firstEnemyIsAlive && heroIsAlive) {
                        heroHP = heroHP - firstEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                break;
                case 3: //Se ejecuta solo si elegimos Kamehameha
                    secondEnemyHP = secondEnemyHP - kamehamehaDamage;
                    PlaySound(TEXT("kamehameha.wav"), NULL, SND_SYNC);
                    maxKamehamehaUses--;
                    if (secondEnemyHP <= 0) {
                        secondEnemyHP = 0;
                        secondEnemyIsAlive = false;
                        cout << "Has derrotado a " << secondEnemyName << ".\n";
                        PlaySound(TEXT("dead_notification.wav"), NULL, SND_SYNC);
                    }
                    else {
                        cout << "A " << secondEnemyName << " le queda(n) " << secondEnemyHP << " punto(s) de vida.\n";
                    }
                    if (secondEnemyIsAlive) {
                        heroHP = heroHP - secondEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << secondEnemyName << " te ha contraatacado con " << secondEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }
                    if (firstEnemyIsAlive && heroIsAlive) {
                        heroHP = heroHP - firstEnemyDamage;
                        if (heroHP <= 0) {
                            heroHP = 0;
                            heroIsAlive = false;
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te ha derrotado.\n";
                        }
                        else {
                            cout << firstEnemyName << " te ha contraatacado con " << firstEnemyDamage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
                        }
                        PlaySound(TEXT("ouch.wav"), NULL, SND_SYNC);
                    }  
                break;
                }
            }
        break;
        default: //Se ejecuta si el usuario elige un enemigo que no existe
            cout << "Este enemigo no existe. Vuelve a elegir otra vez:\n";
        } 
    }
    if (!heroIsAlive){
        cout << "La Tierra ha sido destruida por " << firstEnemyName << " y " << secondEnemyName << ".\n";
        PlaySound(TEXT("game_over.wav"), NULL, SND_SYNC);
    }
    else if (!firstEnemyIsAlive && !secondEnemyIsAlive){
        cout << "Felicidades, has acabado con los dos enemigos y la Tierra vuelve a estar a salvo.\n";
        PlaySound(TEXT("congratulations.wav"), NULL, SND_SYNC);
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
