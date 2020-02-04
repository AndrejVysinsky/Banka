#include "HypotekarnyUcet.h"

HypotekarnyUcet::HypotekarnyUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena, double urokovaSadzba, int dobaFixacie)
	: SporiaciUcet(cislo, meno, priezvisko, vyskaZostatku, mena, urokovaSadzba), dobaFixacie(dobaFixacie), vyskaHypoteky(vyskaZostatku)
{
}

HypotekarnyUcet::~HypotekarnyUcet()
{
	std::cout << "Hypotekarny ucet bol vymazany.\n";
}

void HypotekarnyUcet::print(std::ostream& os)
{
	os << "Hypotekarny ucet, ";
	Ucet::print(os);
}

double HypotekarnyUcet::vypocetUrokov()
{
	return (vyskaHypoteky * urokovaSadzba) / 100;
}
