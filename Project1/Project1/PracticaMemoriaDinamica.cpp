#include <iostream>
#include <string>

using namespace std;

int RellenoCin()
{
    int a;
    cout << "Ingrese un valor: ";
    cin >> a;
    return a;
}

int RellenoCero()
{
    return 0;
}

void LiberarMatriz(int** matriz, int fila) {
    for (int i = 0; i < fila; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int** MatrizA(int& fila, int& columna, int (*alternativa)())
{
    cout << "Ingrese un valor para la fila: ";
    cin >> fila;
    cout << endl;

    cout << "Ingrese un valor para la columna: ";
    cin >> columna;
    cout << endl;

    cout << "Nueva Matriz:" << endl;
    int** A = new int* [fila];
    for (int i = 0; i < fila; i++)
    {
        A[i] = new int[columna];
        for (int j = 0; j < columna; j++)
        {
            int a = alternativa();
            A[i][j] = a;
        }
    }
    cout << endl;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return A;
}

int** Traspuesta(int fila, int columna, int(*alternativa)())
{
    int** A = MatrizA(fila, columna, alternativa);
    cout << "\nMatriz Traspuesta:" << endl;
    int** B = new int* [columna];
    for (int i = 0; i < columna; i++)
    {
        B[i] = new int[fila];
        for (int j = 0; j < fila; j++)
        {
            B[i][j] = A[j][i];
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    LiberarMatriz(A, fila);
    return B;
}

int** Multiplicacion(int& fila, int& columna, int (*alternativa)())
{
    int** A = MatrizA(fila, columna, alternativa);
    cout << endl;
    int filaA = fila;
    int columnaA = columna;
    int filaB = columnaA;
    int columnaB = filaA;

    int** B = MatrizA(fila, columna, alternativa);
    int** C = new int* [filaA];
    for (int i = 0; i < filaA; i++) {
        C[i] = new int[columnaB];
        for (int j = 0; j < columnaB; j++) {
            C[i][j] = 0;
        }
    }
    cout << "Matriz C (A * B):" << endl;
    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < fila; j++) {
            for (int k = 0; k < columna; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    LiberarMatriz(A, filaA);
    LiberarMatriz(B, columnaA);

    return C;
}

int main()
{
    int fila{ 0 }, columna{ 0 };
    int alternativa{ 0 }, Seleccion{ 0 };
    bool Verificacion1{ false }, Verificacion2{ false };
    do
    {
        cout << "Que desea Realizar?(1.Traspuesta / 2. Multiplicación) ";
        cin >> Seleccion;

        if (Seleccion == 1)
        {
            do
            {
                cout << "Desea agregar los valores de cada array(1.Si | 2.No): ";
                cin >> alternativa;
                if (alternativa == 1)
                {
                    Verificacion1 = true;
                    Verificacion2 = true;
                    LiberarMatriz(Traspuesta(fila, columna, RellenoCin), fila);
                }
                else if (alternativa == 2)
                {
                    Verificacion1 = true;
                    Verificacion2 = true;
                    LiberarMatriz(Traspuesta(fila, columna, RellenoCero), fila);
                }
            } while (Verificacion2 == false);
        }
        else if (Seleccion == 2)
        {
            do
            {
                cout << "Desea agregar los valores de cada array(1.Si | 2.No): ";
                cin >> alternativa;
                if (alternativa == 1)
                {
                    Verificacion1 = true;
                    Verificacion2 = true;
                    LiberarMatriz(Multiplicacion(fila, columna, RellenoCin), fila);
                }
                else if (alternativa == 2)
                {
                    Verificacion1 = true;
                    Verificacion2 = true;
                    LiberarMatriz(Multiplicacion(fila, columna, RellenoCero), fila);
                }
            } while (Verificacion2 == false);
        }
    } while (Verificacion1 == false);

    return 0;
}
