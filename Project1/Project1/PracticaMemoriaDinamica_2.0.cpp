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
    for (int** p = matriz; p < matriz + fila; p++) {
        delete[] * p;
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
    for (int** p = A; p < A + fila; p++)
    {
        *p = new int[columna];
        for (int* q = *p; q < *p + columna; q++)
        {
            int a = alternativa();
            *q = a;
        }
    }
    cout << endl;
    for (int** p = A; p < A + fila; p++)
    {
        for (int* q = *p; q < *p + columna; q++)
        {
            cout << *q << " ";
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
    int sumador{ 0 };
    for (int** p = B, **n = A; p < B + columna; p++)
    {
        *p = new int[fila];
        for (int* q = *p; q < *p + fila; q++)
        {
            if (n == A + fila)
            {
                n = A;
                sumador++;
                *q = *(*n + sumador);
                n++;
            }
            else
            {
                *q = *(*n + sumador);
                n++;
            }
            cout << *q << " ";
        }
        cout << endl;

    }
    return B;
}

int** Multiplicacion(int& fila, int& columna, int (*alternativa)())
{
    int** A = MatrizA(fila, columna, alternativa);
    cout << endl;
    int filaA = fila;
    int columnaA = columna;

    int** B = MatrizA(fila, columna, alternativa);
    int filaB = fila;
    int columnaB = columna;

    if (columnaA != filaB)
    {
        cout << "No se puede realizar la multiplicacion" << endl;
        //LiberarMatriz(A, filaA);
        //LiberarMatriz(B, filaB);
        return nullptr;
    }

    int** C = new int* [filaA];
    for (int** p = C; p < C + filaA; p++)
    {
        *p = new int[columnaB];
        for (int* q = *p; q < *p + columnaB; q++)
        {
            *q = 0;
        }
    }
    for (int** pA = A; pA < A + filaA; pA++)
    {
        for (int* qA = *pA; qA < *pA + columnaA; qA++)
        {
            for (int** pB = B; pB < B + filaB; pB++)
            {
                int* pC = *(C + (pA - A)) + (pB - B);
                *pC += (*qA) * (*(*pB + (qA - *pA)));
            }
        }
    }

    cout << "Matriz C (A * B):" << endl;
    for (int** pC = C; pC < C + filaA; pC++)
    {
        for (int* qC = *pC; qC < *pC + columnaB; qC++)
        {
            cout << *qC << " ";
        }
        cout << endl;
    }


    //LiberarMatriz(A, filaA);
    //LiberarMatriz(B, filaB);

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
                    Traspuesta(fila, columna, RellenoCin);

                }
                else if (alternativa == 2)
                {
                    Verificacion1 = true;
                    Verificacion2 = true;
                    Traspuesta(fila, columna, RellenoCero);
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
                    Multiplicacion(fila, columna, RellenoCin);
                }
                else if (alternativa == 2)
                {
                    Verificacion1 = true;
                    Verificacion2 = true;
                    Multiplicacion(fila, columna, RellenoCero);
                }
            } while (Verificacion2 == false);
        }
    } while (Verificacion1 == false);

    return 0;
}
