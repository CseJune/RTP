#pragma once

#include <string>

class Character;

using namespace std;

class CodingBooster
{
private:
    string name;    // 아이템 이름   
    int codingIncrease; // 코딩력 증가량
public:    
    CodingBooster();    // 생성자
    string GetName();   // 아이템 이름 반환
    void Use(Character* character); // 캐릭터 코딩력 증가 효과 적용
};
