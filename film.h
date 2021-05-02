#ifndef FILM_H
#define FILM_H
#include "kivetelek.h"
#include <string>
#include "cross_platform.h"
#include "memtrace.h"

class Film{
	std::string cim;
	size_t hossz;
	int ev;

	public:
		Film() {}
		virtual ~Film(){}

        const std::string& getCim() const {
            return cim;
			}

        void setCim(const std::string& cim) {
            this->cim =cim;
			}

        const size_t getHossz() const {
            return hossz;
			}
        void setHossz(const size_t hossz) {
            this->hossz= hossz;
			}

		const int getEv() const{
			return ev;
			}

		void setEv(/*const*/ int ev){
			this->ev=ev;
			}

		virtual std::ostream& kiir(std::ostream& os) const {
            return os<<cim<<","<<hossz<<","<<ev;
        }

        /// az fb parméter azt adja meg hogy fájlból olvasunk-e be
        ///tehát a beolvas_fajlbol vagy beolvas_billenyturol fv hivta-e meg
        virtual std::istream& beolvas(std::istream & is, bool fb) {
           if(fb==1){getline(is, cim, ',');
                    //is.get();
            }else{getline(is,cim,'\n');
                    //is.get();
            }

            if (!(is >> hossz)){ throw AddBajVan("betut olvastam szam helyett");
                } ///ez arra jó ha a hossz elejé betu lenne akkor kivételt dob, igy nem kerul végtelen ciklusba, ha a számon belul van a betu, akkor az határoló karakternek minõsül
            is.get();
            if (!(is >> ev)){throw AddBajVan("betut olvastam szam helyett");
               } ///ez arra jó ha a ev elején betu lenne akkor kivételt dob, igy nem kerul végtelen ciklusba, ha a számon belul van a betu, akkor az határoló karakternek minõsül

        return is;
		}
};
#endif
