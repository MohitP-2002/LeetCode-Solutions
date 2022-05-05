// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


 // } Driver Code Ends
//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int distributeCandyUtil(Node* root, int& ans)
{
    // Base Case
    if (root == NULL)
        return 0;
 
    // Traverse left subtree
    int l = distributeCandyUtil(root->left, ans);
 
    // Traverse right subtree
    int r = distributeCandyUtil(root->right, ans);
 
    // Update number of moves
    ans += abs(l) + abs(r);
 
    // Return number of moves to balance
    // current node
    return root->key + l + r - 1;
}
 
// Function to find the number of moves to
// distribute all of the candies
int distributeCandy(Node* root)
{
    int ans = 0;
 
    distributeCandyUtil(root, ans);
 
    return ans;
}
 
};

// { Driver Code Starts.
int main() {

	int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);

		Node *root = buildTree(str);
		Solution ob;
		cout << ob.distributeCandy(root) << "\n";

	}

	return 0;
}
  // } Driver Code Ends