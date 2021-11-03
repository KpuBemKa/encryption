#include "caesarKey.h"

std::string KeyGen(std::string key)
{
    std::string keystream;

    keystream = key + alphabet;

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = i + 1; j < keystream.size(); j++)
        {
            if (keystream[i] == keystream[j])
            {
                keystream.erase(j, 1);
            }
        }
    }

    return keystream;
}

std::string CaesarKeyEncrypt(std::string word)
{
    std::string key;
    std::cout << "key: ";
    std::cin >> key;

    std::string keystream = KeyGen(key);

    for (int i = 0; i < word.length(); i++)
    {
        for(int j = 0; j < keystream.size(); j++)
        {
            if(word[i] == alphabet[j])
            {
                int index = j % 26;
                word[i] = keystream[index];
                break;
            }
        }
    }

    return word;
}

std::string CaesarKeyDecrypt(std::string word)
{
    std::string key, keystream;

    std::cout << "key: ";
    std::cin >> key;

    keystream = KeyGen(key);

    for (int i = 0; i < word.length(); i++)
    {
        for(int j = 0; j < keystream.size(); j++)
        {
            if(word[i] == keystream[j])
            {
                int index = j % 26;
                word[i] = alphabet[index];
                break;
            }
        }
    }

    return word;
}