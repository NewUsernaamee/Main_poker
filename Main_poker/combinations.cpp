#include "combinations.h"
#include "cards.h"
Combinations::Combinations(Hand hand)

{
	comb["pair"].push_back(hand);
}

std::ostream& operator<<(std::ostream& out, Combinations comb)
{
	std::vector <Hand> ha = comb.comb.at("pair");
	for (int x = 0; x != 7; x++)
	{
		Card cardnew = ha[0].GetCard(x);
		out << cardnew;
	}
	return out;
}
