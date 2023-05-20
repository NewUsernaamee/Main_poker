#pragma once
#include "Cards.h"
#include "Deck.h"
#include "iostream"

//хранение руки
class Hand
{ private:
  Card card[7];
  int pair = 0, three = 0, four = 0;
  bool street = false, flash = false;
public:
  Hand();
  Hand(Deck deck);
  Card GetCard(int i);
  Hand SetCard(int i,Card NewCard);
  Card SetCard(int i);
  int  GetPair();
  int  GetThree();
  int  GetFour();
  bool GetFlash();
  bool GetStreet();
  void  SetPair(int x);
  void SetThree(int x);
  void SetFour();
  void SetFlash();
  void SetStreet();
  
  bool operator >(Hand hand);
  bool operator==(Hand hand);
	class Iterator
	{
	private:
		Card* current;
	public:
		void SetCurrent(int x);
		Card& operator *();
		const Card& operator *() const;
		Iterator& operator ++();
		Iterator operator +(int x) const;
		Iterator operator -(Iterator x) const;
		Iterator operator -(const int x) const;
		Iterator (Hand& hand);
		Iterator();
		Iterator& operator-=(int x); // +=   -- -= реалезовать все
		bool operator !=(Iterator it) const ;
		bool operator < (Iterator it) const;
		bool operator >(Iterator it) const;
		bool operator >=(Iterator it) const;
		bool operator <=(Iterator it) const;
		bool operator ==(Iterator it) const;
		Iterator& operator +=(int x);
		Iterator& operator -=(Iterator x);
		Iterator& operator --();
		Iterator operator ++(int x);
		Iterator operator --(int x);
	};
	
friend std::ostream& operator << (std::ostream &out,Hand &PartDeck);
Iterator Begin();
Iterator End();
Hand Sort();// operator > || < Card
};

