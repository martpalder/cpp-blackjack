build:
	g++ -O2 src/game.cpp -o./Blackjack

clean:
	del ./Blackjack

debug:
	gdb ./Blackjack

run:
	./Blackjack
