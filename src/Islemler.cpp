// @file         DaireselDugum.cpp
// @description  Yapılacak islemleri iceren fonksiyonların bulundugu liste
// @course       2. Öğretim B grubu
// @assignment   1.Ödev
// @date         17.11.2024
// @author       Yusuf Taha Ezgin

#include "Islemler.hpp"

TekYonluDugum* Islemler::satirBul(int satirNo,TekYonluListe* liste){
    //bu fonk verilen satırNo ya gore distaki tek yonlu bagli listede ilerler ve
    // istenilen satırın adresini geri dondurur
    TekYonluDugum* gec = liste->ilk;
    if(satirNo>=liste->satirSayisi|| satirNo<0){
        throw std::out_of_range("Hata: Satir numarasi gecersiz!");
    }
    for(int i=0;i<satirNo;i++){
        gec=gec->sonraki;
    }
    return gec;
}

DaireselDugum* Islemler::satirVeSutunBul(int satirNo,int sutunNo,TekYonluListe* liste){
    //bu fonk ise distaki tek yonlu bagli listede gezer istenilen satırı bulur
    //daha sonra o satırın icinde tuttugu icteki dairesel iki yonlu bagli listede gezerek
    //istenilen sutunun(genin) adresini geri dondurur
    TekYonluDugum* gec = satirBul(satirNo,liste);
    DaireselListe* p;
    p->ilk=gec->ilkEleman;
    if(sutunNo>=p->genSayisiBul() || sutunNo<0){
        throw std::out_of_range("Hata: Sutun numarasi gecersiz!");
    }
    else{
        DaireselDugum* gec2=gec->ilkEleman;
        for(int i=0;i<sutunNo;i++){
            gec2=gec2->sonraki;
        }
        return gec2;
    }
    
}

DaireselDugum* Islemler::ikiyeAyir(int satirNo,TekYonluListe* liste,int ortaIndex){
    //bu fonk parametre olarak verilen satirin icindeki dairesel iki yonlu bagli listeyi
    //dolasir orta elemaninin adresini geri dondurur

    TekYonluDugum* gec = satirBul(satirNo,liste);

    DaireselDugum* gec2=gec->ilkEleman;
    for(int i=0;i<ortaIndex;i++){
        gec2=gec2->sonraki;
    }
    return gec2;
}

void Islemler::birlestir(DaireselDugum* liste1BasAdres,DaireselDugum* liste1ortaAdres,DaireselDugum* liste2BasAdres,DaireselDugum* liste2ortaAdres,int liste1GenSayisi,int liste2GenSayisi,TekYonluListe* liste){
    //bu fonk caprazlama islemini yapar ve yeni satirlari distaki tek yonlu bagli listeye ekler

    DaireselListe* yeniListe1=new DaireselListe();

    // birinci kromozomun ortasinin solu ile ikincinin ortasinin sagini birlestirme
    DaireselDugum* gec=liste1BasAdres;
    if(liste1GenSayisi%2==0){
        do{
        yeniListe1->ekle(gec->veri);
        gec=gec->sonraki;
        }while(gec!=liste1ortaAdres);
    }
    else{
        do{
        yeniListe1->ekle(gec->veri);
        gec=gec->sonraki;
        }while(gec->sonraki!=liste1ortaAdres);
    }
    
    
    DaireselDugum* gec2=liste2ortaAdres;
    do{
        yeniListe1->ekle(gec2->veri);
        gec2=gec2->sonraki;
    }while(gec2!=liste2BasAdres);

    liste->ekle(yeniListe1);


    // birinci kromozomun ortasinin sagi ile ikincinin ortasinin solunu birlestirme
    DaireselListe* yeniListe2=new DaireselListe();

    gec2=liste1ortaAdres;
    do{
        yeniListe2->ekle(gec2->veri);
        gec2=gec2->sonraki;
    }while(gec2!=liste1BasAdres);

    gec=liste2BasAdres;
    if(liste2GenSayisi%2==0){
        do{
            yeniListe2->ekle(gec->veri);
            gec=gec->sonraki;
        }while(gec!=liste2ortaAdres);
    }
    else{
        do{
            yeniListe2->ekle(gec->veri);
            gec=gec->sonraki;
        }while(gec->sonraki!=liste2ortaAdres);
    }
    
    liste->ekle(yeniListe2);
}

void Islemler::mutasyon(int satirNo,int sutunNo,TekYonluListe* liste){
    // verilen kromozomun genini bulur yerine X yazar
    DaireselDugum* gec= satirVeSutunBul(satirNo,sutunNo,liste);
    gec->veri='X';
}


void Islemler::caprazlama(int satirNo1, int satirNo2,TekYonluListe* liste){
    TekYonluDugum* gec = liste->ilk;
    if((satirNo1>=liste->satirSayisi|| satirNo1<0) &&(satirNo2>=liste->satirSayisi|| satirNo2<0)){
        throw std::out_of_range("Hata: Satir numarasi gecersiz!");
    }
    DaireselDugum* liste1BasAdres = satirBul(satirNo1,liste)->ilkEleman;
    DaireselDugum* liste2BasAdres = satirBul(satirNo2,liste)->ilkEleman;

    DaireselListe* liste1 = new DaireselListe();
    liste1->ilk=liste1BasAdres;
    int liste1GenSayisi= liste1->genSayisiBul();
    //cout<<liste1->genSayisiBul()<<endl<<endl;

    DaireselListe* liste2 = new DaireselListe();
    liste2->ilk=liste2BasAdres;
    int liste2GenSayisi= liste2->genSayisiBul();
    //cout<<liste2->genSayisiBul()<<endl<<endl;

    int liste1Orta=0;
    int liste2Orta=0;

    //verilen kromozomların gen sayılarına bakar
    // eger gen cift iste orta noktasi gen sayisinin yarisi olur
    // eger gen sayisi  tek ise orta nokta gen sayisinin yarisinin bir fazlasi olur
    if(liste1GenSayisi%2==0){
        liste1Orta=liste1GenSayisi/2;
    }
    else{
        liste1Orta=(liste1GenSayisi/2)+1;
    }

    if(liste2GenSayisi%2==0){
        liste2Orta=liste2GenSayisi/2;
    }
    else{
        liste2Orta=(liste2GenSayisi/2)+1;
    }

    DaireselDugum* liste1OrtaAdres = ikiyeAyir(satirNo1,liste,liste1Orta);
    DaireselDugum* liste2OrtaAdres = ikiyeAyir(satirNo2,liste,liste2Orta);
    
    /*cout<<liste1BasAdres->veri<<endl;
    cout<<liste1OrtaAdres->veri<<endl;
    cout<<liste2BasAdres->veri<<endl;
    cout<<liste2OrtaAdres->veri<<endl;*/

    birlestir(liste1BasAdres,liste1OrtaAdres,liste2BasAdres,liste2OrtaAdres,liste1GenSayisi,liste2GenSayisi,liste);
}

void Islemler::ekranaYaz(TekYonluListe* liste){
    // kromozomun basındaki geni tutar kromozmun en soluna gider ve karsilastirma yapar
    // kromozomun en sonunda en basina dogru gider(en sagdan en sola) 
    // ilk genden kucuk bir gen buldugu gibi ekrana yazdiri
    //dis listede bir alt satıra(kromozoma) gecer 
    //ayni seyi listedeki tum kromozomlar icin tekrar eder her kromzomda enkucugu yazdirir
    TekYonluDugum* disGec=liste->ilk;
    

    while(disGec!=0){
        DaireselDugum* icGec = disGec->ilkEleman;
        char enKucuk=icGec->veri;
        do{
            icGec=icGec->sonraki;

        }while(icGec->sonraki!=disGec->ilkEleman);
        //icGec degiskeni icteki dairesel iki yonlu listenin son elemanına geldi
        do{
            if(enKucuk>icGec->veri){
                enKucuk=icGec->veri;
                break;
            }
            else{
                icGec=icGec->onceki;
            } 

        }while(icGec!=disGec->ilkEleman);
        cout<<enKucuk<<" ";
        disGec=disGec->sonraki;
    }
   
}

void Islemler::otomatikIslemler(const string& dosyaAdi,TekYonluListe* liste){
    ifstream dosya(dosyaAdi);
    string satir;
    if (!dosya.is_open()) {
        cout << "Dosya acilamadi!" << endl;
        return;
    }

    while (getline(dosya, satir)) {
        istringstream ss(satir);
        char islem;
        ss >> islem;
        
        if (islem=='C') {
            int satirNo1;
         	int satirNo2;
            ss >> satirNo1 >> satirNo2;
            caprazlama(satirNo1,satirNo2,liste);
            
        }
        else if (islem == 'M') {
            int satirNo1;
         	int satirNo2;
            ss >> satirNo1 >> satirNo2;
            mutasyon(satirNo1,satirNo2,liste);
            
        }
        else {
            cout << "Bilinmeyen komut: " << islem << endl;
        }
    }

    dosya.close();
}