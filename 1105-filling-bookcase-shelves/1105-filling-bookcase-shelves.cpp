class Solution {
public:

int n;
int width;

int dp[1001][1001];

int solve(vector<vector<int>> books, int remainingWidth, int i, int maxHeight){
    if(i >= n) return maxHeight;

    if(dp[i][remainingWidth] != -1) return dp[i][remainingWidth];

    int take = INT_MAX;

    if(remainingWidth >= books[i][0]){
        take = solve(books,remainingWidth - books[i][0],i+1,max(maxHeight,books[i][1]));
    }

    int skip = maxHeight + solve(books,width-books[i][0],i+1,books[i][1]);

    return dp[i][remainingWidth] = min(take,skip);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        width = shelfWidth;

        memset(dp,-1,sizeof(dp));

        return solve(books,shelfWidth,0,0);
    }
};