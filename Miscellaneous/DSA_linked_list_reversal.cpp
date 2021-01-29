#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};

void Reverse(struct node* h){
    struct node*current,*prev,*temp;
    current = h;
    prev = NULL;
    while (temp != NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    h = prev;
}


int main()
{
    struct node* head;
    head->data = 2;
    head->next = NULL;

    return 0;
}
