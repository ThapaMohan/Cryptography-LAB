#include <stdio.h>
#include <stdint.h>
 
// Function to perform the key scheduling and generate subkeys
void generateSubkeys(uint16_t* key, uint16_t subkeys[8][6]) {
    int round, subkey;
    uint16_t temp, Z[52];
 
    // Initialize Z values
    for (round = 0, subkey = 0; round < 8; round++) {
        for (subkey = 0; subkey < 6; subkey++) {
            Z[round * 6 + subkey] = *key;
            key++;
        }
    }
    // Generate subkeys
    for (round = 0; round < 8; round++) {
        for (subkey = 0; subkey < 6; subkey++) {
            subkeys[round][subkey] = Z[(round + subkey) % 8 * 6 + (subkey + 1) % 6];
        }
    }
}
int main() {
    uint16_t mainKey[8] = {0x1001, 0x2345, 0x6789, 0xabcd, 0xef01, 0x2345, 0x6789, 0xabcd};
    uint16_t subkeys[8][6];
    generateSubkeys(mainKey, subkeys);
  printf("Mohan Thapa Mashrangi\n");
    // Display the generated subkeys
    printf("Generated Subkeys:\n");
    for (int round = 0; round < 8; round++) {
        printf("Round %d: ", round + 1);
        for (int subkey = 0; subkey < 6; subkey++) {
            printf("%04X ", subkeys[round][subkey]);
        }
        printf("\n");
    }
    return 0;
}
