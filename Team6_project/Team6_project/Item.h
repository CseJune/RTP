#pragma once

#include <string>

class Character;
class Tutor;

using namespace std;

class Item
{
    public:
    virtual string GetName() const = 0;

    // 캐릭터에게 아이템 효과를 적용하는 순수 가상 함수
    virtual void Use(Character* character) = 0;

    // 튜터에게 아이템 효과를 적용하는 순수 가상 함수
    virtual void Use(Tutor* tutor) = 0;

    // 가상 소멸자
    virtual ~Item() {}
};
