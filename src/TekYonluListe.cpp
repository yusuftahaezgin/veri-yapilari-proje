// @file         DaireselDugum.cpp
// @description  Satırların ilk elemanının adresini veri olarak tutan tek yönlü bağlı liste sınıfı
// @course       2. Öğretim B grubu
// @assignment   1.Ödev
// @date         16.11.2024
// @author       Yusuf Taha Ezgin

#include "TekYonluListe.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

TekYonluListe::TekYonluListe()
{
    ilk=0;
    satirSayisi=0;
}

TekYonluListe::~TekYonluListe()
{
    TekYonluDugum *gec=ilk;
    while(gec!=0){ 
        TekYonluDugum* sil=gec;
        gec=gec->sonraki;
        delete sil;
        //cout<<sil<<" silindi siradaki " <<gec<<endl;
    }
}

void TekYonluListe::ekle(DaireselListe* liste)
{
    TekYonluDugum* yeni=new TekYonluDugum(liste->ilk);
    if(ilk==0){ // bagli listede hic eleman yoksa
        ilk=yeni;  
    }
    else{
        TekYonluDugum* gec=ilk;
    
        while(gec->sonraki!=0){
            gec=gec->sonraki;
        }

        gec->sonraki=yeni;
    }
    satirSayisi++;
}

ostream& operator<<(ostream& os,TekYonluListe& liste){
    /*os<<"-------------------------------------------------------------"<<endl;
    os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"sonraki"<<endl;

    TekYonluDugum* gecici=liste.ilk;

    while(gecici!=0)
    {
        os<<setw(15)<<gecici<<setw(15)<<gecici->ilkEleman<<setw(15)<<gecici->sonraki<<endl;
        gecici=gecici->sonraki;
    }

    os<<"-------------------------------------------------------------"<<endl<<endl;*/

    
    TekYonluDugum* gecici2=liste.ilk;
    int satirSirasi=0;
    while(gecici2!=0)
    {
        /*os<<"-------------------------------------------------------------"<<endl;
        os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;*/
        DaireselDugum* gecici3=gecici2->ilkEleman;
        cout<<satirSirasi<<"=> ";
        do
        {
            /*os<<setw(15)<<gecici2->ilkEleman<<setw(15)<<gecici2->ilkEleman->veri<<setw(15)<<gecici2->ilkEleman->onceki<<setw(15)<<gecici2->ilkEleman->sonraki<<endl;
            gecici2->ilkEleman=gecici2->ilkEleman->sonraki;*/
            cout<<gecici2->ilkEleman->veri<<" ";
            gecici2->ilkEleman=gecici2->ilkEleman->sonraki;

        }while(gecici2->ilkEleman!=gecici3);
        cout<<endl;
        gecici2=gecici2->sonraki;
        satirSirasi++;
        //cout<<gecici2<<endl;
        
    }
    
    return os;
}