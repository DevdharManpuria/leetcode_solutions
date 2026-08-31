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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int cur = 1;
        vector<int> idx;
        while(curr != nullptr && curr->next != nullptr){
            ListNode* nextNode = curr->next;
            if(curr->val > prev->val && curr->val > nextNode->val || curr->val < prev->val && curr->val < nextNode->val) idx.push_back(cur);
            cur++;
            prev = curr;
            curr = nextNode;
        }
        if(idx.size() < 2) {
            return {-1, -1};
        }
        for(int i=0;i<idx.size()-1;i++){
            mini = min(mini,idx[i+1]-idx[i]);
        }
        maxi = max(maxi,idx[idx.size()-1]-idx[0]);
        return {mini,maxi};
    }
};