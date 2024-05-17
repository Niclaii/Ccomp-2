#include <iostream>
#include <string>

using namespace std;

int main()
{
    int fila{ 4 }, columna{ 2 };
    int** A = nullptr;
    /*cout << "ingrese un valor para la fila ";
    cin >> fila; cout << endl;
    cout << "ingrese un valor para la columna ";
    cin >> fila; cout << endl;
    */

    int a{ 1 };
    A = new int* [fila];
    for (int i = 0; i < fila; i++)
    {
        A[i] = new int[columna];
        for (int j = 0; j < columna; j++)
        {
            A[i][j] = a;
            a++;
        }
    }
    for (int i = 0; i < fila; i++)
    {
        delete[] A[i];

    }
    delete[] A;
    


    


    return 0;
}