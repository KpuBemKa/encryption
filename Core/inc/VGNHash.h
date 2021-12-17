#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <bitset>
#include "alphabet.h"

std::string VGNHashEncrypt(std::string message);
std::string VGNHashDecrypt(std::string message);