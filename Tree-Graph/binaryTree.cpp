#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int n){data = n;}
};

class BinTree{
    public:
    Node *root;

    BinTree(Node*r){
        root = r;
    }
    void inOrdertraverse(Node*root){
        inOrdertraverse(root->left);
        cout<<root->data<<" ";
        inOrdertraverse(root->right);
    }

};

int main(){
    BinTree *tree = new BinTree(new Node(5));
    
    tree->inOrdertraverse(tree->root);
    
    return 0;
}