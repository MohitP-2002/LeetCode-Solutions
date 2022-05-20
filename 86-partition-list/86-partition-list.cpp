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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        ListNode* n = head;
        while(n!=nullptr){
            v.push_back(n->val);
            n=n->next;
        }
        vector<int> a,b;
        for(int i=0;i<v.size();i++){
            if(v[i]<x){
                a.push_back(v[i]);
            }
            else{
                b.push_back(v[i]);
            }
        }
        v.clear();
        for(auto i:a){
            v.push_back(i);
        }
        for(auto i:b){
            v.push_back(i);
        }
        int k=0;
        n=head;
        while(n!=NULL){
            n->val=v[k++];
            n=n->next;
        }
        return head;
    }
};