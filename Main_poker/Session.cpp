#include "Session.h"
#include "game_rules.h"
int capasity = 51,previous=51;
Hand Session::Deal(Deck deck)
{
    Hand hand;
    int i = 0;
    for (capasity;capasity!=previous-7;capasity--)
    {   
        hand.card[i] = deck.card[capasity];
        i++;
        
    }
    previous = capasity;
    hand.card[i] = deck.card[51 - 7];
    return hand;
}

/*void Session::Winner( hand1, Hand hand2)
{
    if (hand1 > hand2)
        std::cout << "первый выиграл";
        std::cout << "второй выиграл";
}*/
