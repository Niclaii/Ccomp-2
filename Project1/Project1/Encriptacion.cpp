#include <iostream>
#include <fstream> 
#include <string>
#include "Encriptacion.h"
using namespace std;

int main() 
{  
    bool continuar{ true }, validacion{false},VI(false);
    int clave{ 0 },  opcion1{ 0 }, opcion2{0};
    static int modulo{ 256 };
    string texto;

    do
    {
        cout << "Que desea hacer? (1.Encriptar / 2.Desencriptar / 3.Salir): ";
        cin >> opcion1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcion1 == 1)
        {

            do
            {
                cout << "Ingrese el valor de la clave (debe tener inverso bajo modulo 95): ";
                cin >> clave;

                if (inverso_modular(clave, modulo) == -1)
                {
                    continue;
                }
                else
                {
                    int claveInversa = inverso_modular(clave, modulo);
                    cout << "El inverso modular de la clave es: " << claveInversa << endl;
                    VI = true;

                }
            } while (VI == false);
              
            ifstream archivoEntrada("texto.txt");
            /*string textoCifrado((istreambuf_iterator<char>(archivoEntrada)),
                istreambuf_iterator<char>());
            archivoEntrada.close();    
            */
            ofstream archivoSalida("textoCifrado.txt");
            string texto;
            


            if (archivoSalida.is_open())
            {
                if (archivoEntrada.is_open())
                {
                    string linea;
                    while (getline(archivoEntrada, linea))
                    {
                        texto += linea + "\n";
                    }

                    string TextoEncriptado = cifrarTexto(texto,clave,modulo);
                    texto == archivoSalida;

                    archivoSalida.close();
                    cout << "Texto cifrado guardado en 'textoCifrado.txt'.\n";
                }
               
            }
            else
            {
                cout << "No se pudo abrir el archivo para escribir.\n";
            }

        }
        else if (opcion1 == 2)
        {
            if (esArchivoVacio("texto.txt"))
            {
                cout << "El archivo 'textoCifrado.txt' está vacío o no existe." << endl;
            }
            else
            {
                ifstream archivoEntrada("textoCifrado.txt");
                string textoCifrado((istreambuf_iterator<char>(archivoEntrada)),
                    istreambuf_iterator<char>());
                archivoEntrada.close();

                cout << "Ingrese el valor de la clave usada para encriptar: ";
                cin >> clave;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                int claveInversa = inverso_modular(clave, modulo);
                if (claveInversa == -1)
                {
                    cout << "No se puede continuar sin un inverso modular válido." << endl;
                    continue;
                }

                string textoDescifrado = descifrarTexto(textoCifrado, claveInversa, modulo);
                cout << "Texto descifrado: " << textoDescifrado << "\n";
            }
        }

        cout << "Desea continuar? (1.Si / 2.No) \n";
        cin >> opcion2;

        do 
        {
            if (opcion2 == 1)
            {
                continuar = true;
                validacion = true;
                opcion1 = 0;
                clave = 0;
            }
            else if (opcion2 == 2)
            {
                continuar = false;
                validacion = true;
            }
            else
            {
                cout << "Ingrese una opcion valida\n";
            }
        } while (validacion == false);
       

    } while (continuar == true);
    

    return 0;
}
