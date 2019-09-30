#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T>
class BSTree {
    Node<T> *root;
    size_t nodes;

public:
    BSTree() : root(nullptr) {};

    bool find(T data) {

        while(root!= nullptr){
            if(data==root->data)
                return true;
            else if(data>root->data){
                root=root->right;
            }
            else this->root=this->root->left;
        }
        return false;
    }
    T findMax(T data){
        // Estás creando nuevos nodos en cada iteración
        auto root =new Node<T>;
        if(root->right== nullptr)
            return this->root->data;
        else return findMax(root->right->data);
    }

    void insert(T data) {
        // Cómo estás insertando?
        root->data=data;
        this->root->left=root->right= nullptr;
        if(data<this->root->data)
            this->root->left->data=root->data;
        else if (data<this->root->data)
            this->root->right->data=root->data;

        nodes++;
    }

    Node<T>* remove(T data) {
        nodes--;
        // Estás creando nodos al eliminar
        auto temp=new Node<T>;
        if(data<this->root->data)
            root->left=remove(data);
        else if(data>this->root->data)
            this->root->right=remove(data);
        else if(root->right and root->left){

            temp->data=findMax(root->left->data);
            root->data=temp->data;
            root->left=remove(root->data);


        } else {

            temp=root;
            if(root->left==nullptr){
                root=root->right;
            }
            if(root->right==nullptr){
                root=root->left;
            }
            delete temp;

        }

        // Falta return

    }

    size_t size() {
        return this->nodes;
    }

    T height(Node<T> node) {
        if (!root)
            return 0;
        int left = findHeight(root->left);
        int right = findHeight(root->right);
        return max( left, right ) + 1;
    }

    void traversePreOrder() {
        Node<T> *ite = root;
        if (ite != nullptr){
            cout<<ite->data<<" ";
            if (ite->left != nullptr){
                print(ite->left);
            }
            if (ite->right != nullptr){
                print(ite->right);
            }

    }}

    void traverseInOrder() {
        Node<T> *ite = root;
        if (ite != nullptr){
            if (ite->left != nullptr){
                print(ite->left);
            }
            cout<<ite->data<<" ";
            // >?
            if (ite>right != nullptr){
                // Qué es print???
                print(ite->right);
            }
        }
        cout<<endl;
    }

    void traversePostOrder() {
        Node<T> *ite = root;

            if (ite->left != nullptr){
                print(ite->left);
            }
            if (ite->right != nullptr){
                print(ite->right);
            }
            cout<<ite->data<<" ";

    }

    Iterator<T> begin() {
        return Iterator<T> (this->root);
    }

    Iterator<T> end() {
        return Iterator<T> ();
    }

    ~BSTree() {
        this->root->killSelf();
    }
};

#endif
