#pragma once
#include "SporiaciUcet.h"
class HypotekarnyUcet :	public SporiaciUcet
{
public:
	HypotekarnyUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena, double urokovaSadzba, int dobaFixacie);

	~HypotekarnyUcet();

	virtual void print(std::ostream& os);

	virtual double vypocetUrokov();

private:
	int dobaFixacie; //v rokoch
	double vyskaHypoteky;
};

