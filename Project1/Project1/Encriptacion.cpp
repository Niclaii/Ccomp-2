#include <iostream>
#include <fstream>
#include <string>
#include "Encriptacion.h"

using namespace std;

int main() 
{
    string texto;
    int clave{0};

    cout << "Ingrese el texto a cifrar: ";
    getline(cin, texto);

    cout << "Ingrese el digito para cifrar: ";
    cin >> clave;

    
       
    string textoCifrado = encriptar(texto, clave);
    cout << "Texto cifrado: " << textoCifrado << endl;
    
    string textoDescifrado = desencriptar(textoCifrado, clave);
    cout << "Texto descifrado: " << textoDescifrado << endl;
    
    return 0;
}
