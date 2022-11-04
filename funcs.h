#pragma once

// add prototypes here
void testAscii(std::string asciiLine);
std::string encryptCaesar(std::string asciiLine, int shiftVal);
std::string encryptVigenere(std::string plaintext, std::string keyword);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);