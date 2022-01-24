/**
* @file NodeNokta.hpp
* @description Nokta sinifini tutan dugum sinifidir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef NODENOKTA_HPP
#define NODENOKTA_HPP


#include "Nokta.hpp"

class NodeNokta{
	public:
        Nokta *data;
        NodeNokta *next;
        
        NodeNokta(Nokta *&nokta, NodeNokta *next=NULL);
};

#endif