#include "VGNHash.h"

std::vector<std::bitset<8>> stringToBit(std::string word)
{
    std::vector<std::bitset<8>> bits;

    for (char c : word)
    {
        std::bitset<8> x(c);
        bits.push_back(x);
    }

    return bits;
}

std::string randomization()
{
    std::bitset<32> seed = 157375;
    std::string result = "";

    for (int i = 0; i < 4; i++)
    {
        std::bitset<8> bitChar;

        for(int j = i*8; j < (i+1)*8; j++)
        {
            bitChar[j%8] = seed[j];
        }

        result.push_back((char)(bitChar.to_ulong()));
    }

    return result;
}

std::string stringXOR(std::string word, std::string key)
{
    std::string result = "";

    for (int i = 0; i < word.size(); i++)
    {
        char c1 = word[i];
        char c2 = key[i % key.size()];

        char xor = c1 ^ c2;

        result.push_back(xor);
    }

    return result;
}

std::string VGNHashEncrypt(std::string message)
{
    std::string key = randomization();
    std::string result = stringXOR(message, key);

    return result;
}

std::string VGNHashDecrypt(std::string message)
{
    std::string key;

    std::cout << "Key: ";
    std::cin >> key;

    return stringXOR(message, key);
}