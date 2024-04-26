#include <iostream>

int main() {
    int n, t0 = 0, t1 = 1, t2;

    std::cout << "Ingrese el número de términos para la secuencia Fibonacci: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Por favor, ingrese un número mayor que cero." << std::endl;
        return 0;
    }

    std::cout << "La serie Fibonacci de " << n << " términos es: ";

    if (n == 1) {
        std::cout << t0 << std::endl;
        return 0;
    }

    std::cout << t0 << ", " << t1;

    for (int i = 2; i < n; ++i) {
        t2 = t0 + t1;
        std::cout << ", " << t2;
        t0 = t1;
        t1 = t2;
    }

    std::cout << std::endl;
    return 0;
}
