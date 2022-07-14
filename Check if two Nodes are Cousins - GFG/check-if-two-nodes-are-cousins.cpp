// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false
struct Child{
    int parent;
    int level;
};
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   queue<pair<Node*,int>> q;
   q.push({root,0});
   Child A,B;
   while(!q.empty()){
       auto cur=q.front();
       q.pop();
       int  level = cur.second;
       Node* temp = cur.first;
       if(temp->left){
            if(temp->left->data==a){
                A.parent = temp->data;
                A.level=level+1;
            }
            if(temp->left->data==b){
                B.parent = temp->data;
                B.level=level+1;
            }
            q.push({temp->left, level+1});
       }
       if(temp->right){
           if(temp->right->data==a){
                A.parent = temp->data;
                A.level=level+1;
            }
            if(temp->right->data==b){
                B.parent = temp->data;
                B.level=level+1;
            }
           q.push({temp->right, level+1});
       }
   }
//   cout<<A.parent<<" "<<B.parent<<" "<<A.level<<" "<<B.level;
   if(A.parent!=B.parent && A.level == B.level) return true;
   return false;
}