#pragma once
#include "Ucet.h"
#include "BeznyUcet.h"
#include "HypotekarnyUcet.h"
#include "SporiaciUcet.h"
#include "TerminovanyUcet.h"

#include <memory>
#include <vector>
#include <iostream>

class Banka
{
public:
	Banka();
	~Banka() = default;

	void zaevidovanieUctu(std::unique_ptr<Ucet> ptr);
	void vkladPenazi(int index);
	void vyberPenazi(int index);
	void vypisZostatku(int index);
	int vypisVsetkychUctov();
	void vypocetUrokov(std::unique_ptr<Ucet>& ptr);
	void zrusenieUctu(int index);

	int getNoveCisloUctu();

private:
	std::vector<std::unique_ptr<Ucet>> ucty;
	int id;
};

