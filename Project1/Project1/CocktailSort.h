#pragma once
#include <iostream>

using namespace std;

void cocktailAs(int* ptrI, int* ptrF, int* ptrA)
{
	int* temp = ptrI;
	int* tempF = ptrF;
	for (; ptrA <= ptrF; ptrA++)
	{

		if (*ptrI > *ptrA)
		{
			int tmp{ 0 };
			tmp = *ptrI;
			*ptrI = *ptrA;
			*ptrA = tmp;

			ptrI++;
		}
		else
		{
			ptrI++;
			continue;
		}


	}
	ptrA = ptrF - 1;
	ptrI = temp;
	ptrF = tempF;
	
	for (; ptrI < ptrF; ptrF--)
	{
		if (*ptrF < *ptrA)
		{
			int tmp{ 0 };
			tmp = *ptrF;
			*ptrF = *ptrA;
			*ptrA = tmp;

			ptrA--;
		}
		else
		{

			ptrA--;
			continue;
		}


	}

	ptrI = temp;
	ptrF = tempF;
	for (; ptrI <= ptrF; ptrI++)
	{

		cout << *ptrI << " ";
	}
	cout << "\n";


}

void cocktailDe(int* ptrI, int* ptrF, int* ptrA)
{
	int* temp = ptrI;
	int* tempF = ptrF;
	for (; ptrA <= ptrF; ptrA++)
	{

		if (*ptrI < *ptrA)
		{
			int tmp{ 0 };
			tmp = *ptrI;
			*ptrI = *ptrA;
			*ptrA = tmp;

			ptrI++;
		}
		else
		{
			ptrI++;
			continue;
		}


	}
	ptrA = ptrF - 1;
	ptrI = temp;
	ptrF = tempF;

	for (; ptrI < ptrF; ptrF--)
	{
		if (*ptrF > *ptrA)
		{
			int tmp{ 0 };
			tmp = *ptrF;
			*ptrF = *ptrA;
			*ptrA = tmp;

			ptrA--;
		}
		else
		{

			ptrA--;
			continue;
		}


	}

	ptrI = temp;
	ptrF = tempF;
	for (; ptrI <= ptrF; ptrI++)
	{

		cout << *ptrI << " ";
	}
	cout << "\n";

}

void BusquedaBinariaAs(int* ptrI, int* ptrF, int* ptrA)
{
	int* temp{ ptrI };
	int CE{ 0 }, num{ 0 };

	cout << "Ingrese el numero a buscar: ";
	cin >> num;

	for (; temp <= ptrF; temp++)
	{
		CE++;
	}
	ptrA = ptrF - (CE / 2);
	CE = 0;

	while (true)
	{
		if (*ptrA == num)
		{
			cout << "\nSe encontro el numero: " << num << "\n";
			break;
		}
		else if (*ptrA == *ptrF || *ptrA == *ptrI)
		{
			cout << "\nEl numero no se ha encontrado. \n";
			break;
		}
		else if (*ptrA > num)
		{
			ptrF = ptrA - 1;

			CE = 0;
			
			for (; temp <= ptrF; temp++)
			{
				CE++;

			}

			ptrA = ptrF - (CE / 2);
			int* temp = ptrI;
		}
		else if (*ptrA < num)
		{
			ptrI = ptrA + 1;

			CE = 0;
			for (; temp <= ptrF; temp++)
			{
				CE++;

			}
			ptrA = ptrI + (CE / 2);
			int* temp = ptrI;
		}
	}
}

void BusquedaBinariaDe(int* ptrI, int* ptrF, int* ptrA)
{
	int* temp = ptrI;
	int CE{ 0 }, num{ 0 };

	cout << "Ingrese el numero a buscar: ";
	cin >> num;

	for (; temp <= ptrF; temp++)
	{
		CE++;
	}
	ptrA = ptrF - (CE / 2);
	CE = 0;

	while (true)
	{
		if (*ptrA == num)
		{
			cout << "\nSe encontro el numero: " << num << "\n";
			break;
		}
		else if (*ptrA == *ptrF || *ptrA == *ptrI)
		{
			cout << "\nEl numero no se ha encontrado. \n";
			break;
		}
		else if (*ptrA < num)
		{
			ptrF = ptrA - 1;

			CE = 0;
			for (; ptrI <= ptrF; ptrI++)
			{
				CE++;

			}

			ptrA = ptrF - (CE / 2);
			int* temp = ptrI;
		}
		else if (*ptrA > num)
		{
			ptrI = ptrA + 1;

			CE = 0;
			for (; temp <= ptrF; temp++)
			{
				CE++;

			}
			ptrA = ptrI + (CE / 2);
			int* temp = ptrI;
		}	
	}
}


