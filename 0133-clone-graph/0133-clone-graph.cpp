

class Solution {
public:

vector<Node*> visited;

void dfs(Node* clone, Node* real){
    for(auto ele : real->neighbors){
        if(visited[ele->val] == NULL){
            Node* reference = new Node(ele->val);
            visited[ele->val] = reference;
            clone->neighbors.push_back(reference);
            dfs(reference,ele);
        }
        else{
            clone->neighbors.push_back(visited[ele->val]);
        }
    }
}

void bfs(queue<Node*> &q){

    while(!q.empty()){
        Node* real = q.front();   // real node
        q.pop();

        Node* clone = visited[real->val];  // clone of real

        for(Node* ele : real->neighbors){

            if(visited[ele->val] == NULL){
                Node* cloned_node = new Node(ele->val);
                visited[ele->val] = cloned_node;

                q.push(ele);   // ✅ real neighbor push

                clone->neighbors.push_back(cloned_node);
            }
            else{
                clone->neighbors.push_back(visited[ele->val]);
            }
        }
    }
}


    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        visited.resize(101,NULL);
        Node* clone = new Node(node->val);
        visited[clone->val] = clone;
        // dfs(clone,node);
        queue<Node*> q;

        q.push(node);

        bfs(q);

        return clone;
    }
};