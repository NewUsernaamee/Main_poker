#pragma once
#include <iostream>
#include "Cards.h"
#include "hand.h"

class Deck
{ public:
    Card card[52];
	Deck();
  
	void Shufle();
    friend std::ostream& operator << (std::ostream &out,Deck &Deck);
  public:
  class Iterator
  {
  public:
	  Card* current;
	  Card &operator *();
	  Iterator& operator ++();
	  Iterator& operator +(int x);
	  Iterator(Deck& deck);
	  Iterator(Hand& hand);
	  
	  
  };
};
