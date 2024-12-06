// @file         DaireselDugum.cpp
// @description  Main
// @course       2. Öğretim B grubu
// @assignment   1.Ödev
// @date         16.11.2024
// @author       Yusuf Taha Ezgin

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "DaireselListe.hpp"
#include "TekYonluListe.hpp"
#include "Islemler.hpp"

using namespace std;

void DosyaOku(const string& dosyaAdi, TekYonluListe* liste){
    ifstream file(dosyaAdi);

    if (!file.is_open()) {
        cout << "Dosya açma başarisiz." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        DaireselListe* dliste = new DaireselListe();
        istringstream ss(line);
        char ch;
        //cout<<liste->satirSayisi<<" ";
        while (ss >> ch) {
            dliste->ekle(ch);
            //cout<<dliste->genSayisi<<" ";   
        }
        //cout<<endl;
        liste->ekle(dliste);
        
    }

    file.close();
}

int main()
{
    TekYonluListe* liste = new TekYonluListe();

    Islemler islem;
    DosyaOku(".\\doc\\Dna.txt", liste);

    
    //cout<<*liste<<endl;

   /* islem.caprazlama(0,3,liste);
    cout<<*liste<<endl;
    islem.mutasyon(4,3,liste);
    cout<<*liste<<endl;*/
    /*islem.otomatikIslemler("C:\\Users\\HP\\Desktop\\deneme\\doc\\Islemler.txt",liste);
    cout<<*liste;*/

    
    /*islem.otomatikIslemler("C:\\Users\\HP\\Desktop\\deneme\\doc\\Islemler.txt",liste);
    cout<<*liste;*/
    int secim;

    do
    {
        cout<<"1- Caprazlama"<<endl;
        cout<<"2- Mutasyon"<<endl;
        cout<<"3- Otomatik Islemler"<<endl;
        cout<<"4- Ekrana Yaz"<<endl;
        cout<<"5- Cikis"<<endl<<endl;
        cout<<"Yapilacak islemi secin: ";
        cin>>secim;
        
        system("cls");
        switch (secim)
        {
            case 1:
                //cout<<*liste;
                cout<<"Caprazlanacak kromozomlari giriniz."<<endl;
                cout<<"Ilk kromozom: ";
                int kromozom1;
                cin>>kromozom1;
                while(kromozom1>=liste->satirSayisi||kromozom1<0){
                    cout<<"Boyle bir kromozom sayisi yok lutfen gecerli kromozom numarasi giriniz!"<<endl;
                    cout<<"Ilk kromozom: ";
                    cin>>kromozom1;
                }
                cout<<"Ikinci kromozom: ";
                int kromozom2;
                cin>>kromozom2;
                while(kromozom2>=liste->satirSayisi||kromozom2<0){
                    cout<<"Boyle bir kromozom sayisi yok lutfen gecerli kromozom numarasi giriniz!"<<endl;
                    cout<<"Ikinci kromozom: ";
                    cin>>kromozom2;
                }
                cout<<endl;
                islem.caprazlama(kromozom1,kromozom2,liste);
                cout<<"Caprazlama tamamlandi"<<endl;
                //cout<<*liste<<endl;
                break;
            case 2:
                //cout<<*liste;
                cout<<"Mutasyona ugrayacak kromozom ve gen konumlarini giriniz."<<endl;
                cout<<"Kromozom: ";
                int kromozom;
                cin>>kromozom;
                cout<<"Gen: ";
                int gen;
                cin>>gen;
                cout<<endl;
                islem.mutasyon(kromozom,gen,liste);
                cout<<"Mutasyon tamamlandi"<<endl;
                //cout<<*liste<<endl;
                break;
            case 3:             
                islem.otomatikIslemler(".\\doc\\Islemler.txt",liste);
                cout<<"Otomatik Islemler tamamlandi"<<endl;
                //cout<<*liste<<endl;
                break;
            case 4:
                islem.ekranaYaz(liste);
                cout<<endl;
                break;
            case 5:
                cout<<"Cikis yapildi"<<endl;
                break;
            default:
                cout<<"Yanlis tusladiniz 1-5 arasi tuslayin!"<<endl;
                cout<<endl;
        }
    } while (secim!=5);
    
    delete liste;
    return 0;
}

