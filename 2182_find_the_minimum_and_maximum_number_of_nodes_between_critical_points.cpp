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
        ListNode* curr = head->next;
        ListNode* prev = head;
        int idx=1;
        vector<int> indexes;
        while(curr && curr->next){
            int prevVal = prev->val;
            int currVal=curr->val;
            int nxtVal = curr->next->val;
            if((currVal>prevVal && currVal>nxtVal) || (currVal<prevVal && currVal<nxtVal)){
                indexes.push_back(idx);
            }

            curr=curr->next;
            prev = prev->next;
            idx++;
        }

        int n = indexes.size();
        if(n<2){
            return {-1,-1};
        }

        int maxDist = indexes[n-1] - indexes[0];
        int minDist=INT_MAX;
        for(int i=1;i<n;i++){
            int dist = indexes[i]-indexes[i-1];
            minDist=min(minDist,dist);
        }

        return {minDist,maxDist};
    }
};