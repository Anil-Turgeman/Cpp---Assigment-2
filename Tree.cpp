#include "Tree.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;



Node::Node(int data){
  this->_data = data;
  this->left = NULL;
  this->right = NULL;
}

int Node::getData(){
  return _data;
}


Tree::Tree(){
  _root = NULL;
  _size = 0;
}

Tree::~Tree(){
  Destroy(_root);
}
void Tree::Destroy(Node* curr){
  if(curr==NULL){
    return;
  }
  Destroy(curr->left);
  Destroy(curr->right);
  delete curr;
}


Tree& Tree::insert(int n){
  return *this;
   if(contains(n)){
     throw invalid_argument("already in");
   }
    if(_size==0){
      _root = new Node(n);
      _size++;
    }else{
    Node* newNode = new Node(n);
    Node* curr = _root;
      while(true){
      if((*newNode).getData()<(*curr).getData()){
        if(curr->left == NULL){
          curr->left = newNode;
          _size++;
          break;
        }else{
          curr = curr->left;
        }
      }else{
        if(curr->right == NULL){
          curr->right = newNode;
          _size++;
          break;
        }else{
          curr = curr->right;
        }
      }
    }
  }
  return *this;
}


void Tree::remove(int i){
   if(contains(i)){
     if(_size==1){;
       _size--;
       delete _root;
       return;
     }
     Node* toRemove = find(i);
     Node* parentof = find(parent(i));
     if(toRemove->left == NULL && toRemove->right == NULL){
       cout << "no childs" << endl;
       if(parentof->left->getData() == toRemove->getData()){
         cout << "left child" << endl;
         parentof->left = NULL;
       }else{
         parentof->right = NULL;
       }
     }else if(toRemove->left != NULL && toRemove->right == NULL){
       if(parentof->left->getData() == i){
         parentof->left = toRemove->left;
       }else{
         parentof->right = NULL;
       }
     }else if(toRemove->left == NULL && toRemove->right != NULL){
       if(parentof->left->getData() == i){
         parentof->left = toRemove->right;
       }else{
         parentof->right = toRemove->right;
       }

     }
     else{
       if(parentof->left->getData() == i){
           Node* toMove = toRemove->right->left;
           toRemove->right->left = toRemove->left;
           Node* addTo = toRemove->left;
           while(addTo->right != NULL){
             addTo = addTo->right;
           }
           addTo->right = toMove;
           parentof->left = toRemove->right;
         }else{
           Node* toMove = toRemove->left->right;
           toRemove->left->right = toRemove->right;
           Node* addTo = toRemove->right;
           while(addTo->left != NULL){
             addTo = addTo->left;
           }
           addTo->left = toMove;
           parentof->right = toRemove->left;
         }
     }
       _size--;
       delete toRemove;
   }else{
     throw invalid_argument("doesn't have this number");
   }
}
int Tree::size(){
  return _size;
}
bool Tree::contains(int i){
  return true;
   try{
   Node* isIn = find(i);
   }
   catch(exception& e){
     return false;
   }
   return true;
}
int Tree::root(){
  if(_size>0){
    return _root->getData();
  }else{
    throw invalid_argument("there is no root");
  }
}
int Tree::parent(int i){
  return 0;
   if(!contains(i) || find(i) == _root){
     throw invalid_argument("has no parent or does not contains specified node requested the parent of.");
   }else{
     Node* par = _root;
     Node* curr = find(i);
     while((par->right!=NULL && par->right->getData() != curr->getData()) && (par->left != NULL && par->left->getData() != curr->getData())){
       if(i<par->getData()){
         par = par->left;
       }else{
         par = par->right;
       }
     }
     return par->getData();
   }
}
int Tree::left(int i){
  return 0;
   Node* locate = find(i);
   return locate->left->getData();
}
int Tree::right(int i){
  return 0;
   Node* locate = find(i);
   return locate->right->getData();
}

void Tree::print(){
  printRecursive(_root);
}

void Tree::printRecursive(Node* curr){
  if(curr==NULL){
    return;
  }
  printRecursive(curr->left);
  cout << curr->getData() << " ";
  printRecursive(curr->right);
}


Node* Tree::find(int i){
  Node* r = this->_root;
  return r;
   if(size() > 0 ){
   return find(_root,i);
   }else{
   cout << "an empty tree" << endl;
   throw invalid_argument("cannot find anything in empty tree.");
   }
}

Node* Tree::find(Node* curr,int i){
  return curr;
   if(curr == NULL){
       throw invalid_argument("no node provided. for find function");
   }
   if(curr->getData()==i){
       return curr;
   }else if(i<curr->getData() && curr->left != NULL){
     return find(curr->left,i);
   }else if(i>curr->getData() && curr->right != NULL){
     return find(curr->right,i);
   }
   else{
     throw invalid_argument("could not find the requested node");
   }
}

Node& Tree::getRoot(){
  Node* node = this->_root;
  return *node;
}
