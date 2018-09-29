#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "node.h"
#include "iterator.h"


template <typename T>
class Tree{
  Node<T> *root;
  int nodos;
public:
  Tree(){
    this->root=nullptr;
    this->nodos=0;
  };
  void insert(T data){
    if(!root){
      root=new Node<T>{data,nullptr, nullptr};
      nodos++;
    }else{
      root->insert(data,nodos);
    }
  };
  void remove(T data){
    if(!root){
      cout<<"lista vacia"<<endl;
    }
    else{
      auto* aux=root;
      root->remove(data, root);
    }
  }
  void enOrden(){
    if(root)
      root->enOrden();
    else
      cout<<"Arbol vacio"<<"\n";
    cout<<"\n";
  };
  void preOrden(){
    if(root)
      root->preOrden();
    else
      cout<<"Arbol vacio"<<"\n";
    cout<<"\n";
  };
  void postOrden(){
    if(root)
      root->postOrden();
    else
      cout<<"Arbol vacio"<<"\n";
    cout<<"\n";
  };
  int peso(){
    return nodos;
  }
  Iterator<T> begin(){
    Iterator<T> ite;
    auto temp=root;
    do{
      ite.stack->push(temp);
      temp=temp->left;
    }
    while(temp->left);
    //ite.stack.print();
    ite.igual(temp);
    return ite;
  };
  Iterator<T> end(){
    /*Iterator<T> ite;
    auto temp=root;
    do{
      ite.stack->push(temp);
      temp=temp->right;
    }
    while(temp->right);
    //ite.stack.print();
    cout<<temp->data<<endl;
    ite.igual(temp);
    return ite;*/
    return Iterator<T>(nullptr);
  };
};

#endif
