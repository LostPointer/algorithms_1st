#pragma once

#include <cstddef>

struct Node {
  Node(int key, int value) : key_(key), value_(value) {}
  Node *left_child_ = nullptr;
  Node *right_child_ = nullptr;
  int key_{};
  int value_{};
  int height_{1};
};

class AVL_Tree {
public:
  void Insert(int key, int value);
  void Remove(int key);
  int Find(int key);
  int Size();

private:
  Node *InsertNode(Node *root, int key, int value);
  Node *RemoveNode(Node *root, int key);
  Node *FindNode(Node *root, int key);

  Node *TurnLeft(Node *root);
  Node *TurnRight(Node *root);
  void NewHeight(Node *root);
  Node *SetBalance(Node *root);
  Node *FindMinRightSubtree(Node *root);
  Node *RemoveMinRightSubtree(Node *root);

  Node *root = nullptr;
  int size_ = 0;
};