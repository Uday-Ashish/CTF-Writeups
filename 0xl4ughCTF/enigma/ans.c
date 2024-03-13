#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Enigma machine structure
struct EnigmaMachine {
    char plugboard[ALPHABET_SIZE];
    char rotors[3][ALPHABET_SIZE];
    char rings[3];
    char indicator[3];
};

// Function to initialize the Enigma machine with the provided key settings
void initializeEnigma(struct EnigmaMachine *machine, char *indicator, char *rotors, char *rings, char *plugboard) {
    strcpy(machine->indicator, indicator);
    strcpy(machine->rings, rings);
    strcpy(machine->plugboard, plugboard);

    for (int i = 0; i < 3; i++) {
        int rotorIndex = rotors[i] - '1';
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            machine->rotors[i][j] = 'A' + (j + rotorIndex) % ALPHABET_SIZE;
        }
    }
}

// Function to encrypt/decrypt a character through the Enigma machine
char processChar(struct EnigmaMachine *machine, char c) {
    // Step 1: Pass through the plugboard
    if (c >= 'A' && c <= 'Z') {
        c = machine->plugboard[c - 'A'];
    }

    // Step 2: Pass through the rotors from right to left
    for (int i = 2; i >= 0; i--) {
        int inputIndex = c - 'A';
        int outputIndex = machine->rotors[i][inputIndex] - 'A';
        c = 'A' + outputIndex;
    }

    // Step 3: Pass through the reflector (currently set to B)
    c = 'A' + (c - 'A' + 13) % ALPHABET_SIZE;

    // Step 4: Pass through the rotors from left to right
    for (int i = 0; i < 3; i++) {
        int inputIndex = c - 'A';
        int outputIndex;
        for (outputIndex = 0; outputIndex < ALPHABET_SIZE; outputIndex++) {
            if (machine->rotors[i][outputIndex] == c) {
                break;
            }
        }
        c = 'A' + outputIndex;
    }

    // Step 5: Pass through the plugboard again
    if (c >= 'A' && c <= 'Z') {
        c = machine->plugboard[c - 'A'];
    }

    return c;
}

// Function to decrypt the provided ciphertext
void decryptCiphertext(struct EnigmaMachine *machine, char *ciphertext, char *decryptedText) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        decryptedText[i] = processChar(machine, ciphertext[i]);
    }
    decryptedText[length] = '\0';
}

int main() {
    // Enigma key settings
    char indicator[] = "KEU";
    char rotors[] = "243";
    char rings[] = "AAP";
    char plugboard[] = "AY";

    // Ciphertext to decrypt
    char ciphertext[] = "XTKOFZFRIFWLOESVNSAGZYUJHTXSOHSMHQLNWYGEFVNXNQOMSGJSIEKEQZGPRBQUIJMHIPOVQKOYDOBIFWCIQBJFREQFWTLRXITPTYMUDJWKLWTLWIIZHYOENRGPLBYWKBBEZFHFETJALRFJJNLLEJWWPQDDUEHTNITAIWHYGUPSRZZAPYGLPHCBKFMMQV";

    // Initialize the Enigma machine
    struct EnigmaMachine enigma;
    initializeEnigma(&enigma, indicator, rotors, rings, plugboard);

    // Decrypt the ciphertext
    char decryptedText[sizeof(ciphertext)];
    decryptCiphertext(&enigma, ciphertext, decryptedText);

    // Print the decrypted text
    printf("Decrypted Text: %s\n", decryptedText);

    return 0;
}
