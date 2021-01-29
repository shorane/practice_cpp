// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
using namespace std;

/*
Objective: 
split a linked list in half

Process: 
- assuming odd length lists are split such that first half gets the extra item
- use two pointers, one travels 2x the other
- when you reach the end, the slower pointer should be adjusted
- adjustment: make its next node head_2. Make it point to nullptr. 
*/

class Node{
    public:
    int data;
    shared_ptr<Node> next;
    Node(): data(0), next(nullptr) {};
    Node(int d, shared_ptr<Node> n): data(d), next(n) {};
};

void printList(shared_ptr<Node> ptr);
void splitList(shared_ptr<Node> ptr);   // splits and prints list

int main(){

    // make linked list
    shared_ptr<Node> n5(new Node(5, nullptr));
    shared_ptr<Node> n4(new Node(4, n5));
    shared_ptr<Node> n3(new Node(3, n4));
    shared_ptr<Node> n2(new Node(2, n3));
    shared_ptr<Node> head(new Node(1, n2));

    cout << "Original List: " << endl; printList(head); // print original list

    // call function to split the linked lists
    splitList(head);    // splits and prints

    return 0;
}

void splitList(shared_ptr<Node> ptr){
    // edge case handling: splitting requires at least 2 items in list
    if (ptr == nullptr or ptr->next == nullptr){
        cout << "cannot split. list has less than two elements"<< endl;
    }
    
    shared_ptr<Node> head_1 = ptr, head_2, fast_ptr = ptr, slow_ptr = ptr;

    int counter = 0; // allows maintaining fast and slow pointers

    while(true){
        fast_ptr = fast_ptr->next;
        if (fast_ptr == nullptr){break;}    // exit condition
        ++counter;
        if (counter%2==0){                  // moves slow ptr in alternate cycles 
            slow_ptr = slow_ptr->next;
        }
    }
    head_2 = slow_ptr->next;
    slow_ptr->next = nullptr;

    // print both lists
    cout << "List 1: " << endl; printList(head_1);
    cout << "List 2: " << endl; printList(head_2);
}

void printList(shared_ptr<Node> ptr){
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }cout << endl << endl;
}