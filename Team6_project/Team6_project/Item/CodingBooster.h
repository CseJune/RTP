#pragma once
#include <string>

class Character;
using namespace std;

class CodingBooster
{
public:
    string name;
    int CodingIncrease;

    CodingBooster();
    string getName();
    void use(Character* character);
};
