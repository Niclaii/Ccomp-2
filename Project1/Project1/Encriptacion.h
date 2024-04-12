#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

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

string cifrarTexto(const string& texto, int clave, int modulo)
{
    string textoCifrado;
    for (char c : texto) 
    {
        if (c >= 32 && c <= 126) 
        {
            int valor = c - 32;
            int cifrado = (valor * clave) % modulo;
            char caracterCifrado = cifrado + 32;
            textoCifrado += caracterCifrado;
        }
        else 
        {
            textoCifrado += c;
        }
    }
    return textoCifrado;
}

string descifrarTexto(const string& textoCifrado, int claveInversa, int modulo) {
    return cifrarTexto(textoCifrado, claveInversa, modulo);
}

bool esArchivoVacio(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ifstream::ate | ifstream::binary);
    return archivo.is_open() && archivo.tellg() == 0;
}