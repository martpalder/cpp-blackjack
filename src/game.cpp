#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.hpp"
#include "entity.hpp"
#include "output.hpp"

bool askChoice();
bool isBlackjack(unsigned short, unsigned short);
unsigned short checkWinner(unsigned short, unsigned short, bool, bool);
bool playAgain();
void moveCards(Deck*, Entity*, Entity*);

int main() {
	// seed random number generator
	std::srand(std::time(0));
	
	// a deck of cards
	Deck deck;
	
	// player and dealer
	Entity player;
	Entity dealer;
	
	// hit choices
	bool playerHit = false;
	bool dealerHit = false;
	
	// checks
	bool blackjack = false;
	bool stand = false;
	
	// moves and winner
	unsigned short moves = 0;
	unsigned short winner = 0;
	
	// number of wins
	unsigned short playerWins = 0;
	unsigned short dealerWins = 0;
	
	// game loop
	while (1) {		
		// shuffle deck cards
		deck.ShuffleCards();
		
		// add 1st card to player and remove a card from deck
		player.AddCard(deck.GetCards()->back());
		deck.RemoveCard();
		
		// add 1st card to dealer and remove a card from deck
		dealer.AddCard(deck.GetCards()->back());
		deck.RemoveCard();
		
		// print cards and scores
		printCards(player.GetCards(), dealer.GetCards());
		printScores(player.GetScore(), dealer.GetScore());
		
		// moves loop
		while (1) {
			// ask for player choice
			playerHit = askChoice();
			if (playerHit) {
				// add a card to player and remove a card from deck
				player.AddCard(deck.GetCards()->back());
				deck.RemoveCard();
				stand = false;
				std::cout << "You hit" << std::endl;
			}
			else {
				stand = true;
				std::cout << "You stand" << std::endl;
			}
			
			// randomize dealer choice
			dealerHit = rand() % 2;
			if (dealer.GetScore() < 12) {
				// add a card to dealer and remove a card from deck
				dealer.AddCard(deck.GetCards()->back());
				deck.RemoveCard();
				std::cout << "Dealer hits" << std::endl;
			}
			else if (dealer.GetScore() < 20 and dealerHit) {
				// add a card to dealer and remove a card from deck
				dealer.AddCard(deck.GetCards()->back());
				deck.RemoveCard();
				std::cout << "Dealer hits" << std::endl;
			}
			else std::cout << "Dealer stands" << std::endl;
			
			// print cards and scores
			printCards(player.GetCards(), dealer.GetCards());
			printScores(player.GetScore(), dealer.GetScore());
			
			// if there's no previous moves: check for blackjack
			if (!moves) blackjack = isBlackjack(player.GetScore(), dealer.GetScore());
			
			// check for winner
			winner = checkWinner(player.GetScore(), dealer.GetScore(), blackjack, stand);
			if (winner) break;
			
			// increase number of moves
			++moves;
		}
		
		// reset number of moves
		moves = 0;
		
		// increase number of wins
		if (winner == 1) ++playerWins;
		else if (winner == 2) ++dealerWins;
		
		// print number of wins
		printWins(playerWins, dealerWins);
		
		// ask if player wants to play again
		bool again = playAgain();
		if (again) moveCards(&deck, &player, &dealer);
		else break;
	}
	
	std::cout << "\nGame over!" << std::endl;
	return 0;
}

bool askChoice()
{
	char charChoice;
	unsigned short choice;
	bool hit;
	
	std::cout << "\nChoice:" << std::endl;
	std::cout << "1 - Hit" << std::endl;
	std::cout << "2 - Stand" << std::endl;
	
	while (1) {
		std::cin >> charChoice;
		choice = static_cast<unsigned short>(charChoice) - '0';
		std::cout << choice << std::endl;
		if (choice == 1 or choice == 2) break;
	}
	
	if (choice == 1) hit = true;
	else hit = false;
	
	return hit;
}

bool isBlackjack(unsigned short playerScore, unsigned short dealerScore)
{
	bool blackjack;
	if (playerScore == 21 or dealerScore == 21) blackjack = true;
	else blackjack = false;
	return blackjack;
}

unsigned short checkWinner(unsigned short playerScore, unsigned short dealerScore, bool blackjack, bool stand)
{
	unsigned short winner;
	if (playerScore > 21) {
		winner = 2;
		std::cout << "\nYou're bust!" << std::endl;
		std::cout << "Dealer wins!" << std::endl;
	}
	else if (dealerScore > 21) {
		winner = 1;
		std::cout << "\nDealer's bust!" << std::endl;
		std::cout << "You win!" << std::endl;
	}
	else if (blackjack) {
		if (playerScore > dealerScore) {
			winner = 1;
			std::cout << "\nBlackjack!" << std::endl;
			std::cout << "You win!" << std::endl;
		}
		else if (dealerScore > playerScore) {
			winner = 2;
			std::cout << "\nBlackjack!" << std::endl;
			std::cout << "Dealer wins!" << std::endl;
		}
		else {
			winner = 3;
			std::cout << "\nPush" << std::endl;
		}
	}
	else if (stand) {
		if (playerScore > dealerScore) {
			winner = 1;
			std::cout << "\nYou win!" << std::endl;
		}
		else if (dealerScore > playerScore) {
			winner = 2;
			std::cout << "\nDealer wins!" << std::endl;
		}
		else {
			winner = 3;
			std::cout << "\nPush" << std::endl;
		}
	}
	else winner = 0;
	
	return winner;
}

bool playAgain()
{
	char choice;
	bool again;
	
	std::cout << "\nDo you want to play again? (Y/n): ";
	std::cin >> choice;
	
	if (choice == 'N' or choice == 'n') again = false;
	else again = true;
	
	return again;
}

void moveCards(Deck* deck, Entity* player, Entity* dealer)
{
	for (const unsigned short& card : *player->GetCards()) {
		deck->AddCard(card);
		player->RemoveCard();
	}
	
	for (const unsigned short& card : *dealer->GetCards()) {
		deck->AddCard(card);
		dealer->RemoveCard();
	}
}
