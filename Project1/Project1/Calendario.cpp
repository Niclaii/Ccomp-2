#include <iostream>
#include "Calendario.h"

using namespace std;

int main()
{
	int dia{ 0 }, mes{ 0 }, year{ 0 };

	cout << "ingresa la fecha que desees (dia) ";
	cin >> dia;

	cout << "ingresa la fecha que desees (mes) ";
	cin >> mes;

	cout << "ingresa la fecha que desees (anio) ";
	cin >> year;

	cout << dia<<" ";
	mesLetras(mes);
	cout <<" "<< year << " ";

	ImprimirCalendario(dia, mes, year);

	return 0;
}

