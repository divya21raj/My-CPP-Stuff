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
    if(head == NULL){
        cout<<"NULL";
        head = new Node(d);
        return;
    }
    cout<<"Not null";
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

int findMiddle(Node*head){
    Node*runner = head;

    while(runner != NULL && runner->next != NULL){
        runner = runner->next->next;
        head = head->next;
    }

    return head->data;
}

Node* reverse(Node*&head){
    if(head->next==NULL) return head;

    Node* chotaHead = reverse(head->next);
    
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

int kFromEnd(Node*head, int k){
    Node*runner = head;
    while(k!=0){
        runner = runner->next;
        k--;
    }    
    while(runner!=NULL){
        runner = runner->next;
        head=head->next;
    }

    return head->data;
}

int search(Node*head, int key){
    if(head == NULL) return -1;
    if(head->data == key) return 0;

    int ans = search(head->next, key);
    
    if(ans != -1) return 1 + ans;
    else return ans;
}

void deleteNode(Node*&head, int n){
    Node*temp = head;
    while(temp->next!=NULL){
        if(temp->next->data == n){
            Node*t = temp->next;
            temp->next = t->next;
            delete t;
            break;
        }
        temp = temp->next;
    }
}

int main(){
    Node*head;
    int n, in;
    cin>>n;
    
    while(n>0){
        n--;
        cin>>in;
        insertAtHead(head, in);
    }
    
    printList(head);
    
    cout<<findMiddle(head);
    
    return 0;
}