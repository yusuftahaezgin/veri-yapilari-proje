#ifndef DaireselListe_hpp
#define DaireselListe_hpp

#include <iostream>
#include "DaireselDugum.hpp"

class DaireselListe{ // satırları tutan dairesel iki yönlü bağlı liste
public: 
    DaireselListe();
    ~DaireselListe();
    void ekle(char veri);
    int genSayisiBul();
    friend ostream& operator<<(ostream& os,DaireselListe& liste);
    DaireselDugum* ilk;
};


#endif