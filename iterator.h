#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <iostream>
using namespace std;
template <typename T>
class Iterator {
    private:
        Node<T> *current;

    public:
        Iterator() {
            this->current= nullptr;
        }

        Iterator(Node<T> *node) {

        }

        Iterator<T>& operator=(const Iterator<T> &other) {
            this->current=other.current;
                return *this;
        }

        bool operator!=(Iterator<T> other) {
                return this->current!=other.current;
        }

        Iterator<T>& operator++() {
            if(this->current->left!=nullptr){
                    this->current=this->current->left;
            }
                return *this;
        }

       Iterator<T>& operator--() {

        }

        T operator*() {
                if(this->current!= nullptr){
                        return this->current->data;
                } else throw out_of_range("error");
        }
};

#endif
