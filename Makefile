build:
	g++ -std=c++11 src/game.cpp -o bin/Blackjack

clean:
	del bin\Blackjack.exe

run:
	bin/Blackjack