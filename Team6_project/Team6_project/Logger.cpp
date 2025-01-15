#include "Logger.h"

void initializeLog() {
    ofstream logFile("game_log.txt", ios::trunc);
    if (logFile.is_open()) {
        logFile << "===== 게임 로그 시작 =====\n";
        logFile.close();
    }
}

void writeLog(const string& logMessage) {
    ofstream logFile("game_log.txt", ios::app);  // append 모드로 열기
    if (logFile.is_open()) {
        time_t now = time(0);
        char dt[26];
        ctime_s(dt, sizeof(dt), &now);  // 현재 시간 안전하게 포맷

        logFile << "[" << dt << "] " << logMessage << endl;
        logFile.close();
    }
    else {
        cerr << "로그 파일 열기에 실패했습니다.\n";
    }
}