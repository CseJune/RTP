#pragma once

#include "Item.h"
#include <string>

using namespace std;

class ChatGPT : public Item
{
private:
    string name;    // 아이템 이름

public:
    ChatGPT();  // 기본 생성자
    string GetName() const override;    // 아이템 이름 반환
    void Use(Character* character) override; 
    void Use(Tutor* tutor) override;
};
