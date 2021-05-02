#ifndef DOKUFILM_H
#define DOKUFILM_H
#include "film.h"

#include "memtrace.h"

class DokuFilm : public Film{
	std::string leiras;

	public:
        const std::string& getLeiras() const {
            return leiras;
        }

        void setLeiras(const std::string& leiras) {
           this->leiras=leiras;
        }

        std::ostream& kiir(std::ostream& os) const {
            return Film::kiir(os << "doku: ")<<","<<leiras;
        }

        std::istream& beolvas(std::istream & is, bool fb) {
            Film::beolvas(is, fb);
			is.get();
            //is.get();
            cp::getline(is, leiras);
            //is.get();
            return is;
        }
};
#endif
