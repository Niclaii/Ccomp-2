#include <iostream>
#include <bitset>
#include <cmath>

// Función para descomponer el número en punto flotante y obtener el signo, exponente y mantisa
void descomponer(float valor, uint32_t& signo, uint32_t& exponente, uint32_t& mantisa) {
    uint32_t bits = *reinterpret_cast<uint32_t*>(&valor);
    signo = (bits >> 31) & 1;
    exponente = (bits >> 23) & 0xFF;
    mantisa = bits & 0x7FFFFF;
    if (exponente != 0) { // Si no es un número denormal
        mantisa |= 0x800000; // Añadir el bit implícito
    }
}

// Función para recomponer el número de punto flotante a partir del signo, exponente y mantisa
float recomponer(uint32_t signo, uint32_t exponente, uint32_t mantisa) {
    uint32_t bits = (signo << 31) | ((exponente & 0xFF) << 23) | (mantisa & 0x7FFFFF);
    return *reinterpret_cast<float*>(&bits);
}

// Función para multiplicar dos números en punto flotante
float multiplicar(float a, float b) {
    uint32_t signoA, exponenteA, mantisaA;
    uint32_t signoB, exponenteB, mantisaB;

    descomponer(a, signoA, exponenteA, mantisaA);
    descomponer(b, signoB, exponenteB, mantisaB);

    // Verificación de cero
    if (a == 0 || b == 0) return 0.0;

    // Cálculo del signo del resultado
    uint32_t signoResultado = signoA ^ signoB;

    // Suma de exponentes ajustada por el bias
    int32_t exponenteResultado = (int32_t)exponenteA + (int32_t)exponenteB - 127;

    // Multiplicación de mantisas
    uint64_t mantisaResultado = (uint64_t)mantisaA * (uint64_t)mantisaB;
    mantisaResultado >>= 23; // Normalización

    // Ajuste si hay overflow en la mantisa
    if (mantisaResultado >= (1 << 24)) {
        mantisaResultado >>= 1;
        exponenteResultado++;
    }

    // Componer y retornar el resultado
    return recomponer(signoResultado, exponenteResultado, mantisaResultado);
}

int main() {
    float a, b;
    std::cout << "Ingrese dos valores en punto flotante: ";
    std::cin >> a >> b;
    float resultado = multiplicar(a, b);
    float esperado = a * b;

    std::cout << "Resultado emulado: " << resultado << "\n";
    std::cout << "Resultado esperado: " << esperado << "\n";
    return 0;
}
