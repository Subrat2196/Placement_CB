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

		node* kth_node(node *head,int k)
		{
			if(k>length_ll(head))
				return NULL;
			node *p=head;
			for(int i=1;i<=k;i++)
			{
				p=p->next;
			}

			node *q=head;
			while(p!=NULL)
			{
				p=p->next;
				q=q->next;
			}

			return q;

		}



		int main()
		{
			node *head=input();

			print(head);
			cout<<endl;
			int k;
			cin>>k;
			cout<<"The kth node from the end is"<<kth_node(head,k)->data<<endl;

		}

