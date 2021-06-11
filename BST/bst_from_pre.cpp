#include <iostream>
#include <stdio.h>
#include <vector>
#include<climits>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

/* Naive approach

class Solution {
public:
    TreeNode* solve(TreeNode*& root,int ele)
    {
        if(!root)
        {
            root=new TreeNode(ele);
        }
        
        if(root->val>ele)
        {
            root->left=solve(root->left,ele);
        }
        
        else
        {
            root->right=solve(root->right,ele);
        }
        
        return root;
        
    }
        
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode* root=NULL;
        
        for(auto x: preorder)
        {
            solve(root,x);
        }
        
        
        return root;
    }
};


*/

class Solution {
public:
    
    int solve(vector<int> &v,int n,int i,TreeNode* root,int min,int max)
    {    
        if(i==n || v[i]<min || v[i]>max)  //Here it is for the boundary case when either we have traversed the vector or out of range scenarios
              return i;
        
        if(v[i]<root->val)              // Now we already checked the range i.e it lies in range now we will see if its smaller then insert on left
        {
            root->left=new TreeNode(v[i]);
            i++;
            i=solve(v,n,i,root->left,min,root->val-1);  //The position will keep on changing when we return,thereofore we need to return position
        }         //When we go left our max reduces by one from the current value
        
        if(i==n || v[i]<min || v[i]>max)   //After inserting on left we will again check the boundary condition before going to the right
              return i;
        
    
         root->right=new TreeNode(v[i]);   
         i++;
         i=solve(v,n,i,root->right,root->val+1,max);  //Here when we go right our min is root->val+1;
        
        return i;
        
        
    } 
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        
        int n=preorder.size();
        
        if(n==0)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[0]);
        
        if(n==1)
            return root;
        
        int min=INT_MIN;
        int max=INT_MAX;
        int i=1;
        solve(preorder,n,i,root,min,max); 
        return root;
    }
};

int main()
{


    return 0;
}
