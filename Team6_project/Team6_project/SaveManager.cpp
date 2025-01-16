#include "SaveManager.h"
#include <fstream>
#include <iostream>
#include "ItemFactory.h"
#include "Logger.h"

using namespace std; 
bool SaveManager::SaveGame(const Character* character, const string& filename) 
{
    if (!character) return false;

    // 스트림 객체 생성
    ofstream file(filename, ios::binary);
    if (!file.is_open()) 
    {
        cout << "저장 파일을 생성할 수 없습니다!" << endl;
        writeLog("게임 저장 실패: 파일을 생성할 수 없습니다.");
        return false;
    }

    file.write(character->getName().c_str(), character->getName().size() + 1);
    int hp = character->getHp();
    int maxHp = character->getMaxHp(); 
    int add = character->getAdd();
    int exp = character->getExp();
    int level = character->getLevel();
    int gold = character->getGold();
    
    file.write(reinterpret_cast<const char*>(&hp), sizeof(int));
    file.write(reinterpret_cast<const char*>(&maxHp), sizeof(int));
    file.write(reinterpret_cast<const char*>(&add), sizeof(int));
    file.write(reinterpret_cast<const char*>(&exp), sizeof(int));
    file.write(reinterpret_cast<const char*>(&level), sizeof(int));
    file.write(reinterpret_cast<const char*>(&gold), sizeof(int));

    SaveInventory(file, character->getInventory());

    file.close();
    cout << "게임이 성공적으로 저장되었습니다!" << endl;
    writeLog("게임 저장 완료: " + character->getName() + "의 게임 데이터가 저장되었습니다.");
    return true;
}

bool SaveManager::LoadGame(Character* character, const string& filename)
{
    if (!character) return false;

    ifstream file(filename, ios::binary);
    if (!file.is_open()) 
    {
        cout << "저장된 게임을 찾을 수 없습니다!" << endl;
        writeLog("게임 불러오기 실패: 저장 파일을 찾을 수 없습니다.");
        return false;
    }

    string name;
    getline(file, name, '\0');
    character->setName(name);

    int hp, maxHp, add, exp, level, gold;
    file.read(reinterpret_cast<char*>(&hp), sizeof(int));
    file.read(reinterpret_cast<char*>(&maxHp), sizeof(int));
    file.read(reinterpret_cast<char*>(&add), sizeof(int));
    file.read(reinterpret_cast<char*>(&exp), sizeof(int));
    file.read(reinterpret_cast<char*>(&level), sizeof(int));
    file.read(reinterpret_cast<char*>(&gold), sizeof(int));

    character->setHp(hp);
    character->setMaxHp(maxHp);
    character->setAdd(add);
    character->setExp(exp);
    character->setLevel(level);
    character->setGold(gold);

    LoadInventory(file, character->getInventory());

    file.close();
    cout << "게임을 성공적으로 불러왔습니다!" << endl;
    writeLog("게임 불러오기 완료: " + character->getName() + "의 게임 데이터가 로드되었습니다.");
    return true;
}

void SaveManager::SaveInventory(ofstream& file, const Inventory* inventory)
{
    if (!inventory) return;

    int itemCount = inventory->getItemCount();
    file.write(reinterpret_cast<const char*>(&itemCount), sizeof(int));

    for (int i = 0; i < itemCount; i++)
    {
        string itemName = inventory->getItemNameByIndex(i);
        file.write(itemName.c_str(), itemName.size() + 1);
    }
}

void SaveManager::LoadInventory(ifstream& file, Inventory* inventory)
{
    if (!inventory) return;

    int itemCount;
    file.read(reinterpret_cast<char*>(&itemCount), sizeof(int));

    for (int i = 0; i < itemCount; i++)
    {
        string itemName;
        getline(file, itemName, '\0');
        
        Item* item = ItemFactory::CreateItem(itemName);
        if (item)
        {
            inventory->addItem(item);
        }
    }
} 

