#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "filmtar.h"
#include "dokufilm.h"
#include "romifilm.h"
#include "csaladifilm.h"
#include "kivetelek.h"
#include "tomb.hpp"
#include "test.cpp"
#include "memtrace.h"

using namespace std;

int main(){
    teszteles();
    ifstream be ;
    ofstream ki;
    Filmtar tar; /// itt hozom létre a tarolo peldanyt

    try{
        be.open("adatfajl.txt");
        tar.beolvas_fajlbol(be);
        be.close();
        char o; //ha ez int lenne és betűt irunk bele akkor végtelen ciklus lenne;
        bool fuss=true;
       while(fuss){ //menu !be.eof()
            cout<<endl<<"#----------------------------------------#"<<endl
            <<"| Valasszon az alabbi lehetosegek kozul: |"<<endl
            <<"#----------------------------------------#"<<endl
            <<"| 1: Adatbazis kepernyore irasa          |"<<endl
            <<"| 2: Film hozzaadasa                     |"<<endl
            <<"| 3: Film torlese                        |"<<endl
            <<"| 0: Futas vege es mentes                |"<<endl
            <<"#----------------------------------------#"<<endl;
           // cin>>o;
            if(!(cin>>o)){
                    throw "nem sikerult cinelni";
            }

            switch(o){
                case '1':{cout<<endl<<"Az adatbazis jelenlegi allapota:"<<endl;
                        tar.kiir(cout);
                        break;
                }
                case '2':{    char m; ///film hozzaadasa billyentyuzettel
                            cout<<endl<<"#--------------------------------#"<<endl
                            <<"| Milyen mufaju filmet ad hozza? |"<<endl
                            <<"#--------------------------------#"<<endl
                            <<"| C: Csaladi                     |"<<endl
                            <<"| D: Dokumentum                  |"<<endl
                            <<"| R: Romantikus                  |"<<endl
                            <<"| X: Vissza                      |"<<endl
                            <<"#--------------------------------#"<<endl;
                            cin>>m;
                                switch(tolower(m)){
                                            case 'c':{Film* p = new CsaladiFilm();
                                                    cout<<endl<<"Adja meg a film cimet, hosszat (percben), megjelenesi evet es a korhatart!"<<endl;
                                                    tar.beolvas_billentyurol(cin, p);
                                                    break;
                                            }
                                            case 'd':{Film* p = new DokuFilm();
                                                    cout<<endl<<"Adja meg a film cimet, hosszat (percben), megjelenesi evet es a leirast!"<<endl;
                                                    tar.beolvas_billentyurol(cin,p);
                                                    break;
                                            }
                                            case 'r':{Film* p = new RomiFilm();
                                                    cout<<endl<<"Adja meg a film cimet, hosszat (percben), megjelenesi evet, valamint a noi es ferfi foszereploket!"<<endl;
                                                    tar.beolvas_billentyurol(cin,p);
                                                    break;
                                            }
                                            case 'x':{break;
                                            }
                                            default:{cout<<"helytelen bevitel"<<endl;
                                                    break;
                                            }
                                }
                    break;
                }
                case '3':{string torlendo; ///adott cimu filmet torlunk
                                    cout<<"Irja be a torolni kivant film cimet:"<<endl;
                                    cin.get(); ///azert kell hogy tobb szavas cimeket is be tudjon olvasni
                                    getline(cin, torlendo);
                                    cout<<"Torlendo:'"<<torlendo<<"'"<<endl;
                                    tar.remove(torlendo);
                                    break;
                }
                case '0':{fuss=false;
                        break;
                }
                default: {cout<<"helytelen bevitel"<<endl;
                         break;
                }
            }
        }
        ki.open("adatfajl.txt");
        tar.kiir(ki);
        ki.close();

    }catch(BeBajVan&){
        be.close();
        cout<<endl<<"Az adatfajl tatalma hibas, ezert nem tudtam beolvasni."<<endl;
    }catch(AddBajVan&){cout<<endl<<"Helytelen bevitel. Nem sikerult a hozzaadas."<<endl;
        ki.open("adatfajl.txt");
        tar.kiir(ki);
        ki.close();
    }catch(...){cout<<endl<<"Valami nem klappolt."<<endl;
        ki.open("adatfajl.txt");
        tar.kiir(ki);
        ki.close();
    }
    cout<<"Mentes... A program futasa befejezodik"<<endl;
    return 0;
}

