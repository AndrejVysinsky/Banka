#include "Banka.h"


Banka::Banka() : id(0)
{
}

void Banka::zaevidovanieUctu(std::unique_ptr<Ucet> ptr)
{
	ucty.push_back(std::move(ptr));
}

void Banka::vkladPenazi(int index)
{
	std::unique_ptr<Ucet>& ptr = ucty[index];

	std::cout << *ptr;
	std::cout << "\nZadajte sumu, ktora sa ma vlozit na ucet:\n";

	int suma = 0;
	std::cin >> suma;

	ptr->vkladPenazi(suma);
}

void Banka::vyberPenazi(int index)
{
	std::unique_ptr<Ucet>& ptr = ucty[index];

	double zostatok = ptr->getZostatok();

	std::cout << *ptr;
	std::cout << "Zostatok na ucte: " << zostatok << "\n\n";
	std::cout << "Zadajte sumu, ktoru chcete vybrat z uctu:\n";

	int suma = 0;
	std::cin >> suma;

	if (suma > zostatok)
		std::cout << "Na ucte nemate dostatok prostriedkov.\n";
	else
		ptr->vyberPenazi(suma);
}

void Banka::vypisZostatku(int index)
{
	std::unique_ptr<Ucet>& ptr = ucty[index];
	double zostatok = ptr->getZostatok();

	std::cout << *ptr;
	std::cout << "Zostatok na ucte: " << zostatok << "\n";

	vypocetUrokov(ptr);
}

int Banka::vypisVsetkychUctov()
{
	int i = 0;
	for (std::unique_ptr<Ucet> const& ptr : ucty)
		std::cout << ++i << ". " << *ptr;

	std::cout << "\n";

	return i;
}

void Banka::vypocetUrokov(std::unique_ptr<Ucet>& ptr)
{
	double uroky = ptr->vypocetUrokov();
	if (uroky != 0)
		std::cout << "Uroky ku koncu roka: " << uroky << "\n";
}

void Banka::zrusenieUctu(int index)
{
	ucty.erase(ucty.begin() + index);
}

int Banka::getNoveCisloUctu()
{
	return id++;
}
