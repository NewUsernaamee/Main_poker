#pragma once
#include "Hand.h"
#include"Cards.h"
#include"Deck.h"

std::ostream& operator << (std::ostream &out,Hand &Hand)
  {
    for (int i = 0; i <7; i++)
    {
      out << Hand.card[i];
    }  
    return out;
  }

/*Hand& Hand::operator =(Card& card1)
{
  card->suit=card1.suit;
  card->cost=card1.cost;
  return *this;
}*/

 Hand::Hand(Deck deck)
{ 
  for (int i = 0; i < 7; i++)
  {
    card[i]=deck.card[i];
  }
}



Hand Hand::Sort()
{
  Card temp;
  int size=7;
  for (int i = 0; i < size - 1; i++) 
  {
    for (int j = 0; j < size - i - 1; j++) 
    {
      if (card[j]> card[j + 1]) 
      {
        temp = card[j];
        card[j] = card[j + 1];
        card[j + 1] = temp;
      }
    }
  }
  return *this; 
}

Hand Hand::CopyHand(Hand deck7)
{  
  for (int i = 0; i < 7; i++)
  {
     card[i]=deck7.card[i];
  }
  return deck7;
}


Hand::Hand()
{ 
  for(int q=0; q<7; q++)
  { 
    card[q]= Card(none1,none2);
  }
}

