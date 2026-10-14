
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next) return head;
        
        int n = 1;

        ListNode* temp = head;

        while(temp->next){
            n++;
            temp = temp->next;
        }

        k = k % n;
        if(k == 0) return head;

        ListNode* right = head;

        for(int i = 0; i < k; i++) right = right->next;

        ListNode* left = head;

        while(right->next) 
        {
            right = right->next;
            left = left->next;
        }

        temp = left->next;

        left->next = nullptr;

        right->next = head;

        return temp;


    }
};