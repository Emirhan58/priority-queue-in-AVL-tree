/**
* @file LinkedList.cpp
* @description Cift yonlu bagli listenin fonksiyon govdelerinin dolduruldugu kisim.
* @course 2/A
* @assignment 1
* @date 24/10/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "LinkedList.hpp"

Iterator LinkedList::FindPrevByPosition(int position) {
    Iterator iterator(head);
    int index = 0;
    while(iterator.hasNext() && position != index) {
        iterator.next();
        index++;
    }
    return iterator;
}

void LinkedList::Ekle(const string &item,int position) {
    add(item);
    if (position < 0 || position > size) position = size-1;
    Iterator iterator = FindPrevByPosition(size);
    int index = size-1;
    while(iterator.hasPrev() && index != position) {
        iterator.current->item = iterator.current->prev->item;
        iterator.prev();
        index--;
    }
    iterator.current->item = item;
}

void LinkedList::Sil(int position) {
    if (position < 0 || position >= size) position = size-1;
    Iterator iterator = FindPrevByPosition(position+1);
    int index = position;
    while(iterator.hasNext() && index != size-1) {
        iterator.current->item = iterator.current->next->item;
        iterator.next();
        index++;
    }
    removeAt(index);
}

LinkedList::LinkedList() {
    head = new Node();
    size = 0;
}
bool LinkedList::isEmpty()const {
    return head->next == NULL;
}
void LinkedList::add(const string &item) {
    insert(size,item);
}
void LinkedList::insert(int index,const string &item) {
    Iterator iterator = FindPrevByPosition(index);
    iterator.current->next = new Node(item,iterator.current->next,iterator.current);
    if (iterator.current->next->next != NULL )
        iterator.current->next->next->prev = iterator.current->next;
    size++;
}
void LinkedList::removeAt(int index){
    Iterator iterator = FindPrevByPosition(index);
    Node* del = iterator.current->next;
    iterator.current->next = iterator.current->next->next;
    if (iterator.current->next != NULL) iterator.current->next->prev = iterator.current;
    delete del;
    size--;
}
ostream& operator<<(ostream& screen,const LinkedList& right) {
    int index = 0;
    Iterator iterator(right.head->next);
    while(index < right.size - 1) {
        screen << iterator.getCurrent() << "<-->";
        iterator.next();
        index++;
    }
    screen << iterator.getCurrent() << endl;
    return screen;
}
void LinkedList::clear() {
    while(!isEmpty()) {
        removeAt(0);
    }
}
LinkedList::~LinkedList() {
    clear();
    delete head;
}