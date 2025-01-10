#pragma once
#include"Character.h"
#include"Monster.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Monster
{
public:
	Monster();

	virtual string getname();
	virtual int gethp();
	virtual int getadd();
	virtual void takedamage(int damage);

};
