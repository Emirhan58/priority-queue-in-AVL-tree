/**
* @file LinkedList.hpp
* @description Cift yonlu bagli liste sinifinin header dosyasi. Icerisinde bizden istenen kurallara gore Ekle ve Sil fonksiyonlari tanimlanmistir.
* @course 2/A
* @assignment 1
* @date 24/10/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Iterator.hpp"

class LinkedList {
    private:
        Node* head;
        int size;
        Iterator FindPrevByPosition(int position);
    public:
        LinkedList();
        bool isEmpty()const;
        void add(const string &item);
        void insert(int index,const string &item);
        void removeAt(int index);
        void Ekle(const string &item,int position);
        void Sil(int position);
        friend ostream& operator<<(ostream& screen,const LinkedList& right);
        void clear();
        ~LinkedList();
};

#endif