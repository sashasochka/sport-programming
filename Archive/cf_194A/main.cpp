#include <iostream>

int main() {
    long n;
    std::cin >> n;
    while (n % 3 == 0) n /= 3;

    std::cout << n / 3 + 1;
}

