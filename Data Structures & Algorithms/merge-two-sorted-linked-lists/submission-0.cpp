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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode* head;
        ListNode* itr1 = list1;
        ListNode* itr2 = list2;
        
        if(list1->val <= list2->val){
            head = list1;
            itr2 = list1;
            itr1 = list2;
        }else{
            head = list2;
            itr2 = list2;
            itr1 = list1;
        }

        while(itr1 && itr2){
            if(itr1->val >= itr2->val && (itr2->next == nullptr || itr2->next->val >= itr1->val)){
                ListNode* temp = itr1->next;
                itr1->next = itr2->next;
                itr2->next = itr1;
                itr1 = temp;
            }
            itr2 = itr2->next;
        }
        return head;
    }
};
