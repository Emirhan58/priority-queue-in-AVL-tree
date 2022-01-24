/**
* @file Node.hpp
* @description Oncelikli kuyruk sinifini tutan dugum sinifidir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef NODE_HPP
#define NODE_HPP

#include "DogruKuyrugu.hpp"

class Node{
	public:
        DogruKuyrugu* kuyruk;
        Node *left;
        Node *right;
        int yukseklik;
        Node(DogruKuyrugu *&kuyruk,Node *sol=NULL,Node *sag=NULL);
};

#endif