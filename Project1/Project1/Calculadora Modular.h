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

int euclides_extendido(int a, int b, int& x) {
    if (b == 0) {
        x = 1;
        return a;
    }
    int x1;
    int gcd = euclides_extendido(b, a % b, x1);
    x = x1 - (a / b) * x1;
    return gcd;
}

int inverso_modular(int a, int b) {
    int x;
    int g = euclides_extendido(a, b, x);
    if (g != 1) {
        // Si g no es 1, entonces no existe inverso modular
        cout << "El inverso modular no existe." << endl;
        return -1;
    }
    else {
        int inverso = (x % b + b) % b;
        cout << "El inverso modular de " << a << " bajo modulo " << b << " es: " << inverso << endl;
        return inverso;
    }
}

