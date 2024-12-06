// @file         DaireselDugum.cpp
// @description  Satırları tutan dairesel iki yönlü bağlı liste
// @course       2. Öğretim B grubu
// @assignment   1.Ödev
// @date         16.11.2024
// @author       Yusuf Taha Ezgin

#include "DaireselListe.hpp"
#include <iomanip>


DaireselListe::DaireselListe(){
    ilk=0;
}

DaireselListe::~DaireselListe(){
    DaireselDugum*gec=ilk; 
    do
    {
        DaireselDugum* sil=gec;
        gec=gec->sonraki;
        delete sil;
    }while(gec!=ilk);
}

void DaireselListe::ekle(char veri)
{
    DaireselDugum* yeniDugum=new DaireselDugum(veri);

    if(ilk==0) //hic eleman yoksa
    {
        ilk=yeniDugum;
        ilk->onceki=ilk;
        ilk->sonraki=ilk;
    }
    else
    {
        DaireselDugum* gec=ilk;
        
        while(gec->sonraki!=ilk){
            gec=gec->sonraki;
        }

        gec->sonraki=yeniDugum;
        yeniDugum->onceki=gec;
        yeniDugum->sonraki=ilk;
        ilk->onceki=yeniDugum;
    }
}

int DaireselListe::genSayisiBul(){
    if(ilk==0) return 0;
    int sayi=0;
    DaireselDugum* gec=ilk;
    do{
        sayi++;
        gec=gec->sonraki;
    }while (gec!=ilk);
    
    return sayi;
}

ostream& operator<<(ostream& os,DaireselListe& liste){
    os<<"-------------------------------------------------------------"<<endl;
    os<<setw(15)<<"dugum adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;

    DaireselDugum* gec=liste.ilk;
    cout<<gec<<endl;

    /*do
    {
        os<<setw(15)<<gec->ilkEleman<<setw(15)<<gec->ilkEleman->veri<<setw(15)<<gec->ilkEleman->onceki<<setw(15)<<gec->ilkEleman->sonraki<<endl;
        gec=gec->sonraki;
    }while ();*/
    

    os<<"-------------------------------------------------------------"<<endl<<endl;
    return os;
}