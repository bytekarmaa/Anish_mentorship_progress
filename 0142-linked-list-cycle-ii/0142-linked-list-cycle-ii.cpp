
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }

        if(flag){
            ListNode* tem = head;
            while(tem != slow){
                slow = slow->next;
                tem = tem->next;
            }
            return slow;
        }

        else return NULL;
    }
};
