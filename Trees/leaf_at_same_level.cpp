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


int ans=1;  // We assume that our answer is true, therefore we only need to check the false condition
void solve(Node *root,int h,int &ma)
{
    if(!root) return;

    if(ans==0)
        return;
        
    if(!root->left and !root->right)
    {
        if(ma==-1)
        {
            ma=h;
        }
        else
        {
            if(h!=ma)
                ans=0;
        }
        
        return;
    }
    
    solve(root->left,h+1,ma);
    solve(root->right,h+1,ma);

    
}


class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        int ma=-1; //for knowing that it is the first time we are traversing a leaf node
        int h=0; //initially height is set to 0
        ans=1;   //assume that same levels of all the binary tree
        
        
        solve(root,h,ma);
        return ans;
        //Your code here
    }
};


int main()
{
    return 0;
}