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
    //int a{ 0 };
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
    int contador{ 0 };  
    bool PV{ true };

    for (int** p = C, **pB = B, **pA = A; p < C + fila; p++)
    {
        *p = new int[columna];
        
        for (int* q = *p ; q < *p + columna; q++)
        {
            *q = 0;
            for (int k = 0; k < columna; k++)
            {
                
                *q += (**pA) * (**pB);
                (*pA)++;
                if (PV == true)
                {
                    *pB++;
                    PV = false;
                }
                else 
                {
                    *pB++;
                }
                contador++;
                
                if(contador==columna)
                {
                    (*pA)-=columna;
                    pB = B;
                    *pB--;
                    contador = 0;
                    PV = true;
                }            
            }   
            cout << *q << " ";
        }
        cout << endl;
    }

    return C;
    
}
/*
int** MatrizC(int fila, int columna, int (*alternativa)())
{
    int** A = MatrizB(fila, columna, alternativa);
    int** B = MatrizB(fila, columna, alternativa);
    int** C = new int* [fila];
    cout << "Matriz C (A * B):" << endl;

    for (int** p = C, **p2 = B, **p3 = A; p < C + fila; p++)
    {
        *p = new int[columna];
        int* q = *p;
        for (int* q2 = *p2, *q3 = *p3; q < *p + columna;)
        {
            *q += *q2 + *q3;
        }
        q++;
        cout << endl;
    }
    return C;
}*/
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
    /*
    if (alternativa == 1)
    {
        Funcion1(fila, columna,RellenoCin);
    }
    else if (alternativa == 2)
    {
        Funcion1(fila, columna,RellenoCero);
    }*/
    //MatrizA(fila, columna, RellenoCin);
    MatrizB(fila, columna, RellenoCin);


    return 0;
}