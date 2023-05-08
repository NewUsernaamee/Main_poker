#pragma once
#include "deck.h"
#include "hand.h"
class Session
{
	Deck deck;
public:
	Hand Deal(Deck deck);//раздача
	//void Winner();//сравнение
};

