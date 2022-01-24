/**
* @file Nokta.hpp
* @description noktalar.txt icerisindeki x,y,z koordinatlarini ve bu noktanin orjine olan uzakligini tutan siniftir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef NOKTA_HPP
#define NOKTA_HPP


#include <iostream>
#include <math.h>

using namespace std;


class Nokta{
    public:
        int x, y, z, orjineUzaklik;
        
        Nokta(const int &x,const int &y,const int &z);
};

#endif