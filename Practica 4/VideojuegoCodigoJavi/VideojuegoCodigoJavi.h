// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

//Atributos del primer enemigo
string enemyName1 = "Freezer";
int enemyHP1 = 1000;
bool enemyIsAlive1 = true;

//Atributos del segundo enemigo
string enemyName2 = "Bills";
int enemyHP2 = 1000;
bool enemyIsAlive2 = true;

//Atributos de nuestro héroe
string heroName;
int heroDamage;
int heroHP = 2000;
bool heroIsAlive = true;

//Atributos del juego
int enemyChoosed = 0;
int maxKamehamehaUses = 1;
int patadaValue = 200;
int espadazoValue = 500;
int kamehamehaValue = 1000;

void gameStart() {
    cout << "Los enemigos " << enemyName1 << " y " << enemyName2 << " acaban de aparecer en la Tierra. Cada uno tiene " << enemyHP1 << " puntos de vida.\n";
    cout << "Inserta el nombre del heroe que los va a derrotar:\n";
    cin >> heroName;
    cout << "El nombre del heroe es " << heroName << ".\n";
}

int chooseEnemy() {
    int userOption = 0;
    while (userOption != 1 && userOption != 2) {
        cout << "A que enemigo quieres atacar? \n";
        if (enemyIsAlive1) {
            cout << "1. " << enemyName1 << "\n";
        }
        if (enemyIsAlive2) {
            cout << "2. " << enemyName2 << "\n";
        }
        cin >> userOption;
        if (userOption <= 0 || userOption > 2) {
            cout << "La opcion elegida no es correcta. Por favor, elige una opcion valida.\n";
        }
        if (!enemyIsAlive1 && userOption == 1) {
            cout << enemyName1 << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo.\n";
            userOption = 0;
        }
        if (!enemyIsAlive2 && userOption == 2) {
            cout << enemyName2 << " ya esta muerto. Por favor, elige un enemigo que todavia este vivo.\n";
            userOption = 0;
        }
    }
    return userOption;
}

int chooseAttack() {
    int userOption = 0;
    while (userOption != 1 && userOption != 2 && userOption != 3) {
        cout << "Que ataque quieres usar?\n";
        cout << "1. Patada\n";
        cout << "2. Golpe de espada\n";
        if (maxKamehamehaUses > 0) {
            cout << "3. Kamehameha\n";
        }
        cin >> userOption;
        if (userOption <= 0 || userOption > 3) {
            cout << "El ataque seleccionado no es correcto. Por favor, elige una opcion valida.\n";
        }
        if (userOption == 3) {
            if (maxKamehamehaUses > 0) {
                maxKamehamehaUses--;
            }
            else {
                userOption = 0;
                cout << "No te queda energia para hacer un Kamehameha. Por favor, selecciona otro ataque. \n";
            }
        }
    }
    if (userOption == 1) {
        return patadaValue;
    }
    else if (userOption == 2) {
        return espadazoValue;
    }
    else {
        return kamehamehaValue;
    }
}

void heroAttackEnemy(string enemyName, int damage, int& enemyHP) {
    cout << "Acabas de atacar a " << enemyName << " y le has hecho " << damage << " punto(s) de damage.\n";
    enemyHP = enemyHP - damage;
}

void checkEnemyStatus(string enemyName, int& enemyHP, bool& enemyIsAlive) {
    if (enemyHP <= 0) {
        cout << "Te has cargado a " << enemyName << ".\n";
        enemyHP = 0;
        enemyIsAlive = false;
    }
    else {
        cout << "A " << enemyName << " le queda(n) " << enemyHP << " punto(s) de vida.\n";
        enemyIsAlive = true;
    }
}

void enemyAttack(string enemyName, int damage) {
    heroHP = heroHP - damage;
    if (heroHP > 0) {
        cout << enemyName << " te ha contraatacado con " << damage << " puntos de damage y te queda(n) " << heroHP << " punto(s) de vida.\n";
    }
    else {
        cout << enemyName << " te ha contraatacado con " << damage << " y te ha matado. El mundo esta condenado.\n";
        heroIsAlive = false;
    }
}

int main() {
    gameStart();
    while (heroIsAlive && (enemyIsAlive1 || enemyIsAlive2)) {
        //ELEGIMOS EL ENEMIGO AL QUE ATACAR
        enemyChoosed = chooseEnemy();
        //ELEGIMOS EL ATAQUE Y CAPTURAMOS EL VALOR DEL DAMAGE QUE HAREMOS
        heroDamage = chooseAttack();
        if (enemyChoosed == 1) {
            //ATACAMOS AL ENEMIGO 1
            heroAttackEnemy(enemyName1, heroDamage, enemyHP1);
            checkEnemyStatus(enemyName1, enemyHP1, enemyIsAlive1);
        }
        else {
            //ATACAMOS AL ENEMIGO 2
            heroAttackEnemy(enemyName2, heroDamage, enemyHP2);
            checkEnemyStatus(enemyName2, enemyHP2, enemyIsAlive2);
        }
        srand(time(NULL));
        //ATACA EL ENEMIGO 1 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive1 && heroIsAlive) {
            enemyAttack(enemyName1, 1 + rand() % 1000);
        }
        //ATACA EL ENEMIGO 2 SI ESTÁ VIVO Y EL HÉROE TAMBIÉN
        if (enemyIsAlive2 && heroIsAlive) {
            enemyAttack(enemyName2, 1 + rand() % 1000);
        }
    }
    if (!enemyIsAlive1 && !enemyIsAlive2) {
        cout << "Felicidades, has acabado con los dos enemigos y la Tierra vuelve a estar a salvo.\n";
    }
}