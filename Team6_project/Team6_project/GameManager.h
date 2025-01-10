#pragma once
#include"Character.h"
#include"Monster.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GameManager
{
public:
	Monster* generateMonster(int level = 1);
	void battle(Character* player);
	void displayInventory();

};