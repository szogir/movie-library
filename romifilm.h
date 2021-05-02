#ifndef ROMIFILM_H
#define ROMIFILM_H
#include "film.h"

#include "memtrace.h"

class RomiFilm : public Film{
	std::string csaj;
	std::string srac;

	public:
        const std::string& getCsaj() const {
            return csaj;
        }

        void setCsaj(const std::string& csaj) {
           this->csaj=csaj;
        }

        const std::string& getSrac() const {
            return srac;
        }

        void setSrac(const std::string& srac){
            this->srac=srac;
        }

        std::ostream& kiir(std::ostream& os) const {
            return Film::kiir(os << "romi: ")<<","<<csaj<<","<<srac;
        }

        std::istream& beolvas(std::istream & is, bool fb) {
            Film::beolvas(is, fb);
            is.get();
            //is.get();
            if(fb==1){getline(is, csaj, ',');
                }else{getline(is, csaj, '\n');
                }
            cp::getline(is, srac);
            //is.get();
            return is;
        }
};
#endif
