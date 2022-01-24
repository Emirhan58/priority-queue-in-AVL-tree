/**
* @file Node.cpp
* @description Oncelikli dogru kuyrugunu tutan dugumun cpp dosyasi. Header dosyasinda tanimlanan constructor govdesinin dolduruldugu dosyadir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "Node.hpp"

Node::Node(DogruKuyrugu *&kuyruk,Node *sol,Node *sag){
    this->kuyruk = kuyruk;
    this->left = sol;
    this->right = sag;
    yukseklik = 0;
}