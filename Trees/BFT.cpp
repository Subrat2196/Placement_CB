#include<iostream>
#include<queue>
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


	void BFT(node *root)
	{
		queue<node*> q;  // here the data in queue will be address of the node
						 // we want to push or pop since even though we know that data is int
						 // dont know what its children data may be of what type		

		q.push(root);

		while(!q.empty())
		{
			node *f=q.front();
			cout<<f->data<<",";
			q.pop();

			if(f->left)
			{
				q.push(f->left);
			}
			if(f->right)
			{
				q.push(f->right);
			}
		}

		return;
	}


	int main()
	{

		node *root=build();
		BFT(root);

		return 0;
	}