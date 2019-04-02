#include <iostream>
#include <string>

namespace ariel{

struct Node{
	int data;
	Node* right;
	Node* left;
	Node* parent;
};


class Tree{

	int num;
	Node *Root;

	void Insert(int a, Node* now);
	Node *Contains(int key, Node *leaf);
	void remove(Node* leaf);
	Node* closest(Node* now);
	void destroyTree(Node* leaf);
	Node* find(int a);
	void print(Node* leaf);

public:
	Tree();
	~Tree();
	void insert(int a);
	int size();
	bool contains(int a);
	int parent (int a);
	int right (int a);
	int left (int a);
	void remove(int a);
	void print();
	int root();
	//void buildTree(Node* Root,int a, int b);

};
}
