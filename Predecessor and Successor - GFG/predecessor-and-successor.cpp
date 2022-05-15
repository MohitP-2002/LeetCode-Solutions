// { Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}// } Driver Code Ends

#include <bits/stdc++.h>
/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void inorder(Node* root, vector<int>&v){
    if(root==nullptr) return;
    inorder(root->left, v);
    v.push_back(root->key);
    inorder(root->right, v);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
    vector<int> v;
    inorder(root, v);
    
    set<int> s;
    for(auto i:v){
        s.insert(i);
    }
    v.clear();
    for(auto i:s){
        if(i==key) continue;
        v.push_back(i);
    }
    if(key<=v[0]){
        pre=nullptr;
        suc=new Node(v[0]);
    }
    if(key>=v[v.size()-1]){
        pre=new Node(v[v.size()-1]);
        suc=nullptr;
    }
    for(int i=1;i<v.size();i++){
        if(v[i-1]<key && v[i]>key){
            pre=new Node(v[i-1]);
            suc=new Node(v[i]);
            break;
        }
    }
}