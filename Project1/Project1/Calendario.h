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

void ImprimirCalendario(int dia,int mes,int año)
{
	int a{ 1 }, x[31];

	cout << "\nDom " << "Lun " << "Mar " << "Mie " << "Jue " << "Vie " << "Sab \n";



	for (int i{ 1 }; i < 31; i++)
	{



	}
	return;
}

int CalcularDias(int mes, int a)
{
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
	{

	}
}