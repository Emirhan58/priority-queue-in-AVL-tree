/**
* @file Iterator.cpp
* @description Iterator nesnesinin fonksiyon govdelerinin dolduruldugu kisim.
* @course 2/A
* @assignment 1
* @date 24/10/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "Iterator.hpp"

Iterator::Iterator() {
    current = NULL;
}
Iterator::Iterator(Node* current) {
    this->current = current;
}
bool Iterator::hasNext() {
    return current != NULL;
}

bool Iterator::hasPrev() {
    return current != NULL;
}

void Iterator::next() {
    current = current->next;
}

void Iterator::prev() {
    current = current->prev;
}

const string& Iterator::getCurrent() const{
    return current->item;
}
