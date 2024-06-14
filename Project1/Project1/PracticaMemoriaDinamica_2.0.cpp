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

int** MatrizA(int fila, int columna, int (*alternativa)())
{
    cout << "Matriz A:" << endl;
    int** A = new int* [fila];
    for (int** p = A; p < A + fila; p++)
    {
        *p = new int[columna];
        for (int* q = *p; q < *p + columna; q++)
        {
            int a = alternativa();
            *q = a;
            cout << *q << " ";
        }
        cout << endl;
    }
    return A;
}

int** MatrizB(int fila, int columna, int (*alternativa)())
{
    int **A = MatrizA(fila, columna,alternativa);
    cout << "\nMatriz B:" << endl;
    int** B = new int* [columna];
    int sumador{ 0 };
    for (int** p = B , **n = A ; p < B + columna; p++)
    {
        *p = new int[fila];
        for (int* q = *p ; q < *p + fila; q++)
        {
            if (n == A+fila)
            {
                n=A;
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

    int** C = new int* [fila];
    cout << "Matriz C (A * B):" << endl;
    int contadorfilas{ 0 }, contadorcolumnas{ 1 };
    int X{ 1 };
    int** pA = A;
    int* pa = *pA;
    int** pB = B;
    int* pb = *pB;
    int contadorElementos{ 0 };

    columna = fila;

    for (int** p = C; p < C + fila; p++)
    {
        *p = new int[columna];
        
        for (int* q = *p ; q < *p + columna;q++)
        {
            *q = 0;
            for (int k = 0; k < columna; k++)
            {
                *q += (*pa) * (*pb);
                pa++;   
                pB++;
                pb=*pB;
                if (contadorfilas < columna && contadorfilas != 0)
                {
                    pb += contadorfilas;  
                }
                                           
            }   
            cout << *q << " ";
            ++contadorElementos;
            if (contadorElementos == columna * columna)
            {
                break;
            }
            contadorfilas++;
            pa = *pA;
            pB = B;
            pb = *pB;
            pb += contadorfilas;
            
            if (contadorfilas == fila)
            {
                contadorfilas = 0;
                pb = *pB;
            }
            if (X == columna-1)
            { 
                X = 1;
            }
            else
            {
                if (contadorcolumnas == columna)
                {
                    pA++;
                    pa = *pA;
                    contadorcolumnas = 1;
                }
                contadorcolumnas++;
            }
            
        }
        cout << endl;
        X++;
    }

    return C;
    
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

    MatrizB(fila, columna, RellenoCin);


    return 0;
}

