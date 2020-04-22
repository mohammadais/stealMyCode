/*
    LEVEL ORDER TRAVERSAL / BFS

             1
           /   \
          2     3
         / \   / \
        4   5 6   7

    QUEUE : 
    BFS : 1 2 3 4 5 6 7
*/
#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int val;
    node *left, *right;

    // constructor
    node(int data){
        this -> val = data;
        this -> left = this -> right = NULL;
    };
};

void bfs(node* tree){
    // write code here

    queue<node*> q;
    q.push(tree);

    while (!q.empty()){

        node* curr = q.front();
        q.pop();

        cout << curr -> val << ' ';

        if (curr -> left)
            q.push(curr -> left);
        if (curr -> right)
            q.push(curr -> right);
    }
    cout << endl;
}


int main(){

    node* tree = new node(1);
    
    tree -> left = new node(2);
    tree -> right = new node(3);

    tree -> left  -> left = new node(4);
    tree -> left  -> right = new node(5);

    tree -> right  -> left = new node(6);
    tree -> right  -> right = new node(7);

    bfs(tree);

    return 0;
}