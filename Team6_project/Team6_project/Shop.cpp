#include "Shop.h"

// 생성자
Shop::Shop()
{
    initializeShopItems(); // 상점 초기 아이템 설정
}

// 상점 아이템 초기화
void Shop::initializeShopItems()
{
    availableItems.push_back(ItemFactory::CreateItem("HealthPotion"));
    availableItems.push_back(ItemFactory::CreateItem("CodingBooster"));
    availableItems.push_back(ItemFactory::CreateItem("MaxHealthPotion"));
    availableItems.push_back(ItemFactory::CreateItem("TutorAttackReduction"));
    availableItems.push_back(ItemFactory::CreateItem("TutorHealthReduction"));
}

// 상점 아이템 목록 출력
void Shop::displayItems() const
{
    cout << "===== 상점 아이템 목록 =====" << endl;
    for (size_t i = 0; i < availableItems.size(); ++i)
    {
        cout << i + 1 << ". " << availableItems[i]->GetName() 
             << " - " << availableItems[i]->GetPrice() << " Gold" << endl;
    }
}

// 아이템 구매
void Shop::buyItem(Character* player, const string& itemName)
{
    for (auto& item : availableItems)
    {
        if (item->GetName() == itemName)
        {
            if (player->getGold() >= item->GetPrice())
            {
                player->setGold(player->getGold() - item->GetPrice());
                player->addItemToInventory(item);
                return;
            }
            cout << "골드가 부족합니다!" << endl;
            return;
        }
    }
    cout << "아이템을 찾을 수 없습니다!" << endl;
}


// TODO :: findItem, removeItem 함수 구현하고 주석 해제

/*
// 아이템 판매
void Shop::sellItem(Character* player, const string& itemName)
{
    Item* item = player->getInventory()->findItem(itemName);
    if (item)
    {
        int sellPrice = static_cast<int>(item->GetPrice() * 0.6);
        player->setGold(player->getGold() + sellPrice);
        player->getInventory()->removeItem(itemName);
        cout << itemName << "을(를) 판매했습니다! " << sellPrice << " Gold를 획득했습니다." << endl;
    }
    else
    {
        cout << "인벤토리에 해당 아이템이 없습니다!" << endl;
    }
}
*/
