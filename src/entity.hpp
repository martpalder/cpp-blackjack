#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include "card.hpp"

class Entity {
public:
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
	
	unsigned short GetSize()
	{
		return cards.size();
	}
	
	unsigned short GetScore()
	{
		unsigned short score = 0;
		for (const Card& card : cards) {
			score += card.value;
		}
		
		return score;
	}

private:
	std::vector<Card> cards;
};

#endif