#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>

class Entity {
	std::vector<unsigned short> cards;

public:
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
	
	unsigned short GetSize()
	{
		return cards.size();
	}
	
	unsigned short GetScore()
	{
		unsigned short score = 0;
		for (const unsigned short& card : cards) {
			score += card;
		}
		
		return score;
	}
};

#endif