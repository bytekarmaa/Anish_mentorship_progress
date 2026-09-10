class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
         int n = scores.size();

        vector<vector<int>> dp(n+1,vector<int> (n+5,-1));

        vector<pair<int,int>> tem;

        for(int i = 0; i < n; i++) tem.push_back({ages[i],scores[i]});

        sort(tem.begin(),tem.end());

        vector<int> M_Score(n,0);

        M_Score[0] = tem[0].second;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(tem[j].second <= tem[i].second) {
                    M_Score[i] = max(M_Score[i],M_Score[j]);
                }
            }
            M_Score[i] += tem[i].second;
        }

        return *max_element(M_Score.begin(),M_Score.end());
    }
};


// class Solution {
// public:

// vector<vector<int>> dp;

// int n;

// int solve(vector<pair<int,int>> &tem, int ind, int prevInd){
//     if(ind == n) return 0;


//     if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

//     int take = 0;

//     if(prevInd == -1 || tem[prevInd].second <= tem[ind].second){
//         take = tem[ind].second + solve(tem,ind+1,ind);
//     }

//     int skip = solve(tem,ind+1,prevInd);

//     return dp[ind][prevInd+1] = max(take,skip);
// }

//     int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//          n = scores.size();

//         dp.assign(n+1,vector<int> (n+5,-1));

//         vector<pair<int,int>> tem;

//         for(int i = 0; i < n; i++) tem.push_back({ages[i],scores[i]});

//         sort(tem.begin(),tem.end());

//         return solve(tem,0,-1);
//     }
// };