#include "Ucet.h"

Ucet::Ucet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena)
	: cislo(cislo), meno(meno), priezvisko(priezvisko), vyskaZostatku(vyskaZostatku), mena(mena)
{
}

Ucet::~Ucet()
{
	std::cout << "Ucet bol vymazany.\n\n";
}

void Ucet::vkladPenazi(int suma)
{
	vyskaZostatku += suma;
}

void Ucet::vyberPenazi(int suma)
{
	vyskaZostatku -= suma;
}

/*
void Ucet::vypisZostatku()
{
}
*/

double Ucet::vypocetUrokov()
{
	return 0.0;
}

double const& Ucet::getZostatok()
{
	return vyskaZostatku;
}

void Ucet::print(std::ostream& os)
{
	os << "cislo uctu: " << cislo << ", vlastnik uctu : " << meno << " " << priezvisko << "\n";
}

std::ostream& operator<<(std::ostream& os, Ucet& ucet)
{
	ucet.print(os);
	return os;
}
