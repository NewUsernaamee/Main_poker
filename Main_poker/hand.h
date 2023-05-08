#pragma once
#include "Cards.h"
#include "Deck.h"
#include "iostream"

//хранение руки
class Hand
{
public:
  Card card[7];
  Hand();
  Hand(Deck deck);
	
friend std::ostream& operator << (std::ostream &out,Hand &PartDeck);

Hand Sort();// operator > || < Card

Hand CopyHand(Hand deck7);//Hand &operator =(Card &card1);

};

