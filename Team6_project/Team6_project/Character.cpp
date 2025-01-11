#include <iostream>
#include <vector>
#include "Character.h"

using namespace std;

//ĳ���͸� �����ϱ� ���� ���� ������� �ʱ�ȭ
Character* Character::instance = nullptr; 

//getinstance �޼��� ����
Character* Character::getinstance(string name)
{
	if (instance == nullptr) // instance�� ������ ���� ����
	{
		instance = new Character();
		instance->name = name; // �̸� ����
	}
	return instance; // �׻� ������ �ν��Ͻ� ��ȯ
}


// ĳ���� �ʱ� ������
Character::Character()
	: hp(200), maxhp(200), add(30), exp(0), name(name), level(1), gold(0)
{}

// display ��� �Լ� ���� (�κ��丮�� ���ִٰ�)
void Character::displayStatus()
{
	cout << "�̸� : " << name << endl;
	cout << "���� : " << level << endl;
	cout << "�ڵ��� : " << add << endl;
	cout << "��� : " << gold << endl;
	cout << "����ġ : " << exp << endl;
	cout << "ü�� : " << hp << ", " << "�ִ� ü�� : " << maxhp << endl;
}

// �κ��丮 ������ �߰� ����
void Inventory::addItem(string& item)
{
	items.push_back(item);
}

// �κ��丮 ������ ��� ����
void Inventory::displayInventory()
{
	if (items.empty())
	{
		cout << " �κ��丮�� ����ֽ��ϴ� " << endl;
	}

	else
	cout << " �κ��丮 " << endl;
	for (size_t i = 0; i < items.size(); ++i)
	{
		cout << "[" << (i + 1) << "] " << items[i] << endl;
	}
}

// �κ��丮�� ������ ��� ����
bool Inventory::useItem(string& item)
{
	auto it = find(items.begin(), items.end(), item); // �ݺ��ڿ� find�� ����� �κ��丮�� �ִ� ������ ��ȸ
	if (it != items.end()) // �������� ã����( �ݺ��ڰ� find�� ����ߴµ�, ������ �������� �ƴ϶�� )
	{
		items.erase(it); // ������ ����
		return true; // true ��ȯ
	}
	return false; // false ��ȯ
}

// level �Լ� ����
void Character::levelUp()
{
	if (exp >= 100 && level < 10) 
	{
		exp = exp - need_levelUp_exp;
		++level;

		hp += (level * 20);
		maxhp += (level * 20);
		add += (level * 5);

		if (hp > maxhp)
		{
			hp = maxhp;
		}
		if (level == 10)
		{
			exp = 0;
		}
	}
}
//int main()
//{
//	string characterName;
//
//	cout << "ĳ���� �̸� �Է� : ";
//	cin >> characterName;
//
//	Character* player = Character::getinstance(characterName);
//	player->displayStatus();
//
//	Inventory a;
//	
//	string b = "������ ��";
//	a.addItem(b);
//	a.displayInventory();
//}