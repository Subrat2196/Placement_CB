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

		int length_ll(node *head)
		{
			int count=0;
			while(head!=NULL)
			{
				count=count+1;
				head=head->next;		
			}
			return count;
		}

		node *merge_sorted_LL(node *a,node *b)
		{
			node *c;
			if(a==NULL)
				return b;
			if(b==NULL)
				return a;

			else
			{
				if(a->data<b->data)
				{
					c=a;
					c->next=merge_sorted_LL(a->next,b);
				}
				else
				{
					c=b;
					c->next=merge_sorted_LL(a,b->next);
				}

				return c;

			}
		}
		node* mid_point(node *head)
		{
			node *fast=head->next;
			node *slow=head;

			if(head==NULL)
				 return NULL;
			if(head->next==NULL)
				return head;

			while(fast!=NULL && fast->next!=NULL)   //So that we dont get a segmentation fault
			{
				slow=slow->next;
				fast=fast->next->next;
			}
			return slow;
		}

		node * merge_sort(node *head)
		{
			if(head==NULL || head->next==NULL)
				return head;
			//Divide the linked list
			node *mid=mid_point(head);
			node *a=head;
			node *b=mid->next;
			mid->next=NULL;

			//Recursively sort

			a=merge_sort(a);
			b=merge_sort(b);

			//Merge the linked list
			node*c=merge_sorted_LL(a,b);
			return c;

		}

		int main()
		{
			node *head=input();
			print(merge_sort(head));



		}