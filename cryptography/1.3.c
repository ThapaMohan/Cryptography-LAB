#include <stdio.h>
#include <string.h>

void railFenceEncrypt(char *message, int depth) {
    int len = strlen(message);
    char rail1[len], rail2[len], rail3[len];
    int rail1Index = 0, rail2Index = 0, rail3Index = 0;

    for (int i = 0; i < len; ++i) {
        if (i % (2 * (depth - 1)) == 0) {
            rail1[rail1Index++] = message[i];
        } else if (i % (depth - 1) == 0) {
            rail2[rail2Index++] = message[i];
        } else {
            rail3[rail3Index++] = message[i];
        }
    }

    rail1[rail1Index] = rail2[rail2Index] = rail3[rail3Index] = '\0';

    printf("Rail1: %s\n", rail1);
    printf("Rail2: %s\n", rail2);
    printf("Rail3: %s\n", rail3);
}

int main() {
    char message[] = "I love my college";
    int depth = 3;
    printf("Mohan Thapa Mashrangi\n");
    // Encryption
    railFenceEncrypt(message, depth);

    return 0;
}
