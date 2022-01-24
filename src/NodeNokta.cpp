/**
* @file NodeNokta.cpp
* @description Nokta sinifini tutan dugumun cpp dosyasi. Header dosyasinda tanimlanan constructor govdesinin dolduruldugu dosyadir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "NodeNokta.hpp"

NodeNokta::NodeNokta(Nokta*& nokta, NodeNokta *next){
    this->data = nokta;
    this->next = next;
}

