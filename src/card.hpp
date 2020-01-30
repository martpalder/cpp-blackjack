#ifndef CARD_HPP
#define CARD_HPP

struct Card {
	unsigned short value;
	
	Card(unsigned short value)
	{
		this->value = value;
	}
};

#endif