#include "gtest_lite.h"
#include "filmtar.h"
#include "film.h"
#include "tomb.hpp"
#include "csaladifilm.h"
#include "dokufilm.h"
#include "romifilm.h"
#include "kivetelek.h"
#include "memtrace.h"

    ///kiirja az osszes filmet adatokkal a tarolobol
	void Filmtar::kiir(std::ostream& os) {
        for (size_t i=0; i<tomb.size(); i++) {
			tomb[i]->kiir(os)<<std::endl;
	 }
	}
 /// torli a megfelelo nevu filmet
    void Filmtar::remove(const std::string& cim) {
         for(size_t i=0; i< tomb.size(); i++){
			if(tomb[i]->getCim()==cim) {
				tomb.torol(tomb[i]);
				std::cout<<"sikeres torles :)"<<std::endl;
				return;
				}
			}
			std::cout<<"Nem tudtam torolni, mert nem talaltam ilyen cimu filmet :("<<std::endl;
        }

    ///fajlbol egesz adatbazist olvas be fajlbol (ciklus)
	void Filmtar::beolvas_fajlbol(std::istream& is) {
		std::string mufaj;
		//std::cout<< is << std::endl;
		while(getline(is, mufaj, ':')) {
			is.get();
			Film *p;
			if (mufaj == "romi") {
				p = new RomiFilm();
				//std::cout<< "van romi"<< std::endl;
			}
			else if (mufaj == "doku") {
				p = new DokuFilm();
				//std::cout<<"van doku"<< std::endl;
			}
			else if (mufaj == "csaladi") {
				p = new CsaladiFilm();
                    //std::cout<<"van csaladi"<< std::endl;
			} else throw BeBajVan("Nem sikerult beolvasni"); /// a mainben van ami elkapja es bezarja a fajlt
			p->beolvas(is,1);
			tomb.hozzaad(p);
		}
}
    ///standard inputrol egy film adatait olvassa be
    void Filmtar::beolvas_billentyurol(std::istream& is, Film* p){
        is.get();
        try{
        p->beolvas(is,0);
        }catch(...){
            //std::cout<<std::endl<<"Ne irj betut a hosszba/evbe/korhatarba! A fene egyen meg!"<<std::endl;
            delete p;
            throw AddBajVan("Nem sikerult hozzaadni.");///mainben van ami elkapja
        }
        tomb.hozzaad(p);
    }
