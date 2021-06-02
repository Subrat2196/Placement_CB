#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;

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

		void insert_at_tail(node *&head,int data)
		{
			if(head==NULL)
			{
				head= new node(data);
				return;
			}
			else
			{
				node *n=new node(data);
				node *ptr=head;
				while(ptr->next!=NULL)
				{
					ptr=ptr->next;
				}
				ptr->next=n;
				return;

			}
		}

		void delete_head(node *&head)
		{
			if(head==NULL)
			{
				return ;
			}
			else
			{
				node *ptr=head->next;
				delete(head);
				head=ptr;

			}
		}



	node* build()
	{
		int d;
		cin>>d;

		node *head=NULL;

		while(d==-1)
			{
				insert_at_head(head,d);

			}

		return head;

	}

	void print(node *head)   //This head is a copy as we are passing by value
		{
			while(head!=NULL)
			{
				cout<<head->data<<"->";
				head=head->next;
			}

		}


		class Queue
		{
			int cs;
		public:
			node *head=NULL;
			Queue()
			{
				cs=0;
			}

			bool isEmpty()
			{
				return cs==0;
			}
			void push(int data)
			{

				insert_at_tail(head,data);
				cs=cs+1;

			}

			void pop()
			{
				if(!isEmpty())
				{

				cs=cs-1;
				delete_head(head);

				}

			}

			int front()
			{
				return head->data;				
			}


		};


		int main()
		{
			
			node *head=build();

			return 0;
		}