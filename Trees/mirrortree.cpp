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

	int height(node *root)
	{
		if(root==NULL)
			return 0;
		int lh,rh;

		lh=height(root->left);
		rh=height(root->right);

		return max(lh,rh)+1;
	}


	void mirror_tree(node *root)
	{
		if(!root)
		{
			return;
		}

		mirror_tree(root->left);
		mirror_tree(root->right);
		swap(root->left,root->right);


	}



	int main()
	{
		node *root=build();
		preorder_print(root);
		cout<<endl;
		int h=height(root);
		cout<<h;
		cout<<endl;

		mirror_tree(root);
		return 0;
	}