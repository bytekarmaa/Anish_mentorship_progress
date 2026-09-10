class Solution {
public:

vector<vector<int>> dp;

int n;

int solve(vector<pair<int,int>> &tem, int ind, int prevInd){
    if(ind == n) return 0;


    if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];

    int take = 0;

    if(prevInd == -1 || tem[prevInd].second <= tem[ind].second){
        take = tem[ind].second + solve(tem,ind+1,ind);
    }

    int skip = solve(tem,ind+1,prevInd);

    return dp[ind][prevInd+1] = max(take,skip);
}

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
         n = scores.size();

        dp.assign(n+1,vector<int> (n+5,-1));

        vector<pair<int,int>> tem;

        for(int i = 0; i < n; i++) tem.push_back({ages[i],scores[i]});

        sort(tem.begin(),tem.end());

        return solve(tem,0,-1);
    }
};