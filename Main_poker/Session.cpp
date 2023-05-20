#include "Session.h"
#include "game_rules.h"
int capasity = 51,previous=51;
Session::Session()
{
    deck.Shufle();
}
Hand Session::Deal()
{
    Hand hand;
    int i = 0;
    for (capasity;capasity!=previous-7;capasity--)
    {   
        hand.SetCard(i, deck.GetCard(capasity)) ;
        i++;
        
    }
    previous = capasity;
    hand.SetCard(i, deck.GetCard(51 - 7));
    return hand;
}

void Session::Winner( Hand hand1, Hand hand2)
{
    if (hand1 > hand2)
        std::cout << "первый выиграл";
        std::cout << "второй выиграл";
}

Deck Session::GetDeck()
{
    return deck;
}
