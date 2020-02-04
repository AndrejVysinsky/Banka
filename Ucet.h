#pragma once
#include <string>
#include <iostream>

class Ucet
{
public:
	Ucet(int cislo, std::string meno, std::string priezvisko, double vyskaZostatku, std::string mena);
	virtual ~Ucet();

	virtual void vkladPenazi(int suma);
	virtual void vyberPenazi(int suma);

	//void vypisZostatku();

	virtual double vypocetUrokov();

	double const& getZostatok();

	virtual void print(std::ostream& os);
	friend std::ostream& operator<< (std::ostream& os, Ucet& ucet);
	

protected:
	int cislo;
	std::string meno;
	std::string priezvisko;
	double vyskaZostatku;
	std::string mena;
};

