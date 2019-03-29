#include <iostream>
#include <cstdlib>
#include "Tree.hpp"
#include <stdexcept>

using namespace std;

ariel::Tree::Tree(){
    rootValue = NULL;//Initializing the root to null and the createLeaf function initializ the root to be a new noot in the tree
}

//Create a new leaf to the tree
ariel::Tree::node* ariel::Tree::createLeaf(int data){//call only once at insert function
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void ariel::Tree::insert(int i){
    if (contains(i) == true)  cout << "The tree already contain this number" << endl;
    else{
        insertPrivate(i, rootValue);//the user does not need to know which noods theres in the tree so I used a private function for that
    }
}

void ariel::Tree::insertPrivate(int data, node* nodeCheck){
    if(rootValue == NULL){
        rootValue = createLeaf(data);//if the rootValue is not exist the data value will be the root of the tree
    }
    else if(data < nodeCheck->data){//if the data value is lower we go left in the tree and keep checking
            if(nodeCheck->left != NULL){
                insertPrivate(data, nodeCheck->left);
            }
            else{
                nodeCheck->left = createLeaf(data);
            }
    }
    else if(data > nodeCheck->data){//if the data value is greather we go left in the tree and keep checking
        if(nodeCheck->right != NULL){
            insertPrivate(data, nodeCheck->right);
        }
        else{
            nodeCheck->right = createLeaf(data);
        }
    }
    
    else{//in the case the data already in the tree we throw exception
        throw invalid_argument( "The data is already in the tree\n" );
    }
}

void ariel::Tree::print(){
    printPrivate(rootValue);
    cout << "\n";
}

void ariel::Tree::printPrivate(node* nodeCheck){//again, for the user that used the program wont know the the noods of the tree
    if(rootValue != NULL){
        if(nodeCheck->left != NULL){
            printPrivate(nodeCheck->left);
        }
        cout << nodeCheck->data << " ";
        if(nodeCheck->right != NULL){
            printPrivate(nodeCheck->right);
        }
    }
    else{
        throw invalid_argument( "The tree is empty\n" );
    }
}

//Checks if the data is already in the tree
bool ariel::Tree::contains(int i){
    return containsPrivate(i, rootValue);
}

bool ariel::Tree::containsPrivate(int data, node* nodeCheck){
    if(nodeCheck != NULL){
        if(nodeCheck->data == data){
            return true;
        }
        else{
            if(data < nodeCheck->data){
                return returnNodePrivate(data, nodeCheck->left);
            }
            else{
                return returnNodePrivate(data, nodeCheck->right);
            }
        }
    }
    else{
        throw invalid_argument( "The data is not in the tree\n" );
        return false;
    }
}

int ariel::Tree::right(int i){//return the right child of a giving node
    node* ptr = returnNode(i);
    if(ptr != NULL){
        if(ptr->right == NULL){
            throw invalid_argument( "The data is not in the tree\n" );
            return -1;
        }
        else{
            return ptr->right->data;
        }
    }
    else{
        throw invalid_argument( "The tree is empty\n" );
        return -1;
    }
}

int ariel::Tree::left(int i){//Return the left child of a giving node
    node* ptr = returnNode(i);
    if(ptr != NULL){
        if(ptr->left == NULL){
            throw invalid_argument( "The data is not in the tree\n" );
            return -1;
        }
        else{
            return ptr->left->data;
        }
    }
    else{
        throw invalid_argument( "The tree is empty\n" );
        return -1;
    }

}

int ariel::Tree::root(){
    if (rootValue != NULL)
        return rootValue->data;

    else{
        throw invalid_argument( "The tree is empty\n" );
        return -1;
    }
}

int ariel::Tree::size(){//Return the size of the tree
    return sizePrivate(rootValue);
}

int ariel::Tree::sizePrivate(node* nodeCheck){
    if(nodeCheck == NULL){
        throw invalid_argument( "the tree is empty\n" );
        return -1;
    }
    else{
      return (sizePrivate(nodeCheck->left) + sizePrivate(nodeCheck->right) + 1);
    }
}

ariel::Tree::node* ariel::Tree::returnNode(int i){//help function to the parent, left and right function that return the node with the data
    return returnNodePrivate(i, rootValue);
}

ariel::Tree::node* ariel::Tree::returnNodePrivate(int data, node* nodeCheck){// go recursion until you found the correct node
    if(nodeCheck != NULL){//if the tree is not empty
        if(nodeCheck->data == data){
            return nodeCheck;//found what we want
        }
        else{//go right or left according to the data and keep going - Recursion 
            if(data < nodeCheck->data){
                return returnNodePrivate(data, nodeCheck->left);
            }
            else{
                return returnNodePrivate(data, nodeCheck->right);
            }
        }
    }else{
            throw invalid_argument( "The tree is empty\n" );
            return NULL;
        }
}

int ariel::Tree::parent(int i){// Return parent
    return parentPrivate(i, rootValue);
}

int ariel::Tree::parentPrivate(int data, node* nodeCheck){
    if(rootValue != NULL && contains(data)){//contain check if the number is in the tree
        if(rootValue->data != data){
            if(data < nodeCheck->data){//go left
                if(nodeCheck->left->data == data){
                    return nodeCheck->data;
                }
                else{
                    return parentPrivate(data, nodeCheck->left);
                }
            }
            else{//go right
                if(nodeCheck->right->data == data){
                    return nodeCheck->data;
                }
                else{
                    return parentPrivate(data, nodeCheck->right);
                }
            }
        }
        else{
            throw invalid_argument("we're at the root\n");
            return -1;
        }
    }
    else{
        throw invalid_argument("The tree is empty or the data is not in the tree\n");
        return -1;
    }
}
