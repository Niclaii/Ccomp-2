#include <iostream>

using namespace std;

void CambiarEntreUnos(int(*Tablero)[8]) {
    int i_local = 0, j_local = 0, k_local = 0, primerUno_local = -1;
    int* i = &i_local;
    int* j = &j_local;
    int* k = &k_local;
    int* primerUno = &primerUno_local;

    for (*i = 0; *i < 8; (*i)++) {
        *primerUno = -1;
        for (*j = 0; *j < 8; (*j)++) {
            if (Tablero[*i][*j] == 1) {
                if (*primerUno == -1) {
                    *primerUno = *j; // Guarda la posición del primer '1'
                }
                else {
                    for (*k = *primerUno + 1; *k < *j; (*k)++) {
                        Tablero[*i][*k] = 1;
                    }
                }
            }
        }
    }
}

void Imprimir_Tablero(int(*Tablero)[8]) {
    int i_local = 0, j_local = 0;
    int* i = &i_local;
    int* j = &j_local;
    for (*i = 0; *i < 8; (*i)++) {
        for (*j = 0; *j < 8; (*j)++) {
            cout << Tablero[*i][*j] << " ";
        }
        cout << endl;
    }
}

bool TableroLleno(int(*Tablero)[8]) {
    int i_local = 0, j_local = 0;
    int* i = &i_local;
    int* j = &j_local;
    for (*i = 0; *i < 8; (*i)++) {
        for (*j = 0; *j < 8; (*j)++) {
            if (Tablero[*i][*j] == 0) {
                return false;  // Hay al menos un espacio vacío
            }
        }
    }
    return true;  // No hay espacios vacíos
}

void ColocarFichas(int(*Tablero)[8]) {
    int fila_local = 0, columna_local = 0, ficha_local = 1;
    int* fila = &fila_local;
    int* columna = &columna_local;
    int* ficha = &ficha_local;  // Comienza con el jugador 1 ('1')

    while (!TableroLleno(Tablero)) {
        cout << "Ingrese la fila (0-7): ";
        cin >> *fila;
        cout << "Ingrese la columna (0-7): ";
        cin >> *columna;

        if (*fila >= 0 && *fila < 8 && *columna >= 0 && *columna < 8) {
            if (Tablero[*fila][*columna] == 0) {
                Tablero[*fila][*columna] = *ficha;
                *ficha = (*ficha == 1) ? 2 : 1;  // Cambia de ficha
                Imprimir_Tablero(Tablero);
            }
            else {
                cout << "Esa posición ya está ocupada. Elija otra posición." << endl;
            }
        }
        else {
            cout << "Posición fuera de los límites. Intente de nuevo." << endl;
        }
    }

    cout << "El tablero está completamente lleno." << endl;
}

int main() {
    int Tablero[8][8] = { 0 };  // Inicializa todo el tablero a 0

    // Establece los valores centrales como predefinidos
    Tablero[3][3] = 1;
    Tablero[3][4] = 2;
    Tablero[4][3] = 2;
    Tablero[4][4] = 1;

    cout << "Tablero inicial:" << endl;
    Imprimir_Tablero(Tablero);

    ColocarFichas(Tablero);

    CambiarEntreUnos(Tablero);

    cout << "Tablero final después de que todos los lugares fueron ocupados:" << endl;
    Imprimir_Tablero(Tablero);

    return 0;
}
