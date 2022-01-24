/**
* @file Main.cpp
* @description Noktalar.txt dosyasinin satir satir okundugu ve odevde istenilen AVL agacina dogru kuyruklarini dugum yoluyla ekleme, sonrasinda okuma islemlerinin yapildigi main dosyasidir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "AVL.hpp"
#include <fstream>

int main() {
    AVL* agacim = new AVL();

    ifstream dosyaAl("Noktalar.txt");
	ofstream dosyaYaz("./bin/Noktalar.txt");
    dosyaYaz << dosyaAl.rdbuf();
	

    ifstream dosyaOku("Noktalar.txt");
    string satir = "";

    if ( dosyaOku.is_open() ){
		while ( getline(dosyaOku, satir) ){
            DogruKuyrugu *kuyrugum = new DogruKuyrugu(satir);
            agacim->Ekle(kuyrugum);
		}
		dosyaOku.close();
	}
    
    agacim->postorder();

    cout << endl << "Programi kapatmak icin herhangi bir tusa basip entera basiniz..." << endl;
    cin >> satir;

    delete agacim;
    return 0;
}