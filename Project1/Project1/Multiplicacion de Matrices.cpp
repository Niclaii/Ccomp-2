#include <iostream>

using namespace std;


void Imprimir_matrices(int A[3][3][3])
{
	int(*ptr3D)[3][3] = A;
	int(*ptr2D)[3] = *ptr3D;
	int(*ptr1D) = *ptr2D;

	for (; ptr3D < A + 3; ptr3D++)
	{
		for (; ptr2D < *(ptr3D + 1); ptr2D++)
		{
			for (; ptr1D < *(ptr2D + 1); ptr1D++)
			{
				cout << *ptr1D << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "-------------------------" << endl;
}

int Operacion(int A[3][3][3],int columna,int fila)
{
	int sumador{ 0 }, multiplicador{ 0 };
	
	int(*ptr3D)[3][3] = A;
	int(*ptr2D)[3] = *ptr3D;
	int(*ptr1D) = *ptr2D;
	
	for (; ptr2D < *(ptr3D + 1); ptr2D++)
	{
			multiplicador = *(*(ptr2D + 3)+columna);
			multiplicador = multiplicador * (*(ptr1D+fila));			
			sumador = multiplicador + sumador;
			ptr1D++;	
	}
	return sumador;
}


void Establecer_matriz(int A[3][3][3])
{
	int* ptrF = **(A + 2);

	for (int i{ 0 }, j{ 0 }, h{ 0 }; i < 9; i++, j++)
	{
		if (i % 3 == 0 && i != 1 && i != 0)
		{
			h += 3;
		}
		if (h == 9)
		{
			h = 0;
		}
		if (j == 3)
		{
			j = 0;
		}
		int a = Operacion(A, j, h);

		*ptrF = a;
		ptrF++;
	}
}

int main()
{
	int A[3][3][3] = { {{1,2,3},{4,5,6},{7,8,9}} ,{ { 10,11,12 },{13,14,15},{ 16,17,18 } },{{0,0,0},{0,0,0},{ 0,0,0 }} };
		
	Imprimir_matrices(A);
	Establecer_matriz(A);
	Imprimir_matrices(A);
	return 0;
}