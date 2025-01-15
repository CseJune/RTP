#pragma once
#include <string>
#include "Character.h"

class SaveManager
{
public:
    static bool SaveGame(const Character* character, const std::string& filename = "savegame.dat");
    static bool LoadGame(Character* character, const std::string& filename = "savegame.dat");
    
private:
    static void SaveInventory(std::ofstream& file, const Inventory* inventory);
    static void LoadInventory(std::ifstream& file, Inventory* inventory);
}; 