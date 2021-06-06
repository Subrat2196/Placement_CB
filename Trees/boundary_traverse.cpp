#include<iostream>
#include<vector>
using namespace std;

class Node
{
    
public:
        int data;
        Node *left;
        Node *right;

    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;

    }
    
};


class Solution {
public:
    void left_boundary(Node *root,vector<int> &v)
    {
        if(!root)
            return;
            
         Node *head=root;
        //print left boundary without the leaf nodes
        if(head->left)
        {
            v.push_back(head->data);
            left_boundary(head->left,v);
        }
        else if(head->right)
        {
            v.push_back(head->data);
            left_boundary(head->right,v);
            
        }
        
    }
    
    void right_boundary(Node *head,vector<int> &v)
    {
        Node *ptr=head;
        if(ptr->right)
        {
            right_boundary(ptr->right,v);
            v.push_back(ptr->data);
            
        }
        else if(ptr->left)
        {
            right_boundary(ptr->left,v);
            v.push_back(ptr->data);
        }
    }
    
    void print_leaf_node(Node *root,vector<int> &v)
    {
        if(!root) return;
        
        Node *p=root;
        if(p->left==NULL and p->right==NULL)
        {
            v.push_back(p->data);
        }
        
        print_leaf_node(p->left,v);
        print_leaf_node(p->right,v);
        
    }

    vector <int> printBoundary(Node *root)
    {
        vector <int> v;
        if(root==NULL)
        {
            return v;
        }
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->data);
            return v;
        }
        
        v.push_back(root->data);
        
        //print the left boundary
        left_boundary(root->left,v);
       
        //print all the leaf nodes
        print_leaf_node(root,v);
        
        
        //print the right boundary without the leaf nodes
        right_boundary(root->right,v);
        
        
        
        return v;
        //Your code here
    }
};

int main()
{


    return 0;
}