#include <stdexcept>

#include "tree.hpp"

Node *AVL_Tree::TurnLeft(Node *root) {
  Node *right_subtree = root->right_child_;
  root->right_child_ = right_subtree->left_child_;
  right_subtree->left_child_ = root;
  NewHeight(right_subtree);
  NewHeight(root);
  return right_subtree;
}

Node *AVL_Tree::TurnRight(Node *root) {
  Node *left_subtree = root->left_child_;
  root->left_child_ = left_subtree->right_child_;
  left_subtree->right_child_ = root;
  NewHeight(left_subtree);
  NewHeight(root);
  return left_subtree;
}

Node *AVL_Tree::SetBalance(Node *root) {
  int right_child_height =
      (root->right_child_ == nullptr) ? 0 : root->right_child_->height_;
  int left_child_height =
      (root->left_child_ == nullptr) ? 0 : root->left_child_->height_;

  if (right_child_height - left_child_height > 1) {
    Node *right_subtree = root->right_child_;
    int right_subchild_height = (right_subtree->right_child_ == nullptr)
                                    ? 0
                                    : right_subtree->right_child_->height_;
    int left_subchild_height = (right_subtree->left_child_ == nullptr)
                                   ? 0
                                   : right_subtree->left_child_->height_;

    if (left_subchild_height > right_subchild_height)
      right_subtree = TurnRight(right_subtree);

    return TurnLeft(root);
  }
  if (left_child_height - right_child_height > 1) {
    Node *left_subtree = root->left_child_;
    int right_subchild_height = (left_subtree->right_child_ == nullptr)
                                    ? 0
                                    : left_subtree->right_child_->height_;
    int left_subchild_height = (left_subtree->left_child_ == nullptr)
                                   ? 0
                                   : left_subtree->left_child_->height_;

    if (left_subchild_height < right_subchild_height)
      left_subtree = TurnLeft(left_subtree);

    return TurnRight(root);
  }
  return root;
}

void AVL_Tree::NewHeight(Node *root) {
  if (root->left_child_ == nullptr && root->right_child_ == nullptr)
    root->height_ = 1;

  else if (root->left_child_ == nullptr)
    root->height_ = root->right_child_->height_ + 1;

  else if (root->right_child_ == nullptr)
    root->height_ = root->left_child_->height_ + 1;

  else
    root->height_ =
        std::max(root->left_child_->height_, root->right_child_->height_) + 1;
}

Node *AVL_Tree::InsertNode(Node *root, int key, int value) {
  if (root == nullptr) {
    root = new Node(key, value);
    return root;
  }
  if (key >= root->key_)
    root->right_child_ = InsertNode(root->right_child_, key, value);
  else {

    root->left_child_ = InsertNode(root->left_child_, key, value);
  }
  NewHeight(root);
  root = SetBalance(root);
  return root;
}

Node *AVL_Tree::FindMinRightSubtree(Node *root) {
  return (root->left_child_ == nullptr)
             ? root
             : FindMinRightSubtree(root->left_child_);
}

Node *AVL_Tree::RemoveMinRightSubtree(Node *root) {
  if (root->left_child_ == nullptr)
    return root->right_child_;
  root->left_child_ = RemoveMinRightSubtree(root->left_child_);
  NewHeight(root);
  root = SetBalance(root);
  return root;
}

Node *AVL_Tree::RemoveNode(Node *root, int key) {
  if (root == nullptr)
    throw std::out_of_range("Wrong key");

  if (key > root->key_)
    root->right_child_ = RemoveNode(root->right_child_, key);
  else if (key < root->key_)
    root->left_child_ = RemoveNode(root->left_child_, key);
  else {
    Node *right_subtree = root->right_child_;
    Node *left_subtree = root->left_child_;
    delete root;
    if (right_subtree == nullptr)
      return left_subtree;
    Node *min_right_subtree = FindMinRightSubtree(right_subtree);
    right_subtree = RemoveMinRightSubtree(right_subtree);
    min_right_subtree->right_child_ = right_subtree;
    min_right_subtree->left_child_ = left_subtree;
    return min_right_subtree;
  }
  NewHeight(root);
  root = SetBalance(root);
  return root;
}

Node *AVL_Tree::FindNode(Node *root, int key) {
  if (root == nullptr)
    throw std::out_of_range("Wrong key");
  if (key > root->key_)
    return FindNode(root->right_child_, key);
  else if (key < root->key_)
    return FindNode(root->left_child_, key);
  else
    return root;
}

void AVL_Tree::Insert(int key, int value) {
  ++size_;
  root = InsertNode(root, key, value);
}

void AVL_Tree::Remove(int key) {
  if (size_ == 0)
    throw std::out_of_range("Empty tree");
  root = RemoveNode(root, key);
  --size_;
}

int AVL_Tree::Find(int key) { return FindNode(root, key)->value_; }

int AVL_Tree::Size() { return size_; }