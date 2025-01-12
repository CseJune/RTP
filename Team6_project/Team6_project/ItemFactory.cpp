#include "ItemFactory.h" 
#include "HealthPotion.h" 
#include "CodingBooster.h"
#include "MaxHealthPotion.h" 
#include "TutorAttackReduction.h"

// CreateItem 구현
Item* ItemFactory::CreateItem(const string& itemType)
{
    if (itemType == "HealthPotion")
    {
        return new HealthPotion();
    }
    else if (itemType == "CodingBooster")
    {
        return new CodingBooster();
    }
    else if (itemType == "MaxHealthPotion")
    {
        return new MaxHealthPotion();
    }
    else if (itemType == "TutorAttackReduction")
    {
        return new TutorAttackReduction();
    }
    
    return nullptr; // 일치하는 타입이 없으면 nullptr 반환
}
