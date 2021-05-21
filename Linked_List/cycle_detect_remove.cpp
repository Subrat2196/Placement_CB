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

		bool cycle_detect(node *head)
		{
			node *s;
			node *f;
			while(f!=NULL and f->next!=NULL)
			{
				s=s->next;
				f=f->next->next;
			
				if(f==s)
				{
					return true;
				}

			}

			return false;
			
		}


		int main()
		{
			node *head=input();

			print(head);


			cycle_detect(head);


		}