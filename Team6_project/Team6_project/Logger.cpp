#include "Logger.h"

void initializeLog() {
    ofstream logFile("game_log.txt", ios::trunc);
    if (logFile.is_open()) {
        logFile << "===== ���� �α� ���� =====\n";
        logFile.close();
    }
}

void writeLog(const string& logMessage) {
    ofstream logFile("game_log.txt", ios::app);  // append ���� ����
    if (logFile.is_open()) {
        time_t now = time(0);
        char dt[26];
        ctime_s(dt, sizeof(dt), &now);  // ���� �ð� �����ϰ� ����

        logFile << "[" << dt << "] " << logMessage << endl;
        logFile.close();
    }
    else {
        cerr << "�α� ���� ���⿡ �����߽��ϴ�.\n";
    }
}