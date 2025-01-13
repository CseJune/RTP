#pragma once

#include "Item.h"
#include <string>

using namespace std;

class ChatGPT : public Item
{
private:
    string name;    // 아이템 이름
    int price = 100000; // 아이템 가격 (100000 Gold)
    
public:
    ChatGPT();  // 기본 생성자
    string GetName() const override;    // 아이템 이름 반환
    void Use(Character* character) override;    // 캐릭터에게 효과 적용
    void Use(Tutor* tutor) override;    // 튜터에게 효과 적용
};
