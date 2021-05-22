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

	void print_kth_level(node *root,int k)
	{
		if(root==NULL)
		{
			return;
		}

		if(k==1)
		{
			cout<<root->data<<"  ";
			return;
		}
			print_kth_level(root->left,k-1);
			print_kth_level(root->right,k-1);

			return;

	}

	void print_all_level(node *root)
	{
		for(int i=1;i<=height(root);i++)
		{
			print_kth_level(root,i);
			cout<<endl;
		}
		return;
	}

	int main()
	{
		node *root=build();
		preorder_print(root);
		cout<<endl;
		int h=height(root);
		cout<<h;
		cout<<endl;

		print_all_level(root);
		return 0;
	}