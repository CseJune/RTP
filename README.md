# RTP
Real Team Project

아래는 주어진 내용을 바탕으로 한 README 작성 예시입니다. 필요에 따라 세부사항을 조정하고 추가하여 사용하세요.

-----------------------------------------------------------------------------------------------------------

RPG Game Project

프로젝트 소개

프로젝트 이름 : " 환생했더니 군필여고생이 튜터님을 죽일 수 밖에 없었던 이유 "


프로젝트 개요

이 프로젝트는 텍스트 기반의 RPG 게임입니다.  

주요 콘텐츠는 캐릭터 생성, 전투 시스템, 아이템 관리 등이며 해당 프로젝트를 통해 프로그래밍 능력을 향상시키고 게임 개발에 대한 이해를 깊게 하고자 하였습니다.

주요 콘텐츠는 정상적인 게임인 척 하다가 주인공이 곤듀화 되어 나쁜 튜터들을 물리치는 컨셉의 게임입니다. 자세한 내용은 스토리 라인을 참고해주시면 감사하겠습니다.

팀원간의 유기적인 소통으로 프로젝트를 진행하였으며 생초보들이 모여 만든 프로젝트 임을 인지해주셨으면 감사하겠습니다.

C++에서 활용한 라이브러리는 iosteram, string, cstdlib, set, chrono, thread, functional, ctime
STL 라이브러리로는 vector, unordered_map 이 있습니다.

-----------------------------------------------------------------------------------------------------------

개발 환경

개발 언어 및 도구

- IDE: Visual Studio 2022
- Compiler: MSVC 14.XX / C++17 이상
- CMake 3.X 이상

실행 방법

VisualStudio 설치
Team6_project.sln 실행
F5를 눌러 게임 시작


의존 라이브러리/패키지

특별한 외부 라이브러리는 사용하지 않았습니다. 모든 구현은 표준 C++ 라이브러리(STL)를 활용하였습니다.


프로젝트 구조

Team6_project/
┣ src/
┃ ┣ main.cpp               // 메인 함수 진입점 
┃ ┗ game/                  // 게임 관련 파일 위치 
┃ ┃ ┣ character.h          // 캐릭터 시스템 헤더 
┃ ┃ ┣ character.cpp        // 캐릭터 시스템 구현 
┃ ┃ ┣ inventory.h          // 인벤토리 관리 헤더 
┃ ┃ ┗ inventory.cpp        // 인벤토리 관리 구현 
┣ tests/                   // 테스트 코드 위치 (예: 유닛 테스트)
┗ README.md                // 이 문서 자체 (README)

핵심 로직/클래스 설명

Character 클래스

플레이어의 속성(체력, 공격력 등)과 행동(공격, 방어)을 정의하는 클래스입니다.

메소드 예시:

attack(): 적에게 피해를 입히는 메소드.

levelUp(): 경험치에 따라 레벨업 하는 메소드.

Inventory 클래스

아이템 관리를 담당하며 아이템 추가와 제거 방법 등을 정의하고 있습니다.

메소드 예시:

addItem(Item* item): 새로운 아이템을 인벤토리에 추가하는 메소드.

useItem(string& itemName): 특정 아이템을 사용하는 기능

-----------------------------------------------------------------------------------------------------------

주요 기능 요약

1. 캐릭터 생성

2. 전투 및 레벨 업 시스템 구현

3. 인벤토리 관리 (아이템 추가/사용)

4. 다양한 몬스터와의 전투 지원

5. 상점 구현

6. 보스 몬스터 구현

7. 게임 진행 상황 로그 text파일에 저장


-----------------------------------------------------------------------------------------------------------

프로젝트 내에서 특히 고민했던 부분은 전투 알고리즘 설계로, 랜덤성과 확률 요소 등을 고려하여 공정한 진행이 이루어질 수 있도록 했습니다.


과제 추가 구현 사항 (추가 구현을 했다면 필히 작성!)

여러 가지 특수 효과가 있는 아이템들을 설계했습니다. 이는 플레이어가 보다 다양한 전략으로 싸울 수 있게 하기 위함이며 각기 다른 효과(예: 체력 회복, 공격 증가)를 가지고 있어 흥미로운 요소로 작용하도록 했습니다.

또한 컨셉을 맞추는데 중점을 두어서, 캐릭터와 튜터간 상호작용 대사나 엔딩 문구 같은 다양한 상호작용에서 컨셉에 맞추어서 대사를 출력하게끔 신경 썼습니다.


주의사항

현재까지 수정되지 않은 버그나 제한 사항은 없습니다만, 다음과 같은 점에 유의하시길 바랍니다:

호환성 이슈: 특정 Windows 버전에서는 경고 또는 오류 메시지가 발생할 수 있으니 최신 업데이트 상태인지 확인 후 진행하세요!

테스트 미비된 부분: 일부 기능은 충분히 테스트되지 않았으므로 문제가 있을 경우 피드백 주시면 감사하겠습니다!

게임이 컨셉에 잡아먹혀 글 가독성이 매우 떨어질 수 있습니다.
이 점 양해부탁드립니다.