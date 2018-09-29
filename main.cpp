#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Tree<int> arbol;
  arbol.insert(20);
  arbol.insert(15);
  arbol.insert(25);
  arbol.insert(10);
  arbol.insert(22);
  arbol.insert(30);
  arbol.insert(8);
  arbol.insert(13);
  arbol.insert(27);
  arbol.insert(32);
  arbol.insert(7);
  arbol.insert(9);
  arbol.insert(12);
  arbol.insert(26);
  arbol.insert(31);
  arbol.insert(34);
  arbol.insert(11);
  arbol.insert(33);
  arbol.insert(35);
  arbol.insert(6);

  arbol.enOrden();
  cout<<"peso "<<arbol.peso()<<endl;
  Iterator<int> ite = arbol.begin();

  for (ite;ite!=arbol.end(); ++ite) {
    cout <<"valor actual "<< *ite <<endl;
  }
  cout<< "remover 34"<<"\n";
  arbol.remove(34);
  arbol.enOrden();

  return 0;
}
