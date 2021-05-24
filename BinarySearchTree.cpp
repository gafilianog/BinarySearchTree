//
// Created by Gafiliano on 14/05/2021.
//

#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree() {
    this->root = NULL;
}

BinarySearchTree::Node *BinarySearchTree::getRoot() const {
    return root;
}

void BinarySearchTree::setRoot(BinarySearchTree::Node *root_) {
    BinarySearchTree::root = root_;
}

BinarySearchTree::Node *BinarySearchTree::insert(BinarySearchTree::Node *root_, const std::string &data_) {
    if (!root_)
        return new Node(data_);
    if (data_ > root_->data)
        root_->right = insert(root_->right, data_);
    else
        root_->left = insert(root_->left, data_);
    return root_;
}

//BinarySearchTree::Node *
//BinarySearchTree::update(BinarySearchTree::Node *root_, const std::string &target, const std::string &newData) {
//    if (!root_) return root_;
//    if (target > root_->data) root_->right = update(root_->right, target, newData);
//    else if (target < root_->data) root_->left = update(root_->left, target, newData);
//    else if (target == root_->data) root_->data = newData;
//    return root_;
//}

BinarySearchTree::Node *BinarySearchTree::delNode(BinarySearchTree::Node *root_, const std::string &data_) {
    if (!root_) return root_;
    if (data_ > root_->data) root_->right = delNode(root_->right, data_);
    else if (data_ < root_->data) root_->left = delNode(root_->left, data_);
    else {
        if (!(root_->left)) {
            Node *temp = root_->right;
            delete root_;
            return temp;
        } else if (!(root_->right)) {
            Node *temp = root_->left;
            delete root_;
            return temp;
        }
        Node *temp = findSuccessor(root_->right);
        root_->data = temp->data;
        root_->right = delNode(root_->right, temp->data);
    }
    return root_;
}

BinarySearchTree::Node *BinarySearchTree::findSuccessor(BinarySearchTree::Node *temp) {
    Node *curr;
    for (curr = temp; curr && curr->left != NULL; curr = curr->left);
    return curr;
}

void BinarySearchTree::inOrder(BinarySearchTree::Node *root_) {
    if (!root_) return;
    inOrder(root_->left);
    std::cout << root_->data << std::endl;
    inOrder(root_->right);
}

void BinarySearchTree::postOrder(BinarySearchTree::Node *root_) {
    if (!root_) return;
    postOrder(root_->right);
    std::cout << root_->data << std::endl;
    postOrder(root_->left);
}