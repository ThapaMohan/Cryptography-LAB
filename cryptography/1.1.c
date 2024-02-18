#include <stdio.h>
#include <ctype.h>

void encrypt(char *plaintext, int shift);
void decrypt(char *ciphertext, int shift);

int main() {
    int shift;
    char message[1000];
    printf("\n");
    // Input shift value
    printf("Enter the shift value (between +/- 26): ");
    scanf("%d", &shift);

    // Input plaintext message
    printf("Enter the plaintext message: ");
    scanf(" %[^\n]s", message);

    // Encryption
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decryption
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *plaintext, int shift) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            plaintext[i] = (char)(((plaintext[i] - base + shift) % 26) + base);
        }
    }
}

void decrypt(char *ciphertext, int shift) {
    // Decryption is just encryption with a negative shift
    encrypt(ciphertext, -shift);
}
