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
int burn(node* &targetnode, unordered_map<node*,node*>&mp){
    queue<node*>q;
    q.push(targetnode);
    unordered_map<node*,bool>visited;
    
    while(!q.empty()){
        bool flag=false;
        int size=q.size();
        int count=0;
        for(int i=0;i<size;i++){
            node* front=q.front();
            q.pop();

            if(front->left && !visisted[front->left]){
                q.push(front->left);
                visited[front->left]=true;
                flag=true;
                
            }
            if(front->right && !visited[front->right]){
                q.push(front->right);
                visited[front->right]=true;
                flag=true;
            }

            if(mp[front] && !visited[mp[front]]){
                q.push(mp[front]);
                visited[mp[front]]=true;
                flag=true;
            }
        }
        if(flag==true)count++;
    }
    return count;

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