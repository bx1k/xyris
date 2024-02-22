#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define AES block size
#define AES_BLOCK_SIZE 16

// Sample key (128-bit key)
uint8_t key[AES_BLOCK_SIZE] = {
    0x2b, 0x7e, 0x15, 0x16,
    0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x97, 0x56,
    0x46, 0x4d, 0x8e, 0x7f
};

// Simple XOR encryption function
void encryptAES(uint8_t *input, uint8_t *output, uint8_t *key) {
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i];
    }
}

int main() {
    FILE *inFile = fopen("data.txt", "rb");
    FILE *outFile = fopen("encrypted.bx1", "wb");

    if (inFile == NULL || outFile == NULL) {
        perror("Error opening files");
        return 1;
    }

    uint8_t input[AES_BLOCK_SIZE];
    uint8_t output[AES_BLOCK_SIZE];

    // Read the input file in blocks and encrypt each block
    size_t bytesRead;
    while ((bytesRead = fread(input, 1, AES_BLOCK_SIZE, inFile)) > 0) {
        // Pad the input if necessary
        if (bytesRead < AES_BLOCK_SIZE) {
            memset(input + bytesRead, AES_BLOCK_SIZE - bytesRead, AES_BLOCK_SIZE - bytesRead);
        }
        
        // Encrypt the block
        encryptAES(input, output, key);
        
        // Write the encrypted block to the output file
        fwrite(output, 1, AES_BLOCK_SIZE, outFile);
    }

    fclose(inFile);
    fclose(outFile);

    printf("Encryption complete.\n");

    return 0;
}




// the AES encryption works fine