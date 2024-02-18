#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// Modular exponentiation
uint64_t modExp(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Miller-Rabin primality test
int isPrime(uint64_t n, int k) {
    // Handle basic cases
    if (n <= 1 || n == 4) {
        return 0; // Not prime
    }
    if (n <= 3) {
        return 1; // Prime
    }

    // Find d such that n-1 = 2^r * d
    uint64_t d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    // Witness loop
    for (int i = 0; i < k; ++i) {
        uint64_t a = 2 + rand() % (n - 4); // Random base between 2 and n-2

        // Compute a^d % n
        uint64_t x = modExp(a, d, n);

        if (x == 1 || x == n - 1) {
            continue; // Likely prime, try another witness
        }

        // Repeat squaring
        for (uint64_t r = 1; r < n - 1; r *= 2) {
            x = modExp(x, 2, n);
            if (x == 1) {
                return 0; // Composite
            }
            if (x == n - 1) {
                break; // Likely prime, try another witness
            }
        }

        if (x != n - 1) {
            return 0; // Composite
        }
    }

    return 1; // Likely prime
}

int main() {
    // Test the Miller-Rabin primality test with various values of 'n'
    uint64_t testValues[] = {2, 11, 13, 37, 97, 199, 563, 997, 9973};

    int k = 5; // Number of iterations for the Miller-Rabin test

    for (int i = 0; i < sizeof(testValues) / sizeof(testValues[0]); ++i) {
        uint64_t n = testValues[i];
        if (isPrime(n, k)) {
            printf("%llu is likely prime.\n", n);
        } else {
            printf("%llu is composite.\n", n);
        }
    }

    return 0;
}
