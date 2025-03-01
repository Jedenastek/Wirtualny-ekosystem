#include "organizm.h"

Organizm::Organizm(unsigned short dlugosc_zycia,
                   unsigned short limit_posilkow,
                   unsigned short koszt_potomka):
    limit_posilkow(limit_posilkow),
    koszt_potomka(koszt_potomka),
    licznik_zycia(dlugosc_zycia),
    licznik_posilkow(0)
{

}

bool Organizm::posilek()
{
    if(glodny()){
        licznik_posilkow++;
        return true;
    }else return false;
}

bool Organizm::potomek()
{
    if(paczkujacy())
    {
        licznik_posilkow -= koszt_potomka;
        return true;
    }else return false;
}

void Organizm::krokSymulacji()
{
    if(zywy()) licznik_zycia--;
}
