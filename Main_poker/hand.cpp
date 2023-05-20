#pragma once
#include "Hand.h"
#include"Cards.h"
#include"Deck.h"
#include "game_rules.h"

std::ostream& operator << (std::ostream &out,Hand &Hand)
  {
    for (int i = 0; i <7; i++)
    {
      out << Hand.card[i];
    }  
    return out;
  }

 Hand::Hand(Deck deck)
{ 
  for (int i = 0; i < 7; i++)
  {
    card[i]=deck.GetCard(i);
  }
}

 Card Hand::GetCard(int i)
 {
     return card[i];
 }

 Hand Hand::SetCard(int i,Card NewCard)
 {
     card[i] = NewCard;
     return *this;
 }

 Card Hand::SetCard(int i)
 {
     return card[i];
 }

 Hand::Iterator Hand::Begin()
 {
     Hand::Iterator iterBegin(*this);

     return iterBegin;
 }

 Hand::Iterator Hand::End()
 {
     Hand::Iterator iterEnd(*this);
     iterEnd.SetCurrent(7);
     return iterEnd;
 }

 Hand Hand::Sort()
{
  Card temp;
  int size=7;
  for (Hand::Iterator it=this->Begin(); it!=this->End() - 1; ++it)
  {
    for (Hand::Iterator it2 = this->Begin(); it2 != this->End() - 1; ++it2)
    {
      if (*it2> *(it2 + 1))
      {
        temp = *it2;
        *it2 = *(it2+1);
        *(it2+1) = temp;
      }
    }
  }
  return *this; 
}

Hand::Hand()
{ 
  for(int q=0; q<7; q++)
  { 
    card[q]= Card(none1,none2);
  }
}

bool Hand::operator==(Hand hand)
{
    if (this->GetFlash() == hand.GetFlash())
        return true;
    if (this->GetStreet() == hand.GetStreet())
        return true;
    if (this->GetFour() == hand.GetFour())
        return true;
    if (this->GetThree() == hand.GetThree())
        return true;

    if (this->GetPair() == hand.GetPair())
        return true;
    return false;


}

int Hand::GetPair()
{
    return pair;
}

int Hand::GetThree()
{
    return three;
}

int Hand::GetFour()
{
    return four;
}

bool Hand::GetFlash()
{
    return flash;
}

bool Hand::GetStreet()
{
    return street;
}

void Hand::SetPair(int x)
{
    pair = x;
}

void Hand::SetThree(int x)
{
    three = x;
}

void Hand::SetFour()
{
    four = 1;
}

void Hand::SetFlash()
{
    flash = true;
}

void Hand::SetStreet()
{
    street = true;
}

bool Hand::operator>(Hand hand)
{
    if (this->GetFlash() > hand.GetFlash())
        return true;
    if (this->GetStreet() > hand.GetStreet())
        return true;
    if (this->GetFour() > hand.GetFour())
        return true;
    if (this->GetThree() > hand.GetThree())
        return true;
    if (this->GetPair() > hand.GetPair())
        return true;
    return false;
}

void Hand::Iterator::SetCurrent(int x)
{
    this->current += x;
}

Card& Hand::Iterator::operator*()
{
    return *current;
}

const Card& Hand::Iterator::operator*() const
{
    return *current;
}

Hand::Iterator& Hand::Iterator::operator++()
{
    current += 1;
    return *this;
}

Hand::Iterator Hand::Iterator::operator+(int x)const
{
    Hand::Iterator NewIter=*this;
    NewIter.current = NewIter.current + x;
    
    return NewIter;
}

Hand::Iterator Hand::Iterator::operator-( int x) const
{
    Hand::Iterator NewIter = *this;
    NewIter.current = NewIter.current - x;
    return NewIter;
}

Hand::Iterator Hand::Iterator::operator-(Hand::Iterator x) const
{
    Hand::Iterator NewIter=*this;
    int diff = NewIter.current - x.current;
    NewIter -= diff;
   
    return NewIter;
}

Hand::Iterator::Iterator(Hand& hand)
{
    current = hand.card;
}

Hand::Iterator::Iterator()
{
    current = 0;
}

Hand::Iterator& Hand::Iterator::operator-=(int x)
{
    this->current -= x;
    return *this;
}

bool Hand::Iterator::operator<(Iterator it) const
{
    if (this->current < it.current)
        return true;
    return false;
}

bool Hand::Iterator::operator>(Iterator it) const
{
    if (this->current<it.current)
        return false;
    return true;
}

bool Hand::Iterator::operator>=(Iterator it) const
{
    if (this->current <= it.current)
        return false;
    return true;
}

bool Hand::Iterator::operator<=(Iterator it) const
{
    if (this->current >= it.current)
        return false;
    return true;
}

bool Hand::Iterator::operator==(Iterator it) const
{
    if (this->current == it.current)
        return false;
    return true;
}

Hand::Iterator& Hand::Iterator::operator+=(int x)
{
    
    this->current += x;
    return *this;
}

Hand::Iterator& Hand::Iterator::operator-=(Iterator x)
{
    
    int diff = this->current - x.current;
    this->current -= diff;
    return *this;
}

Hand::Iterator& Hand::Iterator::operator--()
{
    current--;
    return *this;
}

Hand::Iterator Hand::Iterator::operator++(int x)
{
    current++;
    return *this;
}

Hand::Iterator Hand::Iterator::operator--(int x)
{
    current++;
    return Iterator();
}

bool Hand::Iterator::operator!=(Iterator it) const
{   if (this->current==it.current)
    return false;
    return true;
}
