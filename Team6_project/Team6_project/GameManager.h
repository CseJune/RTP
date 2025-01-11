#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

class GameManager
{
public:
	Monster* generateMonster(int level = 1);
	void battle(Character* player);
	void displayInventory();
	void generateTutor();
	void StartGame(int start);
	void StartBoss();
	void monster();

};