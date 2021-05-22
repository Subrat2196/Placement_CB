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

	int count_nodes(node *root)
	{
		if(root==NULL)
		{
			return 0;
		}
		else
		{
			int lc,rc;
			lc=count_nodes(root->left);
			rc=count_nodes(root->right);

			return (1+lc+rc);
		}
	}
	int sum_nodes(node *root)
	{
		if(root==NULL)
		{
			return 0;
		}
		else
		{
			int ls,rs;
			ls=sum_nodes(root->left);
			rs=sum_nodes(root->right);

			return (root->data +ls+rs);
		}
	}

	int main()
	{
		//  1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1
		node *root=build();
		int total_nodes=count_nodes(root);
		cout<<"The total nodes in the tree are "<<"-> "<<total_nodes<<endl;

		int total_sum=sum_nodes(root);
		cout<<"The total sum of nodes in the tree is "<<"-> "<<total_sum<<endl;

		return 0;
	}