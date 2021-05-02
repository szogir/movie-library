#ifndef CSALADIFILM_H
#define CSALADIFILM_H
#include "kivetelek.h"
#include "film.h"
#include "memtrace.h"

class CsaladiFilm : public Film{
	int korhatar;

	public:
	   const int getKorhatar() const {
            return korhatar;
        }

        void setKorhatar(const int korhatar) {
            this->korhatar= korhatar;
        }

		std::ostream& kiir(std::ostream& os) const {
            return Film::kiir(os << "csaladi: ") <<","<<korhatar;
        }

        std::istream& beolvas(std::istream & is, bool fb) {
            Film::beolvas(is, fb);
            is.get();
			//is.get();
            if(!(is >> korhatar)){throw AddBajVan("betut olvastam szam helyett");
                }/// ez arra jó ha korhatar elejen betu lenne akkor kivetelt dob, ha a szamon belul akkor hatarolo karakternek szamit
            is.get();
            is.get();
           return is;
        }
};
#endif
