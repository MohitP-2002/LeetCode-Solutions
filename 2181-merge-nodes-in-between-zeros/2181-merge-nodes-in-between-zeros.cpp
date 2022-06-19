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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow=head;
        ListNode* ans = new ListNode(-1);
        head=ans;
        while(slow!=NULL){
            if(slow->val==0){
                int sum=0;
                while(slow->next!=NULL && slow->next->val!=0){
                    sum+=slow->next->val;
                    slow=slow->next;
                }
                if(sum==0) break;
                ans->next=new ListNode(sum);
                ans=ans->next;
            }
            slow=slow->next;
        }
        return head->next;
    }
};