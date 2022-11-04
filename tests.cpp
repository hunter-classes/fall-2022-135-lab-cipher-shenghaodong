#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here
TEST_CASE("Encrypt Caesar"){
    CHECK(encryptCaesar("I love vocaloid", 25) == "H knud unbzknhc");
    CHECK(encryptCaesar("Hunter College", 3) == "Kxqwhu Froohjh");
}

TEST_CASE("Encrypt Vigenere"){
    CHECK(encryptVigenere("It is raining today!", "rain") == "Zt qf iaqazno gfdil!");
    CHECK(encryptVigenere("I want to go to sleep", "sleep") == "A heri lz ks ig dpith");
}

TEST_CASE("Decrypt Caesar"){
    CHECK(decryptCaesar("H knud unbzknhc", 25) == "I love vocaloid");
    CHECK(decryptCaesar("Kxqwhu Froohjh", 3) == "Hunter College");
}

TEST_CASE("Decrypt Vigenere"){
    CHECK(decryptVigenere("Zt qf iaqazno gfdil!", "rain") == "It is raining today!");
    CHECK(decryptVigenere("A heri lz ks ig dpith", "sleep") == "I want to go to sleep");
}