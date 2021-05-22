#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *left;
	node *right;

	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

	node* build()
	{
		int d;
		cin>>d;

		if(d==-1)
			return NULL;

		node *root=new node(d);
		
		root->left=build();
		root->right=build();

		return root;

	}

	int height(node *root)
	{
		if(root==NULL)
			return 0;
		else
		{
			int lh,rh;
			lh=height(root->left);
			rh=height(root->right);
			return 1+max(lh,rh);
		}
	}

	int diameter(node *root)
	{

		if(root==NULL)
			return 0;

		//case1 - when the diameter traverses the root of the tree to other side of the root

		int first_case=height(root->left) + height(root->right);
		
		//second case - when the diameter is on the left side of the tree

		int second_case=diameter(root->left);

		//third case - when the diameter is on the right side of the tree 

		int third_case=diameter(root->right);

		return max(third_case,max(first_case,second_case));

	}


	int main()
	{
		node *root=build();
		cout<<height(root)<<endl;
		cout<<diameter(root)<<endl;;
		return 0;
	}