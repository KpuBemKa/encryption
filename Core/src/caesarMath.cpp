#include "caesarMath.h"

std::string CaesarMathEncrypt(std::string word)
{
    int key;
    std::cout << "Introduceti cheia: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        int letterIndex = (word[i] - 65 + key) % 26;

        word[i] = letterIndex + 65;
    }

    return word;
}

std::string CaesarMathDecrypt(std::string word)
{
    int key;
    std::cout << "Introduceti cheia: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        int letterIndex = (word[i] - 65 - key) % 26;

        word[i] = (word[i] - 65 - key) % 26 + 65;

        if (letterIndex < 0)
            letterIndex += 26;

        word[i] = letterIndex + 65;
    }

    return word;
}