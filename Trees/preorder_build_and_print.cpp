#include<iostream>
using namespace std;

class node
	{
	public:
			int data;
			node*left;
			node*right;

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

	void pre_order_print(node *root)
	{
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";
		pre_order_print(root->left);
		pre_order_print(root->right);
	}

int main()
{
	node *root=build();

	pre_order_print(root);
}