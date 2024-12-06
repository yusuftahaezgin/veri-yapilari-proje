#ifndef TekYonluDugum_hpp
#define TekYonluDugum_hpp

#include <iostream>
#include "DaireselDugum.hpp"

using namespace std;

class TekYonluDugum{// satırların ilk elemanının adresini veri olarak tutan tek yönlü bağlı liste düğüm sınıfı

public: 
    TekYonluDugum(DaireselDugum* ilk);
    TekYonluDugum* sonraki;
    DaireselDugum* ilkEleman;
};


#endif