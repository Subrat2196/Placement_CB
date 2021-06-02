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

		void last_to_first(node *&head)
		{
			node *p=head;

			if(p->next==NULL)
				return;

			node*q=p->next;
			while(q->next!=NULL)
			{
				q=q->next;
				p=p->next;
			}

			q->next=head;
			p->next=NULL;
			head=q;


		}

		int main()
		{
			node *head=input();


			last_to_first(head);

			print(head);


			return 0;
		}