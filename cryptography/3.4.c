#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int modulo(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generateRandomPrime() {
    int prime;
    do {
        prime = rand() % 100 + 50;  // Generate a random number between 50 and 150
    } while (!isPrime(prime));
    return prime;
}

int generatePublicKey(int phi) {
    int e;
    do {
        e = rand() % (phi - 2) + 2;  // Generate a random number between 2 and phi-1
    } while (gcd(e, phi) != 1);
    return e;
}

int generatePrivateKey(int e, int phi) {
    int d = 1;
    while ((e * d) % phi != 1) {
        d++;
    }
    return d;
}

int main() {
    srand(time(NULL));

    int p, q, n, phi, e, d, message;
    printf("Enter two prime numbers (p and q): ");
    scanf("%d%d", &p, &q);

    if (!isPrime(p) || !isPrime(q)) {
        printf("Both numbers must be prime.\n");
        return 1;
    }

    n = p * q;
    phi = (p - 1) * (q - 1);

    e = generatePublicKey(phi);
    d = generatePrivateKey(e, phi);

    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);

    printf("Enter the message: ");
    scanf("%d", &message);

    int cipher = modulo(message, e, n);
    printf("Encrypted message: %d\n", cipher);

    int decrypted = modulo(cipher, d, n);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}
