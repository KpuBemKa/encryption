#include "vgm.h"

std::string VGMEncrypt(std::string word)
{
    std::string key, enc;
    int k = 0;
    int seed = time(NULL);
    int wordLetterIndex, keyLetterIndex;

    std::cout << "key: ";
    std::cin >> key;

    for (int i = 0; i < word.length(); i++)
    {
        for(int j = 0; j < alphabet.length(); j++)
        {
            if(alphabet[j] == word[i])
                wordLetterIndex = j;

            if(alphabet[j] == key[k])
                keyLetterIndex = j;
        }

        int letterIndex = (wordLetterIndex + keyLetterIndex + seed) % 26;

        word[i] = alphabet[letterIndex];

        if (k < key.length() - 1)
            k++;
        else
            k = 0;
    }

    std::cout << "seed: " << seed << "\n";

    return word;
}

std::string VGMDecrypt(std::string word)
{
    std::string key, enc;
    int k = 0;
    int seed;
    int wordLetterIndex, keyLetterIndex;

    std::cout << "key: ";
    std::cin >> key;
    std::cout << "seed: ";
    std::cin >> seed;

    for (int i = 0; i < word.length(); i++)
    {
        for(int j = 0; j < alphabet.length(); j++)
        {
            if(word[i] == alphabet[j])
                wordLetterIndex = j;

            if(key[k] == alphabet[j])
                keyLetterIndex = j;
        }

        int letterIndex = ((wordLetterIndex - keyLetterIndex - seed) % 26 + 26) % 26;

        word[i] = alphabet[letterIndex];

        if (k < key.length() - 1)
            k++;
        else
            k = 0;
    }

    return word;
}