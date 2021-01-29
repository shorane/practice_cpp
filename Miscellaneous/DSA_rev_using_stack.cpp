#include <iostream>
#include<strings.h>

using namespace std;

// Class for stack
class Stack{
private:
    char A[101];
    int B[101];
    int top;
public:
    void push(char x){
        //cout<<"top is: "<<top<<" | ";
        top++;
        //cout<<"top after inc: "<<top<<endl;
        A[top] = x;
    }
    void push(int x){
        top++;
        B[top] = x;
    }

    /*char pop(){
        if (top==-1){
            cout<<"Stack is empty"<<endl;
            return NULL;
        }
        else{
        int t = top;
        top--;
        return A[t];
        }
    }*/
    int pop(){
        if (top==-1){
            cout<<"Stack is empty"<<endl;
            return NULL;
        }
        else{
        int t = top;
        top--;
        return B[t];
        }
    }/*
    char Top(){
        return A[top];
    }*/
    int Top(){
        return B[top];
    }
    bool isEmpty(){
        if(top==-1){ return true;}
        else{return false;}
    }
    Stack();
};
Stack::Stack(){
    top = -1;
}

void Reverse(char* A, int len){
    Stack S;
    for(int i=0; i<len; i++){
        S.push(A[i]);
        //cout<<S.Top()<<" ";
    }//cout<<endl;
    for(int i=0; i<len; i++){
        A[i] = S.pop();
        //cout<<A[i]<<"  ";
    }cout<<endl;
}

class node{
public:
    int data;
    node * next;
};node * head;

node* getnewnode(){
    node* newnode = new node;
    return newnode;
}
void Insert(int x){
    node *temp = new node;
    temp->data = x;
    temp->next = head;
    head = temp;
}
void Print(node* addr){
if (addr == NULL){
    cout<<endl;
    return;
}
cout<<addr->data<<" ";
Print(addr->next);
}
void rev_linked(){
    Stack S1;
    node * temp = getnewnode();
    temp = head;
    while (temp!=NULL){
        S1.push(temp->data);
        temp = temp->next;
        cout<<S1.Top()<<" ";
    }cout<<endl;
    temp = head;
    while(S1.Top()!=NULL){
        temp->data = S1.pop();
        temp = temp->next;
    }temp->next = NULL;
}

int main()
{
    /*
    char A[101];
    cout<<"enter: "<<endl;
    cin>>A;
    //cout<<"A entered is: "<<A[0]<<endl;
    Reverse(A,strlen(A));
    cout<<A<<endl;*/

    head = NULL;
    Insert(6);Insert(5);Insert(4);Insert(3);Insert(2);Insert(1);
    Print(head);
    rev_linked();
    Print(head);
    return 0;
}
