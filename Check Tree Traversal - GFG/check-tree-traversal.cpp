// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    struct Node {
    int data;
    Node *left, *right;
 
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node* buildTreeFromInorderPreorder(
    int inStart, int inEnd, int& preIndex, int preorder[],
    unordered_map<int, int>& inorderIndexMap,
    bool& notPossible)
{
    if (inStart > inEnd)
        return NULL;
 
    // build the current Node
    int rootData = preorder[preIndex];
    Node* root = new Node(rootData);
    preIndex++;
 
    // find the node in inorderIndexMap
    if (inorderIndexMap.find(rootData)
        == inorderIndexMap.end()) {
        notPossible = true;
        return root;
    }
 
    int inorderIndex = inorderIndexMap[rootData];
    if (!(inStart <= inorderIndex
          && inorderIndex <= inEnd)) {
        notPossible = true;
        return root;
    }
 
    int leftInorderStart = inStart,
        leftInorderEnd = inorderIndex - 1,
        rightInorderStart = inorderIndex + 1,
        rightInorderEnd = inEnd;
 
    root->left = buildTreeFromInorderPreorder(
        leftInorderStart, leftInorderEnd, preIndex,
        preorder, inorderIndexMap, notPossible);
 
    if (notPossible)
        return root;
 
    root->right = buildTreeFromInorderPreorder(
        rightInorderStart, rightInorderEnd, preIndex,
        preorder, inorderIndexMap, notPossible);
 
    return root;
}
 
    bool checkPostorderCorrect(Node* root, int& postIndex,
                           int postorder[])
{
    if (!root)
        return true;
 
    if (!checkPostorderCorrect(root->left, postIndex,
                               postorder))
        return false;
    if (!checkPostorderCorrect(root->right, postIndex,
                               postorder))
        return false;
 
    return (root->data == postorder[postIndex++]);
}
 
void printPostorder(Node* root)
{
    if (!root)
        return;
 
    printPostorder(root->left);
    printPostorder(root->right);
 
    cout << root->data << ", ";
}
 
void printInorder(Node* root)
{
    if (!root)
        return;
 
    printInorder(root->left);
    cout << root->data << ", ";
    printInorder(root->right);
}
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	// Your code goes here
    	if (N == 0)
        return true;
 
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < N; i++)
        inorderIndexMap[inorder[i]] = i;
 
    int preIndex = 0;
 
    // return checkInorderPreorder(0, N - 1, preIndex,
    // preorder, inorderIndexMap) &&
    // checkInorderPostorder(0, N - 1, postIndex, postorder,
    // inorderIndexMap);
 
    bool notPossible = false;
 
    Node* root = buildTreeFromInorderPreorder(
        0, N - 1, preIndex, preorder, inorderIndexMap,
        notPossible);
 
    if (notPossible)
        return false;
 
    int postIndex = 0;
 
    return checkPostorderCorrect(root, postIndex,
                                 postorder);
    } 

};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends