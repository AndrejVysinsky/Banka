#pragma once
#include "SporiaciUcet.h"
class TerminovanyUcet :	public SporiaciUcet
{
public:
	TerminovanyUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena, double urokovaSadzba, int periodicitaPripisovaniaUrokov);

	~TerminovanyUcet();

	virtual void print(std::ostream& os);

	virtual double vypocetUrokov();

private:
	int periodicitaPripisovaniaUrokov; //v mesiacoch - vraj moze byt stvrtrocna, polrocna alebo rocna
};

