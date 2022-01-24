/**
* @file DogruKuyrugu.hpp
* @description Oncelikli dogru kuyrugunun header dosyasi. Nokta sinifini tutan NodeNokta sinif verilerini tutan bir oncelikli kuyruktur. Noktalar.txt dosyasindaki her bir satir burada tutulur.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP

#include "NodeNokta.hpp"

class DogruKuyrugu {
    private:
		NodeNokta *front;
		NodeNokta *back;
		int length;
		
        NodeNokta* previousMaxNode();

		void ToplamUzunlukHesapla();

	public:
		string satir;
		int toplamUzunluk;

		DogruKuyrugu(const string& satir);

		DogruKuyrugu();

		void makeEmpty();
		
        bool isEmpty();

		int count();
		
        void enqueue(Nokta *&item);

		void kuyruguDoldur(const string &satir);

		Nokta* peek();

        Nokta* peekMax();

		void dequeue();

        void dequeueMax();

		friend ostream& operator<<(ostream& screen,const DogruKuyrugu &right);

		~DogruKuyrugu();
};


#endif