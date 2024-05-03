#include <iostream>

using namespace std;

void Imprimir_Tablero(int Tablero[8][8]) {
    for (int i = 0; i < 8; i++) {
        int(*columna) = *(Tablero + i);
        for (; columna < *(Tablero + i + 1); columna++) {
            cout << *columna << " ";
        }
        cout << endl;
    }
}

bool TableroLleno(int Tablero[8][8]) 
{
    for (int i = 0; i < 8; i++) {
        int(*columna) = *(Tablero + i);
        for (; columna < *(Tablero + i + 1); columna++) {
            if (*columna == 0) {
                return false;  // Hay al menos un espacio vacío
            }
        }
    }
    return true;  // No hay espacios vacíos
}
void contarFichas(int Tablero[8][8])
{
    int contador1 = 0;
    int contador2 = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (Tablero[i][j] == 1) {
                contador1++;
            }
            else if (Tablero[i][j] == 2) {
                contador2++;
            }
        }
    }
    cout << "1s:" << contador1 << "  |  2s:" << contador2 << endl;
}
void CambiarHorizontal(int Tablero[8][8], int n, int ficha) 
{
    int(*fila)[8] = Tablero + n;  
    int* columna = *fila; 

    int* tmp1 = nullptr;
    int* tmp2 = nullptr;

    if (ficha == 1)
    {
        for (; columna < *(fila + 1); columna++)
        {
            if (*columna == 1)
            {
                if (!tmp1)
                {
                    tmp1 = columna; 
                }
                else
                {
                    tmp2 = columna;
                }
            }

            if (tmp1 && tmp2)
            {
                for (; tmp1 < tmp2; tmp1++)
                {
                    *tmp1 = 1;

                }
            }
        }
        tmp1 = nullptr;
        tmp2 = nullptr;
    }
    else if (ficha == 2)
    {
        for (; columna < *(fila + 1); columna++)
        {
            if (*columna == 2)
            {
                if (!tmp1)
                {
                    tmp1 = columna; 
                }
                else
                {
                    tmp2 = columna;
                }
            }

            if (tmp1 && tmp2)
            {
                for (; tmp1 < tmp2; tmp1++)
                {
                    *tmp1 = 2;

                }
            }
        }
        tmp1 = nullptr;
        tmp2 = nullptr;
    }
    
}
void CambiarVertical(int Tablero[8][8], int m, int ficha) 
{
    int(*fila)[8] = Tablero;
    int* columna = *fila+m;
    int* tmp1 = nullptr;
    int* tmp2 = nullptr;

    if (ficha == 1)
    {
        for (; columna < *(fila+8); columna+=8)
        {
            if (*columna == 1)
            {
                if (!tmp1)
                {
                    tmp1 = columna;
                }
                else
                {
                    tmp2 = columna;
                }
            }
            if (tmp1 && tmp2)
            {
                for (; tmp1 < tmp2; tmp1 += 8)
                {
                    *tmp1 = 1;
                }
            }

            
        }
        tmp1 = nullptr;
        tmp2 = nullptr;
    }
    else if (ficha == 2)
    {
        for (; columna < *(fila + 8); columna += 8)
        {
            if (*columna == 2)
            {
                if (!tmp1)
                {
                    tmp1 = columna;
                }
                else
                {
                    tmp2 = columna;
                }
            }
            if (tmp1 && tmp2)
            {
                for (; tmp1 < tmp2; tmp1 += 8)
                {
                    *tmp1 = 2;
                }
            }


        }
        tmp1 = nullptr;
        tmp2 = nullptr;
    }


}
        


void ColocarFichas(int Tablero[8][8])
{
    int ficha = 1;
    int(*fila)[8] = Tablero;
    int* columna = *fila;
    int n{ 0 } ,m{ 0 };

    while (!TableroLleno(Tablero)) {
        cout << "Ingrese la fila (0-7): ";
        cin >> n;
        fila = Tablero + n; // Correctly set fila to the right row based on user input
        columna = *fila; // Correctly reset columna to the start of the fila

        cout << "Ingrese la columna (0-7): ";
        cin >> m;
        columna += m; // Move columna to the correct column

        if (n >= 0 && n < 8 && *columna == 0 && m < 8) {
            cout << "Es el turno del jugador " << ficha << endl;
            *columna = ficha;
            Imprimir_Tablero(Tablero);
            cout << endl;

            CambiarHorizontal(Tablero, n,ficha);
            CambiarVertical(Tablero, m, ficha);

            ficha = (ficha == 1) ? 2 : 1;  // Cambia de ficha

            Imprimir_Tablero(Tablero);
            contarFichas(Tablero);
        }
        else {
            cout << "Esa posición ya está ocupada o fuera de los límites. Elija otra posición." << endl;
        }
        n = 0;
    }

    cout << "El tablero está completamente lleno." << endl;
}


int main() {
    int Tablero[8][8] = { 0 };

    Tablero[3][3] = 1;
    Tablero[3][4] = 2;
    Tablero[4][3] = 2;
    Tablero[4][4] = 1;

    cout << "Tablero inicial:" << endl;
    Imprimir_Tablero(Tablero);

    ColocarFichas(Tablero);

    cout << "Tablero final después de que todos los lugares fueron ocupados:" << endl;

    
    Imprimir_Tablero(Tablero);
    
    return 0;
}
