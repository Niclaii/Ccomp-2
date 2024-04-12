#include <iostream>
#include "Calculadora Modular.h"

using namespace std;

int main()
{
	int opcion{ 0 }, opcion2, a{ 0 }, b{ 0 };
	bool continuar{ true },VI{ false };

	do
	{
		cout << "Elija una de las siguientes opciones:\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Inversa\n5.Salir\n";
		cin >> opcion;

		if (opcion == 1)
		{
			cout << "Ingrese el valor para a ( a mod b )";
			cin >> a;
			cout << "Ingrese el valor para b ( a mod b )";
			cin >> b;

			Suma(a, b);
		}
		else if (opcion == 2)
		{
			cout << "Ingrese el valor para a ( a mod b )";
			cin >> a;
			cout << "Ingrese el valor para b ( a mod b )";
			cin >> b;

			Resta(a, b);
		}
		else if (opcion == 3)
		{
			cout << "Ingrese el valor para a ( a mod b )";
			cin >> a;
			cout << "Ingrese el valor para b ( a mod b )";
			cin >> b;

			Multiplicacion(a, b);
		}
		else if (opcion == 4)
		{
			
			cout << "Ingrese el valor para a ( a mod b )";
			cin >> a;
			cout << "Ingrese el valor para b ( a mod b )";
			cin >> b;

			do
			{
				if (inverso_modular(a, b) == -1)
				{
					cout << "Ingrese el valor para a ( a mod b ) porque no tiene inversa ";
					cin >> a;
					continue;
				}
				else
				{
					cout << "El inverso modular  es: " << inverso_modular(a,b) << endl;
					VI = true;
				}
			} while (VI == false);
			
		}
		else if (opcion == 5)
		{
			break;
		}

		cout << "\nDesea continuar?(1.Si/2.No)";
		cin >> opcion2;

		if (opcion2 == 1)
		{
			continuar = true;
		}
		else if (opcion2 == 2)
		{
			continuar = false;
		}

	} while (continuar == true);

	return 0;
}
