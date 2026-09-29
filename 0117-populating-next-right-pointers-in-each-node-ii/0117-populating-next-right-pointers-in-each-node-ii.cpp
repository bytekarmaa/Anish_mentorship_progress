class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        Node* curr = root;

        while (curr) {
            Node dummy(0);          // dummy node for next level
            Node* tail = &dummy;    // builds next pointers

            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }

                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }

                curr = curr->next;  // move horizontally
            }

            curr = dummy.next;      // move to next level
        }

        return root;
    }
};
