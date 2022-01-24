/**
* @file DogruKuyrugu.cpp
* @description Oncelikli dogru kuyrugunun cpp dosyasi. Header dosyasinda tanimlanan fonksiyon govdelerinin dolduruldugu dosyadir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "DogruKuyrugu.hpp"
#include <string.h>


NodeNokta* DogruKuyrugu::previousMaxNode() {
    NodeNokta *prev = NULL;
    NodeNokta *tmp = front;
    int min = front->data->orjineUzaklik;

    while(tmp->next != NULL) {
        if(tmp->next->data->orjineUzaklik < min) {
            min = tmp->next->data->orjineUzaklik;
            prev = tmp;
        }
        tmp = tmp->next;
    }
    return prev;
}

DogruKuyrugu::DogruKuyrugu(const string& satir) {
    this->satir = satir;
    front = back = NULL;
    length = 0;
    toplamUzunluk = 0;
    kuyruguDoldur(satir);
    ToplamUzunlukHesapla();
}

DogruKuyrugu::DogruKuyrugu() {
    satir = "";
    front = back = NULL;
    length = 0;
    toplamUzunluk = 0;
}

void DogruKuyrugu::makeEmpty() {
    while(!isEmpty())
        dequeue();
}
bool DogruKuyrugu::isEmpty() {
    return length == 0;
}
int DogruKuyrugu::count() {
    return length;
}

void DogruKuyrugu::kuyruguDoldur(const string &satir) {
    int i=0;
    int sayac;
    int *noktaKoordinat = new int[3];
    string sayi;
    Nokta *nokta;
    while(i<satir.length()) {
        sayac = 0;
        while (sayac != 3) {
            sayi = "";
            while(satir[i] != ' ' && i<satir.length()) {
                sayi += satir[i];
                i++;
            }
            noktaKoordinat[sayac] = stoi(sayi);
            sayac++;
            i++;
        }
        nokta = new Nokta(noktaKoordinat[0],noktaKoordinat[1],noktaKoordinat[2]);
        enqueue(nokta);
    }
    delete[] noktaKoordinat;
}

void DogruKuyrugu::ToplamUzunlukHesapla() {
    DogruKuyrugu *tmp = new DogruKuyrugu();
    tmp->kuyruguDoldur(satir);
    Nokta* nokta1, *nokta2;
    nokta1 = tmp->peek();
    tmp->dequeue();
    while(!tmp->isEmpty()) {
        nokta2 = tmp->peek();
        tmp->dequeue();
        this->toplamUzunluk += sqrt(pow((nokta2->x - nokta1->x),2)+pow((nokta2->y - nokta1->y),2)+pow((nokta2->z - nokta1->z),2));

        nokta1 = nokta2;
    }
    
    delete tmp;
}


void DogruKuyrugu::enqueue(Nokta*& item) {
    NodeNokta *last = new NodeNokta(item);
    if(isEmpty()) front = back = last;
    else {
        back->next = last;
        back = last;
    }
    this->length += 1;
}
Nokta* DogruKuyrugu::peek() {
    if(isEmpty()) throw "Hata";
    return front->data;
}

Nokta* DogruKuyrugu::peekMax() {
    if(isEmpty()) throw "Hata";
    NodeNokta *prev = previousMaxNode();
    if(prev == NULL) return peek();
    return prev->next->data;
}

void DogruKuyrugu::dequeue() {
    if(isEmpty()) throw "Hata";
    NodeNokta *tmp = front;
    front = front->next;
    delete tmp;
    length--;
}

void DogruKuyrugu::dequeueMax() {
    if(isEmpty()) throw "Hata";
    NodeNokta *prev = previousMaxNode();
    NodeNokta *tmp;
    if (prev == NULL) dequeue();
    else {
        if(prev->next == back) back = prev;
        tmp = prev->next;
        prev->next = tmp->next;
        delete tmp;
        length--;
    }
}

ostream& operator<<(ostream& screen,const DogruKuyrugu &right) {
    DogruKuyrugu *tmp = new DogruKuyrugu();
    tmp->kuyruguDoldur(right.satir);
    while(!tmp->isEmpty()) {
        screen << tmp->peekMax()->orjineUzaklik << " ";
        tmp->dequeueMax();
    }
    
    delete tmp;
    return screen;
}


DogruKuyrugu::~DogruKuyrugu() {
    makeEmpty();
}