// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

int length(Node *head)
{
    int count=0;
    Node *ptr=head;
    while(ptr!=NULL)
    {
        count=count+1;
        ptr=ptr->next;
    }
    
    return count;
    
    }

class Solution
{
    public:
    
    struct Node* insert_at_head(Node *root,int m)
    {
        if(root==NULL)
        {
            root = new struct Node(m);
            return root;
        }
        
        struct Node *ptr=new struct Node(m);
        ptr->next=root;
        root=ptr;
        return ptr;
        
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int n=length(first);
        int m=length(second); 
        
        int N=1;
        
        while(--n)
        {
            N=N*10;
        }
        struct Node *q=first;
        int count1=0;
        while(q!=NULL)
        {
            count1+=(q->data)*N;
            N=N/10;
            q=q->next;
        }
        
        // return NULL;
        
        int M=1;
        while(--m)
        {
            M=M*10;
        }
        // cout<<M<<endl;
        Node *r=second;
        int count2=0;
        while(r!=NULL)
        {
            count2+=(r->data)*M;
            M=M/10;
            r=r->next;
        }
        
        // return NULL;
      int count=count1+count2;
        
        struct Node *root=NULL;
        while(count>0)
        {
            int m=count%10;
            root=insert_at_head(root,m);
            count=count/10;
        }
        
        return root;     
        
        // code here
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends