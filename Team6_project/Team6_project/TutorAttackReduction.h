#pragma once

#include <string>

class Tutor;
class Character;

using namespace std;

class TutorAttackReduction
{
private:
    string name;    // 아이템 이름   
    int attackReduction; // 공격력 감소량
    
public:    
    TutorAttackReduction();    // 생성자
    string GetName();   // 아이템 이름 반환
    void Use(Tutor* tutor); // 튜터 공격력 감소 효과 적용
};

