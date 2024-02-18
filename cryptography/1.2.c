#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenereEncrypt(char *message, char *key) {
    int keyLen = strlen(key);
    int i;

    for (i = 0; *message != '\0'; ++message, ++i) {
        if (isalpha(*message)) {
            char base = isupper(*message) ? 'A' : 'a';
            char keyChar = toupper(key[i % keyLen]);
            *message = ((*message - base + keyChar - 'A') % 26) + base;
        }
    }
}

int main() {
    char key[100];
    char message[100];
    printf("Mohan Thapa Mashrangi\n");
    // Input
    printf("Enter the Vigenere cipher key: ");
    scanf("%s", key);
    printf("Enter the plaintext message: ");
    scanf(" %[^\n]s", message);

    // Encryption
    vigenereEncrypt(message, key);
    printf("Vigenere Cipher: %s\n", message);

    return 0;
}
