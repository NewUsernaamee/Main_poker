#pragma once
#include "hand.h"
#include "game_rules.h"
#include "cards.h"

std::ostream& operator << (std::ostream& out, GameRules chek)
{
    for (int x = 0; x != 7; x++) {
        Card cardnew = chek.hand.GetCard(x);
        out << cardnew;
    }
    return out;
}

Hand GameRules::IsFlesh()
{
    Suit suit = none1;
    Suit suit2 = none3;
  for (int i = 0; i < 3; i++)
  {
    if (hand.GetCard(i).GetSuit() == hand.GetCard(i+1).GetSuit() && hand.GetCard(i).GetSuit() == hand.GetCard(i+2).GetSuit() && hand.GetCard(i).GetSuit() == hand.GetCard(i+3).GetSuit() && hand.GetCard(i).GetSuit() == hand.GetCard(i+4).GetSuit())
    {
      std:: cout << "FLESH!!!!!\n";
      hand.SetFlash();
      break;
    } 
  }
  return hand;
}

GameRules::GameRules(Hand hand)
{
        this->hand = hand;
}


GameRules::~GameRules()
{}



Hand GameRules::CheckStreet ()
{
  for (int i = 0; i < 6; i++)
  { 
    if (int(hand.GetCard(i+1).GetCost() - hand.GetCard(i).GetCost()) == 1 && int(hand.GetCard(i+ 2).GetCost() - hand.GetCard(i+1).GetCost()) == 1 && int(hand.GetCard(i+3).GetCost() - hand.GetCard(i+2).GetCost()) == 1 && int(hand.GetCard(i+4).GetCost() - hand.GetCard(i+3).GetCost()) == 1)
    {
      std:: cout <<"STREET!!!\n";
      hand.SetStreet();
      break;
    }
  }
  return hand;
}

void GameRules::Check2 ()
{
    int countOf2 = 0;
  for ( int i = 0; i < 6; i++)
  {
    if (hand.GetCard(i-1).GetCost() != hand.GetCard(i).GetCost() && hand.GetCard(i).GetCost() == hand.GetCard(i + 1).GetCost() && hand.GetCard(i + 1).GetCost() != hand.GetCard(i + 2).GetCost())
    {
      countOf2=countOf2+1;
    }
  }
  hand.SetPair(countOf2);
  std:: cout <<"\n" <<"number of \"Pairs\" = " << countOf2 << "\n";
 
}

Hand GameRules::Check4 ()
{

  int countOf4=0;
  for ( int i = 0; i < 4; i++)
  {
    if (hand.GetCard(i).GetCost() != hand.GetCard(i - 1).GetCost() && hand.GetCard(i).GetCost() == hand.GetCard(i+1).GetCost() && hand.GetCard(i).GetCost() == hand.GetCard(i+2).GetCost() && hand.GetCard(i).GetCost() == hand.GetCard(i+3).GetCost() && hand.GetCard(i+3).GetCost() != hand.GetCard(i + 4).GetCost())
    {
      countOf4=countOf4+1;
      break;
    }
  }
  hand.SetFour();
  std:: cout <<"\n" <<"number of \"four of kind\" = " << countOf4;
  return hand;
}

Hand GameRules::Check3 ()
{
  int countOf3=0;
 
  for ( int i = 0; i < 5; i++)
  {
    if (hand.GetCard(i).GetCost() != hand.GetCard(i - 1).GetCost() && hand.GetCard(i).GetCost() == hand.GetCard(i+1).GetCost() && hand.GetCard(i+1).GetCost() == hand.GetCard(i+2).GetCost() && hand.GetCard(i + 2).GetCost()!= hand.GetCard(i + 3).GetCost())
    {
        Cost cost1 = none;
        Cost cost2 = none2;
             countOf3=countOf3+1;
      hand.SetCard(i).SetCost(cost1);
      hand.SetCard(i).SetCost(cost2);
      hand.SetCard(i).SetCost(cost1);
    }
  }
  hand.SetThree(countOf3);
  std:: cout <<"\n" <<"number of \"three of kind\" = " << countOf3;
  return hand;
}

GameRules::GameRules(){
Cost cost = none;
Suit suit =none1;
 for (int x=0;x<7;x++)
    {
    this->hand.SetCard(x).SetCost(cost);
    this->hand.SetCard(x).SetSuit(suit);
    }
}