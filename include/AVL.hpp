/**
* @file AVL.hpp
* @description AVL agacinin header dosyasi. Öncelikli kuyruk sinifini tutan Node sinif verileri bu agacta tutulur.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"

class AVL {
    private:
        Node *kok;
        int sayac;

        Node* AraVeEkle(Node *&subNode,DogruKuyrugu *&yeniEleman);

        bool AraVeSil(Node *&subNode,const DogruKuyrugu& veri);

        bool SilNode(Node *&subNode);

        int getBalance(Node *subNode);

        void postorder(Node *subNode);

        int Yukseklik(Node *subNode);

        Node *rightRotate(Node *&y);

        Node *leftRotate(Node *&x);


    public:
        AVL();

        bool bosMu()const;
        
        void Ekle(DogruKuyrugu *&yeniEleman);
        
        void Sil(const DogruKuyrugu& veri);
        
        void postorder();
        
        int Yukseklik();
        
        void Temizle();
        
        ~AVL();
};

#endif