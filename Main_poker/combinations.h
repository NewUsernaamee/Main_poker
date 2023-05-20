#pragma once
#include "cards.h"
#include "map"
#include "hand.h"
#include "vector"
class Combinations
{
private:
	std::map<std::string, std::vector <Hand>>comb;
public:
	Combinations(Hand hand);
friend	std::ostream& operator << (std::ostream& out, Combinations comb);
	
};

