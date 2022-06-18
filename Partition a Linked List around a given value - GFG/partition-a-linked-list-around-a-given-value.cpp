// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    vector<int> v;
        struct Node* n = head;
        while(n!=nullptr){
            v.push_back(n->data);
            n=n->next;
        }
        vector<int> a,b,c;
        for(int i=0;i<v.size();i++){
            if(v[i]<x){
                a.push_back(v[i]);
            }
            else if(v[i]==x){
                c.push_back(v[i]);
            }
            else{
                b.push_back(v[i]);
            }
        }
        v.clear();
        for(auto i:a){
            v.push_back(i);
        }
        for(auto i:c) v.push_back(i);
        for(auto i:b){
            v.push_back(i);
        }
        int k=0;
        n=head;
        while(n!=NULL){
            n->data=v[k++];
            n=n->next;
        }
        return head;
}