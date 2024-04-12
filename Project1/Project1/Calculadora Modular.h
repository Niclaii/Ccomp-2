#pragma once
#include <iostream>

using namespace std;

void Suma(int a , int b)
{
	int sum{ 0 }, rpta{ 0 };
	cout << "ingrese el valor a sumar:";
	cin >> sum;

	sum = sum + a;

	rpta = sum % b;
	cout << sum << " mod " << b << " = " << rpta;

}
void Resta(int a, int b)
{
	int res{ 0 }, rpta{ 0 };
	cout << "ingrese el valor a restar:";
	cin >> res;

	res = a - res;
	
	rpta = res % b;
	cout << res << " mod " << b << " = " << rpta;

}
void Multiplicacion(int a, int b)
{
	int mul{ 0 }, rpta{ 0 };
	cout << "ingrese el valor a multiplicar:";
	cin >> mul;

	mul = a * mul;

	rpta = mul % b;
	cout << mul << " mod " << b << " = " << rpta;

}

int inverso_modular(int a, int modulo)
{
	int inverso = 1;
	while ((a * inverso) % modulo != 1)
	{
		inverso++;
		if (inverso > modulo)
		{
			return -1;
		}
	}
	return inverso;
}

