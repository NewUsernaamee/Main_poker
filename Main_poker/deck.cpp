#pragma once
#include "deck.h"
#include "cards.h"

std::ostream& operator << (std::ostream &out,Deck &Deck)
{
  for (int i = 0; i < 52; i++)
 {
   out << Deck.card[i];
   if (i==12 || i==25 || i==38)
   {
    out << "\n"; 
   }
  }
  return out;
}

Deck::Deck()
{
  int q=0; 
  for(Suit s=hearts;s<=clubs;s=Suit(s+1))
  {
    for(Cost z=tw;z<=ace;z=Cost(z+1))
    { 
      card[q]= Card(s,z);
      q = q + 1;
    }
  }
 
}

Card &Deck::Iterator::operator*()
{
    return *current;
}

Deck::Iterator& Deck::Iterator::operator++()
{
    current += 1;
    return *this;
}

Deck::Iterator& Deck::Iterator::operator+(int x)
{
    current += x;
    return *this;
}


Deck::Iterator::Iterator(Deck& deck)
{
    current = deck.card;
}




void Deck::Shufle()
{
       Iterator iterator(*this);
     
    for (int i = 0; i < 52; i++)
    {
        Iterator iterator2(*this);
        int x = RandomInt(0, 51);
        iterator2 = iterator2 + x;
        std::swap(*iterator,*iterator2);
        ++iterator;
    }
        
    
}

Card Deck::GetCard(int x)
{
    return card[x];
}
