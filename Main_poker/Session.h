#pragma once
#include "deck.h"
#include "hand.h"
class Session
{	
private:
	Deck deck;
public:
	Session();
	Hand Deal();//�������
	void Winner(Hand hand,Hand hand2);//���������
	Deck GetDeck();//�������� ������
};

