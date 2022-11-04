#include <iostream>
#include <cctype>

#include "funcs.h"

int main()
{
  std::cout << "Task A: " << std::endl;
  testAscii("Cat :3 Dog");

  std::cout << "\nTask B: " << std::endl;
  std::cout << "Enter plaintext: Hello, World!" << std::endl;
  std::cout << "Enter shift    : 10" << std::endl;
  std::string encryptCae = encryptCaesar("Hello, World!", 10);
  std::cout << "Ciphertext     : " << encryptCae << std::endl; 

  std::cout << "\nTask C: " << std::endl;
  std::cout << "Enter plaintext: Hello, World!" << std::endl;
  std::cout << "Enter keyword    : cake" << std::endl;
  std::string encryptVig = encryptVigenere("Hello, World!", "cake");
  std::cout << "Ciphertext     : " << encryptVig << std::endl; 

  std::cout << "\nTask D: " << std::endl;
  std::cout << "= Caesar =" << std::endl;
  std::cout << "Enter shift    : 10" << std::endl;
  std::cout << "Ciphertext     : Rovvy, Gybvn!" << std::endl;
  std::cout << "Decrypted      : ";
  std::string decryptCae = decryptCaesar("Rovvy, Gybvn!", 10);
  std::cout << decryptCae << std::endl; 
  std::cout << "\n= Vigenere = "<< std::endl;
  std::cout << "Enter keyword  : cake" << std::endl;
  std::cout << "Ciphertext     : Jevpq, Wyvnd!" << std::endl;
  std::cout << "Decrypted      : ";
  std::string decryptVig = decryptVigenere("Jevpq, Wyvnd!", "cake");
  std::cout << decryptVig << std::endl; 
  return 0;
}
