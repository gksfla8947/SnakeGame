CC = g++


main : main.o StartScene.o SnakeGame.o Snake.o Map.o GameScene.o GameoverScene.o GameclearScene.o EndScene.o
	g++ -o main main.o StartScene.o SnakeGame.o Snake.o Map.o GameScene.o GameoverScene.o GameclearScene.o EndScene.o -lncurses -std=c++11

main.o : main.cpp
	g++ -c main.cpp -lncurses -std=c++11

StartScene.o : StartScene.cpp
	g++ -c StartScene.cpp -lncurses -std=c++11

SnakeGame.o : SnakeGame.cpp
	g++ -c SnakeGame.cpp -lncurses -std=c++11

Snake.o : Snake.cpp
	g++ -c Snake.cpp -lncurses -std=c++11

Map.o : Map.cpp
	g++ -c Map.cpp -std=c++11 -lncurses -std=c++11

GameScene.o : GameScene.cpp
	g++ -c GameScene.cpp -lncurses -std=c++11

GameoverScene.o : GameoverScene.cpp
	g++ -c GameoverScene.cpp -lncurses -std=c++11

GameclearScene.o : GameclearScene.cpp
	g++ -c GameclearScene.cpp -lncurses -std=c++11

EndScene.o : EndScene.cpp
	g++ -c EndScene.cpp -lncurses -std=c++11

clean : 
	rm -rf *.o *.exe
