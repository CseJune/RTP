#pragma once
#include <string>

class Character;
using namespace std;

class Item
{
    public:
    virtual string GetName() const = 0;
    virtual void Use(Character* character) = 0;
};
