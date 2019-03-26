#include <iostream>
#include <cstdlib>
#include "Tree.hpp"
#include <stdexcept>

using namespace std;

ariel::Tree::Tree(){
    rootValue = NULL;//Initializing the root to null and the createLeaf function initializ the root to be a new noot in the tree
}

//Create a new leaf to the tree
ariel::Tree::node* ariel::Tree::createLeaf(int data){
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void ariel::Tree::insert(int i){}

void ariel::Tree::insertPrivate(int data, node* nodeCheck){}

void ariel::Tree::print(){}

void ariel::Tree::printPrivate(node* nodeCheck){//again, for the user that used the program wont know the the noods of the tree
}


bool ariel::Tree::contains(int i){//Checks if the data is already in the tree
    return containsPrivate(i, rootValue);
}

bool ariel::Tree::containsPrivate(int data, node* nodeCheck){
  return true;
}


ariel::Tree::node* ariel::Tree::returnNode(int i){//help function to the parent, left and right function that return the node with the data
    return returnNodePrivate(i, rootValue);
}

ariel::Tree::node* ariel::Tree::returnNodePrivate(int data, node* nodeCheck){// go recursion until you found the correct node
    return NULL;
}

int ariel::Tree::left(int i){//Return the left child of the node
    return 0;
}

int ariel::Tree::root(){
    return 0;
}


int ariel::Tree::findSmallest(){
    return findSmallestPrivate(rootValue);
}

int ariel::Tree::findSmallestPrivate(node* nodeCheck){
     return 0;
}

int ariel::Tree::size(){
    return sizePrivate(rootValue);
}

int ariel::Tree::sizePrivate(node* nodeCheck){
    return 0;
}

int ariel::Tree::parent(int i){// Return the data of the parent
    return parentPrivate(i, rootValue);
}

int ariel::Tree::parentPrivate(int data, node* nodeCheck){
    return 0;
}


void ariel::Tree::remove(int i){//Remove a node with the data from the tree
   removePrivate(i, rootValue);
}

void ariel::Tree::removePrivate(int data, node* parent){}

void ariel::Tree::removeRoot(){}

void ariel::Tree::removeMatch(node* parent, node* match, bool left){}
