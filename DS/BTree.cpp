#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left, *right;

    //Init List
    Node(int d):data(d),left(NULL),right(NULL){}
};

Node* createTree(){
    int d;
    cin>>d;

    if(d==-1) return NULL;

    Node*root = new Node(d);
    root->left = createTree();
    root->right = createTree();

    return root;
}

void preorderPrint(Node*root){
    if(root==NULL) return;
    
    cout<<root->data<<" ";

    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorderPrint(Node*root){
    if(root==NULL) return;
    
    preorderPrint(root->left);
    cout<<root->data<<" ";
    preorderPrint(root->right);
}

int countNodes(Node *root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int height(Node *root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left) , height(root->right));
}

void bfs(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //Marking levels

    while(!q.empty()){
        Node*f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout<<f->data<<" ";
        q.pop();

        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
}

void printList(vector<int> &v){
    for(auto i:v) cout<<i<<" ";
    cout<<endl;
}

void allPathToLeaves(Node*root, vector<int> &v){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        printList(v);
        return;
    }

    v.push_back(root->data);
    allPathToLeaves(root->left, v);    
    allPathToLeaves(root->right, v);    
    v.pop_back();
}

void levelOrderPrint(Node *root){
    
}

int main(){
    Node* root = createTree();
    
    preorderPrint(root);
    cout<<endl;
    inorderPrint(root);
}