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




int** MatrizA(int fila, int columna,int alternativa)
{
    int a{ 0 };
    cout << "Matriz A:" << endl;
    int** A = new int* [fila];
    for (int** p = A; *p < *A + fila; p++)
    {
        *p = new int[columna];
        for (int* q = *p; q < *p + columna; q++)
        {
            cout << "Ingrese un valor: ";
            cin >> a;
            *q = a;
            cout << *q << " ";
        }
        cout << endl;
    }
    return A;
}

int** MatrizAB(int fila, int columna, int (*alternativa)())
{
    //int a{ 0 };
    cout << "Matriz A:" << endl;
    int** A = new int* [fila];
    for (int** p = A; *p < *A + fila; p++)
    {
        *p = new int[columna];
        for (int* q = *p; q < *p + columna; q++)
        {
            *q = alternativa();
            cout << *q << " ";
        }
        cout << endl;
    }
    return A;
}

int** MatrizB(int fila, int columna)
{
    
    int **A = MatrizA(fila, columna);
    cout << "\nMatriz B:" << endl;
    int** B = new int* [columna];
    for (int** p = B; *p < *B + columna; p++)
    {
        *p = new int[fila];
        for (int* q = *p; q < *p + fila; q++)
        {
            B[i][j] = A[j][i];
            cout << B[i][j] << " ";
        }
        cout << endl;
    }


}









void Funcion1(int fila, int columna,int alternativa)
{
 
    MatrizA(fila, columna);
 

    int** C = new int* [fila];
    for (int i = 0; i < fila; i++) {
        C[i] = new int[fila];
        for (int j = 0; j < fila; j++) {
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

    for (int i = 0; i < fila; i++)
    {
        delete[] A[i];

    }
    delete[] A;

    for (int i = 0; i < columna; i++)
    {
        delete[] B[i];

    }
    delete[] B;

    for (int i = 0; i < fila; i++)
    {
        delete[] C[i];

    }
    delete[] C;
}
void Funcion2(int fila, int columna)
{
    int a{ 1 };
    cout << "Matriz A:" << endl;
    int** A = new int* [fila];
    for (int i = 0; i < fila; i++)
    {
        A[i] = new int[columna];
        for (int j = 0; j < columna; j++)
        {
            A[i][j] = a++;
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz B:" << endl;
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

    int** C = new int* [fila];
    for (int i = 0; i < fila; i++) {
        C[i] = new int[fila];
        for (int j = 0; j < fila; j++) {
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

    for (int i = 0; i < fila; i++)
    {
        delete[] A[i];

    }
    delete[] A;

    for (int i = 0; i < columna; i++)
    {
        delete[] B[i];

    }
    delete[] B;

    for (int i = 0; i < fila; i++)
    {
        delete[] C[i];

    }
    delete[] C;
}

int main()
{
    int fila{ 0 }, columna{ 0 };
    int alternativa{ 0 };


    cout << "Ingrese un valor para la fila: ";
    cin >> fila;
    cout << endl;

    cout << "Ingrese un valor para la columna: ";
    cin >> columna;
    cout << endl;

    cout << "Desea agregar los valores de cada array(1.Si | 2.No): ";
    cin >> alternativa;

    if (alternativa == 1)
    {
        Funcion1(fila, columna,alternativa);
    }
    else if (alternativa == 2)
    {
        Funcion2(fila, columna);
    }

    return 0;
}