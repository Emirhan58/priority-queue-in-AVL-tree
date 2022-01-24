/**
* @file Test.cpp
* @description Veri.txt dosyasinda yazilmis olan komutlari okuyup, cift yonlu bagli liste icerisinde komutlari uygulayan main dosya.
* @course 2/A
* @assignment 1
* @date 24/10/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#pragma GCC diagnostic ignored "-Wdeprecated"
#include <fstream>
#include "LinkedList.hpp"

int main()
{
	LinkedList *isimler = new LinkedList();
	
	ifstream inFile("Veri.txt");
	ofstream outFile("./bin/Veri.txt");

	outFile << inFile.rdbuf();

	ifstream dosyaOku("Veri.txt");
	string satir = "";
	string isim = "";
	int index;
	if ( dosyaOku.is_open() ){
		while ( getline(dosyaOku, satir) ){
			if ( satir[0] == 'E') {
				index = satir.find('#');
				isim = satir.substr(index+1,satir.length()-(index+2));
				index = stoi(satir.substr(2,index-2));
				isimler->Ekle(isim,index);
			}
			else if (satir[0] == 'S') {
				index = stoi(satir.substr(2,satir.length()-1));
				isimler->Sil(index);
			}
		}
		dosyaOku.close();
	}
	
	cout << *isimler << endl;
	cout << "Programi kapatmak icin herhangi bir tusa basip entera basiniz.";
	cin >> isim;
		
	delete isimler;
	
	return 0;
}