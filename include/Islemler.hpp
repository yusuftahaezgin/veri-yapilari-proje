#ifndef Islemler_hpp
#define Islemler_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "TekYonluDugum.hpp"
#include "DaireselDugum.hpp"
#include "TekYonluListe.hpp"

using namespace std;

class Islemler{ 
public: 
   void mutasyon(int satirNo, int sutunNo,TekYonluListe* liste);
   void caprazlama(int satirNo1, int satirNo2,TekYonluListe* liste);
   void ekranaYaz(TekYonluListe* liste);
   void otomatikIslemler(const string& dosyaAdi,TekYonluListe*liste);
private:
   TekYonluDugum* satirBul(int satirNo,TekYonluListe* liste);
   DaireselDugum* satirVeSutunBul(int satirNo, int sutunNo,TekYonluListe* liste);
   DaireselDugum* ikiyeAyir(int satirNo,TekYonluListe* liste,int ortaIndex);
   void birlestir(DaireselDugum* liste1BasAdres,DaireselDugum* liste1ortaAdres,DaireselDugum* liste2BasAdres,DaireselDugum* liste2ortaAdres,int liste1GenSayisi,int liste2GenSayisi,TekYonluListe* liste);

};



#endif
