#pragma once

#include <string>

class Character;
class Tutor;

using namespace std;

class Item
{
public:
    // 아이템 이름을 반환하는 순수 가상 함수
    virtual string GetName() const = 0;

    // 아이템 설명을 반환하는 순수 가상 함수
    virtual string GetDescription() const = 0;

    // 캐릭터에게 아이템 효과를 적용하는 순수 가상 함수
    virtual void Use(Character* character) = 0;

    // 튜터에게 아이템 효과를 적용하는 순수 가상 함수
    virtual void Use(Tutor* tutor) = 0;

    // 아이템 가격을 반환하는 가상 함수
    virtual int GetPrice() const {return 0;}

    // 가상 소멸자
    virtual ~Item() {}
};
