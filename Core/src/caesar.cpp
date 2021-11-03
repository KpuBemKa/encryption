#include "caesar.h"

std::string CaesarEncrypt(std::string word)
{
    int key;
    std::cout << "Introduceti cheia: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] + key > 90)
        {
            word[i] = word[i] + key - 26;
        }
        else
        {
            word[i] += key;
        }
    }

    return word;
}

std::string CaesarDecrypt(std::string word)
{
    int key;
    std::cout << "Introduceti cheia: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        if (word[i] - key < 65)
        {
            word[i] = word[i] - key + 26;
        }
        else
        {
            word[i] -= key;
        }
    }

    return word;
}