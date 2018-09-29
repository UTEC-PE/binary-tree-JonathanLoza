#ifndef NODESTACK_H
#define NODESTACK_H

#include <iostream>

using namespace std;

template <typename T>
struct Nodestack {
    T data;
    Nodestack* next;
    Nodestack* prev;

    void killSelf(){
        if(next!=nullptr)
            next->killSelf();
        delete this;
    };
    //void print_next();
};

#endif
