class Solution {
public:

int n,m,len;

vector<vector<int>> dir = {{1,0},{-1,0},{0,-1},{0,1}};

bool found(vector<vector<char>>& board,int i, int j, int ind, string &word){
    if(ind == len) return true;

    if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[ind]) return false;

    char ch = board[i][j];

    board[i][j] = '$';



    for(vector<int> &d : dir){
        int new_r = i + d[0];
        int new_c = j + d[1];

        if(found(board,new_r,new_c,ind+1,word)) return true;
    }

    board[i][j] = ch;


    return false;

}

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        len = word.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0] && found(board,i,j,0,word)) return true;
            }
        }

        return false;

    }
};