

// by pure backtracking


// class Solution {
// public:
//     int n;
    
//     bool isPalindrome(string &s, int l, int r) {
        
//         while(l < r) {
//             if(s[l] != s[r])
//                 return false;
//             l++;
//             r--;
//         }
        
//         return true;
        
//     }
    
//     void backtrack(string &s, int idx, vector<string> &curr, vector<vector<string>> &result) {
        
//         if(idx == n) {
//             result.push_back(curr);
//             return;
//         }
        
        
//         for(int i = idx; i<n; i++) {
            
//             if(isPalindrome(s, idx, i)) {
                
//                 curr.push_back(s.substr(idx, i-idx+1));
                
//                 backtrack(s, i+1, curr, result);
                
//                 curr.pop_back();
                
//             }
            
//         }
        
//     }
    
//     vector<vector<string>> partition(string s) {
//         n = s.length();
//         vector<vector<string>> result;
//         vector<string> curr;
        
//         backtrack(s, 0, curr, result);
        
//         return result;
        
//     }
// };




// dp approch

class Solution {
public:
vector<vector<bool>> dp;

vector<vector<string>> result;

void solve(string &s, int i, int j, vector<string> ref,int &n){
   
    if(i == n){
        result.push_back(ref);
        return;
    }

     if(j == n) return;

    if(dp[i][j]){
        ref.push_back(s.substr(i,j-i+1));
        solve(s,j+1,j+1,ref,n);
        ref.pop_back();
    }

    solve(s,i,j+1,ref,n);
}

    vector<vector<string>> partition(string s) {
        int n = s.size();

        dp.resize(n,vector<bool> (n,false));

        for(int len = 1; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = len + i - 1;

                if(i == j) dp[i][j] = true;

                else if(s[i] == s[j]){
                    if(len == 2) dp[i][j] = true;

                    else dp[i][j] = dp[i+1][j-1];
                }
            }
        }

        vector<string> ref;

        solve(s,0,0,ref,n);

        return result;

    }
};





