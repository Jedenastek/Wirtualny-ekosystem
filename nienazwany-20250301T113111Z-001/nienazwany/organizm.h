#ifndef ORGANIZM_H
#define ORGANIZM_H


class Organizm
{
public:
    const unsigned short limit_posilkow;
    const unsigned short koszt_potomka;

private:
    unsigned short licznik_zycia;
    unsigned short licznik_posilkow;

public:
    Organizm(unsigned short dlugosc_zycia,
             unsigned short limit_posilkow,
             unsigned short koszt_potomka);
    bool zywy() const{
        return licznik_zycia > 0;
    }

    bool glodny() const{
        return zywy() && licznik_posilkow < limit_posilkow;
    }

    bool paczkujacy() const{
        return zywy() && licznik_posilkow > koszt_potomka;
    }

    unsigned short stan_licznika_zycia() const
    {
        return licznik_zycia;
    }

    unsigned short stan_licznika_posilkow() const
    {
        return licznik_posilkow;
    }

    bool posilek();
    bool potomek();

    void krokSymulacji();
};

#endif // ORGANIZM_H
