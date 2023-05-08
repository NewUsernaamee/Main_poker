#include "combinations.h"

Combinations::Combinations(Hand hand)

{
	comb["pair"].push_back(hand);
}

std::ostream& operator<<(std::ostream& out, Combinations comb)
{
	std::vector <Hand> ha = comb.comb.at("pair");
	for (int x = 0; x != 7; x++)
	{
		out << ha[0].card[x];
	}
	return out;
}
