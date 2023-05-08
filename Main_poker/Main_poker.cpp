#include <algorithm>
#include <iostream>
#include <ctime>
#include "deck.h"
#include "game_rules.h"
#include "combinations.h"
#include "cards.h"
#include "hand.h"
#include "Session.h"


//
//создание псевдослучайного числа
int RandomInt(int min, int max)
{
    int x;
    x = min + std::rand() / ((RAND_MAX + 1u) / (max - min));
    return x;
}

//запуск игры
void BeginGame()
{
    Deck deck;
    //Session 
    deck.Shufle();
    Hand topSeven(deck);
    Deck::Iterator it(deck);
    Deck::Iterator itEnd(deck);
    itEnd = itEnd + 7;
    std::cout<< std::endl << *itEnd << std::endl;
  //  std::sort(it,itE)
    topSeven.Sort();
    Combinations comb(topSeven);
    Hand Copy;
    std::cout << comb;
    Copy.CopyHand(topSeven);
    GameRules cheker(Copy);
    cheker.Check4();
    cheker.Check3();
    cheker.Check2();
    cheker=Copy;
    cheker.CheckStreet();
    cheker.IsFlesh();
    /*deck.Shufle
    Hand topSeven;
    topSeven.TakeHand(deck);*/
   
    
}




int main()
{
    std::srand(time(0));

    BeginGame();
    return 0;

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"