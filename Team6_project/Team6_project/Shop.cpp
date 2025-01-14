#include "Shop.h"

// 생성자
Shop::Shop()
{
    initializeShopItems(); // 상점 초기 아이템 설정
}

vector<Item*> Shop::getAvailableItems() const
{
    if (isInitializing)
    {
        cout << "아이템 초기화 중입니다. 잠시 후 다시 시도해주세요." << endl;
        return {};
    }
    return availableItems;
}

// 상점 아이템 초기화
void Shop::initializeShopItems()
{
    isInitializing = true;
    
    // 이전 아이템들을 삭제하고, 새로 초기화
    if (!availableItems.empty())
    {
        for (auto item : availableItems) {
            delete item;  // 이전에 동적으로 할당된 Item 객체들을 삭제
        }
        availableItems.clear();  // 벡터 초기화
    }

    // 새로운 아이템들 추가
    availableItems.push_back(ItemFactory::CreateItem("HealthPotion"));
    availableItems.push_back(ItemFactory::CreateItem("CodingBooster"));
    availableItems.push_back(ItemFactory::CreateItem("MaxHealthPotion"));
    availableItems.push_back(ItemFactory::CreateItem("TutorAttackReduction"));
    availableItems.push_back(ItemFactory::CreateItem("TutorHealthReduction"));

    isInitializing = false;
}

// 상점 아이템 목록 출력
void Shop::displayItems(Character* player) const
{
    cout << "===== 상점 =====" << endl;
    for (size_t i = 0; i < availableItems.size(); ++i)
    {
        cout << i + 1 << ". " << availableItems[i]->GetName() 
             << " - " << availableItems[i]->GetPrice() << " Gold" << endl;
    }
    cout << "보유 골드: " << player->getGold() << endl;
}

// 상점 객체 파괴 시, 할당된 메모리 해제
Shop::~Shop() {
    if (availableItems.empty()) return;  // 아이템이 비었으면 리턴
    for (auto item : availableItems) {
        if (item != nullptr) {  // nullptr 체크
            cout << "Deleting item: " << item->GetName() << endl;
            delete item;  // 아이템 객체들을 메모리에서 해제
        } 
        else {
            cout << "Encountered nullptr, skipping delete." << endl;
        }
    }
    availableItems.clear();  // 벡터 초기화
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
