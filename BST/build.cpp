#include <iostream>
#include <queue>

using namespace std;
//template<typename T> you can also do like this for template class
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



// what this function does it, it accepts the old root node and data and returns the new root node
node * insert_bst(node* root,int d)
{	
	//base case
	if(root==NULL)
	{
		return new node(d);
	}

	//recursive case

	if(d <= root->data)
	{
		root->left=insert_bst(root->left,d);
	}
	else
	{
		root->right=insert_bst(root->right,d);
	}

	return root;
}


node *build()
{
//read a list of numbers till -1 and all these numbers will be added to the bst

	int d;
	cin>>d;

	node *root=NULL;

	while(d!=-1)
	{
		root=insert_bst(root,d);
		cin>>d;
	}

	return root;
}

void bst(node *root)
{
	queue<node *> q;

	if(root==NULL)
		return;

	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node *temp=q.front();
		if(temp==NULL)
		{
			cout<<endl;
			q.pop();

			if(!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout<<temp->data<<",";
			q.pop();
		
		if(temp->left)
			{
				q.push(temp->left);
			}

		if(temp->right)
			{
				q.push(temp->right);
			}
		}

	}

	return;
}
	bool flag=false;

	void solve(node *root,int key)
	{	

		if(root==NULL)
			return;

		if(root->data==key){
			flag=true;
			return;
		}

		else if(root->data>key)
		{
			solve(root->left,key);
		}
		else
		{
			solve(root->right,key);
		}
	}

	bool search(node *root,int key)
	{
		if(root==NULL)
			return false;

			solve(root,key);		

			return flag;

	}


	node* deleteinbst(node *root,int key)
		{	
			//The first thing we need to do is to search the node

			if(root==NULL)
				return NULL;

			else if(root->data==key)
			{
				//found the element to do the 3 cases

				// 1st case-> Leaf Node to be deleted

				if(root->left==NULL and root->right==NULL){
					delete root;
					return NULL;
				}

				// 2nd case - when a node with only one child either left or right is to be deleted

				if(root->left!=NULL and root->right==NULL)
				{
					node *temp=root->left;
					delete root;
					return temp;
				}
				if(root->right!=NULL and root->left==NULL)
				{
					node *temp=root->right;
					delete root;
					return temp;
				}

				//3rd case- when a node with 2 nodes has to be deleted

				//Here we need to see the node's inorder predecessor or inorder successor and replace it with that value and then 
				// see if the successor predecessor has children or not and deal accordingly

				//lets say we have to find the inorder successor

				node *val=root->right;
				while(val->left!=NULL)
				{
					val=val->left;
				}

				root->data=val->data;
				//val will give me the inorder successor


				root->right=deleteinbst(root->right,val->data);
				return root;

			}

			else if(root->data<key)
			{	
				deleteinbst(root->right,key);
				return root;

			}
			else
			{
				deleteinbst(root->left,key);
				return root;

			}

		}


	int main()
	{

		node *root=build();

		bst(root);  //here we are printing the bst level by level

		cout<<endl;

		int key;
		cout<<"Enter the key to be deleted"<<endl;
		cin>>key;

		cout<<endl;

		// if(search(root,key))
		// {
		// 	cout<<"Element has been found"<<endl;
		// }
		// else
		// {
		// 	cout<<"Not found"<<endl;
		// }

		root=deleteinbst(root,key);
		bst(root);
		cout<<endl;
		return 0;
	}
