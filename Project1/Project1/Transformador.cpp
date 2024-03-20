#include <iostream>
#include "Transformador.h"

using namespace std;
 
int opcion{0}, numero{0}, contadorI{0}, contadorV{0}, contadorX{0}, contadorL{0}, contadorC{0}, contadorD{0}, contadorM{0}, contador_V{0}, contador_X{0};
bool terminar{ false };



int main()
{
	do
	{
		cout << "ingrese un numero del 1 al 9999:";
		cin >> numero;

		PonerContador(numero, contadorI, contadorV, contadorX, contadorL, contadorC, contadorD, contadorM, contador_V, contador_X);
		CantidadDeLetras(contadorI, contadorV, contadorX, contadorL, contadorC, contadorD, contadorM, contador_V, contador_X);


		cout << "\nDesea continuar?(1.Si/2.No)";
		cin >> opcion;
		if (opcion == 1)
		{
			terminar = false;
		}
		else if (opcion == 2)
		{
			terminar = true;
		}



	} while (terminar==false);
	

	return 0;
}
