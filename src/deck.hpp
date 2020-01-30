#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <algorithm>
#include "card.hpp"

class Deck {
public:
	Deck()
	{
		for (unsigned short i = 2; i < 12; ++i) {
			for (unsigned short j = 0; j < 4; ++j) {
				Card aCard(i);
				cards.push_back(aCard);
				if (i == 10) {
					for (unsigned short k = 0; k < 3; ++k) {
						cards.push_back(aCard);
					}
				}
			}
		}
	}
	
	void ShuffleCards()
	{
		std::random_shuffle(cards.begin(), cards.end());
	}
	
	void AddCard(Card aCard)
	{
		cards.push_back(aCard);
	}
	
	void RemoveCard()
	{
		cards.pop_back();
	}
	
	std::vector<Card>* GetCards()
	{
		return &cards;
	}
	
	unsigned short GetSize() const
	{
		return cards.size();
	}

private:
	std::vector<Card> cards;
};

#endif