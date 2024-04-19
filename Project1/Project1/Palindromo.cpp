#include <iostream>
#include <cctype>  // Necesario para las funciones tolower y isalpha

using namespace std;

bool Palindromo(const char* c) {
    const char* P = c;
    while (*P) P++;  
    P--;             

    while (c < P) {
        while (*c && !isalpha(*c)) c++;  
        while (*P && !isalpha(*P)) P--;  

        if (tolower(*c) != tolower(*P)) return false;  

        c++;          P--;  
    }
    return true; 
}

int main() {
    char a[100] = "Anita lava la tina";

    if (Palindromo(a)) {
        cout << "Es palíndromo ";
    }
    else {
        cout << "No es palíndromo ";
    }

    return 0;
}
