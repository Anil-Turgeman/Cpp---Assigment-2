#include <iostream>
#include <cstdlib>
#include "Tree.hpp"
#include <exception>

using namespace std;

ariel::Tree::Tree(){
    rootValue = NULL;//Initializing the root to null and the createLeaf function initializ the root to be a new noot in the tree
}

ariel::Tree::node* ariel::Tree::createLeaf(int data){//Create a new leaf to the tree, call only once at insert function
    node* n = new node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

ariel::Tree::~Tree(){DeconstructorTree(rootValue);}

void ariel::Tree::DeconstructorTree(node* nodeCheck){
    if(nodeCheck != NULL){
        if(nodeCheck->left != NULL) {
            DeconstructorTree(nodeCheck->left);
        }
        if(nodeCheck->right != NULL) {
            DeconstructorTree(nodeCheck->right);
        }
        delete nodeCheck;
    }
    else{
        throw std::invalid_argument("The tree is empty\n");
    }
}

void ariel::Tree::insert(int i){
    if (contains(i) == true)  cout << "The tree already contain this number" << endl;
    else{
        insertPrivate(i, rootValue);//the user does not need to know which noods theres 
                                    //in the tree so I used a private function for that
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
        //throw std::invalid_argument( "The data is already in the tree\n" );
    }
}

void ariel::Tree::print(){
    printPrivate(rootValue);
    cout << "\n";
}

void ariel::Tree::printPrivate(node* nodeCheck){//again, for the user that used the program wont know the the noods of the tree
    if(rootValue != NULL){//print inorder, print from smallest to highest
        if(nodeCheck->left != NULL){
            printPrivate(nodeCheck->left);
        }
        cout << nodeCheck->data << " ";//print the corrent node
        if(nodeCheck->right != NULL){
            printPrivate(nodeCheck->right);
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );
    }
}

bool ariel::Tree::contains(int i){//Checks if the data is already in the tree
    return containsPrivate(i, rootValue);
}

bool ariel::Tree::containsPrivate(int data, node* nodeCheck){
    if(nodeCheck != NULL){
        if(nodeCheck->data == data){
            return true;
        }
        else{
            if(data < nodeCheck->data){
                return SearchNodePrivate(data, nodeCheck->left);
            }
            else{
                return SearchNodePrivate(data, nodeCheck->right);
            }
        }
    }
    else{
        throw std::invalid_argument( "The data is not in the tree\n" );
        return false;
    }
}

int ariel::Tree::right(int i){//return the right child of a giving node
    node* ptr = SearchNode(i);
    if(ptr != NULL){
        if(ptr->right == NULL){
            throw std::invalid_argument( "The data is not in the tree\n" );
            return -1;
        }
        else{
            return ptr->right->data;
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );
        return -1;
    }
}

int ariel::Tree::left(int i){//Return the left child of a giving node
    node* ptr = SearchNode(i);
    if(ptr != NULL){
        if(ptr->left == NULL){
            throw std::invalid_argument( "The data is not in the tree\n" );
            return -1;
        }
        else{
            return ptr->left->data;
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );
        return -1;
    }
}

int ariel::Tree::root(){
    if (rootValue != NULL)
        return rootValue->data;

    else{
        throw std::invalid_argument( "The tree is empty\n" );
        return -1;
    }
}

int ariel::Tree::size(){//Return the size of the tree
    return sizePrivate(rootValue);
}

int ariel::Tree::sizePrivate(node* nodeCheck){
    if(nodeCheck == NULL){
        throw std::invalid_argument( "the tree is empty\n" );
        return -1;
    }
    else{
      return (sizePrivate(nodeCheck->left) + sizePrivate(nodeCheck->right) + 1);
    }
}

ariel::Tree::node* ariel::Tree::SearchNode(int i){//help function to the parent, left and right function that return the node with the data
    return SearchNodePrivate(i, rootValue);
}

ariel::Tree::node* ariel::Tree::SearchNodePrivate(int data, node* nodeCheck){// go recursion until you found the correct node
    if(nodeCheck != NULL){//if the tree is not empty
        if(nodeCheck->data == data){
            return nodeCheck;//found what we want
        }
        else{//go right or left according to the data and keep going - Recursion 
            if(data < nodeCheck->data){
                return SearchNodePrivate(data, nodeCheck->left);
            }
            else{
                return SearchNodePrivate(data, nodeCheck->right);
            }
        }
    }else{
            throw std::invalid_argument( "The tree is empty\n" );
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
            throw std::invalid_argument("we're at the root\n");
            return -1;
        }
    }
    else{
        throw std::invalid_argument("The tree is empty or the data is not in the tree\n");
        return -1;
    }
}

int ariel::Tree::findSmallest(){
    return findSmallestPrivate(rootValue);
}

int ariel::Tree::findSmallestPrivate(node* nodeCheck){
    if(rootValue == NULL){
        throw std::invalid_argument( "the tree is empty\n" );
        return -1;
    }
    else{
        if(nodeCheck->left != NULL){
            return findSmallestPrivate(nodeCheck->left);
        }
        else{
            return nodeCheck->data;
        }
    }
}

void ariel::Tree::remove(int i){//remove a number
   removePrivate(i, rootValue);
}


void ariel::Tree::removePrivate(int data, node* parent){
    if(rootValue != NULL){
        if(rootValue->data == data){
            removeRoot();
        }
        else{
            if(data < parent->data && parent->left != NULL){
                if(parent->left->data == data){
                    removeMatch(parent, parent->left, true);
                }
                else{
                    removePrivate(data, parent->left);
                }
            }
            else if(data > parent->data && parent->right != NULL){
                if(parent->right->data == data){
                    removeMatch(parent, parent->right, false);
                }
                else{
                    removePrivate(data, parent->right);
                }
            }
            else{
                throw std::invalid_argument( "The data is not in the tree\n" );  
            } 
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );
    }
}

void ariel::Tree::removeRoot(){
    if(rootValue != NULL){
        node* delPtr = rootValue;
        int smallestInRightSubTree;

        if(rootValue->left == NULL && rootValue->right == NULL){
            rootValue = NULL;
            delete delPtr;
        }

        else if(rootValue->left == NULL && rootValue->right != NULL){
            rootValue = rootValue->right;
            delPtr->right = NULL;
            delete delPtr;
        }
        else if(rootValue->left != NULL && rootValue->right == NULL){
            rootValue = rootValue->left;
            delPtr->left = NULL;
            delete delPtr;
        }

        else{//rootValue->left != NULL && rootValue->right != NULL
            smallestInRightSubTree = findSmallestPrivate(rootValue->right);
            removePrivate(smallestInRightSubTree, rootValue);
            rootValue->data = smallestInRightSubTree;
        }
    }
    else{
        throw std::invalid_argument( "The tree is empty\n" );  
    }
}


void ariel::Tree::removeMatch(node* parent, node* match, bool leftOrRight){//left = true -> match is the left chiled
    if(rootValue != NULL){
        node* delPtr;
        int matchData = match->data;
        int smallestInRightSubTree;

        if(match->left == NULL && match->right == NULL){
            delPtr = match;
            if(leftOrRight == true){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            delete delPtr;
        }

        else if(match->left == NULL && match->right != NULL){
            if(leftOrRight == true){
                parent->left = match->right;
            }
            else{
                parent->right = match->right;
            }
            match->right = NULL;
            delPtr = match;
            delete delPtr;
        }

        else if(match->left != NULL && match->right == NULL){
            if(leftOrRight == true){
                parent->left = match->left;
            }
            else{
                parent->right = match->left;
            }
            match->left = NULL;
            delPtr = match;
            delete delPtr;
        }
        else{
            smallestInRightSubTree = findSmallestPrivate(match->right);
            removePrivate(smallestInRightSubTree, match);
            match->data = smallestInRightSubTree;
        }

    }
    else{
        throw std::invalid_argument( "The tree is empty so we don't have anything to remove...\n" );  
    }
}
