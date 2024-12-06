#ifndef TekYonluListe_hpp
#define TekYonluListe_hpp
#include "TekYonluDugum.hpp"
#include "DaireselListe.hpp"

class TekYonluListe{// satırların ilk elemanının adresini veri olarak tutan tek yönlü bağlı liste sınıfı
public:
    TekYonluListe(); // kurucu fonk
    ~TekYonluListe();// yok edici fonk (cop kalmamasi icin)
    void ekle(DaireselListe* liste);
    friend ostream& operator<<(ostream& os,TekYonluListe& liste);

    TekYonluDugum* ilk;
    int satirSayisi;
};

#endif