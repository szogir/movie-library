#ifndef TAROLO_H
#define TAROLO_H
#include <cstring>
#include "memtrace.h"

template <typename T>
class Tomb{
		T** tomb;
		size_t meret;
	public:
		Tomb(){
			tomb=NULL;
			meret=0;
			}

		~Tomb(){
			for(int i=meret-1; i>-1; i--){
					delete tomb[i];
				}
			delete[] tomb;
			}

		const size_t size() const{
			return meret;
			}

        T* operator[](size_t n)  {
            if (n >= meret)
                throw "tulindexeles!";

            if (n < 0)
                throw "alulindexeles!";

            return tomb[n];
			}

        const T* operator[](const size_t n) const {
            if (n >= meret)
                throw "tulindexeles!";

            if (n < 0)
                throw "alulindexeles!";

            return tomb[n];
			}

		void hozzaad(T* elem){
			if(meret==0){
				delete[] tomb;
				tomb= new T*[1];
				tomb[0]=elem;
				meret=1;
				return;
				}

			T**temp = new T*[meret+1];

			for(size_t i=0;i<meret;i++) {
				temp[i] =tomb[i];
				}

			temp[meret]=elem;
			meret++;
			delete[] tomb;
			tomb= temp;
		}

		void torol( T* elem){
			for(size_t i=0; i<meret; i++){
				if(elem==tomb[i]){
					delete tomb[i];
					for(size_t j =i; j<meret-1; j++){
						tomb[j]=tomb[j+1];
						}
					meret-=1;
					}
				}
			return;
			}
};
#endif
