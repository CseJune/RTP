#pragma once
#include"Character.h"
#include <iostream>
#include <string>

using namespace std;

class Item
{
    public:
    virtual string getName() const = 0;
    virtual void use(Character* character) = 0;
};
