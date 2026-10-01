class Trie {
public:
    struct Node {
        Node* child[26] = {nullptr};
        bool isEnd = false;
    };
    
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* travel = root;
        for(int i = 0; i < s.size(); i++){
            int ch = s[i] - 'a';
            if(travel->child[ch] == nullptr){
                travel->child[ch] = new Node();
            }
            travel = travel->child[ch];
        }
        travel->isEnd = true;
    }
};

class Solution {
public:
    int n, m;
    vector<string> res;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};

    bool validate(vector<vector<char>>& board, int i, int j){
        if(i >= n || i < 0 || j >= m || j < 0 || board[i][j] == '#') return false;
        return true;
    }

    void solve(vector<vector<char>>& board, int i, int j, Trie::Node* node, string &ref){
        char ch = board[i][j];
        Trie::Node* nextNode = node->child[ch - 'a'];
        
        if(nextNode == nullptr) return;

        ref.push_back(ch);
        board[i][j] = '#'; 

        if(nextNode->isEnd){
            res.push_back(ref);
            nextNode->isEnd = false; 
        }

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(validate(board, new_i, new_j)){
                solve(board, new_i, new_j, nextNode, ref);
            }
        }

        board[i][j] = ch; 
        ref.pop_back(); 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string &t : words){
            trie.insert(t);
        }

        n = board.size();
        m = board[0].size();
        string ref = "";

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                solve(board, i, j, trie.root, ref);
            }
        }
        
        return res;
    }
};