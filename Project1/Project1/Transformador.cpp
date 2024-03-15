#include <iostream>
#include "Transformador.h"
using namespace std;
 
int numero, contadorI, contadorV, contadorX, contadorL, contadorC, contadorD, contadorM;

int main()
{
	cout << "ingrese un numero del 1 al 9999:";
	cin >> numero;

	for (int i=0; numero > 1000; i++)
	{

		numero - 1000;
		contadorM++;

	};
	for (int i = 0; numero > 500; i++)
	{
		numero - 500;
		contadorD++;
	};
	for (int i = 0; numero > 100; i++)
	{
		numero - 500;
		contadorC++;
	};
	for (int i = 0; numero > 50; i++)
	{
		numero - 50;
		contadorL++;
	};
	for (int i = 0; numero > 10; i++)
	{
		numero - 10;
		contadorX++;
	};
	for (int i = 0; numero > 5; i++)
	{
		numero - 5;
		contadorV++;
	};
	for (int i = 0; numero > 1; i++)
	{
		numero - 1;
		contadorI++;
	};

	CantidadDeLetras(contadorI, contadorV, contadorX, contadorL, contadorC, contadorD, contadorM);








	return 0;
}
