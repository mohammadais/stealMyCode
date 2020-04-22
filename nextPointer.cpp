/*
    POPULATE NEXT POINTER

             1
           /   \
          2     3
         / \   / \
        4   5 6   7


            1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \  / \
        4->5->6->7 -> NULL

    QUEUE : 

*/
#include<iostream>
#include<queue>
using namespace std;

class node{
public:
    int val;
    node *left, *right, *next;

    // constructor
    node(int data){
        val = data;
        left = right = next = NULL;
    };
};


void populateNextPointer(node* tree){
    // write code here

    queue<pair<int, node*> > q;
    q.push(make_pair(1, tree));

    while (!q.empty()){

        node* currNode = q.front().second;
        int currLevel = q.front().first;
        q.pop();

        // iterating over current level
        while (!q.empty() && currLevel == q.front().first){

            currNode -> next = q.front().second;
            q.pop();

            cout << currNode -> val << ' ' << currNode -> next -> val << endl;


            if (currNode -> left)
                q.push(make_pair(currLevel + 1, currNode -> left));
            if (currNode -> right)
                q.push(make_pair(currLevel + 1, currNode -> right));


            currNode = currNode -> next;
        }

        currNode -> next = NULL;
        cout << currNode -> val << ' ' << "NULL" << endl;

        if (currNode -> left)
            q.push(make_pair(currLevel + 1, currNode -> left));
        if (currNode -> right)
            q.push(make_pair(currLevel + 1, currNode -> right));

    }

}


void bfs(node* tree){

    // write code here
    queue<node*> q;
    q.push(tree);

    while (!q.empty()){

        node* curr = q.front();
        q.pop();

        cout << curr -> val << ' ' ;
        if (curr -> next)
            cout << curr -> next -> val;
        cout << endl;
        
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

    populateNextPointer(tree);

    return 0;
}