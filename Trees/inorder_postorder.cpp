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

	void preorder_print(node *root)
	{
		if(root==NULL){
			return;
		}
		cout<<root->data<<" ";	
		preorder_print(root->left);
		preorder_print(root->right);
		
	}

	void inorder_print(node *root)
	{
		if(root==NULL){
			return;
		}	
		inorder_print(root->left);
		cout<<root->data<<" ";
		inorder_print(root->right);
	}


	void postorder_print(node *root)
	{
		if(root==NULL){
			return;
		}	
		postorder_print(root->left);	
		postorder_print(root->right);
		cout<<root->data<<" ";
	}

	int main()
	{
		node *root=build();

		preorder_print(root);
		cout<<endl;
		inorder_print(root);
		cout<<endl;
		postorder_print(root);
		cout<<endl;

		return 0;
	}