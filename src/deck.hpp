#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include <algorithm>

class Deck {
	std::vector<unsigned short> cards;

public:
	Deck()
	{
		for (unsigned short i = 2; i < 12; ++i) {
			for (unsigned short j = 0; j < 4; ++j) {
				cards.push_back(i);
				if (i == 10) {
					cards.push_back(i);
					cards.push_back(i);
					cards.push_back(i);
				}
			}
		}
	}
	
	void ShuffleCards()
	{
		std::random_shuffle(cards.begin(), cards.end());
	}
	
	void AddCard(unsigned short card)
	{
		cards.push_back(card);
	}
	
	void RemoveCard()
	{
		cards.pop_back();
	}
	
	std::vector<unsigned short>* GetCards()
	{
		return &cards;
	}
	
	unsigned short GetSize() const
	{
		return cards.size();
	}
};

#endif