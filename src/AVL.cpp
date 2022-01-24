/**
* @file AVL.cpp
* @description AVL agacinin cpp dosyasi. Header dosyasinda tanimlanan fonksiyon govdelerinin dolduruldugu dosyadir.
* @course 2/A
* @assignment 2
* @date 23/12/2021
* @author Emirhan KAYA / Emirhan.kaya5@ogr.sakarya.edu.tr
*/

#include "AVL.hpp"

Node* AVL::AraVeEkle(Node *&subNode,DogruKuyrugu *&yeniEleman) { 
    if (subNode == NULL)
        return (new Node(yeniEleman));
 
    if (yeniEleman->toplamUzunluk <= subNode->kuyruk->toplamUzunluk)
        subNode->left = AraVeEkle(subNode->left, yeniEleman);
    else if (yeniEleman->toplamUzunluk > subNode->kuyruk->toplamUzunluk)
        subNode->right = AraVeEkle(subNode->right, yeniEleman);
    else 
        return subNode;
 
    subNode->yukseklik = 1 + max(Yukseklik(subNode->left),
                        Yukseklik(subNode->right));
 
    int balance = getBalance(subNode);
 
    if (balance > 1 && yeniEleman->toplamUzunluk <= subNode->left->kuyruk->toplamUzunluk)
        return rightRotate(subNode);
 
    if (balance < -1 && yeniEleman->toplamUzunluk > subNode->right->kuyruk->toplamUzunluk)
        return leftRotate(subNode);
 
    if (balance > 1 && yeniEleman->toplamUzunluk > subNode->left->kuyruk->toplamUzunluk)
    {
        subNode->left = leftRotate(subNode->left);
        return rightRotate(subNode);
    }
 
    if (balance < -1 && yeniEleman->toplamUzunluk <= subNode->right->kuyruk->toplamUzunluk)
    {
        subNode->right = rightRotate(subNode->right);
        return leftRotate(subNode);
    }
 
    return subNode;
}

Node* AVL::rightRotate(Node *&y) {
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->yukseklik = max(Yukseklik(y->left),
                    Yukseklik(y->right)) + 1;
    x->yukseklik = max(Yukseklik(x->left),
                    Yukseklik(x->right)) + 1;
 
    return x;
}

Node* AVL::leftRotate(Node *&x) {
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->yukseklik = max(Yukseklik(x->left),   
                    Yukseklik(x->right)) + 1;
    y->yukseklik = max(Yukseklik(y->left),
                    Yukseklik(y->right)) + 1;
 
    return y;
}

int AVL::getBalance(Node *subNode)
{
    if (subNode == NULL)
        return -1;
    return Yukseklik(subNode->left) - Yukseklik(subNode->right);
}


bool AVL::AraVeSil(Node *&subNode,const DogruKuyrugu& veri){
    if(subNode == NULL) return false;
    else if(subNode->kuyruk->toplamUzunluk == veri.toplamUzunluk) return SilNode(subNode);
    else if (veri.toplamUzunluk < subNode->kuyruk->toplamUzunluk) return AraVeSil(subNode->left,veri);
    else return AraVeSil(subNode->right,veri);
}

bool AVL::SilNode(Node *&subNode) {
    Node *DelNode = subNode;

    if(subNode->right == NULL) subNode = subNode->left;
    else if(subNode->left == NULL) subNode = subNode->right;
    else {
        DelNode = subNode->left;
        Node *parent = subNode;
        while(DelNode->right != NULL){
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->kuyruk = DelNode->kuyruk;
        if(parent->kuyruk == subNode->kuyruk) subNode->left = DelNode->left;
        else parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}

void AVL::postorder(Node *subNode) {
    if(subNode != NULL) {
        postorder(subNode->left);
        postorder(subNode->right);
        cout << *(subNode->kuyruk)<< endl;
    }
}  // SOL SAG KENDISI

int AVL::Yukseklik(Node *subNode){
    if (subNode == NULL)
        return -1;
    return subNode->yukseklik;
}

AVL::AVL() {
    kok = NULL;
}
bool AVL::bosMu()const{
    return kok == NULL;
}
void AVL::Ekle(DogruKuyrugu *&yeniEleman){
    kok = AraVeEkle(kok,yeniEleman);
}
void AVL::Sil(const DogruKuyrugu& veri) {
    if(AraVeSil(kok,veri) == false) throw "Item not found.";
}
void AVL::postorder() {
    postorder(kok);
}
int AVL::Yukseklik() {
    return Yukseklik(kok);
}
void AVL::Temizle() {
    while(!bosMu()) SilNode(kok);
}
AVL::~AVL() {
    Temizle();
}