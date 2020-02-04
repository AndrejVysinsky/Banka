#pragma once
#include "Ucet.h"
class SporiaciUcet : public Ucet
{
public:
	SporiaciUcet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena, double urokovaSazdba);

	~SporiaciUcet();

	virtual void print(std::ostream& os);

	virtual double vypocetUrokov();

protected:
	double urokovaSadzba;
	/*
		priblizne
		pre sporenie od 3,5 do 5
		pre hypoteku od 0,5 do 1,25
	*/
};

