#pragma once
#include "deck.h"
#include "hand.h"
class Session
{	
private:
	Deck deck;
public:
	Session();
	Hand Deal();//раздача
	void Winner(Hand hand,Hand hand2);//сравнение
	Deck GetDeck();//возможно лишний
};

