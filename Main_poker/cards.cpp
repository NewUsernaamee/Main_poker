#include "Cards.h"
#include <iostream> 
std::ostream& operator << (std::ostream &out,Card &Card)
{
  out<<ToString(Card.cost) << "_";
  out<<ToChar(Card.suit) << "  ";
  return out;
}    


Card::Card()
: suit(none1)
, cost(none)
{}

bool Card::operator>(Card card)
{   
    if (card.cost>cost)
    return true;
}
  
Card::Card(Suit suit_, Cost cost_)
: suit(suit_)
, cost(cost_)
{}

Card::Card(Cost cost_,Suit suit_)
: suit(suit_)
, cost(cost_)
{}

std::string ToChar(Suit suit)
{
  switch (suit)
  {
    case hearts:
        return { 3}; break;// черви
    case diamonds:
     return {4}; break;// ромбы   
    case spades:
     return {5}; break;//  пики чер
    case clubs:
        return { 6}; break;//   крести
    case none1:
     return " "; break;
    case none3:
     return " "; break;
  }        
}

std::string ToString(Cost cost)
{

    switch (cost)
    {
    case none:
        return { " " };  break;
    case none2:
        return { " " };   break;
    case tw:
        return { "2" };  break;
    case tr:
        return { "3" }; break;
    case fo:
        return { "4" };  break;
    case fi:
        return { "5" }; break;
    case si:
        return { "6" };  break;
    case se:
        return { "7" };  break;
    case ei:
        return { "8" }; break;
    case ni:
        return { "9" }; break;
    case te:
        return { "10" }; break;
    case ja:
        return { "J" }; break;
    case qu:
        return { "Q" }; break;
    case ki:
        return { "K" }; break;
    case ace:
        return { "A" }; break;
    default:
        break;
    }
}


/*std::string ToChar_(Cost cost)
{

    switch (cost)
    {
    case none:
        return {  " "};  break;
    case none2:
        return { " "};   break;
    case tw:
        return { "2" };  break;
    case tr:
        return { "3" }; break;
    case fo:
        return { "4" };  break;
    case fi:
        return { "5" }; break;
    case si:
        return { "6" };  break;
    case se:
        return { "7" };  break;
    case ei:
        return { "8" }; break;
    case ni:
        return { "9" }; break;
    case te:
        return { "10" }; break;
    case ja:
        return { "J"}; break;
    case qu:
        return { "Q" }; break;
    case ki:
        return { "K" }; break;
    case ace:
        return { "A" }; break;
    default:
        break;
    }
}*/