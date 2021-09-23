#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <math.h>

std::string CSR_encrypt(std::string word, int key)
{
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

std::string CSR_decrypt(std::string word, int key)
{
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

std::string CSR_encrypt_math(std::string word, int key)
{
    int k;

    for (int i = 0; i < word.length(); i++)
    {
        int letterIndex = (word[i] - 65 + key) % 26;

        word[i] = letterIndex + 65;
    }

    return word;
}

std::string CSR_decrypt_math(std::string word, int key)
{
    int k;

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

int main(int argc, char *argv[])
{
    std::string decription = argv[1];
    std::string word = argv[2];

    if (decription == "-Ecsr")
    {
        int key = 0;
        std::cout << "Introduceti cheia: ";
        std::cin >> key;

        std::cout << CSR_encrypt(word, key);
    }

    if (decription == "-Dcsr")
    {
        int key = 0;
        std::cout << "Introduceti cheia: ";
        std::cin >> key;

        std::cout << CSR_decrypt(word, key);
    }

    if (decription == "-Ecsrm")
    {
        int key = 0;
        std::cout << "Introduceti cheia: ";
        std::cin >> key;

        std::cout << CSR_encrypt_math(word, key);
    }

    if (decription == "-Dcsrm")
    {
        int key = 0;
        std::cout << "Introduceti cheia: ";
        std::cin >> key;

        std::cout << CSR_decrypt_math(word, key);
    }

    return 0;
}
