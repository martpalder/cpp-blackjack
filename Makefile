build:
	g++ src/game.cpp -O2 -o bin/Blackjack

clean:
	del bin\Blackjack.exe

debug:
	gdb bin/Blackjack

run:
	bin/Blackjack