#include <iostream>
#include <cctype>
#include "funcs.h"

// add functions here
void testAscii(std::string asciiLine){
    std::string userLine;
    userLine = asciiLine;
    std::cout << "Input: " << asciiLine << "\n" << std::endl;
    for(int i = 0; i < asciiLine.size(); i++){
        int convert = (int)userLine[i];
        std::cout << userLine.substr(i, 1) << " " << convert << std::endl;
    }
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string userLine = plaintext;
    std::string returnVal;
    for(int i = 0; i < plaintext.size(); i++){
        bool isAlp = isalpha(userLine[i]);
        int convert;
        if(isAlp == true){
            convert = userLine[i] + rshift;
            if((int)userLine[i] >= 65 && (int)userLine[i]<= 90){//Uppercase
                if(convert > 90){
                    convert = convert - 90 + 64;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }

            }else if((int)userLine[i] >= 97 && (int)userLine[i]<= 122){//Lowercase
                if(convert > 122){
                    convert = convert - 122 + 96;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }
            }

        }else{
            returnVal += userLine.substr(i, 1);
        }
    }
    return returnVal;
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
    std::string userLine = plaintext;
    std::string returnVal;
    int max = keyword.size();
    int keyCount = 0;
    int keywordNum;
    for(int i = 0; i < plaintext.size(); i++){
        bool isAlp = isalpha(userLine[i]);
        int convert;
        if(isAlp == true){
            if(keyCount >= keyword.size()){
                keyCount = 0;
            }
            if((int)userLine[i] >= 65 && (int)userLine[i]<= 90){//Uppercase
                keywordNum = keyword[keyCount] - 97;
                keyCount++;
                convert = userLine[i] + keywordNum;
                if(convert > 90){
                    convert = convert - 90 + 64;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }

            }else if((int)userLine[i] >= 97 && (int)userLine[i]<= 122){//Lowercase
                if(keyCount >= keyword.size()){
                    keyCount = 0;
                }
                keywordNum = keyword[keyCount] - 97;
                keyCount++;
                convert = userLine[i] + keywordNum;
                if(convert > 122){
                    convert = convert - 122 + 96;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }
            }
        }else{
            returnVal += userLine.substr(i, 1);
        }
    }
    return returnVal;
}

std::string decryptCaesar(std::string ciphertext, int rshift){
    std::string userLine = ciphertext;
    std::string returnVal;
    for(int i = 0; i < ciphertext.size(); i++){
        bool isAlp = isalpha(userLine[i]);
        int convert;
        if(isAlp == true){
            convert = userLine[i] - rshift;
            if((int)userLine[i] >= 65 && (int)userLine[i]<= 90){//Uppercase
                if(convert < 65){
                    convert = convert + 90 - 64;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }

            }else if((int)userLine[i] >= 97 && (int)userLine[i]<= 122){//Lowercase
                if(convert < 97){
                    convert = convert + 122 - 96;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }
            }
        }else{
            returnVal += userLine.substr(i, 1);
        }
    }
    return returnVal; 
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
    std::string returnVal;
    std::string userLine = ciphertext;
    int max = keyword.size();
    int keyCount = 0;
    int keywordNum;
    for(int i = 0; i < ciphertext.size(); i++){
        bool isAlp = isalpha(userLine[i]);
        int convert;
        if(isAlp == true){
            if(keyCount >= keyword.size()){
                keyCount = 0;
            }
            if((int)userLine[i] >= 65 && (int)userLine[i]<= 90){//Uppercase
                keywordNum = keyword[keyCount] - 97;
                keyCount++;
                convert = userLine[i] - keywordNum;
                if(convert < 65){
                    convert = convert + 90 - 64;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }

            }else if((int)userLine[i] >= 97 && (int)userLine[i]<= 122){//Lowercase
                if(keyCount >= keyword.size()){
                    keyCount = 0;
                }
                keywordNum = keyword[keyCount] - 97;
                keyCount++;
                convert = userLine[i] - keywordNum;
                if(convert < 97){
                    convert = convert + 122 - 96;
                    char newChar = convert;
                    returnVal += newChar;
                }else{
                    char newChar = convert;
                    returnVal += newChar;
                }
            }
        }else{
            returnVal += userLine.substr(i, 1);
        }
    }
    return returnVal;
}

std::string solve(std::string encrypted_string){
    //vector is in alphabetical order
    std::string closestFreq;
    std::vector<double> alphabetFreq {
        8.12, 1.49, 2.71, 4.32, 12.02, 2.3, 2.03, 5.92, 7.31, 
        0.1, 0.69, 3.98, 2.61, 6.95, 7.68, 1.82, 0.11, 6.02, 
        6.28, 9.1, 2.88, 1.11, 2.09, 0.17, 2.11, 0.07
    }

    std::vector<double> decryptFreq {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    }

    for(int i = 0; i < 26){
        decryptCaesar(encrypted_string, i);
        for(int j = 0; j < 26){
            
        }
    }
    //use decrypt caesar 26 times
    //call vector using std::vector<valueType> variableName {val, val, val};
    //add by using .push-back (might not need since ill directly change values in vector)
    //Can take frequency by taking how much times letter appears dvided by length of word. Might need another vector
}