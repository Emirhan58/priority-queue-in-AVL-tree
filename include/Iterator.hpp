/**
* @file Iterator.hpp
* @description Iterator sinifinin header dosyasi. Icerisinde iteratorun ileri, geri hareket edebilmesi ve isaret ettigi dugumu gosterebilmesi icin gerekli fonksiyonlar tanimlandi.
* @course 2/A
* @assignment 1
* @date 24/10/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

class Iterator {
    public:
        Node* current;

        Iterator();
        Iterator(Node* current);
        bool hasNext();
        bool hasPrev();
        void next();
        void prev();
        const string& getCurrent() const;
};




#endif