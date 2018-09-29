#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    struct Node* right;
    struct Node* left;
    /*void killSelf(){
        if(next!=nullptr)
            next->killSelf();
        delete this;
    }*/
    void insert(T dato,int &nodos){
      if(dato>this->data){
        if(right)
          right->insert(dato,nodos);
        else{
          right=new Node<T>{dato,nullptr, nullptr};
          nodos++;
        }
      }
      else if(dato<this->data){
        if(left)
          left->insert(dato,nodos);
        else{
          left=new Node<T>{dato,nullptr, nullptr};
          nodos++;
        }
      }
    }
    void remove(T dato, Node<T>* &aux){
      if(!aux){
        return;
      }
      else if(data<dato){
        right->remove(dato,right);
      }
      else if(data>dato){
        left->remove(dato,left);
      }
      else if(data==dato){
        if(!left && !right){
          aux=nullptr;
          delete this;
        }
        else if(!left){
          aux=right;
          delete this;
        }
        else if(!right){
          aux=left;
          delete this;
        }
        else if(left && right){
          auto *temp=left;
          if(temp->right){
            Node<T> *temp2;
            while(temp->right){
              temp2=temp;
              temp=temp->right;
            }
            temp2->right=temp->left;
            temp->left=aux->left;
            temp->right=aux->right;
            aux=temp;
            delete this;
          }
          else if(!temp->right){
            temp->right=aux->right;
            aux=temp;
            delete this;
          }
          /*cout<<temp->data<<endl;
          while(temp->right){
            temp2=temp;
            temp=temp->right;
          }
          cout<<temp->data<<endl;
          this->data=temp->data;
          temp2->right=nullptr;
          delete temp;*/
        }
      }
    }
    void enOrden(){
      if(left)
        left->enOrden();
      cout<<data<<" ";
      if(right)
        right->enOrden();
    }
    void preOrden(){
      cout<<data<<" ";
      if(left)
        left->enOrden();
      if(right)
        right->enOrden();
    }
    void postOrden(){
      if(left)
        left->enOrden();
      if(right)
        right->enOrden();
      cout<<data<<" ";
    }

};

#endif
