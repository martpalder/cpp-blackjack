#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <vector>
#include "card.hpp"

void printCards(std::vector<Card>* playerCards, std::vector<Card>* dealerCards)
{
	std::cout << "\nPlayer Cards: " << std::endl;
	for (const Card& card : *playerCards) {
		std::cout << card.value << '\t';
	}
	
	std::cout << "\nDealer Cards: " << std::endl;
	for (const Card& card : *dealerCards) {
		std::cout << card.value << '\t';
	}
}

void printScores(unsigned short playerScore, unsigned short dealerScore)
{
	std::cout << "\nPlayer Score: " << playerScore << std::endl;
	std::cout << "Dealer Score: " << dealerScore << std::endl;
}

void printWins(unsigned short playerWins, unsigned short dealerWins)
{
	std::cout << "\nPlayer wins: " << playerWins << std::endl;
	std::cout << "Dealer wins: " << dealerWins << std::endl;
}

#endif