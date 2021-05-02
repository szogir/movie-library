#include <iostream>
#include <sstream>
//#include "filmtar.h"
#include "tomb.hpp"
#include "romifilm.h"
#include "dokufilm.h"
#include "csaladifilm.h"
#include "gtest_lite.h"
#include "memtrace.h"

void inline teszteles(){
/// az elso 3 teszt: letrehoz 1-1 filmet mindharom mufajból, megnezi hogy a getterek a megfelelo adatokat adjak e vissza, torli(destruktor)

    TEST(Tesztek, Test1){
        CsaladiFilm* cs = new CsaladiFilm();
        cs->setCim("Ez egy csaladi film");
        cs->setHossz(120);
        cs->setEv(2009);
        cs->setKorhatar(12);

        EXPECT_STREQ(cs->getCim().c_str(), "Ez egy csaladi film");
        EXPECT_EQ(120.,cs->getHossz());
        EXPECT_EQ(2009.,cs->getEv());
        EXPECT_EQ(12.,cs->getKorhatar());

        delete cs;
    }END


    TEST(Tesztek, Test2){
        RomiFilm* r = new RomiFilm();
        r->setCim("Ez egy romantikus film");
        r->setHossz(150);
        r->setEv(2002);
        r->setCsaj("Isaura");
        r->setSrac("Elemer");

        EXPECT_STREQ(r->getCim().c_str(), "Ez egy romantikus film");
        EXPECT_EQ(150.,r->getHossz());
        EXPECT_EQ(2002.,r->getEv());
        EXPECT_STREQ(r->getCsaj().c_str(), "Isaura");
        EXPECT_STREQ(r->getSrac().c_str(), "Elemer");

        delete r;
    }END

    TEST(Tesztek, Test3){
        DokuFilm* d = new DokuFilm();
        d->setCim("Ez egy dokumentumfilm");
        d->setHossz(180);
        d->setEv(1999);
        d->setLeiras("Ez egy rohadt hosszu leiras.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.Vege");

        EXPECT_STREQ(d->getCim().c_str(), "Ez egy dokumentumfilm");
        EXPECT_EQ(180.,d->getHossz());
        EXPECT_EQ(1999.,d->getEv());
        EXPECT_STREQ(d->getLeiras().c_str(), "Ez egy rohadt hosszu leiras.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.Vege");

        delete d;

    }END

/// a negyedik teszt letrehoz egy tarolo peldanyt
///  megfelo meretu?
///  indexeles tesztelese
    TEST(Tesztek, Test4){
        Tomb<Film> ftar;
        EXPECT_EQ(ftar.size(), 0.);

        DokuFilm* d = new DokuFilm();
        d->setCim("Ez egy dokumentumfilm");
        d->setHossz(180);
        d->setEv(1999);
        d->setLeiras("Ez egy rohadt hosszu leiras. Lorem ipsum dolor sit amet, consectetur adipiscing elit,sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.Vege");
        ftar.hozzaad(d);


        CsaladiFilm* cs = new CsaladiFilm();
        cs->setCim("Ez egy csaladi film");
        cs->setHossz(120);
        cs->setEv(2009);
        cs->setKorhatar(12);
        ftar.hozzaad(cs);

        EXPECT_EQ(ftar.size(), 2.);

        std::stringstream s;
        ftar[1]->kiir(s);
        EXPECT_STREQ(s.str().c_str(), "csaladi: Ez egy csaladi film,120,2009,12");
        EXPECT_ANY_THROW(ftar[9]->kiir(s));

    }END
}

