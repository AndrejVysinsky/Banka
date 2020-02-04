#include "SporiaciUcet.h"

SporiaciUcet::SporiaciUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena, double urokovaSadzba)
	: Ucet(cislo, meno, priezvisko, vyskaZostatku, mena), urokovaSadzba(urokovaSadzba)
{
}

SporiaciUcet::~SporiaciUcet()
{
	std::cout << "Sporiaci ucet bol vymazany.\n";
}

void SporiaciUcet::print(std::ostream& os)
{
	os << "Sporiaci ucet, ";
	Ucet::print(os);
}

double SporiaciUcet::vypocetUrokov()
{
	return (vyskaZostatku * urokovaSadzba) / 100;
}
