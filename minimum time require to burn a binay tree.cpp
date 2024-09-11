// Minimum time require to burn a binary tree 


#include <iostream>
#include<bits/stdc++.h>
using namespace std;



class node {
public:
    int data;
    node* left;
    node* right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int mapping(node* &root, int target, unordered_map<node*,node*>&mp){
    queue<node*>q;
    q.push(root);
    int res=0;
    mp[root]=nullptr;
    while(!q.empty()){
        node* front=q.front();
        q.pop();
        if(front->data==target)  res=front;

        if(front->left){
            mp[front->left]=root;
            q.push(front->left);
        }

        if(front->right){
            mp[front->right]=root;
            q.push(front->right);
        }


    }
    return res;

}


int time(node* root, int target){

    unordered_map<node*,node*>mp;

    int targetnode=mappping(root,target,mp);

    int ans=(targetnode,mp);

    return ans;

}


int main()
{
     node* root = new node(100);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(40);
    root->left->right = new node(50);
    root->right->left = new node(60);
    root->right->right = new node(70);

    int target;
    cout<<"Enter the target "<<endl;
    cin>>target;

    cout<<"Minimum time require to burn a binary tree is "<<time(root,target);
    
  
}