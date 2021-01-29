// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
using namespace std;

class Node{
    public: 
    int data;
    shared_ptr<Node> next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
    Node(int d, shared_ptr<Node> n) : data(d), next(n) {}
};

void nthToLast ( shared_ptr<Node> head, int n);

int main(){

    // select n
    cout << "Enter n" << endl;
    int dist;
    cin >> dist;
    cout << endl;

    // make linked list
    shared_ptr<Node> n5(new Node(5));
    shared_ptr<Node> n4(new Node(4,n5));
    shared_ptr<Node> n3(new Node(3,n4));
    shared_ptr<Node> n2(new Node(2,n3));
    shared_ptr<Node> n1(new Node(1,n2));

    // call nth-to-last function
    nthToLast ( n1, dist );

    return 0;
}


void nthToLast ( shared_ptr<Node> head, int n){
    shared_ptr<Node> curr = head;
    shared_ptr<Node> foll = head;

    int count = 0;

    while (count < n){
        curr = curr->next;
        ++count;
        
        // edge handling
        if (curr == nullptr){
            cout << "Length of linked list shorter than n" << endl << endl;
            return;
        }
    }

    while (curr->next != nullptr){
        curr = curr->next;
        foll = foll->next;
    }
    cout << "Answer: " << foll->data << endl;
}