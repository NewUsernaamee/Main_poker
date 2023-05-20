﻿#pragma once
#include <algorithm>
#include <iostream>
#include <ctime>
#include "deck.h"
#include "game_rules.h"
#include "combinations.h"
#include "cards.h"
#include "hand.h"
#include "Session.h"

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
    
    Session game;
    Hand FirstPlayer = game.Deal();
    for (Hand::Iterator it = FirstPlayer.Begin(); it < FirstPlayer.End(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;
    std::cout << FirstPlayer << std::endl;// написать свой цикл  и свою сортировку через итеры
   // std::sort(FirstPlayer.Begin(), FirstPlayer.End());
    FirstPlayer.Sort();
    std::cout << FirstPlayer;
  /*  Combinations comb(FirstPlayer);
    Hand Copy(FirstPlayer);
    GameRules cheker(Copy);
    cheker.Check4();
    cheker.Check3();
    cheker.Check2();
    cheker=Copy;
    cheker.CheckStreet();
    cheker.IsFlesh();*/
}




int main()
{
    std::srand(time(0));
    BeginGame();
    return 0;
}