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

		// void insert_at_middle(node *&head,int data,int after_node_data)
		// {
		// 	if(head==NULL)
		// 		return;
		// 	if(head->next==NULL)
		// 	{
		// 		if(head->data==after_node_data)
		// 		{
		// 			node*ptr=new node(data);
		// 			head->next=ptr;
		// 			return;
		// 		}
		// 	}
		// 	else
		// 	{
		// 		node*ptr=new node(data);
		// 		node* n=head;
		// 		while(n->data!=after_node_data)
		// 		{
		// 			n=n->next;
		// 		}
		// 		ptr->next=n->next;
		// 		n->next=ptr;

		// 	}
		// }
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


		void insert_at_middle(node *&head,int data,int p)
		{
			if(head==NULL || p==0)
				insert_at_head(head,data);
			else if(p>length_ll(head))
			{
				insert_at_tail(head,data);
			}

			else
			{
				node*ptr=new node(data);
				node* n=head;
				int jump=1;
				while(jump<=p-1)
				{
					n=n->next;
					jump++;
				}
				ptr->next=n->next;
				n->next=ptr;

			}
		}

		//iterative search
		bool iterative_search(node *head,int key)
		{
			if(head==NULL){
				return false;
			}

			else 
			{
				while(head!=NULL)
				{
					if(head->data==key)
						return true;
				}
				return false;
			}
		}
		//Recursive search of an element in the linked list



		bool Recursive_search(node *head,int key)
		{
			if(head==NULL)
				return false;
			if(head->data==key)
				return true;
			else
				return Recursive_search(head->next,key);
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

	node* input_from_file()   //if you want to take input from file  
	{ 
		int d;
		node*head=NULL;
		while(cin>>d)
		{
			insert_at_head(head,d);
		}
		return head;
	}

	// If we want to print the linked list using cout<<head and not explicitly calling the print function
	// and similarly for taking the input using cin function

	//cout is object of class ostream
	ostream& operator<<(ostream &os,node* head)
	{
		print(head);
		return os;
	}  

	istream& operator>>(istream &is,node* &head)
	{
		head=input();
		return is;
	}

		

int main()
{

	// node *head=input();
	// node *head=input();
	// node* head2=input();


	node *head;
	node* head2;
	cin>>head>>head2;

	//print(head);
	//first operator overloading
	//then cascading of operators
	cout<<head<<"     "<<head2;
	

	// print(head);


	// insert_at_head(head,10);
	// insert_at_head(head,20);
	// insert_at_head(head,30);
	// insert_at_middle(head,40,20);
	
	
	// insert_at_middle(head,40,2);
	// insert_at_tail(head,50);
	
	// cout<<endl;
	// cout<<length_ll(head)<<endl;
	// print(head);
	// cout<<endl;
	// delete_head(head);
	// print(head);
	// if(Recursive_search(head,60))
	// {
	// 	cout<<"element found"<<"\n";
	// }
	// else
	// {
	// 	cout<<"Not found"<<"\n";
	// }
	return 0;

}