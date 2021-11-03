#include "vgn.h"

std::string VGNEncrypt(std::string word)
{
    std::string key, enc;
    int k = 0;

    std::cout << "key: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        int letterIndex = (word[i] + key[k]) % 26;

        word[i] = letterIndex + 65;

        if (k < key.length()-1)
            k++;
        else
            k = 0;
    }

    return word;
}

std::string VGNDecrypt(std::string word)
{
    std::string key, enc;
    int k = 0;

    std::cout << "key: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        int letterIndex = (word[i] - key[k]) % 26;

        if (letterIndex < 0)
            letterIndex += 26;

        word[i] = letterIndex + 65;

        if (k < key.length()-1)
            k++;
        else
            k = 0;
    }

    return word;
}