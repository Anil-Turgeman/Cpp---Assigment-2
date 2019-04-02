#pragma once
namespace ariel{
class Node{
public:
  int _data;
  Node* left;
  Node* right;
  Node(int data);
  int getData();
};
class Tree{
public:
  Node* _root;
private:
  int _size;

public:
//Constructor & Destructor
  Tree();
  ~Tree();
//Methods
  Node* find(int i);
  Tree& insert(int i);
  void remove(int i);
  int size();
  bool contains(int i);
  int root();
  int parent(int i);
  int left(int i);
  int right(int i);
  void print();
private:
  void printRecursive(Node* curr);
  Node* find(Node* curr,int i);
  void Destroy(Node* curr);
  Node& getRoot();
};
}
