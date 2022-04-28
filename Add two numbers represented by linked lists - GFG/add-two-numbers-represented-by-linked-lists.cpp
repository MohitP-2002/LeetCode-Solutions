// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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

class Solution
{
    public:
    struct Node* reverseList(struct Node* head) {
        stack<int> s;
        struct Node* n=head;
        while(n!=nullptr){
            s.push(n->data);
            n=n->next;
        }
        n=head;
        while(n!=nullptr){
            n->data=s.top();
            s.pop();
            n=n->next;
        }
        return head;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        reverseList(l1);
        reverseList(l2);
         if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        int carry=0;
        int t=l1->data+l2->data+carry;
        while(t>=10){
             t-=10;
             carry++;
        }
        struct Node* n=new struct Node(t);
        struct Node* n1=l1->next,*n2=l2->next,*nn=n;
        while(n1!=nullptr || n2!=nullptr){
            if(n1==nullptr && n2!=nullptr){
                int t=n2->data+carry;
                carry=0;
                while(t>=10){
                    t-=10;
                    carry++;
                }
                n->next=new struct Node(t);
                n=n->next;
                n2=n2->next;
            }
            else if(n2==nullptr && n1!=nullptr){
                int t=n1->data+carry;
                carry=0;
                while(t>=10){
                    t-=10;
                    carry++;
                }
                n->next=new struct Node(t);
                n=n->next;
                n1=n1->next;
            }
            else{
                int t=n1->data+n2->data+carry;
                carry=0;
                while(t>=10){
                    t-=10;
                    carry++;
                }
                n->next=new struct Node(t);
                n=n->next;
                n1=n1->next;
                n2=n2->next;
            }
        }
        if(carry!=0){
            n->next=new struct Node(carry);
        }
        reverseList(nn);
        return nn;
        
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