#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <vector>
#include <iostream>

void printCards(std::vector<unsigned short>* playerCards, std::vector<unsigned short>* dealerCards)
{
	std::cout << "\nPlayer Cards: " << std::endl;
	for (const unsigned short& card : *playerCards) {
		std::cout << card << '\t';
	}
	
	std::cout << "\nDealer Cards: " << std::endl;
	for (const unsigned short& card : *dealerCards) {
		std::cout << card << '\t';
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
