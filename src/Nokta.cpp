/**
* @file Nokta.cpp
* @description Nokta sinifinin cpp dosyasi. Header dosyasinda tanimlanan constructor govdesinin dolduruldugu dosyadir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "Nokta.hpp"

Nokta::Nokta(const int& x, const int& y, const int& z) {
    this->x = x;
    this->y = y;
    this->z = z;

    this->orjineUzaklik = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}