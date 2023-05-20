#pragma once
#include "hand.h"

class GameRules
{
private:
 Hand hand;
public:
  GameRules();
  ~GameRules();
  Hand CheckStreet ();
  void Check2 ();
  Hand Check3();
  Hand Check4 ();
  Hand IsFlesh();
  GameRules(Hand hand);
  friend std::ostream& operator << (std::ostream& out, GameRules chek);
};


