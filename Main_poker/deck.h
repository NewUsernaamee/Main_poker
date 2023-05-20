#pragma once
#include <iostream>
#include "Cards.h"
//#include "hand.h"

class Deck
{ private:
    Card card[52];

  public:
	Deck();
	Card GetCard(int x);
	void Shufle();
    friend std::ostream& operator << (std::ostream &out,Deck &Deck);
  class Iterator
  {
  public:
	  Card* current;
	  Card &operator *();
	  Iterator& operator ++();
	  Iterator& operator +(int x);
	  Iterator(Deck& deck);
	  
	 // Iterator(Hand& hand);
	  
	  
  };
};
