
#include "hand.h"
#include "game_rules.h"
#include "cards.h"

std::ostream& operator << (std::ostream& out, GameRules chek)
{
    for (int x = 0; x != 7; x++) {
        out << chek.hand.card[x];
    }
    return out;
}

Hand GameRules::IsFlesh()
{ 
  for (int i = 0; i < 3; i++)
  {
    if (hand.card[i].suit==hand.card[i+1].suit && hand.card[i].suit==hand.card[i+2].suit && hand.card[i].suit==hand.card[i+3].suit && hand.card[i].suit==hand.card[i+4].suit)
    {
      std:: cout << "FLESH!!!!!\n";
      hand.card[i+1].suit=none1;
      hand.card[i+2].suit=none3;
      this->flash=true;
    } 
  }
  return hand;
}

GameRules::GameRules(Hand hand)
{
        this->hand = hand;
}

bool GameRules::operator<(GameRules checker)
{
    if (this->flash > checker.flash)
        return true;
    if (this->street > checker.street)
        return true;
    if (this->four > checker.four)
        return true;
    if (this->three > checker.three)
        return true;
    if (this->pair > checker.pair)
        return true;
    return false;

}

GameRules::~GameRules()
{}

Hand GameRules::CheckStreet ()
{
  for (int i = 0; i < 6; i++)
  { 
    if (int(hand.card[i+1].cost-hand.card[i].cost)==1 && int(hand.card[i+2].cost-hand.card[i+1].cost)==1 && int(hand.card[i+3].cost-hand.card[i+2].cost)==1 && int(hand.card[i+4].cost-hand.card[i+3].cost)==1)
    {
      std:: cout <<"STREET!!!\n";
      hand.card[i+1].cost=none;
      hand.card[i+3].cost=none2;
      this->street=true;
    }
  }
  return hand;
}

void GameRules::Check2 ()
{
    int countOf2 = 0;
  for ( int i = 0; i < 6; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost )
    {
      countOf2=countOf2+1;
    }
  }
  this->pair = countOf2;
  std:: cout <<"\n" <<"number of \"Pairs\" = " << countOf2 << "\n";
 
}

Hand GameRules::Check4 ()
{

  int countOf4=0;
  for ( int i = 0; i < 4; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost && hand.card[i].cost==hand.card[i+2].cost && hand.card[i].cost==hand.card[i+3].cost)
    {
      countOf4=countOf4+1;
      hand.card[i].cost=none;
      hand.card[i+1].cost=none2;
      hand.card[i+2].cost=none;
      hand.card[i+3].cost=none2;
    }
  }
  this->four = countOf4;
  std:: cout <<"\n" <<"number of \"four of kind\" = " << countOf4;
  return hand;
}

Hand GameRules::Check3 ()
{
  int countOf3=0;
 
  for ( int i = 0; i < 5; i++)
  {
    if (hand.card[i].cost==hand.card[i+1].cost && hand.card[i+1].cost==hand.card[i+2].cost)
    {
             countOf3=countOf3+1;
      hand.card[i].cost=none;
      hand.card[i+1].cost=none2;
      hand.card[i+2].cost=none;
    }
  }
  this->three = countOf3;
  std:: cout <<"\n" <<"number of \"three of kind\" = " << countOf3;
  return hand;
}

GameRules::GameRules()
{ for (int x=0;x<7;x++)
    {
    this->hand.card->cost=none;
    this->hand.card->suit = none1;
    }
}