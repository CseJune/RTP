#pragma once
#include"Character.h"
#include"GameManager.h"
#include <iostream>
#include <vector>
#include <string>

class Item 
{
	virtual string getname();
	virtual void use(Character* character);
};