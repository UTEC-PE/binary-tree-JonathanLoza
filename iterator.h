#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include "stack.h"

template <typename T>
class Iterator {
private:
    Node<T>* current;
public:
    Stack<Node<T>*> *stack;
    Iterator(){
      current=nullptr;
      stack=new Stack<Node<T>*>();
    };
    Iterator(Node<T>* node){
      current=node;
    };

    Iterator<T> operator=(Iterator<T> node){
      this->current=node.current;
      return *this;
    };
    bool operator!=(Iterator<T> cmp){
      return current!=cmp.current;
    };
    Iterator<T> operator++(){
      if(current->right){
        auto temp=current->right;
        while(temp){
          this->stack->push(temp);
          temp=temp->left;
        }
      }
      if(stack->empty()){
        current=nullptr;
      }else{
        current=this->stack->get();
        this->stack->pop();
      }
      return *this;
    };
    T operator*(){
      return current->data;
    };
    void igual(Node<T>* nodo){
      this->current=nodo;
    }
};

#endif
