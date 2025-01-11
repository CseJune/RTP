#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#include "Character.h"
#include "Monster.h"

using namespace std;

class GameManager
{
public:
	Tutor* generateMonster(int level = 1);
	void battle(Character* player);
	void displayInventory();
	void generateTutor();
	void StartGame(int start);
	void StartBoss();
	void Tutor();

};