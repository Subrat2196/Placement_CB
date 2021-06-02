class Solution{
  public:
  
     Node* reverse_iter(Node* head)
			{
				Node*p=head;
				Node*q=NULL;
				Node*r;

				while(p!=NULL)
				{
					r=q;
					q=p;
					p=p->next;
					q->next=r;
				}
				return q;
			}
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node * head2=reverse_iter(head);
        
        Node *p=head;
        Node *q=head2;
        while(p!=NULL and q!=NULL)
        {
            if(p->data==q->data)
            {
                p=p->next;
                q=q->next;
            }
            else
            {
                return false;
            }
            
            
        }
        
        return true;
        //Your code here
    }
};