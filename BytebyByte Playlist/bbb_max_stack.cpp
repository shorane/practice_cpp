// #include <bits/stdc++.h>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// Objective: Implement stack with push, pop, max functions, all with O(1) time complexity
// Solution: push and pop work easily with opertions at tail.
//           a vector<int> stores the history of all max nums and is updated in each push/pop
//           in O(1) time. A max_num member is used to store the current max value.

class Node{
    public:
    shared_ptr<Node> next;
    shared_ptr<Node> prev;
    int data;

    Node(): data(0), next(nullptr), prev(nullptr) {};
    Node(int d, shared_ptr<Node> p, shared_ptr<Node> n): data(d), prev(p), next(n) {};
};

class stack{

    vector<int> max_history;
    int max_num;
    public:
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    stack(): head(nullptr), tail(nullptr) {
        max_history.push_back(INT_MIN);
        max_num = INT_MIN;
        }

    void push(int d){
        shared_ptr<Node> new_node(new Node(d,tail,nullptr));
        if (head == nullptr) { head = new_node; tail = new_node;}
        tail->next = new_node;
        tail = new_node;
        max_num = (max_num > d)?max_num:d;
        if (*(max_history.end()-1) < max_num ) max_history.push_back(max_num);
    }

    void pop(){
        if (tail->data == max_num){
            max_history.erase(max_history.end()-1);
            max_num = *(max_history.end()-1);
        }
        if (head == tail) { head = nullptr; tail = nullptr;}
        else{
            tail = tail->prev;
            tail->next = nullptr;
            }

    }

    int max() {return max_num;}

};

void printStack(shared_ptr<stack> s){
    cout << endl << "Printing Stack" << endl;
    shared_ptr<Node> temp = s->head;
    while (temp != nullptr){
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl << "MAX: " << s->max() << endl << "Printing Complete" << endl;
}

int main(){

    // create stack object
    shared_ptr<stack> st(new stack());
    // add elements using push, remove using pull, keep checking for max
    st->push(10);
    st->push(7);
    st->push(87);
    st->push(100);
    printStack(st);
    st->pop();
    printStack(st);
    st->pop();
    printStack(st);


    return 0;
}