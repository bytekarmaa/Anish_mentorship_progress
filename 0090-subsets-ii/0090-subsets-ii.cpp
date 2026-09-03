class Solution {
public:

int total = 0;

vector<vector<int>> res;

int n;

int idx = 0;

void solve(vector<int> &nums, int ind, int bitMask){
    if(ind == n){
        for(int i = 0; i < n; i++){
            if(bitMask & (1 << i)) res[idx].push_back(nums[i]);
        }

        idx++;

        return;
    }

    solve(nums,ind+1,(bitMask | (1 << ind)));

    int j = ind;

    while(j < n && nums[j] == nums[ind]) j++;

    solve(nums,j,bitMask);

    return;
}


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         n = nums.size();
        sort(nums.begin(), nums.end());

        total = 1;

        for(int i = 0; i < n; ) {
            int j = i;

            while(j < n && nums[j] == nums[i]) {
                j++;
            }

            int freq = j - i;
            total *= (freq + 1);

            i = j;
        }

        res.resize(total);

        int bitMask = 0;

        solve(nums,0,bitMask);


        return res;

        
    }
};