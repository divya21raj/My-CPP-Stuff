#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
    int data;
    bool visited;
    vector<Node*> neighs;

    Node(int n){data = n;}
};

class Graph{
    public:
    vector<Node*> nodes;

    void depthFirst(Node*root){
        for(auto node: root->neighs){
            if(!node->visited) {
                cout<<node->data<<" ";
                node->visited = true;
            }
        }
    }

    void breadthFirst(Node*root){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            cout<<node->data<<" ";
            node->visited = true;
            for(auto neigh: node->neighs){
                if(!neigh->visited){
                    q.push(neigh);
                }
            }
        }
    }

};

int main(){
    Graph g;
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);

    g.nodes.push_back(node1);
    g.nodes.push_back(node2);
    g.nodes.push_back(node3);
    g.nodes.push_back(node4);
    g.nodes.push_back(node5);
    g.nodes.push_back(node6);

    g.nodes[0]->neighs.push_back(node2);
    g.nodes[0]->neighs.push_back(node4);

    g.nodes[1]->neighs.push_back(node3);

    g.nodes[2]->neighs.push_back(node3);
    g.nodes[2]->neighs.push_back(node4);
    
    g.nodes[3]->neighs.push_back(node2);
    g.nodes[3]->neighs.push_back(node6);
    
    g.nodes[5]->neighs.push_back(node1);

    g.breadthFirst(node1);
    
    return 0;
}