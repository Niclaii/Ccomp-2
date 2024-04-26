#include <iostream>
#include "CocktailSort.h"

using namespace std;



int main()
{

	int A[] = { 6,4,13,21,50,23,19,5,11,1,82,15,39,60,3,26,45,72}, cont{ 0 }, opcion{ 0 };
	int CE1{ 0 };
	bool Termino{ false }, salir{ false }, As{ false }, De{false};
	int* ptrI = A;
	int* ptrA = A + 1;
	int* ptrF = A+(sizeof(A) / sizeof(A[0]))-1;


	do 
	{
		cout << "Que desea Hacer? (1.Ordenar Ascendente/2.Ordenar Descendente/3.Busqueda Binaria(Es necesario hacer una ordenanza antes)/4.Salir) ";
		cin >> opcion;
		cout << "\n";
		Termino = false;

		if (opcion == 1)
		{
			
			do
			{
				//ORDEN ASCENDENTE

				cocktailAs(ptrI, ptrF, ptrA);


				if (cont == 4)
				{
					int* ptrI = A;
					int* ptrA = A + 1;
					int* ptrF = A + (sizeof(A) / sizeof(A[0])) - 1;
					cont = 0;
					Termino = true;
					As = true;
					De = false;
				}
				else
				{
					cont++;
					continue;
				}
				

			} while (Termino == false);
		}
		else if (opcion == 2)
		{
			do
			{
				//ORDEN DESCENDENTE

				cocktailDe(ptrI, ptrF, ptrA);


				if (cont == 6)
				{
					int* ptrI = A;
					int* ptrA = A + 1;
					int* ptrF = A + (sizeof(A) / sizeof(A[0])) - 1;
					cont = 0;
					Termino = true;
					As = false;
					De = true;
				}
				else
				{
					cont++;
					continue;
				}
				

			} while (Termino == false);
		}
		else if (opcion == 3)
		{
			
			if (As == true)
			{
				ptrI = A;
				cout << *ptrI << " \n";
				BusquedaBinariaAs(ptrI, ptrF, ptrA);
			}
			else if (De == true)
			{
				ptrI = A;
				BusquedaBinariaDe(ptrI, ptrF, ptrA);
			}
		}
		else if (opcion == 4)
		{
			break;
		}
		else
		{
			continue;
		}
		
		
	} while (salir==false);
	
	return 0;

};

