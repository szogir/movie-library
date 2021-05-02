#ifndef FILMTAR_H
#define FILMTAR_H
#include "film.h"
#include "tomb.hpp"
#include <iostream>
#include "memtrace.h"

class Filmtar{
    private:
        Tomb<Film> tomb;

	public:
	void kiir(std::ostream& os);
	void beolvas_fajlbol(std::istream& is);
	void beolvas_billentyurol(std::istream& is, Film* p);
    void remove(const std::string& cim);
	void add(Film* f) {
        tomb.hozzaad(f);
        }
};
#endif
