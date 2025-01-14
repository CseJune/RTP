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
	//Tutor* GenerateTutor(int level = 1);
	void battle(Character& A, Tutor& B);
	void displayInventory();
	void generateTutor(Character& A, Tutor*& currentTutor);
	void StartGame(int parameter);
	void StartBoss();
	};
