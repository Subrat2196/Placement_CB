#include<iostream>
using namespace std;

class node{
public:
		int data;
		node *next;

		//constructor
		node(int d)
		{	
			data=d;
	 		next=NULL;
		}

	};


		void insert_at_head(node *&head,int data)
		{
		//first node is inserted
			if(head==NULL)
			{
				head=new node(data);
				return;	
			}

			node*ptr =new node(data);
			ptr->next=head;
			head=ptr;
		}

		void print(node *head)   //This head is a copy as we are passing by value
		{
			while(head!=NULL)
			{
				cout<<head->data<<"->";
				head=head->next;
			}

		}

		node* input()   
		{ 
			int d;
			cin>>d;
			node*head=NULL;
			while(d!=-1)
			{
				insert_at_head(head,d);
				cin>>d;
			}
			return head;			
		}

		int mid_point(node *head)
		{
			node *fast=head->next;
			node *slow=head;

			if(head==NULL)
				 return 0;
			if(head->next==NULL)
				return head->data;

			while(fast!=NULL && fast->next!=NULL)   //So that we dont get a segmentation fault
			{
				slow=slow->next;
				fast=fast->next->next;
			}
			return slow->data;
		}



		int main()
		{
			node *head=input();

			print(head);
			cout<<endl;

			cout<<"The data in the middle node is"<<mid_point(head)<<endl;

		}