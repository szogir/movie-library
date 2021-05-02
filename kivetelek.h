#ifndef KIVETELEK_H
#define KIVETELEK_H
#include "memtrace.h"
///kivételosztály a hibas adatfájl megnyitasahoz
class BeBajVan {
public:
    BeBajVan(const std::string&) {}
};

///kivételosztály a hibás hozzáadáshoz
class AddBajVan {
public:
    AddBajVan(const std::string&) {}
};
#endif
