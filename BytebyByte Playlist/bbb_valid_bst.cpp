// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Objective: check if given tree is valid or not
// the idea is to have min and max limits for each value being checked.
// For a left value, give (min, root->data) as limits
// For a right value, give (root->data+1, max) as limits
// here the assumption is made that the tree can contain duplicates, but they must be to the relatively left branch


class Node{
    public:
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int d, shared_ptr<Node> l, shared_ptr<Node> r): data(d), left(l), right(r) {};
};

bool isBST ( shared_ptr<Node> rt);
bool isBST (shared_ptr<Node> rt, int min, int max);

int main(){

    // make tree
    shared_ptr<Node> n2(new Node(2, nullptr, nullptr));
    shared_ptr<Node> n1(new Node(1, nullptr, nullptr));
    shared_ptr<Node> n7(new Node(7, nullptr, nullptr));
    shared_ptr<Node> n10(new Node(10, nullptr, nullptr));
    shared_ptr<Node> n12(new Node(12, nullptr, nullptr));
    shared_ptr<Node> n3(new Node(3, n2, nullptr));
    shared_ptr<Node> n5(new Node(5, nullptr, nullptr));
    shared_ptr<Node> n4(new Node(4, n3, n5));
    shared_ptr<Node> n11(new Node(11, n10, n12));
    shared_ptr<Node> root(new Node(9, n4, n11));

    //call checkTree function
    cout << "Result: " << isBST(root) << endl;
    return 0;
}

bool isBST(shared_ptr<Node> rt){
    // if (rt == nullptr) { return true;}
    return isBST(rt, INT_MIN, INT_MAX);
}

bool isBST(shared_ptr<Node> rt, int min, int max){
    if (rt == nullptr) { return true;}
    if (rt->data > max or rt->data < min) return false;
    return isBST(rt->left, min, rt->data) && isBST(rt->right, rt->data + 1, max);
}