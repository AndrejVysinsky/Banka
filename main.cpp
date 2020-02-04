#include <iostream>
#include "Banka.h"

Banka banka;

bool isRunning = true;

void menu();
void vytvorenieUctu();

int main()
{
    while (isRunning)
        menu();

    return 0;
}

void menu()
{
    system("cls");
    std::cout << "1. Vytvorenie uctu\n";
    std::cout << "2. Zrusenie uctu\n";
    std::cout << "3. Vklad penazi\n";
    std::cout << "4. Vyber z uctu\n";
    std::cout << "5. Vypis zostatku na ucte\n";
    std::cout << "6. Vypis vsetkych uctov\n";
    std::cout << "7. Koniec\n\n";

    int vyber = 0;
    std::cin >> vyber;

    system("cls");

    if (vyber == 7)
    {
        isRunning = false;
        return;
    }

    if (vyber == 1)
    {
        vytvorenieUctu();
    }
    else
    {            
        int pocet = banka.vypisVsetkychUctov();

        if (vyber != 6 && pocet != 0)
        {
            std::cout << "Vyberte ucet zo zoznamu:\n";

            int vyberUctu = 0;
            std::cin >> vyberUctu;

            system("cls");
            switch (vyber)
            {
            case 2:
                banka.zrusenieUctu(vyberUctu - 1);
                break;
            case 3:
                banka.vkladPenazi(vyberUctu - 1);
                break;
            case 4:
                banka.vyberPenazi(vyberUctu - 1);
                break;
            case 5:
                banka.vypisZostatku(vyberUctu - 1);
                break;
            }
        }
    }

    std::cout << "Pre navrat do menu stlacte enter\n";
    std::cin.ignore(2);
}

void vytvorenieUctu()
{
    std::string meno;
    std::string priezvisko;

    std::cout << "Zadajte svoje meno a priezvisko:\n";
    std::cin >> meno >> priezvisko;

    std::cout << "\nZvolte si pozadovany typ uctu:\n";
    std::cout << "1. Bezny ucet\n";
    std::cout << "2. Sporiaci ucet\n";
    std::cout << "3. Terminovany ucet\n";
    std::cout << "4. Hypotekarny ucet\n";

    int typUctu;
    std::cin >> typUctu;

    std::cout << "\nZadajte typ meny:\n";

    std::string mena;
    std::cin >> mena;

    std::unique_ptr<Ucet> novyUcet;

    int vyskaHypoteky = 0;
    int dobaFixacie = 0;
    if (typUctu == 4)
    {
        std::cout << "\nZadajte vysku hypoteky:\n";
        std::cin >> vyskaHypoteky;
        std::cout << "\nZadajte dobu fixacie:\n";
        std::cin >> dobaFixacie;
    }

    switch (typUctu)
    {
    case 1:
        novyUcet = std::make_unique<BeznyUcet>(banka.getNoveCisloUctu(), meno, priezvisko, 0, mena);
        break;
    case 2:
        novyUcet = std::make_unique<SporiaciUcet>(banka.getNoveCisloUctu(), meno, priezvisko, 0, mena, 3.5);
        break;
    case 3:
        novyUcet = std::make_unique<TerminovanyUcet>(banka.getNoveCisloUctu(), meno, priezvisko, 0, mena, 3.5, 6);
        break;
    case 4:
        novyUcet = std::make_unique<HypotekarnyUcet>(banka.getNoveCisloUctu(), meno, priezvisko, vyskaHypoteky, mena, 0.5, dobaFixacie);
        break;
    }
    
    banka.zaevidovanieUctu(std::move(novyUcet));
}
