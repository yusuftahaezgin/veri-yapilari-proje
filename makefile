all:derle bagla calistir

derle:
	g++ -c -I "./include" ./src/DaireselListe.cpp -o ./lib/DaireselListe.o
	g++ -c -I "./include" ./src/DaireselDugum.cpp -o ./lib/DaireselDugum.o
	g++ -c -I "./include" ./src/TekYonluListe.cpp -o ./lib/TekYonluListe.o
	g++ -c -I "./include" ./src/Islemler.cpp -o ./lib/Islemler.o
	g++ -c -I "./include" ./src/TekYonluDugum.cpp -o ./lib/TekYonluDugum.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/main.o ./lib/Islemler.o ./lib/TekYonluListe.o ./lib/TekYonluDugum.o ./lib/DaireselListe.o ./lib/DaireselDugum.o -o ./bin/program
calistir:
	./bin/program