#pragma once
#include <iostream>

using namespace std;

void mesLetras(int mes)
{
	string ML{""};
	if (mes == 1)
	{
		ML = "Enero";
	}
	else if (mes == 2)
	{
		ML = "Febrero";
	}
	else if (mes == 3)
	{
		ML = "Marzo";
	}
	else if (mes == 4)
	{
		ML = "Abril";
	}
	else if (mes == 5)
	{
		ML = "Mayo";
	}
	else if (mes == 6)
	{
		ML = "Junio";
	}
	else if (mes == 7)
	{
		ML = "Julio";
	}
	else if (mes == 8)
	{
		ML = "Agosto";
	}
	else if (mes == 9)
	{
		ML = "Septiembre";
	}
	else if (mes == 10)
	{
		ML = "Octubre";
	}
	else if (mes == 11)
	{
		ML = "Noviembre";
	}
	else if (mes == 12)
	{
		ML = "Diciembre";
	}
	return;
}

bool Bisiesto(int año)
{
	if (año % 4 != 0)
	{
		return false;
	}
	else if (año % 100 != 0)
	{
		return true;
	}
	else if (año % 400 != 0)
	{
		return false;
	}
	return true;
}

int CalcularDias(int mes, int año)
{
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	{
		return 31;
	}
	if (mes == 2)
	{
		if (Bisiesto(año) == true)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	return 30;
}

int ordenamiento(int año, int mes, int dia)
{
	int a = (14 - mes) / 12;
	int y = año - a;
	int m = mes + 12 * a - 2;

	int d = (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
	return d;
}


void ImprimirCalendario(int dia, int mes, int año)
{
	int cantdias = CalcularDias(mes, año);
	int x = ordenamiento(año, mes, 1);

	cout << "\nDom " << "Lun " << "Mar " << "Mie " << "Jue " << "Vie " << "Sab \n";

	for (int i = 0; i <= x; i++)
	{
		cout << "   ";
	}
	for (int i{ 1 }; i <= cantdias; i++)
	{
		if (i < 10)
		{
			cout << i << "   ";
		}
		else
		{
			cout << i << "  ";
		}
		x++;
		if (x % 7 == 0)
		{
			cout << "\n";
		}
	}
	cout << endl;
	return;
}