#ifndef DaireselDugum_hpp
#define DaireselDugum_hpp

#include <iostream>
using namespace std;

class DaireselDugum{ // satırları tutan dairesel iki yönlü bağlı listenin düğüm sınıfı

public: 
    DaireselDugum(char veri);
    char veri;
    DaireselDugum* sonraki;
    DaireselDugum* onceki;
};


#endif