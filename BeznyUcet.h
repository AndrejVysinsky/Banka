#pragma once
#include "Ucet.h"
class BeznyUcet : public Ucet
{
public:
	BeznyUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena);

	~BeznyUcet();

	virtual void vkladPenazi(int suma);
	virtual void vyberPenazi(int suma);

	virtual void print(std::ostream& os);

private:
	int pocetOperacii;
};

