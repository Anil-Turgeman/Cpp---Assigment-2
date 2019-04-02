#pragma once
namespace ariel{
  class Node{
    private:
      int _data;
      Node* left;
      Node* right;
    public:
      Node(int data);
      Node* getLeft(); 
      Node* getRight(); 
      void setLeft(Node* left);
      void setRight(Node* right);
      int getData();
  };

  class Tree{
    private:
      int _size;
      Node* _root;
      Node* find(int i);
      void printRecursive(Node* curr);
      void Destroy(Node* curr);
    public:
      Tree();
      ~Tree();
      Node* getRoot();
      Tree& insert(int i);
      void remove(int i);
      int size();
      int root();
      int parent(int i);
      int left(int i);
      int right(int i);
      bool contains(int i);
      void print();
  };
}
