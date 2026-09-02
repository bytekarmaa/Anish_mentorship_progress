
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> results;
//         unordered_map<int, int> counter;
//         for (int num : nums) counter[num]++;
//         vector<int> comb;
//         backtrack(counter, comb, nums.size(), results);
//         return results;
//     }
//     void backtrack(unordered_map<int, int>& counter, vector<int>& comb, int N, vector<vector<int>>& results) {
//         if (comb.size() == N) {
//             results.push_back(comb);
//             return;
//         }
//         for (auto& item : counter) {
//             int num = item.first;
//             int count = item.second;
//             if (count == 0) continue;
//             comb.push_back(num);
//             counter[num]--;
//             backtrack(counter, comb, N, results);
//             comb.pop_back();
//             counter[num]++;
//         }
//     }
// };


class Solution {
public:

vector<vector<int>> res;


int n;


void solve(vector<int> &nums,  int ind){
    if(ind >= n){
        res.push_back(nums);
        return;
    }

    unordered_set<int> st;

    for(int i = ind; i < n; i++){

        if(st.count(nums[i])) continue;

        st.insert(nums[i]);

        swap(nums[i],nums[ind]);

        solve(nums,ind+1);

        swap(nums[i],nums[ind]);
    }

    return;
}

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();

        n = nums.size();

        solve(nums,0);


        return res;
    }
};