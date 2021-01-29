// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

/*
Objective: 
Perform level order traversal

two ways: 1. return a vector of vectors that can be printed later
          2. print as you go

Process: 
1. Return a vector of vectors that can be printed later:
Follow method 2 but dont print, store data in level vectors and level vectors in 
a master vector

2. Print as you go:
- make two queues. par_q and child_q
- run nested while(true) and while(!par_q.empty) 
- let inner while finish (a single level will be processed in this)
- break outer while when child_q comes out empty from inner while
- swap par_q child_q. use queue::swap function or just swap the pointers manually. 
    this swapping is constant time (O(1))

TIME: O(n) for whiles where n is number of nodes + swapping is constant time as pointers are swapped
TOTAL TIME: O(n) 
*/


class Node{
public:
    int data;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    Node(): data(0),left(nullptr),right(nullptr) {};
    Node(int d, shared_ptr<Node> l, shared_ptr<Node> r): data(d), left(l), right(r) {}; 
};

void levelOrderPrint(shared_ptr<Node> root);
vector<vector<int> > levelOrderVect(shared_ptr<Node> root);

int main(){

    // make tree
    shared_ptr<Node> n7 (new Node(7,nullptr, nullptr));
    shared_ptr<Node> n9 (new Node(9,nullptr, nullptr));
    shared_ptr<Node> n12 (new Node(12,nullptr, nullptr));
    shared_ptr<Node> n8 (new Node(8,n7, n9));
    shared_ptr<Node> n1 (new Node(1,nullptr, nullptr));
    shared_ptr<Node> n2 (new Node(2,nullptr, nullptr));
    shared_ptr<Node> n4 (new Node(4,n1, n2));
    shared_ptr<Node> n10 (new Node(10,n8, n12));
    shared_ptr<Node> root (new Node(6,n4, n10));

    // call one of the two level order functions

    // 1. Level Order Vector of levels returned   

    // auto ans = levelOrderVect(root);
    // // print the vector
    // for(auto& item:ans){
    //     for(auto& dat:item){
    //         cout << dat << " ";
    //     }cout << endl;
    // }
    
    //////////////////////////////////////////////

    // 2. Level order print
    levelOrderPrint(root);

    //////////////////////////////////////////////
    return 0;
}

void levelOrderPrint(shared_ptr<Node> root){

    queue<shared_ptr<Node> > parQ, childQ;
    auto ptrPar = &parQ;
    auto ptrChild = &childQ;
    
    ptrPar->push(root);

    while(true)
    {
        while(!ptrPar->empty())
        {
            auto node = ptrPar->front(); 
            ptrPar->pop();
            cout << node->data << " ";
            if (node->left){ ptrChild->push(node->left);}
            if (node->right){ ptrChild->push(node->right);}
        }
        cout << endl;
        if (ptrChild->empty()){break;}

        // swap pointers (constant time is taken)
        auto temp = ptrPar;
        ptrPar = ptrChild;
        ptrChild = temp;
    }
}

vector<vector<int> > levelOrderVect(shared_ptr<Node> root){

    queue<shared_ptr<Node> > parQ, childQ;
    vector<vector<int> > treeNodes;
    vector<int> level;

    auto ptrPar = &parQ;
    auto ptrChild = &childQ;

    ptrPar->push(root);

    while(true)
    {
        while(!ptrPar->empty())
        {
            auto node = ptrPar->front(); 
            ptrPar->pop();
            level.push_back(node->data);          // add to level vector instead of printing
            if (node->left){ ptrChild->push(node->left);}
            if (node->right){ ptrChild->push(node->right);}
        }

        if (ptrChild->empty()){break;}

        treeNodes.push_back(level); // add level vector to main vector
        level.clear();

        // swap pointers (constant time is taken)
        auto temp = ptrPar;
        ptrPar = ptrChild;
        ptrChild = temp;
    }
    return treeNodes;
}