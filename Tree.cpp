#include <iostream>
#include <string>
#include <iomanip>
#include "Tree.hpp"
using namespace std;


namespace ariel{

	Node* Root;
	int num;

	Tree::Tree(){
		Root = NULL;
		num = 0;
	}


	Tree::~Tree(){
		destroyTree(Root);
	}

	void Tree::destroyTree(Node* leaf){ //recursive call to free memory
		if (leaf == NULL) {
			return;
		}
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete(leaf);
	}




	void Tree::insert(int a){
		if (Root == NULL){ //root option
			Root = new Node;
			Root->data = a;
			Root->right = NULL;
			Root->left = NULL;
			Root->parent = NULL;
			num++;
		}else{
			Insert (a, Root); //get to right place if there is a root
		}
	}

	void Tree::Insert(int a, Node* now){
		if(a == now->data){ //exception if node already here
			throw string("already here\n");
		}else{
			if(a > now->data){ //finding the right place for the node
				if(now->right == NULL){
					now->right = new Node;
					now->right->data = a;
					now->right->parent = now;
					now->right->right = NULL;
					now->right->left = NULL;
					num++;
				}else{
					Insert(a, now->right); //going to next node if there's a need
				}
			}else{
				if(now->left == NULL){ //other option, same as before just to left side
					now->left = new Node;
					now->left->data = a;
					now->left->right = NULL;
					now->left->parent = now;
					now->left->left = NULL;
					num++;
				}else{
					Insert(a, now->left);
				}
			}
		}
	}

	int Tree::size(){ //number of nodes
		return num;
	}

	bool Tree::contains(int a){
		if(Contains(a, Root) == NULL){ //sending for a function to find the node
			return false;
		}
		return true;
		}

	Node* Tree::Contains(int key, Node *leaf){
		if(leaf != NULL){ //if there are still nodes to check
			if(key == leaf->data){ //found the node
				return leaf;
			}
			if(key < leaf->data){ //checking to the right and left
				return Contains(key, leaf->left);
			}else{
				return Contains(key, leaf->right);
			}
		}else{
			return NULL;
		}
	}

	Node* Tree::find(int a){
		Node* temp = Contains(a, Root); //finding the right node
		if (temp == NULL){ //exception throw if there's a need
			throw string("fail");
		}
		return temp;
	}



	int Tree::parent (int a){ //return the data of the node parent
		return find(a)->parent->data;
	}
	int Tree::right (int a){ //return the data of the node right son
		return find(a)->right->data;
	}
	int Tree::left (int a){ //return the data of the node left son
		return find(a)->left->data;
	}

	void Tree::remove(int a){
		/*Node* temp = Contains(a, Root); //finding the node to remove
		if(temp == NULL){ //exception if the node isn't in the tree
			throw string("not found");
		}
		remove(temp); //function to actually delete the node
		num--; //update tree size
		return;*/
		}

	void Tree::remove(Node* leaf){
		if (leaf->right == NULL && leaf->left == NULL){ //in case that the node doesn't have sons
			if (leaf->data == Root->data){ //in case node is root
				Root = NULL;
				delete(leaf);
				return;
			}
			if (leaf->parent->right->data == leaf->data){ //updating the father
				leaf->parent->right = NULL; //if node is right son
			}else{
				leaf->parent->left = NULL; //if node is left son
			}
			delete(leaf);
			return;
		}
		if (leaf->right == NULL){ //node to delete has a right son
			if (leaf->data == Root->data){ //checking if the node to delete is root
				Root = leaf->left; //update root
				delete(leaf);
				return;
			}
			if (leaf->parent->right->data == leaf->data){ //checking if node is right or left son of father
				leaf->parent->right = leaf->left; //update father
			}else{
				leaf->parent->left = leaf->left; //else case update father
			}
			delete(leaf);
			return;
		}
		if (leaf->left == NULL){ //node to delete has a right son
			if (leaf->data == Root->data){ //checking if the node to delete is root
				Root = leaf->right; //update root
				delete(leaf);
				return;
			}
			if (leaf->parent->right->data == leaf->data){ //checking if node is right or left son of father
				leaf->parent->right = leaf->right; //update father
			}else{
				leaf->parent->left = leaf->right; //else case update father
			}
			delete(leaf);
			return;
		}
		Node* temp = closest(leaf->right); //getting the next bigger node
		if (temp->right != NULL){ //checking if the next bigger node has a right son
			leaf->right = temp->right; //getting the son to the right place
		}
		leaf->data = temp->data; //update the deleted node data
		delete(temp); //removing the temp node
		return;
	}


	Node* Tree::closest(Node* now){ //getting the next bigger node
		if (now->left == NULL && now->right == NULL){ //gotten to a leaf
			if (now->parent->left->data == now->data){ //checking which son is the leaf
				now->parent->left = NULL; //left case
			}else{
				now->parent->right = NULL; //right case
			}
			return now;
		}else{
			if (now->left != NULL){ //recursive call if there is a smaller next bigger
				closest(now->left);
			}else{
				return now;
			}
		}
	}

	void Tree::print(){
			print(Root);
			}
	void Tree::print(Node* leaf){ //print according to left root right
			if(leaf==NULL){
				return;
			}
			print(leaf->left);
			cout<<leaf->data<<",";
			print(leaf->right);
		}


	int Tree::root(){ //return root data
		return Root->data;
	}

/*	void Tree::buildTree(Node* root, int scrWidth, int itemWidth)
		// breadth-first traversal with depth limit based on screen width and output field width for one elemet
		{
		    bool notFinished = false;
		    // check the root
		    if (root)
		    {
		        notFinished = true;
		    }
		    // calculate maximum possible depth
		    int depth = 1;
		    int field = scrWidth;
		    while (field > itemWidth)
		    {
		        depth++;
		        field /= 2;
		    }
		    // check result
		    if (depth < 1)
		    {
		        cout << " -= erroneous output options =-" << endl;
		        return;
		    }
		    Node** pItems = new Node*[1];
		    *pItems = root; // pointer to item on the first level
		    int itemCnt = 1;
		    int divWidth = 1;
		    // loop for output not more than depth levels until the data is not finished
		    // where level is current depth of tree, and root is on the first level
		    for (int level = 1; level <= depth && notFinished; level++)
		    {
		        itemCnt = (level == 1) ? 1 : (itemCnt * 2);
		        divWidth *= 2;
		        // make list of pointers to refer items on next level
		        Node** list = new Node*[itemCnt * 2];
		        // output all utems of that level
		        int nextCnt = 0;
		        notFinished = false;
		        for (int i = 0; i < itemCnt; i++, nextCnt += 2)
		        {
		            int curWidth = (scrWidth / divWidth) * ((i > 0) ? 2 : 1);
		            cout << setw((curWidth>=itemWidth) ? curWidth:(itemWidth/(1+(i==0))));
		            if (pItems[i])
		            {
		                cout << pItems[i]->data;
		                list[nextCnt] = pItems[i]->left;
		                list[nextCnt + 1] = pItems[i]->right;
		                if (list[nextCnt] || list[nextCnt + 1])
		                    notFinished = true;
		            }
		            else
		            {
		                cout << ".";
		                list[nextCnt] = NULL;
		                list[nextCnt + 1] = NULL;
		            }
		        }
		        cout << endl;
		        // free the memory allocated for list of pointers
		        if (pItems)
		            delete[] pItems;
		        pItems = list; // and shift to new one (for next level)
		    }
		    delete[] pItems;
		}*/

};
