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
		void reverse_iter(node* &head)
			{
				node*p=head;
				node*q=NULL;
				node*r;

				while(p!=NULL)
				{
					r=q;
					q=p;
					p=p->next;
					q->next=r;
				}
				head=q;
			}

		// void reverse_rec(node *&prev,node* &current)
		// {
		// 	if(current!=NULL)
		// 		{
		// 			reverse_rec(current,current->next);
		// 			current->next=prev;
		// 		}
		// 		else
		// 		{
		// 			return;
		// 		}

			
		// }


   	 	void reverse_print_recursion(node *head)
   	 	{
   	 		if(head==NULL)
   	 			return;
   	 		else
   	 		{
   	 			reverse_print_recursion(head->next);
   	 			cout<<head->data<<"->";
   	 		}
   	 	}

   	 	void recursive_rev(node *p,node *&head)
   	 	{
   	 		if(p->next==NULL)
   	 		{
   	 			head = p;
   	 			return;
   	 		}
   	 		else
   	 		{
   	 			recursive_rev(p->next,head);
   	 			p->next->next=p;
   	 			p->next=NULL;
   	
   	 			//cout<<head->data<<"->";
   	 		}
   	 	}

   	 	void reverse(node *head)
   	 	{
   	 		if(head==NULL)
   	 			return;
   	 		else
   	 		{
   	 			reverse_print_recursion(head->next);
   	 			cout<<head->data<<"->";
   	 		}
   	 	}


		int main()
		{
			node *head=input();	

			cout<<"The original list is shown below"<<"\n";
			print(head);

			cout<<endl;
			cout<<"The reversed list is shown below"<<endl;
			// reverse_iter(head);

			 recursive_rev(head,head);

			//reverse_print_recursion(head);			

			print(head);	
			return 0;

		}
