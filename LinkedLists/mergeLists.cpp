// Merge two sorted lists
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int n){
        data = n;
        next = NULL;
    }
};

void insertAtHead(Node*&head, int d){
    Node*n = new Node(d);
    n->next = head;
    head = n;
}

void printList(Node*head){
    while(head->next != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}

Node* reverse(Node*&head){
    if(head->next==NULL) return head;

    Node* chotaHead = reverse(head->next);
    
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

Node* sortedMerge(Node*a, Node*b){
    if(a==NULL) return b;
    if(b==NULL) return a;

    Node*c = new Node(0);
    if(a->data < b->data){
        c = a;
        c->next  = sortedMerge(a->next, b);
    }else{
        c = b;
        c->next  = sortedMerge(a, b->next);
    }

    return c;
}

int main(){
    Node*head1 = new Node(1);
    Node*head2 = new Node(3);

    insertAtHead(head1, 2);
    insertAtHead(head1, 3);
    insertAtHead(head1, 8);
    
    insertAtHead(head2, 4);
    insertAtHead(head2, 5);
    insertAtHead(head2, 7);
    insertAtHead(head2, 10);
    insertAtHead(head2, 11);

    head1 = reverse(head1);
    head2 = reverse(head2);

    printList(head1);
    printList(head2);
    
    printList(sortedMerge(head1, head2));

    return 0;
}