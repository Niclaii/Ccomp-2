#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Funciones básicas para encriptar y desencriptar
string encriptar(string texto, int clave) {
    string resultado = "";
    for (char c : texto)
    {
        // Desplazar dentro del rango imprimible de ASCII (32 a 126)
        int desplazado = ((c - 32 + clave) % 95) + 32; // Asegura que sea imprimible
        resultado += char(desplazado);
    }
    return resultado;
}

string desencriptar(string textoCifrado, int clave) {
    string resultado = "";
    for (char c : textoCifrado)
    {
        // Invertir el desplazamiento dentro del mismo rango
        int desplazado = ((c - 32 - clave + 95) % 95) + 32; // Ajuste para negativos
        resultado += char(desplazado);
    }
    return resultado;
}

int euclides_extendido(int a, int b, int& x) {
    if (b == 0) 
    {
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
    if (g != 1) 
    {
        return -1;
    }
    else 
    {
        int inverso = (x % b + b) % b;
        cout << "El inverso modular de " << a << " bajo modulo " << b << " es: " << inverso << endl;
        return inverso;
    }
}
