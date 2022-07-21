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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*n=head;
        int k=1;
        while(n!=NULL){
            if(k==left){
                vector<int> v;
                ListNode* nn=n;
                while(k<=right){
                    v.push_back(nn->val);
                    nn=nn->next;
                    k++;
                }
                k=left;
                int p=v.size()-1;
                while(k<=right){
                    n->val=v[p--];
                    n=n->next;
                    k++;
                }
            }
            else{
                k++;
                n=n->next;
            }
        }
        return head;
    }
};