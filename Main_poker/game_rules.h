#include "hand.h"

class GameRules
{
public:
 Hand hand;
 int pair = 0, three = 0, four = 0;
 bool street = false, flash = false;

    GameRules();

    ~GameRules();
    
    Hand CheckStreet ();
    
    void Check2 ();
    
    Hand Check3 ();
    
    Hand Check4 ();
    
    Hand IsFlesh();
    
    GameRules(Hand hand);
    
    friend std::ostream& operator << (std::ostream& out, GameRules chek);
    
    bool operator < (GameRules checker);

};


