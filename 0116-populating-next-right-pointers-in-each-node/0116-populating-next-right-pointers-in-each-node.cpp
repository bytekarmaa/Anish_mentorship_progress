
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        Node* start_level = root;

        while(start_level->left){
            Node* curr = start_level;

            while(curr){
                curr->left->next = curr->right;

                if(curr->next){
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }

            start_level = start_level->left;
        }

        return root;
    }
};