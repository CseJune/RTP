#include "ItemFactory.h"

#include <functional>
#include <unordered_map>
#include <string>

#include "ChatGPT.h"
#include "HealthPotion.h" 
#include "CodingBooster.h"
#include "MaxHealthPotion.h" 
#include "TutorAttackReduction.h"
#include "TutorHealthReduction.h"

using namespace std;

// 아이템 타입과 생성 함수 매핑 초기화
unordered_map<string, function<Item*()>> ItemFactory::itemRegistry = {
    {"ChatGPT",[]() { return new ChatGPT(); }},
    {"HealthPotion", []() { return new HealthPotion(); }},
    {"MaxHealthPotion", []() { return new MaxHealthPotion(); }},
    {"CodingBooster", []() { return new CodingBooster(); }},
    {"TutorAttackReduction", []() {return new TutorAttackReduction(); }},
    {"TutorHealthReduction",[]() {return new TutorHealthReduction(); }}
    };

// 아이템 생성 메서드
Item* ItemFactory::createItem(const string& itemType)
{
    auto it = itemRegistry.find(itemType);
    // 해당 아이템이 있으면 생성 함수 호출, 없으면 nullptr 반환
    return (it != itemRegistry.end()) ? it->second() : nullptr;
}

// 아이템 등록 메서드
void ItemFactory::registerItem(const string& itemType, function<Item*()> itemCreator)
{
    itemRegistry[itemType] =itemCreator;
}