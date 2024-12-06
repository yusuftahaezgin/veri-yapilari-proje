// @file         DaireselDugum.cpp
// @description  Satırların ilk elemanının adresini veri olarak tutan tek yönlü bağlı liste düğüm sınıfı
// @course       2. Öğretim B grubu
// @assignment   1.Ödev
// @date         16.11.2024
// @author       Yusuf Taha Ezgin

#include "TekYonluDugum.hpp"
#include <iostream>
using namespace std;

TekYonluDugum::TekYonluDugum(DaireselDugum* ilk){
	ilkEleman=ilk;
	sonraki=0;
}