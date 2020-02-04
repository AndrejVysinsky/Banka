#include "TerminovanyUcet.h"

TerminovanyUcet::TerminovanyUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena, double urokovaSadzba, int periodicitaPripisovaniaUrokov)
	: SporiaciUcet(cislo, meno, priezvisko, vyskaZostatku, mena, urokovaSadzba), periodicitaPripisovaniaUrokov(periodicitaPripisovaniaUrokov)
{
}

TerminovanyUcet::~TerminovanyUcet()
{
	std::cout << "Terminovany ucet bol vymazany.\n";
}

void TerminovanyUcet::print(std::ostream& os)
{
	os << "Terminovany ucet, ";
	Ucet::print(os);
}

double TerminovanyUcet::vypocetUrokov()
{
	int pocetZuroceniZaRok = 12 / periodicitaPripisovaniaUrokov;
	double vyslednaSuma = vyskaZostatku;
	for (int i = 0; i < pocetZuroceniZaRok; i++)
		vyslednaSuma *= 1 + urokovaSadzba / 100;

	return vyslednaSuma - vyskaZostatku;
}
