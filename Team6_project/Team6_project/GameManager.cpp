#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "GameManager.h"

using namespace std;


// StartGame �Լ� ����
void StartGame(int start) {
    if (start == 1) {
        cout << "������ �����մϴ�.\n";
    }
    else if (start == 2) {
        cout << "ķ���� Ż���ϼ̽��ϴ�.\n";
        exit(0);
    }
}

// StartBoss �Լ� ����
void StartBoss() {
    int Boss = 0; // �ʱ�ȭ
    while (true) {
        cout << "1. GPT ���\n";
        cin >> Boss;

        if (Boss == 1) {
            cout << "�������� ���� �ʽ��ϴ�.\n";
            break;
        }
        else {
            cout << "�߸��� �����Դϴ�. �ٽ� �������ּ���.\n";
        }
    }
}

//���� �Լ� ����
void battle() {
    cout << "������ �����մϴ�!\n";
    while (player.hp > 0 && Monster.hp > 0) {
        int damageToMonster = player.add;
        Monster.health -= damageToMonster;
        cout << "�÷��̾ " << damageToMonster << "�� ���ظ� �������ϴ�!\n";
        if (Monster.health <= 0) {
            cout << Monster.name << "�� �����ƽ��ϴ�!\n";
            inventory.gold += 10; // ����
            return;
        }

        int main() {
            int start = 0;

            cout << "�ڵ��� �����Ͻðڽ��ϱ�?\n";
            cout << "1. �����Ѵ� \n2. �����Ѵ�\n";
            cin >> start;

            StartGame(start);

            cout << "�������� ���� ������ �Ŵ����� �ʰ��� GPT�� ���� �����ڴ� �뼭�� �� ����!\n";
            cout << "�Ŵ����� �����ϼ̽��ϴ�. ������ �Ͻðڽ��ϱ�?\n";

            StartBoss();

            return 0;
        }