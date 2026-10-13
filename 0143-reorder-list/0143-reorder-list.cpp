class Solution {
public:
ListNode* reverse(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = head;
    while(next != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tem = reverse(slow->next);
      
  slow->next = NULL;
        ListNode* head_next = head;
        ListNode* tem_next = tem;
        while(head && tem){
            head_next = head_next->next;
            tem_next = tem_next->next;

            head->next = tem;
            tem->next = head_next;

            head = head_next;
            tem = tem_next;
        }
        
    }
};