단계별 완료 현황
1단계 : Map 구현
-SnakeGame 클래스 객체에 생성자로 스테이지의 개수를 설정가능, stage폴더에 stage(n)형태로 텍스트 파일로 맵의 형태 저장

2단계 : Snake 표현과 조작
-Snake의 각 바디와 헤드의 위치를 vector로 pair의 형태로 저장(x,y) move함수를 통해 스네이크의 이동과 충돌 상호작용처리

3단계 : Item 요소 구현
-Map에서 6,7번으로 각각 growth, reduce아이템으로 설정 후 매 시간마다 맵에 랜덤으로 생성되게끔 구현

4단계 : Gate 요소 구현
-Map에서 5번으로 한 쌍 씩 나타나게끔 처리 후 매 시간 마다 맵에 랜덤으로 생성되게 끔 구현, 스네이크의 통과처리도 구현

5단계 : 스코어, 미션요소 구현
-Map 텍스트 파일에 각 스테이지마다 목표 점수들을 상세한 후 게임씬의 scoreboard, missionboard에 점수와 목표 표시 구현

6단계 : 스타트화면, 종료화면, 게임오버화면, 게임클리어화면 개별 구현
-프로그램 첫 실행 시 스타트화면 표현, 게임 종료, 클리어, 죽음 마다 개별 씬 구현

기여도

-EndScene, StartScene, GameoverScene, GameclearScene : 김한림(100%)
EndScene.h
EndScene.cpp
StartScene.h
StartScene.cpp
GameoverScene.h
GameoverScene.cpp
GameclearScene.h
GameclearScene.cpp

-GameScene : 김한림, 김영광
GameScene.h : 김한림(100%)
GameScene.cpp : 김한림(60%), 김영광(40%)

-Map : 김한림, 김영광, 이다은
Map.h : 김한림(30%), 김영광(50%), 이다은(20%)
Map.cpp : 김한림(40%), 김영광(40%), 이다은(20%)

-SnakeGame : 김한림, 김영광
SnakeGame.h : 김한림(100%)
SnakeGame.cpp : 김한림(80%), 김영광(20%)

-Snake : 김한림, 김영광
Snake.h : 김한림(70%), 김영광(30%)
Snake.cpp : 김한림(50%), 김영광(50%)

-main.cpp : 김한림

-makefile : 김영광(50%), 이다은(50%)
-wordfile : 김한림(20%), 이다은(50%), 김영광(30%)

stage/stage1,2,3,4 : 김한림(80%) 김영광(20%)
