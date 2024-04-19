/* ******************
  Clase: Ciencia de la Computación II
  Alumna: Andrea Pozo Chocano
  Programa: Calculadora Modular
  (suma, resta, multiplicacion, inversa)
  NOTA: SOLO SIRVE CON NUMEROS POSITIVOS
****************** */

#include <iostream>
using namespace std;

int modulo(int num, int mod) {
    return num % mod;
};

int mcd(int numa, int numb) {
    int res;
    while (res != 0) {
        res = numb;
        numb = numa % numb;
        numa = res;
    }
    return res;
}

int suma(int numa, int numb, int mod) {
    return modulo(numa + numb, mod);
};

int resta(int numa, int numb, int mod) {
    return modulo(numa - numb, mod);
};

int multiplica(int numa, int numb, int mod) {
    return modulo(numa * numb, mod);
};

int inversa(int num, int mod) {
    if (mcd(num, mod) != 0) {
        return 0;
    }
    else
        for (int i = 0; i < mod; i++) {
            if ((num * i - 1) % mod == 0)
            {
                return i;
            }
        }
}


void hacesuma() {
    int a, b, c;
    cout << "Introduce el operador 1: ";
    cin >> a;
    cout << "Introduce el operador 2: ";
    cin >> b;
    cout << "Introduce el módulo    : ";
    cin >> c;
    cout << "resultado de suma      : " << suma(a, b, c) << "\n";
    cout << endl;
}

void haceresta() {
    int a, b, c;
    cout << "Introduce el operador 1: ";
    cin >> a;
    cout << "Introduce el operador 2: ";
    cin >> b;
    cout << "Introduce el módulo    : ";
    cin >> c;
    cout << "resultado de resta     : " << resta(a, b, c) << "\n";
    cout << endl;
}

void hacemultiplica() {
    int a, b, c;
    cout << "Introduce el operador 1: ";
    cin >> a;
    cout << "Introduce el operador 2: ";
    cin >> b;
    cout << "Introduce el módulo    : ";
    cin >> c;
    cout << "resultado de multiplica: " << multiplica(a, b, c) << "\n";
    cout << endl;
}

void haceinversa() {
    int a, c; //a o b son operandos, c siempre es modulo
    cout << "Introduce el operador  : ";
    cin >> a;
    cout << "Introduce el módulo    : ";
    cin >> c;
    cout << "resultado de inversa   : " << inversa(a, c) << "\n";
    cout << endl;
}

int main() {
    int opc;
    while (opc != 0) {
        cout << " CALCULADORA MODULAR " << '\n';
        cout << "   1. Suma " << '\n';
        cout << "   2. Resta " << '\n';
        cout << "   3. Multiplica " << '\n';
        cout << "   4. Inversa " << '\n';
        cout << "   0. SALIR " << '\n';
        cin >> opc;
        switch (opc) {
        case 1:
            hacesuma();
            break;
        case 2:
            haceresta();
            break;
        case 3:
            hacemultiplica();
            break;
        case 4:
            haceinversa();
            break;
        default:
            break;
        }
    }
}