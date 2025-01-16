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
	bool SaveGameWithTutor(const string& filename);   // 튜터 정보까지 저장
	bool LoadGameWithTutor(const string& filename);   // 튜터 정보까지 불러오기

	Tutor* getTutor() const { return currentTutor; }
	void setTutor(Tutor* tutor) { currentTutor = tutor; }
private:
	Tutor* currentTutor; // 게임 매니저에서 튜터 관리
	};
