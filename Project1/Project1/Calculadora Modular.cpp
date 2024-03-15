#include <iostream>
#include "Calculadora Modular.h"

using namespace std;

main()
{
	int opcion,a, b;

	cout << "Elija una de las siguientes opciones:\n1.Suma\n2.Resta\n3.Multiplicación\n4.Salir";
	cin >> opcion;

	do 
	{
		if (opcion == 1)
		{
			Suma(a, b);
		}
		else if (opcion == 2)
		{
			Resta(a, b);
		}
		else if (opcion == 3)
		{
			Multiplicacion(a, b);
		}
		else if (opcion == 4)
		{
			opcion = 0;
		}

	} while (opcion == 0);

	return 0;
}
