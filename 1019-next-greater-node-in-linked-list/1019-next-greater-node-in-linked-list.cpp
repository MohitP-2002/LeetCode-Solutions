/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        vector<int> v;
        stack<int> s;
        int n = arr.size();
        int r[n];
         for (int i = n - 1; i >= 0; i--) {
        if (!s.empty()) {
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }
        }
        r[i] = s.empty() ? 0 : s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
        v.push_back(r[i]);
        return v;
    }
};