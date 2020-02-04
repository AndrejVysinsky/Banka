#include "BeznyUcet.h"

BeznyUcet::BeznyUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena)
	: Ucet(cislo, meno, priezvisko, vyskaZostatku, mena), pocetOperacii(0)
{
}

BeznyUcet::~BeznyUcet()
{
	std::cout << "Bezny ucet bol vymazany.\n";
}

void BeznyUcet::vkladPenazi(int suma)
{
	Ucet::vkladPenazi(suma);
	pocetOperacii++;
}

void BeznyUcet::vyberPenazi(int suma)
{
	Ucet::vyberPenazi(suma);
	pocetOperacii++;
}

void BeznyUcet::print(std::ostream& os)
{
	os << "Bezny ucet, ";
	Ucet::print(os);
}
