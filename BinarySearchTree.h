//
// Created by Gafiliano on 14/05/2021.
//

#ifndef JB_BINARYSEARCHTREE_H
#define JB_BINARYSEARCHTREE_H

#include <string>

class BinarySearchTree {
private:
    struct Node {
        std::string data;
        Node *left;
        Node *right;
        explicit Node(const std::string& data_, Node *left_ = NULL, Node *right_ = NULL) : data(data_), left(left_), right(right_) {}
    };
    Node *root;

public:
    BinarySearchTree();

    Node *getRoot() const;
    void setRoot(Node *root_);
    Node *insert(Node *root_, const std::string &data_);
    //Node *update(Node *root_, const std::string &target, const std::string &newData);
    Node *delNode(Node *root_, const std::string &data_);
    static Node *findSuccessor(Node *temp);
    void inOrder(Node *root_);
    void postOrder(Node *root_);
};


#endif //JB_BINARYSEARCHTREE_H
