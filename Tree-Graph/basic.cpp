#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
    int data;
    vector<Node*> children;

    Node(int n){data = n;}
};

class Tree{
    public:
    Node *root;

    Tree(Node*r){
        root = r;
    }
    void traverse(Node*root){
        cout<<root->data<<" ";
        for(auto child: root->children){
            traverse(child);
        }
    }

};

int main(){
    Tree *tree = new Tree(new Node(5));
    tree->root->children.push_back(new Node(3));
    tree->root->children.push_back(new Node(2));
    tree->root->children.push_back(new Node(6));
    
    tree->root->children[0]->children.push_back(new Node(6));
    tree->root->children[0]->children.push_back(new Node(1));
    
    tree->root->children[1]->children.push_back(new Node(7));
    
    tree->root->children[2]->children.push_back(new Node(1));
    tree->root->children[2]->children.push_back(new Node(4));
    tree->root->children[2]->children.push_back(new Node(2));

    tree->traverse(tree->root);
    
    return 0;
}